#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int r,c;

char map[21][21];



int answer = 0;

int ydir[4] = {0,0,1,-1};
int xdir[4] = {1,-1,0,0};

vector<vector<bool> > visited(21,vector<bool> (21,false));
vector<bool> alphabets(26,false);


void dfs(int y, int x, int depth){

    int ny,nx;
    bool changable = false;
    visited[y][x] = true;

    alphabets[map[y][x]-65] = true;

    for(int i = 0; i < 4; i++){
        ny = y + ydir[i];
        nx = x + xdir[i];

        if(ny>0 && nx>0 && ny<=r && nx<= c && visited[ny][nx] == false){
            

            if(alphabets[map[ny][nx]-65] == false){
                changable = true;

                visited[ny][nx] = true;
                alphabets[map[ny][nx]-65] = true;
                dfs(ny,nx,depth+1);
                visited[ny][nx] = false;
                alphabets[map[ny][nx]-65] = false;

            }
            

        }

    }

    if(!changable){
        answer = max(answer,depth);
    }



}





int main() {
	

    cin>>r>>c;

    
    for(int i = 1; i<= r;i++){
        string s;
        cin>>s;
        for(int j = 1; j <= c;j++){
            map[i][j] = s[j-1];
            
        }

    }
    dfs(1,1,1);

    cout<<answer<<endl;





	return 0;
}