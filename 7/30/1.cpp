#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string num = to_string(n);

    sort(num.begin(),num.end());

    reverse(num.begin(),num.end());

    char* cn = new char[num.length()];

    for(int i = 0; i < num.length(); i++){
        cn[i] = num[i];
    }


    answer = atoll(cn);
    
    
    return answer;
}