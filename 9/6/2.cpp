#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;



vector<pair<int,int> > graph[1001];

int v, e;

int INF = 1000000000;

vector<int> dist(1001,INF);
vector<bool> visited(1001,false);

vector<vector<int> > map(1001,vector<int> (1001,100001));

int main() {
	

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>v>>e;




    int start,end,cost;
    for(int i = 1 ; i <= e; i++){
        cin>>start>>end>>cost;
        map[start][end] = min(map[start][end],cost);
    }

    for(int i = 1; i< 1001;i++){
        for(int j = 1; j< 1001 ;j++){
            if(map[i][j]<100001){
                graph[i].push_back(make_pair(j,map[i][j]));
            }
        }

    }

    

    cin>>start>>end;
    dist[start] = 0;

    priority_queue<pair<int,int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0,start));
    

    while(!pq.empty()){
        
        int cur = pq.top().second;
        int time = -pq.top().first; 

        pq.pop();

        if(!visited[cur]){    
            visited[cur] = true;

            for(int i = 0; i< graph[cur].size(); i++){

                int next = graph[cur][i].first;
                int nextCost = graph[cur][i].second;

                if(dist[next] > dist[cur] + nextCost){
                    dist[next] = dist[cur] + nextCost;
                    pq.push(make_pair(-dist[next],next));

                }



            }
        }
    }


    cout<<dist[end]<<endl;









	return 0;
}