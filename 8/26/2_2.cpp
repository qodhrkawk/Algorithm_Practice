#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


int arr[1001][1001];
int dp[1001][1001];




int main(){

    
    int n,m;

    cin>>n>>m;

    for(int i = 0; i <n;i++){
        string s;
        cin>>s;
        for(int j = 0 ;j < m ; j++){
            arr[i][j] = s[j]-48;
        }
    }

    int ans = 1;


    for(int i = 0 ; i < n; i ++){
        for(int j = 0; j < m; j++){
            
            int max = 0;
            for(max = 0; j+max < m && max+i < n; max++){
                


            }



        }
    }

    cout<<ans*ans<<endl;

    return 0;
}