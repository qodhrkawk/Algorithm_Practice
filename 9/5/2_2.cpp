#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;

long long int map[1001][1001];
long long int dp[1001][1001];

long long int d;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};



long long int INF = INT64_MAX;




void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));

    int time = 5;

    while(!q.empty()){

        pair<int,int> cur = q.front();
        q.pop();
        

        int ny,nx;

        for(int i = 0; i < 3 ; i++){
            ny = cur.first + ydir[i]; nx = cur.second + xdir[i];

            if(ny > 0 && nx > 0 && nx<= n && ny <=n){
                int tmp  = dp[ny][nx];
                if(dp[ny][nx] > dp[cur.first][cur.second] + map[ny][nx]){
                    dp[ny][nx] = min(dp[ny][nx],dp[cur.first][cur.second] + map[ny][nx]);
                    q.push(make_pair(ny,nx));
                }
                
            }

        }

    }



}



int main() {
	


    cin>>n>>d;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n ;j++){
            cin>>map[i][j];
            dp[i][j] = INF;
        }

    }
    dp[1][1] = map[1][1];

    bfs();

    if(d - dp[n][n] < 0){
        cout<<-1<<endl;
    }
    else{
        cout<<d - dp[n][n]<<endl;
    }



	return 0;
}