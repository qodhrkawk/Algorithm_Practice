#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int d;
int INF = INT32_MAX;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {-1,1,0,0};



int bfs(vector<vector<int> > river,int r,int c){


    queue<pair<int,int>> q;

    q.push(make_pair(r,c));
    pair<int, int> cur;
    int nx,ny;
    while(!q.empty()){

        cur = q.front();
        q.pop();

    
        for(int i = 0; i < 4; i++){
            nx = cur.second+xdir[i]; ny = cur.first + ydir[i];

            if(nx > 0 && nx <= n && ny >0 && ny <=n && river[ny][nx] == 0 && !(ny == r && nx == c)){
                q.push(make_pair(ny,nx));
                river[ny][nx] = river[cur.first][cur.second] + 1;
            }

        }
    }
    
    int res = 1;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(river[i][j] > 0 && river[i][j] <= d){
                res++;
            }
        }

    }




    return res;



}






int main() {


    cin>>n>>d;

    vector<vector<int> > river(n+1,vector<int> (n+1,0));

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            int tmp;
            cin>>tmp;
            if(tmp == 1){
                river[i][j] = -1;
            }
            else{
                river[i][j] = 0;
            }

        }

    }

    int res = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(river[i][j] != -1){
                res = max(res,bfs(river,i,j));
            }

        }


    }

    cout<<res<<endl;





	return 0;
}