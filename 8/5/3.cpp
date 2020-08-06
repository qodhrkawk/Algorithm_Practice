#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
 
    int idx = 0;
    int days = 0;
    while(idx != progresses.size()){
       int count = 0;
       days++;
       for (int i = idx; i < progresses.size(); i++){
              if ((progresses[idx] + (speeds[idx] * days)) >= 100){
                 idx++;
                 count++;
              }
        }
        if (count != 0) 
            answer.push_back(count);
    }
    return answer;
}