#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    string tmp = to_string(n);

    reverse(tmp.begin(),tmp.end());

    for(int i = 0; i <tmp.size();i ++){
        answer.push_back(tmp[i]-48);

    }

    return answer;
}