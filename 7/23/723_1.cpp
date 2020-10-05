#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first = {1,2,3,4,5};
    second = {2,1,2,3,2,4,2,5};
    third = {3,3,1,1,2,2,4,4,5,5};

    int firstCorrect = 0;
    int secondCorrect = 0;
    int thirdCorrect = 0;

    for (int i = 0; i < answers.size(); i++){
        if(answers[i] == first[i%5]){
            firstCorrect++;
        }
        if(answers[i] == second[i%8]){
            secondCorrect++;
        }
        if(answers[i] == third[i%10]){
            thirdCorrect++;
        }
    }

    int maximum = max(firstCorrect,max(secondCorrect,thirdCorrect));

    if(firstCorrect == maximum)
        answer.push_back(1);
    if(secondCorrect == maximum)
        answer.push_back(2);
    if(thirdCorrect == maximum)
        answer.push_back(3);





    return answer;


}