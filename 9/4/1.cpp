#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n,m;


int xdir[4] = {1,0,-1,0};
int ydir[4] = {0,1,0,-1};


vector<pair<int,int> > origins;
vector<pair<int,int> > possibleWalls;


int bfs(vector<vector<int> > map){

    for(auto ori : origins){

        queue<pair<int,int> > q;

        q.push(make_pair(ori.first,ori.second));

        while(!q.empty()){
            
            pair<int,int> cur = q.front();
            q.pop();

            int ny,nx;

            for(int i = 0; i< 4; i++){
                ny = cur.first + ydir[i];
                nx = cur.second + xdir[i];

                if(ny> 0 && nx > 0 && ny <= n && nx <= m && map[ny][nx] == 0){
                    map[ny][nx] = 2;
                    q.push(make_pair(ny,nx));

                }

            }
        }
    }
    int res = 0;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            if(map[i][j] == 0){
                res++;
            }
        }
    }

    return res;



}



int main() {

    cin>>n>>m;
    vector<vector<int> > map(10,vector<int> (10,0));

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                origins.push_back(make_pair(i,j));
            }
            else if(map[i][j] == 0){
                possibleWalls.push_back(make_pair(i,j));
            }
        }
    }

    int res = 0;

    for(int i = 0; i< possibleWalls.size() ;i++){
        for(int j = i+1; j<possibleWalls.size(); j++){
            for(int k = j+1; k<possibleWalls.size(); k++){
                map[possibleWalls[i].first][possibleWalls[i].second] = 1;
                map[possibleWalls[j].first][possibleWalls[j].second] = 1;
                map[possibleWalls[k].first][possibleWalls[k].second] = 1;
                res = max(res,bfs(map));

                map[possibleWalls[i].first][possibleWalls[i].second] = 0;
                map[possibleWalls[j].first][possibleWalls[j].second] = 0;
                map[possibleWalls[k].first][possibleWalls[k].second] = 0;
            }
        }
    }

    cout<<res<<endl;


    
    




	return 0;
}