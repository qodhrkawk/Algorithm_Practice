#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string s, int n) {
    string answer = "";

    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";

    int plus = 0;
    int current = 0;

    for (int i  = 0 ; i < s.size(); i++){
        if(s[i] == ' '){
            answer+= ' ';
        }
        else if(s[i]>=97){
            current = s[i]-97;
            plus = n%26;

            answer += lower[(current+plus)%26];
        }
        else{
            current = s[i]-65;
            plus = n%26;

            answer += upper[(current+plus)%26];


        }


    }



    return answer;
}


int main() {
    string a = "abc";

    cout<<a[0]+1<<endl;


    return 0;
}