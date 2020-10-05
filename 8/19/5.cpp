#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[100001] = {0, };
int coins[101] = {0, };





int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,k;

    cin>>n>>k;
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        cin>>coins[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j>=coins[i]){
                dp[j] += dp[j-coins[i]];
            }

        }

    }

    cout<<dp[k]<<endl;


    return 0;
}