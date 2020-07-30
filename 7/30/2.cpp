#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    answer = n  - lost.size();

    int i = 0; int j = 0;

    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());

    while(j<reserve.size() && i<lost.size()){


        if(lost[i] < reserve[j] - 1){
            i++;
        }
        else if (lost[i] == reserve[j] -1){
            i++;
            answer++;
            j++;
        }
        else if(lost[i] == reserve[j] + 1){
            i++;
            answer++;
            j++;
        }
        else{
            j++;
        }


    }




    return answer;
}