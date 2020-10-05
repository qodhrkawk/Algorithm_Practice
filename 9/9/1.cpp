#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;

int map[101][101];
vector<vector<int> > way(101,vector<int> (101,-1));

int ydir[4] = {0,0,-1,1};
int xdir[4] = {1,-1,0,0};


void bfs(){

    queue<pair<int,int> > q;

    q.push(make_pair(1,1));
    way[1][1] = 0;

    while(!q.empty()){
        
        pair<int,int> cur = q.front();
        q.pop();

        int y = cur.first; int x = cur.second;

        int ny,nx;
        for(int i = 0; i < 4; i++){
            ny = y + ydir[i];
            nx = x + xdir[i];

            if(ny > 0 && nx > 0 && ny <= n && nx <= m && way[ny][nx] == -1){

                if(map[ny][nx] == 1){
                    way[ny][nx] = way[y][x] + 1;
                }
                else{
                    way[ny][nx] = way[y][x];
                }


            }


        }




    }
    



}




int main() {
	

    cin>>n>>m;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ;j<=m;j++){
            cin>>map[i][j];
        }
    }










	return 0;
}