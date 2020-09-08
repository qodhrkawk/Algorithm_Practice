#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n,m;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};

int INF = 987654321;

int answer = INF;
vector<vector<int> > map(1001,vector<int> (1001,0));

bool visited[1001][1001][2];

int bfs(){



    queue<pair<pair<int,int>,pair<int,int> > > q;
    q.push(make_pair(make_pair(1,1),make_pair(0,1)));


    while(!q.empty()){

        pair<int,int> cur = q.front().first;
        pair<int,int> wall = q.front().second;

        q.pop();

        int y = cur.first; int x = cur.second;
        int w = wall.first; int cost = wall.second;

        if(y == n && x == m){
            return cost;
        }


        int ny,nx;
        for(int i = 0; i < 4; i ++){
            ny = y + ydir[i]; nx = x + xdir[i];

            if(ny>0 && nx > 0 && ny <=n && nx <=m){
                
                if(map[ny][nx] == 1 && w == 0){
                    visited[ny][nx][w+1] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(w+1,cost+1)));
                }

                else if(map[ny][nx] == 0 && visited[ny][nx][w] == false){
                    visited[ny][nx][w] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(w,cost+1)));
                }


            }


        }



    }

    return -1;

}





int main() {
	

    cin>>n>>m;

    

    
    for(int i = 1; i<= n;i++){
        string s;
        cin>>s;
        for(int j = 1; j <= m;j++){
            map[i][j] = s[j-1]-48;
            
        }

    }
    

    cout<<bfs()<<endl;

        




	return 0;
}