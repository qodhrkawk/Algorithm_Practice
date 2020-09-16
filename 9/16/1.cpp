#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

int MAX = 501;

vector<vector<int> > graph(501);
vector<int> costs(MAX,0);
vector<int> entry(MAX,0);
vector<int> result(MAX,0);

int n;










int main() {

    cin>>n;

    
    for(int t = 1; t<= n; t++){
        int prev;

        cin>>costs[t];
        cin>>prev;
        while(prev != -1){
            graph[prev].push_back(t);
            cin>>prev;
            entry[t]++;
        }


    }


    queue<int> q;

    for(int i = 1; i <= n; i++){

        if(entry[i] == 0){
            q.push(i);
            result[i] = costs[i];
        }


    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size() ; i++){
            int next = graph[cur][i];

            entry[next]--;

            result[next] = max(result[next], result[cur] + costs[next]);
            
            if(entry[next] == 0)
                q.push(next);
            


        }





    }

    for(int i = 1; i<= n; i++){
        cout<<result[i]<<endl;

    }


	return 0;
}