#include <string>
#include <vector>
#include <algorithm>


using namespace std;



int solution(vector<int> citations) {
    int answer = 0;

    int dp[10001];
    fill_n(dp,0,0);

    for(int i = 0; i < 10001;i++){
        dp[i] = 0;
    }


   
    for(int i = 0; i < citations.size();i++){
        dp[citations[i]]++;

    }

    for (int i = 10000; i>=0; i--){
        dp[i] += dp[i+1];
    }

    for(int i = 0; i < 10001; i++){
        if(dp[i]>=i){
            answer = i;
        }


    }




    return answer;
}