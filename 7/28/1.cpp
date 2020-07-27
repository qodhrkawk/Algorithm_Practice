#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> dates(progresses.size());


    int current = 0;
    int num = 1;

    float tmp;

    for(int i = 0; i < progresses.size(); i++){
        tmp = (100-progresses[i])/speeds[i];
        dates[i] = (int)ceil(tmp);
    }

    current = dates[0];
    

    for(int i = 1; i <progresses.size(); i++){
        int loopCurrent = dates[i];
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