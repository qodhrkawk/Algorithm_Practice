#include <string>
#include <vector>
#include <sstream>

using namespace std;




string solution(string s) {
    string answer = "";

    string word;

    int minimum = INT32_MAX;
    int maximum = INT32_MIN;

    for(stringstream sts(s); (sts>>word);){

        if(stoi(word) > maximum){
            maximum = stoi(word);
        }
        if(stoi(word) < minimum){
            minimum = stoi(word);
        }

    }

    answer+= to_string(minimum) + " " + to_string(maximum);

    



    return answer;
}