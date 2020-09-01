#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[201];
int arr[201];
int res = 0;

int main() {


    cin>>n;

    for(int i = 1; i<=n;i++){
        cin>>arr[i];
        dp[i] = 1;

    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j<i;j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i]++;
        }

        res = max(res,dp[i]);


    }

    
    
    cout<< res<<endl;




	return 0;
}