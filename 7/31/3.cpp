#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    sort(nums.begin(),nums.end());
    int maximum = 0;

    for(int i = nums.size()-3; i<nums.size(); i++){
        maximum += nums[i];
    }

    bool* dp = new bool[maximum+1];
    for(int i = 0 ; i <= maximum; i++)
        dp[i] = true;

    dp[1] = false;
    dp[2] = true;
    for(int i = 2; i <= maximum/2; i++){
        for(int j = 2; j<=maximum/i; j++){
            dp[i*j] = false;
        }
    }

    for(int i = 0 ; i < nums.size()-2; i++){
        for(int j = i+1; j<nums.size()-1; j++){
            for(int k = j+1; k<nums.size(); k++){
                if(dp[nums[i]+nums[j]+nums[k]] == true){
                    answer++;

                }

            }

        }

    }
    
 



    return answer;
}