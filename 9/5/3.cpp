#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

int MAX = 1000001;
vector<int> arr(MAX,0);
vector<int> dp(MAX,0);


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i = 1; i<=n;i++){
        cin>>arr[i];
    }
    int s, e;
    for(int t = 0; t<k; t++){
        cin>>s>>e;
        int res = 0;
        
        
        for(int i = s ; i <= e; i++){
            dp[arr[i]]++;
        }


        for(int i = 0 ; i<  MAX;i++){
            if(dp[i] > 0){
                res += dp[i]*(dp[i]+1)/2*i;
                dp[i] = 0;
            }
            
        }

        cout<<res<<endl;

    }
    

	
    return 0;
}