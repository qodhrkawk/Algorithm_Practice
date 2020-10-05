#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    long long tmp;

    int* dp = new int[n+1];
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }

    answer = dp[n];

    

    return answer;
}