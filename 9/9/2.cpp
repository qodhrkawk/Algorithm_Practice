#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;

bool map[15][15] = {false, };
int answer = 0;

bool check(int i,int res){

    int x,y;

    for(x= 0; x < res; x++){
        if(map[i][x] == true){
            return false;
        }
    }

    

    for(x = res-1,y = i-1; y >= 0; x--,y--){
        if(map[y][x] == true){
            return false;
        }


    }

    for(x = res-1,y = i+1; y< n; x--,y++){
        if(map[y][x] == true){
            return false;
        }


    }



    return true;

}



void dfs(int res){

    int i;

    if(res == n){
        answer++;
        return;
    }


    for(i = 0; i<n; i++ ){
        if(!map[i][res] && check(i,res)){
            map[i][res] = true;
            dfs(res+1);
            map[i][res] = false;

        }

    }






}








int main() {
	

    cin>>n;

    dfs(0);

    cout<<answer<<endl;








	return 0;
}