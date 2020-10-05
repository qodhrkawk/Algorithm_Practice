#include <string>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<stack<int>> stackForAnswer;

    int current = ceil((100-progresses[0])/speeds[0]);
    int num = 1;
    

    for(int i = 1; i <progresses.size(); i++){
        int loopCurrent = ceil((100-progresses[i])/speeds[i]);
        if(loopCurrent > current){
            answer.push_back(num);
            num = 1;
            current = loopCurrent;

        }
        else{
            num++;

        }


    }

    if(progresses.size()!=0){
        answer.push_back(num);
    }
    return answer;
}