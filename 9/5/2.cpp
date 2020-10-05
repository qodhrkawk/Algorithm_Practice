#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int map[1001][1001];

long long int d;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};

long long int answer = INT64_MAX;


void dfs(int y,int x,long long int res,vector<vector<bool > > visited){


    visited[y][x] = true;
    res += map[y][x];

    if(y==n && x == n){
        answer = min(answer,res);
        return;
    }

    else{
        int ny,nx;

        for(int i = 0; i < 3 ; i++){
            ny = y + ydir[i]; nx = x + xdir[i];
            if(ny > 0 && nx > 0 && ny<= n && nx <= n){
                if(!visited[ny][nx])
                    dfs(ny,nx,res,visited);
            }
        }
    }

    return;

}



int main() {
	


    cin>>n>>d;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n ;j++){
            cin>>map[i][j];
        }

    }

    vector<vector<bool > > visited(n+1,vector<bool> (n+1,false));

    dfs(1,1,0,visited);

    if(d - answer < 0){
        cout<<-1<<endl;
    }
    else{
        cout<<d - answer<<endl;
    }



	return 0;
}