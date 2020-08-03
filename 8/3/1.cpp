#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<vector<int> > pairs; 

    for(int i = 1; i <= ceil(yellow/2); i++){
        vector<int> tmp;
        if(yellow%i == 0 && yellow/i>=i){
            // 가로, 세로 순서
            tmp.push_back(yellow/i);
            tmp.push_back(i);
            pairs.push_back(tmp);
        }
    }

    for(int i = 0; i <pairs.size();i++){
        // cout<< pairs[i][0]<<"," <<pairs[i][1]<<endl;
        int size = (pairs[i][0]+2)*(pairs[i][1]+2);

        if(size-yellow == brown){
            answer.push_back(pairs[i][0]+2);
            answer.push_back(pairs[i][1]+2);

        }

        

    }






    return answer;
}



int main(){

    solution(24,24);


    return 0;
}