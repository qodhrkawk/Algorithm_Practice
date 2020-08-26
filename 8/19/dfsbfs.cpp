#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void dfs(vector<vector<int> > graph,vector<bool>& visited,int v1){

    cout<<v1<<" ";
    visited[v1] = true;

    for(int i = 0; i < graph[v1].size(); i++){
        if(visited[graph[v1][i]] == false){
            dfs(graph,visited,graph[v1][i]);
        }

    }





}

void bfs(vector<vector<int> > graph,vector<bool>& visited,int v1){
    
    queue<int> q;
    visited[v1] = true;
    q.push(v1);

    while (!q.empty())
    {
        int tmp = q.front();
        visited[tmp] = true;
        cout<<tmp<<" ";

        q.pop();

        for(int i = 0; i< graph[tmp].size();i++){
            if(visited[graph[tmp][i]] == false){
                visited[graph[tmp][i]] = true;
                q.push(graph[tmp][i]);
            }

        }


        
    }
    

    





}






int main(){
    
    int v,e,start;

    cin>>v>>e>>start;

    vector<vector<int> > graph(v+1);
    vector<bool> dfsvisited(v+1,false);
    vector<bool> bfsvisited(v+1,false);


    for(int i = 0 ; i < e; i++){
        int v1,v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1 ; i <= v; i++){
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(graph,dfsvisited,start);
    cout<<endl;
    bfs(graph,bfsvisited,start);
    cout<<endl;


    return 0;    



}