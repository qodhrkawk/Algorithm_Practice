#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int times[17];
int benefits[17];

int dp[20];

int main(){

    cin>>n;

    for(int i = 1; i<=n;i++){
        cin>>times[i];
        cin>>benefits[i];
    }



    for(int i = 1; i <= n+1;i++){
        dp[i] = max(dp[i],dp[i-1]);
        if(dp[i + times[i]] > dp[i] + benefits[i]){
            dp[i + times[i]] = dp[i] + benefits[i];
        }
        else{
            
        }

        if(i<=n){
            dp[i + times[i]] = max(dp[i + times[i]],dp[i]+benefits[i]);
        }
    }


    // for(int i = 1; i<=n+1;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    cout<<dp[n+1]<<endl;

    return 0;
}