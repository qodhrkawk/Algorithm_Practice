#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int INF = INT32_MAX;


int v,e;
int start;

int main() {
    

    cin>>v>>e;

    vector<vector<int> > graph(v+1,vector<int> (v+1,11));
    
    vector<int> dist(v+1,INF);
    vector<bool> visited(v+1,false);
    
    cin>>start;

    int s,end,w;
    for(int i = 0; i < e; i++){
        cin>>s>>end>>w;
        graph[s][end] = min(graph[s][end],w);
    }


    int visits = 1;
    visited[start] = true;
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        
        int cur = q.front();
        q.pop();

        for(int i = 1; i < graph[cur].size(); i++){
            if(graph[cur][i] == 11){
                continue;
            }
            if(dist[i] > dist[cur] + graph[cur][i]){
                dist[i] = dist[cur] + graph[cur][i];
                q.push(i);
            }
        }

    }

    
    for(int i = 1; i<= v; i++){
        if(dist[i] == INF){
            cout<<"INF"<<endl;
        }
        else{
            cout<<dist[i]<<endl;
        }

    }





	return 0;
}