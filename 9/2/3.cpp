#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int xdir[4] = {1,0,-1,0};
int ydir[4] = {0,1,0,-1};
int n,m;
int res = 0;

int INF = INT32_MAX;

queue<pair<int,int> > q;

vector<vector<int> > maze(1001,vector<int> (1001,-1));
vector<vector<int> > ans(1001,vector<int> (1001,INF));


bool all(){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m;j++){
            if(maze[i][j] == 0){
                return false;
            }

        }
    }
    return true;

}

int bfs(){


    if(q.empty()){
        return -1;
    }

    int day = 0;


    while(!q.empty()){

        int curSize = q.size();

        for(int i = 0; i < q.size();i ++){

            pair<int,int> cur = q.front();
            
            int nx,ny;

            for(int i = 0; i < 4; i++){
                ny = cur.first + ydir[i];
                nx = cur.second + xdir[i];

                if(nx>0 && ny > 0 && nx <= m && ny <=n && maze[ny][nx] == 0){
                    maze[ny][nx] = 1;
                    q.push(make_pair(ny,nx));
                }

            }

            q.pop();

        }

        

        cout<<day<<endl;
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<=m;j++){
                cout<<maze[i][j];

            }
            cout<<endl;
        }
        cout<<endl;


        if(all() && q.size() == 0){
            return day;
        }
        if(!all() && q.size() == 0){
            return -1;
        }

        day++;

        
    }



}


int main() {


    cin>>m>>n;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m;j++){
            cin>>maze[i][j];
            if(maze[i][j] == 1){
                q.push(make_pair(i,j));
            }

        }
    }

    


    res = bfs();



    cout<<res<<endl;







	return 0;
}