#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[60000];


int solution(int n) {
	int answer = 0;
	long long tmp = 0;


    dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-2]+dp[i-1]) % 1000000007;
	}

	answer = dp[n] ;




	return answer;
}