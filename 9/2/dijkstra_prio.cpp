#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int INF = 1000000000;


int v,e;
int start;


vector<pair<int,int> > graph[20010];
int dist[20010];

int main() {
    

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>v>>e;
    cin>>start;

    int s,end,w;
    for(int i = 0; i < e; i++){
        cin>>s>>end>>w;
        graph[s].push_back(make_pair(end,w));

    }

    for(int i = 1 ;i <= v ;i++){
        dist[i] = INF;
    }



    priority_queue<pair<int,int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;

            if(dist[next] > cost + nextCost){
                dist[next] = cost+nextCost;
                pq.push(make_pair(-dist[next],next));
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