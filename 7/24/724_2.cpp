#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.size() != 4 && s.size() != 6)
        answer = false;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i]>=48 && s[i] <= 57){
            continue;
        }
        answer = false;

    }

    



    return answer;
}