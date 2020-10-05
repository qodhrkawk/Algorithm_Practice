#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int dp[10];

int main() {

    int answer= 0;

    for(int i = 1;i <= 9; i++){
        cin>>dp[i];
    }

    int maximum = 0;
    for(int i = 1;i <= 9; i++){
        if(dp[i] > maximum){
            answer = i;
            maximum = dp[i];
        }
    }

    cout<<maximum<<endl;
    cout<<answer<<endl;
	return 0;
}