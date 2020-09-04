#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n,m,r,c,dir;

// 북 동 남 서
int xdir[4] = {0,1,0,-1};
int ydir[4] = {-1,0,1,0};
int res;

vector<vector<int> > map(51,vector<int> (51,0));


void dfs(int y, int x, int d){

    if(map[y][x] == 1){
        return;
    }

    if(map[y][x] == 0){
        map[y][x] = 2;
        res++;
    }

    
    for(int i = 0; i < 4; i++){
        int nDir = (d+3)%4;
    
        int ny = y + ydir[nDir];
        int nx = x + xdir[nDir];

        if(map[ny][nx] == 0){
            dfs(ny,nx,nDir);
            return;
        }
        else{
            d = nDir;
        }



    }

    int ny = y + ydir[(d+2)%4];
    int nx = x + xdir[(d+2)%4];

    dfs(ny,nx,d);

}



int main() {

    cin>>n>>m;

    cin>>r>>c>>dir;


    for(int i = 1; i<= n;i++){
        for(int j = 1; j<=m; j++){
            cin>>map[i][j];
        }
    }

    dfs(r+1,c+1,dir);
    cout<<res<<endl;




    
    




	return 0;
}