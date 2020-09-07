#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;

int map[501][501];

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};

int answer = 0;
vector<vector<bool> > visited(501,vector<bool> (501,false));

void dfs(int y ,int x,int res, int depth){

    if(depth >= 4){
        answer = max(answer, res + map[y][x]);
        return;
    }

    for(int i = 0; i < 4; i ++){
        int ny = y + ydir[i];
        int nx = x + xdir[i];

        if(ny > 0 && nx > 0 && ny <= n && nx <= m && visited[ny][nx] == false){
            visited[ny][nx] = true;
            dfs(ny,nx,res+map[y][x],depth+1);
            visited[ny][nx] = false;
        }
    }



    return;





}



int main() {
	


    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m ;j++){
            cin>>map[i][j];
        }

    }


    

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m ;j++){
            dfs(i,j,0,1);
        }

    }

    cout<<answer<<endl;


	return 0;
}