#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,k;
int INF = 100001;

bool visited[100001];

int dfs(int time,int cur){

    visited[cur] = true;

    if(cur > k+1){
        return INF;
    }

    if(cur == k){
        return time;
    }

    if(cur <= 0){
        return INF;
    }
    
    int minus= INF;
    int plus = INF;
    int mult = INF;

    // cout<<cur<<" ";

    if(visited[cur-1] == false){
        minus = dfs(time+1,cur-1);
    }
    if(visited[cur+1] == false){
        plus = dfs(time+1,cur+1);
    }
    if(visited[cur*2] == false){
        mult = dfs(time+1,cur*2);
    }
    

    return min(minus,min(plus,mult));


}


int main() {

    cin>>n>>k;

    
    cout<<dfs(0,n)<<endl;





	return 0;
}