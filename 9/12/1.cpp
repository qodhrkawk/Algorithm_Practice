#include <string>
#include <vector>

using namespace std;

int dp[1000001];

int solution(vector<vector<int>> boxes) {
    int answer = 0;

    for(int i = 1; i <= 1000001; i++){
        dp[i] = 0;
    }


    for(int i = 0; i < boxes.size(); i++){
        dp[boxes[i][0]]++;
        dp[boxes[i][1]]++;
    }

    for(int i = 1; i <= 1000001; i++){
        if(dp[i] % 2 == 1){
            answer++;
        }
    }

    answer /= 2;



    return answer;
}