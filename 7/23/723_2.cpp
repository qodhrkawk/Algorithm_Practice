#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> div;
    
    for(int i = 1; i <= n; i++){
        if(n%i==0){
            div.push_back(i);
        }

    }

    for (int d : div){
        answer+=d;
    }




    return answer;
}