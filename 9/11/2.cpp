#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<char> > dp(20,vector<char> (26,' '));

vector<vector<pair<int,string>> > menus(11);


void putMenu(string s){

    if(s.length()>1){
        bool wasIn = false;
        for(int x = 0; x < menus[s.length()].size(); x++){
            if(menus[s.length()][x].second == s){
                wasIn = true;
                menus[s.length()][x].first += 1;
                break;

            }
        }
        if(!wasIn){
            menus[s.length()].push_back(make_pair(2,s));
        }
    }


}



void dfs(string s, string origin, int depth, int final){

    if(depth == final){
        putMenu(s);
        return;
    }

    


}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    sort(course.rbegin(),course.rend());

    for(int i = 0; i < orders.size(); i++){
        string s = orders[i];
        for(int j = 0; j< s.length(); j++){
            dp[i][s[j]-65] = s[j];
        }
    }
    

    for(int i = 0; i < orders.size(); i++){
        for(int j = i+1; j< orders.size(); j++){
            
            string tmp;
            for(int k = 0; k < 26; k++){
                
                if(dp[i][k] != ' ' && dp[j][k] != ' '){
                    tmp += dp[i][k];

                    if(tmp.length()>1){
                        bool wasIn = false;
                        for(int x = 0; x < menus[tmp.length()].size(); x++){
                            if(menus[tmp.length()][x].second == tmp){
                                wasIn = true;
                                menus[tmp.length()][x].first += 1;
                                break;

                            }
                        }
                        if(!wasIn){
                            // cout<<tmp<<endl;
                            menus[tmp.length()].push_back(make_pair(2,tmp));
                        }
                    }



                }

                
                
            }

            


        }

    }

    for(int i = 0; i < course.size(); i++){
        sort(menus[course[i]].rbegin(),menus[course[i]].rend());
        int large  = menus[course[i]][0].first;

        for(int j = 0; j < menus[course[i]].size(); j++){
            cout<<menus[course[i]][j].first << menus[course[i]][j].second<<endl;

            if(menus[course[i]][j].first == large){
                

                answer.push_back(menus[course[i]][j].second);
            }


        }
        
            
    }




    sort(answer.begin(),answer.end());


    // for(int i = 0; i < answer.size() ; i++){
    //     cout<<answer[i]<<endl;
    // }


    return answer;
}