#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int> > relation(51,vector<int> (51,INT32_MAX));
vector<vector<int> > dp(51,vector<int> (51,INT32_MAX));




int main(){
    int n;
    cin>>n;
    char c;
    for(int i = 1; i <= n; i++){
    
        for(int j = 1; j<= n; j++){
            cin>>c;
            if(c == 'Y'){
                relation[i][j] = 1;
                dp[i][j] = 1;
            }
            else if(i==j){
                relation[i][j] = 0;
                dp[i][j] = 0;
            }

        }
    }

    
    for(int i = 1; i<= n; i++){
        for(int j = 1 ; j<= n; j++){
            for(int k = 1; k<= n; k++){
                if(dp[j][k] > dp[i][k] + dp[i][j]){
                    dp[j][k] = dp[i][k] + dp[i][j];
                }
            }
        }
    }


    int maximum = 0;
    for(int i = 1; i<= n; i++){
        int res = 0;
        for(int j = 1; j<=n; j++){
            if(dp[i][j] != 0 && dp[i][j] < 2){
                res++;
            }

        }
        maximum = max(res,maximum);
    }

    cout<<maximum<<endl;
    


    return 0;
}