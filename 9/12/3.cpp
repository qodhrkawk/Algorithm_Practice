#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int res = 1000000000;
int num = 0;


void dfs(int s1,int s2,int depth){

    string s = to_string(s1 + s2);

    if(s.length() == 1){
        res = min(res,depth); 
        num = stoi(s);
        return;
    }


    for(int i = 1; i < s.length(); i++){

        string firstS = s.substr(0,i);
        string secondS = s.substr(i,s.length());

        if(firstS[0] == '0' || secondS[0] == '0'){
            continue;
        }

        int first = stoi(firstS);
        int second = stoi(secondS);

        dfs(first,second,depth+1);

    }

    return;


}





vector<int> solution(int n) {
    vector<int> answer;


    if(n/10 == 0){
        answer.push_back(0);
        answer.push_back(n);
        return answer;
    }

    dfs(n,0,0);


    answer.push_back(res);
    answer.push_back(num);


    return answer;
}



