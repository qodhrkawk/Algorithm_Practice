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

    int minimum = 10000;
    for(int i = 1;i <= 9; i++){
        if(dp[i] < minimum){
            answer = i;
            minimum = dp[i];
        }
    }

    cout<<minimum<<endl;
    cout<<answer<<endl;
	return 0;
}