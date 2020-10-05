#include <string>
#include <vector>

using namespace std;

bool dp[1000001];

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;

    for(int i = 0; i < 1000001; i++){
        dp[i] = false;
    }    

    
    for(int i = 0; i < order.size(); i++){
        int next = order[i];

        if(ball[0] == next){
            answer.push_back(ball[0]);
            ball.erase(ball.begin(),ball.begin()+1);
        }
        else if(ball[ball.size()-1] == next){
            answer.push_back(ball[ball.size()-1]);
            ball.erase(ball.end()-1,ball.end());
        }
        else{
            dp[next] = true;
        }

        while(1){

            if(!dp[ball[0]] && !dp[ball[ball.size()-1]])
                break;
            if(dp[ball[0]]){
                answer.push_back(ball[0]);
                ball.erase(ball.begin(),ball.begin()+1);
            }
            if(dp[ball[ball.size()-1]]){
                answer.push_back(ball[ball.size()-1]);
                ball.erase(ball.end()-1,ball.end());
            }

        }



    }




    return answer;
}