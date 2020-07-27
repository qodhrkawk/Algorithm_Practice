#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;

    string xs = to_string(x);

    int sum = 0;
    for(int i = 0; i < xs.length(); i++){
        sum += xs[i]-48;
    }

    answer = x%sum == 0;



    return answer;
}