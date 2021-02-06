#include<bits/stdc++.h>
#include<vector>

using namespace std;

void Create(vector<vector<pair<int, string>>> &mat, vector<char> &List){
    int i, marks;
    string name;
    int a=100, b=200, c=300, d=400, e=500;
    for(i=0; i<25; i++){
        cout<<endl<<"Enter Marks : ";
        cin>>marks;
        cout<<endl<<"Enter Name : ";
        cin>>name;
        if(marks<100 && marks>=90){
            if(List.at(0)=='x'){
                List.at(0)='A';
            }
            a++;         
            mat[0].push_back({a, name});
        }
        else if(marks<90 && marks>=80){
            if(List.at(1)=='x'){
                List.at(1)='B';
            }
            b++;
            mat[1].push_back({b, name});
        }
        else if(marks<80 && marks>=70){
            if(List.at(2)=='x'){
                List.at(2)='C';
            }
            c++;
            mat[2].push_back({c, name});
        }
        else if(marks<70 && marks>=60){
            if(List.at(3)=='x'){
                List.at(3)='D';
            }
            d++;
            mat[3].push_back({d, name});
            
        }
        else if(marks<60 && marks>=50){
            if(List.at(4)=='x'){
                List.at(4)='E';
            }
            e++;
            mat[4].push_back({e, name});
        }
    }
}

void Reset(vector<vector<pair<int, string>>> &mat, vector<char> &List){
    List.reserve(5);
    List.assign(5, 'x');
    int i;
    for(i=0; i<5; i++){
        vector<pair<int, string>> row;
        row.push_back({-1, "x"});
        mat.push_back(row);
        row.clear();
    }
}

void Display(vector<vector<pair<int, string>>> &mat, vector<char> &List){
    int roll, a, b;
    cout<<"Enter ID Number : ";
    cin>>roll;
    a=roll/100-1;
    b=roll%100;
    
    cout<<endl<<"Section : "<<List[a];
    cout<<endl<<"Section Roll: "<<mat[a][b].first%100;
    cout<<endl<<"Name: "<<mat[a][b].second;
}

int main(){
    vector<char> List;
    vector<vector<pair<int, string>>> mat;
    int choice;
    do{
        cout<<endl<<"Enter choice :";
        cin>>choice;
        switch(choice){
            case 1:{
                List.clear();
                mat.clear();
                Reset(mat, List);//Reset the Matrix.
                Create(mat, List);//Create the Matrix and the List.
                break;
            }
            case 2:{
                Display(mat, List);//Search for the element.
                break;
            }
        }
    }while(choice<=2);
    return 0; 
}