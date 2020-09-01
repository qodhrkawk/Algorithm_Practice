#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int res = 0;
int n,m;



int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};



int bfs(int x, int y,vector<vector<int> > maze){

    queue<pair<int,int> > q;

    q.push(make_pair(y,x));
    int nx,ny;

    while(!q.empty()){

        pair<int,int> current = q.front();

        q.pop();

        for(int i = 0; i< 4; i++){
            ny = current.first + ydir[i]; nx = current.second + xdir[i];
            
            if(nx>0 && nx <=m && ny>0 && ny<=n && maze[ny][nx] == 0 &&!(ny == y && nx == x)){
                maze[ny][nx] = maze[current.first][current.second] + 1;
                q.push(make_pair(ny,nx));
            }

        }



    }


    int tmp = 0;


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= m; j++){
            tmp = max(tmp,maze[i][j]);
        }

    }

    return tmp;

}



int main() {

    cin>>n>>m;

    vector<vector<int> > maze(54,vector<int> (54,-1));

    for(int i = 1; i<=n;i++){
        string s; 
        cin>>s;
        for(int j = 1; j<=m; j++){
            if(s[j-1] == 'W'){
                maze[i][j] = -1;
            }
            else{
                maze[i][j] = 0;
            }


        }
    }

    


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= m; j++){
            if(maze[i][j] == 0){
                res = max(bfs(j,i,maze),res);
            }

        }

    }



    

    cout<<res<<endl;

	return 0;
}