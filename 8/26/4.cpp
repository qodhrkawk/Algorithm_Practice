#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

int N;


int ans = 1;


vector<vector<int> > maze(101,vector<int> (101,0));

int ydir[4] = {0,0,1,-1};
int xdir[4] = {-1,1,0,0};

queue<pair<int,int> > q;


int n,m;

void bfs(){

    


    q.push(make_pair(1,1));
    pair<int, int> cur;
    int nx,ny;
    while(!q.empty()){

        cur = q.front();
        q.pop();

        


        for(int i = 0; i < 4; i++){
            nx = cur.second+xdir[i]; ny = cur.first + ydir[i];

            if(nx > 0 && nx <= m && ny >0 && ny <=n && maze[ny][nx] == 1){
                q.push(make_pair(ny,nx));
                maze[ny][nx] = maze[cur.first][cur.second] + 1;
            }

        }

    }




}





int main(){


    cin>>n>>m;
    for(int i = 0 ; i<= n; i++){
        string s;
        if(i!=0){
            
            cin>>s;
        }
        for(int j = 0; j<=m; j++){
            if(i==0 || j ==0){
                maze[i][j] = 0;
            }
            else{
                if(s[j-1] == '1')
                    maze[i][j] = 1;
                else
                    maze[i][j] = 0;
            }

        }

    }


    bfs();

    cout<<maze[n][m]<<endl;


    return 0;
}