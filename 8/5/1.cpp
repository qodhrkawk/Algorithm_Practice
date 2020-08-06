#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;

    int left = 0;
    for(int i = 0 ; i < s.length(); i++){
        if(left == 0){
            if(s[i] == '('){
                left++;
            }
            else{
                return false;
            }


        }
        else{
             if(s[i] == '('){
                left++;
             }
             else{
                 left--;
             }


        }

    }

    if(left == 0)
        answer = true;





    return answer;
}