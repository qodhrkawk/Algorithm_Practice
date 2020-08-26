#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int N;


double ans = 0;
vector<vector<bool> > arr(30,vector<bool> (30,false));


int xdir[4] = {0,0,1,-1};
int ydir[4] = {-1,1,0,0};

double per[4];

void dfs(int time, int r, int c, double res){


    if(time == N){
        ans += res;
        return;
    }
    
    arr[r][c] = true;

    for(int i = 0; i < 4; i++){
        int nx = r + xdir[i]; int ny = c + ydir[i];
        if(!arr[nx][ny]){
            dfs(time+1,nx,ny,res*per[i]);

        }


    }
    arr[r][c] = false;


}





int main(){



    cin>>N>>per[0]>>per[1]>>per[2]>>per[3];

    per[0] *= 0.01; per[1] *= 0.01; per[2] *= 0.01; per[3] *= 0.01;

    int r = 15;
    int c = 15;





    dfs(0,15,15,1.0);

    cout<<fixed;
    cout<<setprecision(10)<<ans<<endl;




    return 0;
}