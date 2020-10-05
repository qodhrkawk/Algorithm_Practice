#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;

int map[501][501];
int answer = 0;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};


void dfs(int y,int x){
    
    if(y == n && x == m){
        answer++;
        return;
    }

    int ny,nx;
    for(int i = 0 ;i < 4; i++){
        ny = y + ydir[i];
        nx = x + xdir[i];

        if(ny > 0 && nx > 0 && ny <= n && nx <=m){
            if(map[ny][nx] < map[y][x]){
                dfs(ny,nx);
            }
        }

    }


    return;


}





int main() {
	

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            cin>>map[i][j];
        }
    }

    cout<<answer<<endl;




	return 0;
}