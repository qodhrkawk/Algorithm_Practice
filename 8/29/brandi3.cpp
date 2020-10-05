#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int m;
int INF = INT32_MAX;

vector<pair<int,int> > a[201];
int d[201];
bool visited[201];

bool dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int,int> > pq;
    visited[start] = true;

    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int cur = pq.top().first;
        int distance = -pq.top().second;
        visited[cur] = true;
        pq.pop();

        if(d[cur] < distance){
            continue;
        }
        for(int i = 0; i < a[cur].size(); i++){
            int next = a[cur][i].first;
            int nextDistance = distance + a[cur][i].second;

            if(nextDistance < d[next]){
                // if(visited[next] == true){
                //     return false;
                // }
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }

        }



    }

    return true;
}





int main() {


    cin>>n>>m;

    int s,e,w;
    for(int i = 0; i < m; i++){
        cin>>s>>e>>w;
        a[s].push_back(make_pair(e,w));

    }

    for(int i = 1; i <= n; i++){
        d[i] = INF;
        visited[i] = false;

    }

    bool noBug = dijkstra(1);
    
    if(noBug){
        cout<<d[n]<<endl;
    }
    else{
        cout<<"bug"<<endl;
    }
    


	return 0;
}