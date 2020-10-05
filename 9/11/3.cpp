#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<vector<int> > dp(50001,vector<int> (5,0));

pair<int,int> aa(string s,int idx){
    if(idx == 0){
        if(s == "cpp")
            return make_pair(0,0);
        else if(s == "java")
            return make_pair(0,1);
        else if(s == "python")
            return make_pair(0,2);
        else
            return make_pair(0,-1);
        
    }

    else if(idx == 1){
    
        if(s == "backend")
        return make_pair(1,0);
        else if(s == "frontend")
            return make_pair(1,1);
        else
            return make_pair(1,-1);

    }

    else if(idx == 2){
        if(s == "junior")
            return make_pair(2,0);
        else if(s == "senior")
            return make_pair(2,1);
        else
            return make_pair(2,-1);
    }

    else if(idx == 3){
        if(s == "chicken")
            return make_pair(3,0);
        else if(s == "pizza")
            return make_pair(3,1);
        else
            return make_pair(3,-1);

    }

    else{
        return make_pair(4,stoi(s));
    }

}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(int i = 0; i < info.size(); i++){
        string word;
        string s = info[i];
        int idx = 0;
        for(stringstream sts(s); (sts>>word);){
            pair<int,int> cur = aa(word,idx);
            dp[i][cur.first] = cur.second;
            idx++;
        }

    }

    for(int i = 0; i < query.size(); i++){
        string word;
        vector<pair<int,int>> ex;
        string s = query[i];
        int idx = 0;
        for(stringstream sts(s); (sts>>word);){
            if(word == "and")
                continue;
            pair<int,int> cur = aa(word,idx);
            ex.push_back(cur);
            idx++;
        }
        int people = 0;
        for(int p = 0; p<info.size(); p++){
            
            bool possible = true;
            for(auto e : ex){
                if(e.second == -1){
                    continue;
                }
                else if(e.first < 4 && dp[p][e.first] == e.second){
                    continue;
                }
                else if(e.first == 4){
                    if(dp[p][e.first] >= e.second){
                        continue;

                    }
                    else{
                        possible = false;
                        break;
                    }
                }
                else{
                    possible = false;
                    break;
                }

            }

            if(possible){
                people++;
            }

        }

        answer.push_back(people);


    }




    return answer;
}