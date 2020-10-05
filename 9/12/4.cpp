#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 동 서 남 북
int ydir[4] = {0,-1,0,1};
int xdir[4] = {1,0,-1,0};
int n;
int res = 0;

// vector<vector<int>> map(301,vector<int> (301,0));

void dfs(int y,int x ,int dir,int depth){

    // cout<<y << " " << x << " "<< depth<<endl;
    if(y == n-1 && x == n-1){
        res = depth;
        return;
    }

    int ny,nx,nd;

    //초기상태
    if(dir == 4){
        for(int i = 0; i < 4 ; i++){
            ny = y + ydir[i];
            nx = x + xdir[i];

            if(ny >= 0 && nx >= 0 && ny < n && nx < n && map[ny][nx] == 0){
                nd = i;
                break;
            }
        }

        dfs(ny,nx,nd,depth+1);
    }


    else{

        ny = y + ydir[dir];
        nx = x = xdir[dir];

        if(map[ny][nx] == 0){
            dfs(ny,nx,dir,depth+1);
        }
        else{
            bool goAble = false;

            while(!goAble){
                dir = (dir+1)%4;
                ny = y + ydir[dir];
                nx = x + xdir[dir];
                if(ny >= 0 && nx >= 0 && ny < n && nx < n && map[ny][nx] == 0){
                    goAble = true;
                }
            }
            
            dfs(ny,nx,dir,depth+1);


        }






    }


    


}


int solution(vector<vector<int>> maze) {
    n = maze.size();

    // for(int i = 0; i < maze.size(); i++){
    //     for(int j = 0; j < maze.size(); j++){
    //         map[i][j] = maze[i][j];
    //     }

    // }

    int ny,nx,nd;
    int y = 0; int x = 0; int dir  = 4;

    while(!(y== n-1 && x == n-1)){
         //초기상태
        if(dir == 4){
            for(int i = 0; i < 4 ; i++){
                ny = y + ydir[i];
                nx = x + xdir[i];

                if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                    nd = i;
                    break;
                }
            }
            res++;
            y = ny; x = nx; dir = nd;
        }

        else{

            ny = y + ydir[dir];
            nx = x = xdir[dir];

            if(maze[ny][nx] == 0){
                y = nx; x = nx; res++;
            }
            else{
                bool goAble = false;

                while(!goAble){
                    dir = (dir+1)%4;
                    ny = y + ydir[dir];
                    nx = x + xdir[dir];
                    if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                        goAble = true;
                    }
                }
                
                y = ny; x = nx; res++;


            }


        }




    }


   



    return res;
}