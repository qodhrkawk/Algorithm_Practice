#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dfs(vector<vector<int> > graph,vector<bool>& isvisited,int start){

    int res = 1;
    isvisited[start] = true;


    for(int i = 0; i<graph[start].size();i++){
        if(isvisited[graph[start][i]]==false){
            res += dfs(graph,isvisited,graph[start][i]);
        }
    }


    return res;
}





int main(){
    
    int v,e,v1,v2;

    cin>>v>>e;


    vector<vector<int> > graph(101);
    vector<bool> isvisited(101,false);
    for(int i = 0;i < e; i++){
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }

    cout<<dfs(graph,isvisited,1)-1<<endl;;


}