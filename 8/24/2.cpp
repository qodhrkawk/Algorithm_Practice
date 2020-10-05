#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;



vector<vector<int> > dp(16,vector<int> (16,0));
vector<bool> visited(16,false);


int dfs(int start, int price,int n){
    int index = -1;
    visited[start] = true;
    int res = 1;
    int maximum = 0;

    bool never = true;
    for(int j = 1 ; j<= n; j++){
        if(j==start)
            continue;
        if(dp[start][j] >= price && visited[j] != true){
            never = false;
            int tmp = dfs(j,dp[start][j],n);
            if(tmp != 1){
                if(tmp > maximum){
                    index = j;
                    maximum = tmp;
                }
            }
        }
    }

    if(index == -1){
        return never? res : res+1; 
    }
    else{
        res += maximum;
        return res;
    }

}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        string s = "";
        cin>>s;

        for(int j = 1; j<= n; j++){
            dp[i][j] = s[j-1]-48;
        }
    }


    

    cout<<dfs(1,0,n)<<endl;

    
    return 0;
}