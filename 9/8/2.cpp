#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dp[1001][10];

int n;


int main() {

    cin>>n;
	
    for(int i = 0; i<=9;i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <=n; i++){
        for(int j = 0; j<=9;j++){
            for(int k = j; k<= 9; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] = dp[i][j] %10007;
            }
        }
    }

    long long int answer = 0;

    for(int i = 0;i <= 9; i++){
        answer = (answer + dp[n][i])%10007;
    }

    cout<<answer%10007<<endl;

	return 0;
}