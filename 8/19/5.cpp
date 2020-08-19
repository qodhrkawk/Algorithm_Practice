#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[100001] = {0, };





int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        dp[tmp] = 1;
    }



    for(int i = 2; i <= k; i++){
        dp[i] += dp[i-1] + dp[i-2];

    }

    cout<<dp[k]<<endl;


    return 0;
}