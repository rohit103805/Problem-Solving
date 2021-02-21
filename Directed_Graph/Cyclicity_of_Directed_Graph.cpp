//Cyclicity of Directed Graph

#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> Graph;
vector<int> Check;
int val=0;

void Create(){
    int i, j, n, m, data;
    cout<<endl<<"How many nodes does the Graph Have ? ";
    cin>>n;
    for(i=0; i<n; i++){
        vector<int> Row;
        cout<<endl<<"Nodes connected to "<<(i+1)<<" : ";
        cin>>m;
        for(j=0; j<m; j++){
            cout<<endl<<"Enter data : ";
            cin>>data;
            Row.push_back(data);
        }
        sort(Row.begin(), Row.end());
        Graph.push_back(Row);
        Row.clear();
    }
}

void DFS(int node){
    int j, element;
    for(j=0; j<Graph[node-1].size(); j++){
        element=Graph[node-1][j];
        if(find(Check.begin(), Check.end(), element)==Check.end()){
            Check.push_back(element);
            DFS(element);
            Check.pop_back();
        }
        else if(find(Check.begin(), Check.end(), element)!=Check.end()){
            val++;
            break;
        }
    }       
}

void Display2(){
    int i, j;
    for(i=0; i<Graph.size(); i++){
        cout<<endl<<(i+1)<<" :  ";
        for(j=0; j<Graph[i].size(); j++){
            cout<<Graph[i][j]<<" ";
        }
    }
}

int main(){
    int choice;
    do{
        cout<<endl<<"Enter 1. Create, 2. Check, 3. Display Graph : ";
        cin>>choice;
        switch(choice){
            case 1:{
                Graph.clear();
                Create();
                break;
            }
            case 2:{
                Check.push_back(1);
                DFS(1);
                if(val>0){
                    cout<<"Cyclic Graph .";
                }
                else if(val==0){
                    cout<<"Acyclic Graph .";
                }
                break;
            }
            case 3:{
                Display2();
                break;
            }
        }
    }while(choice<=3);
    return 0;
}
