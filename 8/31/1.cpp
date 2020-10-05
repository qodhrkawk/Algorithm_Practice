#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[201][201];
int k,n;

long long int d = 1000000000;

int main() {

    cin>>n>>k;

    for(int i = 0; i<= n;i ++){
        dp[1][i] = 1;
    }
    
    for(int i = 2; i<=k ;i++){
        for(int j = 0;j <=n; j++){
            for(int l = 0; l<=j; l++){
                dp[i][j] += dp[i-1][j-l];
                dp[i][j] = dp[i][j]%d;

            }


        }


    }




    cout<<dp[k][n]%d<<endl;
    




	return 0;
}