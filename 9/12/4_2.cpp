#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 동 북 서 남
int ydir[4] = {0,-1,0,1};
int xdir[4] = {1,0,-1,0};

int res = 0;



int solution(vector<vector<int> > maze) {
    
    int n = maze.size();


    int ny,nx;
    int y = 0; int x = 0; int dir  = 4;
    while(!(y== n-1 && x == n-1)){

         //초기상태
        if(dir == 4){
            for(int i = 0; i < 4 ; i++){
                ny = y + ydir[i];
                nx = x + xdir[i];

                if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                    dir = i;
                    break;
                }
            }
            res++;
            
            y = ny; x = nx; 

        }

        else{

            ny = y + ydir[(dir+1)%4];
            nx = x + xdir[(dir+1)%4];  
            if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                
                y = ny;
                x = nx;
                dir = (dir+1)%4;
                res++;
                continue;

            }

            ny = y + ydir[dir];
            nx = x + xdir[dir];
            if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                maze[y][x] = 0;
                y = ny; x = nx; res++;
            }
            else{
                bool goAble = false;
                dir = (dir+1) %4;   
                ny = y + ydir[dir];
                nx = x + xdir[dir];

                if(ny >= 0 && nx >= 0 && ny < n && nx < n && maze[ny][nx] == 0){
                    y = ny; x = nx; res++;
                }
                else{
                    while(!goAble){
                        dir = (dir+3)%4;
                        
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

    }



    return res;
}

