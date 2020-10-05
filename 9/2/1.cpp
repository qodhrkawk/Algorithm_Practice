#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,k,l;

// 시계방향
int xdir[4] = {1,0,-1,0};
int ydir[4] = {0,1,0,-1};
vector<pair<int,int> > snake;
int res = 0;

bool move(int ny, int nx, vector<vector<int> >& maze){
    if(ny > n || nx > n || ny < 1 || nx < 1){
        return false;
    }
    if(maze[ny][nx] == 1){
        return false;
    }

    else if(maze[ny][nx] == 2){
        maze[ny][nx] = 1;
        snake.push_back(make_pair(ny,nx));
    }
    else if(maze[ny][nx] == 0){
        maze[ny][nx] = 1;
        maze[snake[0].first][snake[0].second] = 0;
        snake.erase(snake.begin());
        snake.push_back(make_pair(ny,nx));
    }

    return true;


}


int main() {


    cin>>n>>k;

    vector<vector<int> > maze(n+1,vector<int> (n+1,0));
    

    
    int x,y;
    for(int i = 0; i < k; i++){
        cin>>y>>x;
        maze[y][x] = 2;
    }

    cin>>l;

    int time;
    char c;
    int head;

    maze[1][1] = 1;


    vector<pair<int,char> > changes;

    for(int i = 0 ;i  < l; i++){
        cin>>time>>c;
        changes.push_back(make_pair(time,c));
    }
    changes.push_back(make_pair(10001,'D'));

    int timeIdx = 0;
    int curDirection = 0;
    int ny,nx;
    nx=1; ny = 1;
    snake.push_back(make_pair(1,1));

    for(int i = -1; i <= 10000; i++){

        // cout<<i<<endl;

        // for(int j = 1; j<=n;j++){
        //     for(int k = 1; k<= n; k++){
        //         cout<<maze[j][k]<<" ";
        //     }
        //     cout<<endl;

        // }

        // cout<<endl<<endl;

        


        if(i < changes[timeIdx].first-1){
            ny = ny + ydir[curDirection]; nx = nx + xdir[curDirection];
            if(!move(ny,nx,maze)){
                res = i+1;
                break;
            }
        }

        else{
            
            if(changes[timeIdx].second == 'D'){
                curDirection = (curDirection+1) %4;
            }


            else{
                curDirection = (curDirection+3)%4;
            }
            ny = ny + ydir[curDirection]; nx = nx + xdir[curDirection];

            if(!move(ny,nx,maze)){
                res = i+1;
                break;
            }
            timeIdx++;

        }


    }




    cout<<res+1<<endl;







	return 0;
}