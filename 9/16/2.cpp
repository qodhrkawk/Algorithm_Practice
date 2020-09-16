#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;


int n,k;

int INF = 100001;

vector<int> dp(10001,INF);


int main() {


    cin>>n>>k;


    for(int i = 0 ; i< n; i++){
        int tmp;
        cin>>tmp;

        dp[tmp] = 1;
        // for(int j = 2; tmp*j <= k; j++){
        //     dp[tmp*j] = min(dp[tmp*j],j);
        // }


    }


    for(int i = 1; i<= k; i++){
        for(int j = 1; j< i; j++){
            dp[i] = min(dp[j] + dp[i-j],dp[i]);
            
        }
    }


    if(dp[k] == INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[k]<<endl;

    }
    


	return 0;
}