#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

void Enter(vector<int> &vec, vector<int> &vec1){
    vec.clear();
    vec1.clear();
    int check=1, data;
    do{
        cout<<endl<<"Enter for 1 : ";
        cin>>data;
        vec.push_back(data);
        cout<<endl<<"1 to continue, 0 to STOP : ";
        cin>>check;
    }while(check!=0);
    check=1, data=0;
    do{
        cout<<endl<<"Enter for 2 : ";
        cin>>data;
        vec1.push_back(data);
        cout<<endl<<"1 to continue, 0 to STOP : ";
        cin>>check;
    }while(check!=0);
}

void Multiplication(vector<int> vec, vector<int> vec1, vector<vector<int>> &Result){
    int i, j, rem, n=vec1.size(), data, carry;
    for(i=0; i<n; i++){
        vector<int> Row;
        rem=vec1.back();
        vec1.pop_back();
        carry=0;
        for(j=vec.size()-1; j>=0; j--){
            data=vec[j]*rem;
            data=data+carry;
            carry=data/10;
            data=data%10;
            Row.push_back(data);
        }
        reverse(Row.begin(), Row.end());
        for(j=0; j<i; j++){
            Row.push_back(0);
        }
        Result.push_back(Row);
        Row.clear();
    }
}

void Calculate(vector<vector<int>> Result, vector<vector<int>> &Calc){
    int i, j, data, carry=0;
    vector<int> Row1;
    for(j=0; j<Result[0].size(); j++){
        Row1.push_back(Result[0][j]);
    }
    Calc.push_back(Row1);

    for(i=1; i<Result.size(); i++){
        vector<int> Row;
        for(j=Calc[i-1].size()-1; j>=0; j--){
            data=Calc[i-1][j]+Result[i][j+1];
            data=data+carry;
            carry=data/10;
            data=data%10;
            Row.push_back(data);
        }
        data=Result[i].front()+carry;
        if(data>=10){
            Row.push_back(0);
            Row.push_back(1);
        }
        else if(data<10){
            Row.push_back(data);
        }
        reverse(Row.begin(), Row.end());
        Calc.push_back(Row);
        Row.clear();
    } 
}

void Display(vector<vector<int>> Calc){
    int i=Calc.size()-1, j;
    cout<<endl;
    for(j=0; j<Calc[i].size(); j++){
        cout<<Calc[i][j]<<" ";
    }
}

int main(){
    int choice, num;
    vector<int> vec;
    vector<int> vec1;
    vector<vector<int>> Result;
    vector<vector<int>> Calc;
    do{
        cout<<endl<<"Enter Choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
                Enter(vec, vec1);
                break;
            }
            case 2:{
                Multiplication(vec, vec1, Result);
                Calculate(Result, Calc);
                Display(Calc);
                break;
            }
        }
    }while(choice<=2);
    return 0;
}