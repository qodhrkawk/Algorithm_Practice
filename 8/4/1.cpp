#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> scores;
    int tmp = 0;
    for(int i = 0; i < dartResult.length(); i++){
        
        if(i<dartResult.length()-1){
            if((dartResult[i]>= 48 && dartResult[i] <= 57) || dartResult[i] == '1' && dartResult[i+1] == '0'){
                if( dartResult[i] == '1' && dartResult[i+1] == '0'){
                    tmp = 10;
                    i++;
                }
                else{
                    tmp = dartResult[i]-48;
                }

            }
        }


        switch (dartResult[i])
        {
        case 'S':
            scores.push_back(tmp);
            break;
        case 'D':
            scores.push_back(tmp*tmp);
            break;
        case 'T':
            scores.push_back(tmp*tmp*tmp);
            break;
        case '*':
            scores[scores.size()-1] *= 2;
            scores[scores.size()-2] *= 2;
            break;
        case '#':
            scores[scores.size()-1] *= -1;

        
        
        default:
            break;
        }




    }

    for(int i = 0; i <scores.size(); i++){
        answer+= scores[i];

    }


    return answer;
}