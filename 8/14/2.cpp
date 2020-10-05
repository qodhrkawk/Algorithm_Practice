#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;


    if(arr.size() <= 1){
        answer.push_back(-1);
        return answer;
    }

    int min = INT32_MAX;

    int minIdx = 0;
    for(int i = 0 ; i<arr.size();i++){
        if(min>arr[i]){
            minIdx = i;
            min = arr[i];
        }
        

    }

    arr.erase(arr.begin()+minIdx,arr.begin()+minIdx+1);



    return arr;
}