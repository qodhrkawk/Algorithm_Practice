#include <iostream>


using namespace std;

int n;
const int MAX = 1001;

int dp[MAX];



int main() {

    dp[1] = 1;
    dp[2] = 3;
    cin>>n;

    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;

    
    cout<<dp[n]<<endl;



    




	return 0;
}