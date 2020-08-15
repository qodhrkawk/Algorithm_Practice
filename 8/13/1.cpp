#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;

    sort(arr.begin(),arr.end());

    int largest = arr[arr.size()-1];

    bool escape = true;
    int mult = 0;


    while(escape){
        escape = false;
        answer = largest*(++mult);
        for(int i = 0; i<arr.size(); i++){
            if(answer%arr[i] != 0){
                escape = true;
            }

        }

        

    }




    return answer;
}