#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;

int ydir[4] = {-1,1,0,0};
int xdir[4] = {0,0,-1,1};

int map[501][501];
int dp[501][501];


int dfs(int y, int x){

    if(y == n && x == m) return 1;
    if(dp[y][x] != -1) return dp[y][x];


    dp[y][x] = 0;

    int ny,nx;
    for(int i = 0; i < 4; i++){
        ny = y + ydir[i];
        nx = x + xdir[i];

        if(ny >0 && nx > 0 && ny <=n && nx <=m){
            if(map[y][x] > map[ny][nx]){
                dp[y][x] = dp[y][x] + dfs(ny,nx);
            }

        }

    }

    return dp[y][x];

}








int main() {
	

    cin>>n>>m;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            cin>>map[i][j];
            dp[i][j] = -1;
        }
    }

    cout<<dfs(1,1)<<endl;


    




	return 0;
}