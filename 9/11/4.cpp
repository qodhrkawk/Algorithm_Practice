#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int INF = 1000000000;





vector<pair<int,int> > graph[201];
int dist[201];
int ddist[201];



int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    for(auto fare : fares){
        graph[fare[0]].push_back(make_pair(fare[1],fare[2]));
        graph[fare[1]].push_back(make_pair(fare[0],fare[2]));

    }

    for(int i = 1 ;i <= 201 ;i++){
        dist[i] = INF;
    }

    priority_queue<pair<int,int> > pq;
    dist[s] = 0;
    pq.push(make_pair(0,s));

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

    answer += dist[a];
    answer += dist[b];

    


    for(int i = 1; i<= n; i++){
        if(i == s || dist[i] == INF)
            continue;
        
        int tmp = dist[i];
        
        for(int i = 1 ;i <= n ;i++){
            ddist[i] = INF;
        }

        priority_queue<pair<int,int> > pq;
        ddist[i] = 0;
        pq.push(make_pair(0,i));

        while(!pq.empty()){
            
            int cur = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            for(int i = 0; i < graph[cur].size(); i++){
                int next = graph[cur][i].first;
                int nextCost = graph[cur][i].second;

                if(ddist[next] > cost + nextCost){
                    ddist[next] = cost+nextCost;
                    pq.push(make_pair(-ddist[next],next));
                }
            }

        }
        answer = min(ddist[a] + ddist[b] + tmp,answer);

    }


    

    return answer;
}

