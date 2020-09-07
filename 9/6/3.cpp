#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;




int n,m;

vector<vector<int> > map(21,vector<int> (21,0));

int nowSize = 2;
int ate = 0;

pair<int,int> curPos;

int ydir[4] = {-1,0,1,0};
int xdir[4] = {0,-1,0,1};

int answer = 0;


pair<int,int> bfs(vector<vector<int> > dis){

    pair<int,int> res = make_pair(-1,-1);

    queue<pair<int,int> > q;
    q.push(curPos);
    dis[curPos.first][curPos.second] = 1;

    priority_queue<pair<int,int> > pq;

    while(!q.empty()){

        pair<int,int> curIdx = q.front();
        q.pop();

        int y = curIdx.first; int x = curIdx.second;
        int ny,nx;

        for(int i = 0; i < 4; i ++){
            ny = y + ydir[i]; nx = x + xdir[i];

            if(ny>0 && nx>0 && ny <=n && nx <= n && dis[ny][nx] == 0){
                dis[ny][nx] = dis[y][x] + 1;
                q.push(make_pair(ny,nx));


            }

        }




    }
    int minimum = 100000;

    for(int i = 1; i<= n; i++){
        for(int j = 1;j <=n;j++){
            if(dis[i][j] < minimum){
                priority_queue<pair<int,int> > new_pq;
                pq = new_pq;
                pq.push(make_pair(-i,-j));
            }
            else if(dis[i][j] == minimum){
                pq.push(make_pair(-i,-j));
            }

        }

    }

    if(!pq.empty()){
        res = pq.top();
    }


    return res;



}





int main() {
	

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++){
            cin>>map[i][j];
            if(map[i][j] == 9){
                curPos = make_pair(i,j);
            }
        }
    }


    vector<vector<int> > dis(21,vector<int> (21,0));

    
    while(1){

        curPos = bfs(dis);
        

        if(curPos.first == -1){
            break;
        }

    



    }


    cout<<answer<<endl;







	return 0;
}