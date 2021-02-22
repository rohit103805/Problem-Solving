#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> Graph;
vector<int> Orders;
vector<int> Top;
vector<int> Check;
int val=0;

void Create(int n){
    int i, j, m, data, sum;
    for(i=0; i<n; i++){
        vector<int> Row;
        cout<<endl<<"Nodes connected to "<<(i+1)<<" : ";
        cin>>m;
        for(j=0; j<m; j++){
            cout<<endl<<"Enter data : ";
            cin>>data;
            sum=Orders[data-1];
            sum++;
            Orders[data-1]=sum;
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

void TopSort(int n){
    int i, j, k;
    vector<int>::iterator itr;
    for(i=0; i<n; i++){
        for(j=0; j<Orders.size(); j++){
            if(Orders[j]==0){
                Orders[j]=-1;
                Top.push_back(j+1);
                for(k=0; k<Graph[j].size(); k++){
                    Orders[Graph[j][k]-1]--;
                }
            }
        }
    }
}

void Disp(){
    int i, j;
    for(i=0; i<Graph.size(); i++){
        cout<<endl;
        for(j=0; j<Graph[i].size(); j++){
            cout<<Graph[i][j]<<" ";
        }
    }
}

void Display(){
    for(auto &a:Top){
        cout<<endl<<a;
    }
}

int main(){
    int choice, n;
    do{
        cout<<endl<<"Enter 1. Create, 2. Check Cyclicity and Topological Sort Order, 3. Display Graph : ";
        cin>>choice;
        switch(choice){
            case 1:{
                Orders.clear();
                Graph.clear();
                cout<<endl<<"How many nodes does the Graph Have ? ";
                cin>>n;
                Orders.assign(n, 0);
                Create(n);
                break;
            }
            case 2:{
                Check.push_back(1);
                DFS(1);
                if(val>0){
                    cout<<"Cyclic Graph. Hence no Topological Sorting Possible . ";
                }
                else if(val==0){
                    cout<<"Acyclic Graph. Hence Topological Sorting Possible . "<<endl;
                    TopSort(n);
                    Display();
                }
                break;
            }
            case 3:{
                Disp();
                break;
            }
        }
    }while(choice<=3);
    return 0;
}