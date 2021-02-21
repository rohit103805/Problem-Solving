#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<pair<int, int>>> Graph;   //Containing the Graph
vector<pair<int, pair<int, int>>> Data; // Containing Edge Weight Data
vector<vector<pair<int, int>>> MST; //Containing the MST
vector<pair<int, int>> Edger;   //Edges Visited
vector<int> Visited;    //Sides Visited
int FVal;
int Weights=0;

void Set(){
    int i;
    for(i=0; i<Graph.size(); i++){
        vector<pair<int, int>> Row;
        Row.push_back({-1, -1});
        MST.push_back(Row);
        Row.clear();
    }
}

void Create(){
    int i, j, n, m, data, weight;
    cout<<endl<<"How many nodes does the Graph Have ? ";
    cin>>n;
    for(i=0; i<n; i++){
        vector<pair<int, int>> Row;
        cout<<endl<<"Nodes connected to "<<(i+1)<<" : ";
        cin>>m;
        for(j=0; j<m; j++){
            cout<<endl<<"Enter data : ";
            cin>>data;
            cout<<endl<<"Enter weight : ";
            cin>>weight;
            if(data!=i+1){
                Row.push_back({weight, data});
                Data.push_back({weight, {i+1, data}});
            }
        }
        sort(Row.begin(), Row.end());
        Graph.push_back(Row);
        Row.clear();
    }
    sort(Data.begin(), Data.end());
}

void Disp(){
    int i, j;
    for(i=0; i<MST.size(); i++){
        cout<<endl<<" "<<i+1<<" : ";
        for(j=1; j<MST[i].size(); j++){
            cout<<MST[i][j].second<<" ";
            Weights=Weights+MST[i][j].first;
        }
    }
}

void Disp1(){
    for(auto &a:Data){
        cout<<endl<<"From : "<<a.second.first<<" To : "<<a.second.second<<" Weight : "<<a.first;
    }
}

int Detect(int compare){
    int count=1, Dist;
    vector<int>::iterator itr=Visited.begin();
    vector<int>::iterator itx;
    for(itr; itr!=Visited.end(); itr++){
        if(*itr==compare){
            itx=itr;
            count++;
            break;
        }
    }
    if(count==1){
        Visited.push_back(compare);
        return 0;
    }
    else if(count>1){
        Dist=distance(itx, Visited.end());
        if(Dist>2){
            return 10;
        }
        else if(Dist==2){
            return 1;
        }
    }
}

void Cyclicity(int n){
    int j, data, val;
    for(j=1; j<MST[n-1].size(); j++){
        data=MST[n-1][j].second;
        val=Detect(data);
        if(val==0){
            Cyclicity(data);
        }
        else if(val==10){
            FVal++;
        }
    }
    Visited.pop_back();
}

int Search(int N1, int N2){
    int x=0;
    for(auto &a:Edger){
        if((a.first==N1 && a.second==N2)||(a.first==N2 && a.second==N1)){
            x=1;
            break;
        }
        else{
            x=0;
        }
    }
    return x;
}

void Ready(){
    int weight, N1, N2, val;
    for(auto &a:Data){
        weight=a.first;
        N1=a.second.first;
        N2=a.second.second;
        val=Search(N1, N2);
        FVal=0;
        if(val==0){
            MST[N1-1].push_back({weight, N2});
            MST[N2-1].push_back({weight, N1});
            Edger.push_back({N1, N2});
            Edger.push_back({N2, N1});
            Visited.push_back(N1);
            Cyclicity(N1);
            if(FVal!=0){
                MST[N1-1].pop_back();
                MST[N2-1].pop_back();
            }
            Visited.clear();
        }
    }
}

int main(){
    int choice;
    do{
        cout<<endl<<"Enter choices : ";
        cin>>choice;
        switch(choice){
            case 1:{
                Graph.clear();
                Create();
                Set();
                break;
            }
            case 2:{
                Weights=0;
                Ready();
                Disp();
                Weights=Weights/2;
                cout<<endl<<endl<<"Total Weight : "<<Weights;               
                break;
            }
            case 3:{
                Disp1();
                break;
            }
        }
    }while(choice<=3);
    return 0;
}