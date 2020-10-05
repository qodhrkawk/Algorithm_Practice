#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end());
    reverse(routes.begin(),routes.end());

    int tmp = 300001;

    for(int i = 0; i <routes.size(); i++){
        if(routes[i][1] < tmp){
            answer++;
            tmp = routes[i][0];
        }



    }





    return answer;
}