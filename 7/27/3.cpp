#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";

    int tmp = 0;


    for (int i = 0; i < s.length(); i++){

        if(s[i] == ' '){
            tmp = 0;
            continue;

        }

        if(tmp == 0){
            if(s[i]>=97)
                s[i] = upper[(s[i]-97)%26];
            tmp = 1;
        }

        else{
            if(s[i]>=65 && s[i] <=90){
                s[i] = lower[(s[i]-65)%26];
            tmp = 0;
        }

      

    }


    answer = s;
    return answer;
}