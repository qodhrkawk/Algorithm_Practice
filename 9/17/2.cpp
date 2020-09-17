#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long int n;

bool dp[4000000];

int main() {
	
    cin>>n;
    int answer = 0;

    for(int i = 1; i<= n; i++){
        dp[i] = true;
    }


    for(int i = 2; i<= n; i++){
        for(int j = 2; i*j <= n; j++){
            dp[i*j] = false;
        }
    }

    for(int i = 2; i<= n; i++){

        
        if(dp[i]){
            int sum = i;
            if(sum == n){
                answer++;
                continue;
            }

            for(int j = i+1; j<=n; j++){

                if(dp[j]){
                    sum+=j;
                    if(sum == n){
                        answer++;
                    }
                    else if(sum > n){
                        break;
                    }
                }
            }
        }

    }


    cout<<answer<<endl;

	return 0;
}