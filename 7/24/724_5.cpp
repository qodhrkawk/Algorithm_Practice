#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    reverse(prices.begin(),prices.end());
    
    // for(int i = 0; i <prices.size(); i++){
    //     cout<<prices[i]<< " ";
    // }
    // cout<<endl;

    answer.push_back(0);
   

    for(int i = 1 ; i<prices.size(); i++){
        int tmp = 1;
         bool check = false;
        // cout<<"called"<<endl;
        for(int j = i-1; j>= 1; j--){
            if(prices[j]>=prices[i]){
                // cout<<"here1"<<endl;
                tmp+=1;
            }
            else{
                // cout<<"here2"<<endl;
                answer.push_back(tmp);
                check = true;
                break;
            }
            
        }
        if(check==false){
            answer.push_back(tmp);
        }


    }

    reverse(answer.begin(),answer.end());


    return answer;
}

int main(){
    vector<int>input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(2);
    input.push_back(3);

    solution(input);


    return 0;
}