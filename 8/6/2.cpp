#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int res = 0;    
    bool check = false;
    

    for(int i = 1; i <words.size(); i++){
        
        for(int j = 0; j <i; j++){
            if(words[i]==words[j]){
                check = true;
                break;
            }

        }

        if(words[i-1][words[i-1].length()-1] != words[i][0]){
            check = true;
        }

        if(check){
            res = i;
            break;
        }




    }


    if(check == false){
       
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        cout<<res<<endl;
        answer.push_back(res%n+1);
        answer.push_back(res/n+1);
    }
    


    return answer;
}