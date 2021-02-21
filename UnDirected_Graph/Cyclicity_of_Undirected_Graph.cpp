#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> Visited={1};
vector<vector<pair<int, int>>> Graph;
int FVal=0;

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
            Row.push_back({data, weight});
        }
        sort(Row.begin(), Row.end());
        Graph.push_back(Row);
        Row.clear();
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
    for(j=0; j<Graph[n-1].size(); j++){
        data=Graph[n-1][j].first;
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

int main(){
    int choice;
    do{
        cout<<endl<<"Enter choices : ";
        cin>>choice;
        switch(choice){
            case 1:{
                Graph.clear();
                Create();
                break;
            }
            case 2:{
                Cyclicity(1);
                if(FVal==0){
                    cout<<endl<<" No cycle present ";
                }
                else{
                    cout<<endl<<" Cycles Present ";
                }
                break;
            }
        }
    }while(choice<=2);
    return 0;
}