#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
// vector<vector<int> > house(51,vector<int> (51,1));

int ydir[4] = {0,0,1,-1};
int xdir[4] = {-1,1,0,0};

void bfsRef(vector<vector<int> >& house){

    queue<pair<int,int>> q;

    q.push(make_pair(1,1));
    pair<int, int> cur;
    int nx,ny;
    while(!q.empty()){

        cur = q.front();
        q.pop();

    
        for(int i = 0; i < 4; i++){
            nx = cur.second+xdir[i]; ny = cur.first + ydir[i];

            if(nx > 0 && nx <= n && ny >0 && ny <=n && house[ny][nx] == 0 && !(nx == 1 && ny == 1)){
                q.push(make_pair(ny,nx));
                house[ny][nx] = house[cur.first][cur.second] + 1;
            }

        }
    }

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n; j++){
            if(house[i][j] == 0){
                house[i][j] = 3000;
            }

        }

    }
    
    

}


void bfsFromEndRef(vector<vector<int> >& house){
    queue<pair<int,int>> q;

    q.push(make_pair(n,n));
    pair<int, int> cur;
    int nx,ny;
    while(!q.empty()){

        cur = q.front();
        q.pop();

    
        for(int i = 0; i < 4; i++){
            nx = cur.second+xdir[i]; ny = cur.first + ydir[i];

            if(nx > 0 && nx <= n && ny >0 && ny <=n && house[ny][nx] == 0 && !(nx==n && ny ==n)){
                q.push(make_pair(ny,nx));
                house[ny][nx] = house[cur.first][cur.second] + 1;
            }

        }
    }
    
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n; j++){
            if(house[i][j] == 0){
                house[i][j] = 2999;
            }

        }

    }
    


    
}

int bfs(vector<vector<int> > house){

    queue<pair<int,int>> q;

    q.push(make_pair(1,1));
    pair<int, int> cur;
    int nx,ny;
    while(!q.empty()){

        cur = q.front();
        q.pop();

    
        for(int i = 0; i < 4; i++){
            nx = cur.second+xdir[i]; ny = cur.first + ydir[i];

            if(nx > 0 && nx <= n && ny >0 && ny <=n && house[ny][nx] == 0){
                q.push(make_pair(ny,nx));
                house[ny][nx] = house[cur.first][cur.second] + 1;
            }

        }
    }
    
    int res = 0;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(house[i][j] == 0){
                res++;
            }
        }

    }




    return res;



}





int main() {


    cin>>n;


    vector<vector<int> > house(n+1,vector<int> (n+1,1));
    vector<vector<int> > distance(n+1,vector<int> (n+1,1));
    vector<vector<int> > distanceFromEnd(n+1,vector<int> (n+1,1));

    for(int i = 1; i<= n; i++){
        for(int j = 1 ; j<= n; j++){
            int tmp;
            cin>>tmp;
            if(tmp==1){
                house[i][j] = -1;
            }
            else{
                house[i][j] = 0;
            }
            distance[i][j] = house[i][j];
            distanceFromEnd[i][j] = house[i][j];
        }
    }


    bfsRef(distance);
    bfsFromEndRef(distanceFromEnd);




    int res = 0;
    for(int i = n; i>=1; i--){
        for(int j = n; j>=1; j--){
            if(distanceFromEnd[i][j]<distance[i][j] && house[i][j] != -1 && !(i==n&& j ==n) && !(i==1 && j==1)){
                house[i][j] = -1;
                int temp = bfs(house);
                res = max(res,temp);
                house[i][j] = 0;
            }
            
        }

    }



    cout<<res<<endl;

	return 0;
}