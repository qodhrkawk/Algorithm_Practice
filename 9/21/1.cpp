#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long int dp[91];


int main() {
	

    cin>>n;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i<= n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;



	return 0;
}