#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;


    if(s[0] == '-'){
        string abs = s.substr(1);
        answer = -stoi(abs);
    }

    else{
        answer = stoi(s);
    }

    return answer;
}