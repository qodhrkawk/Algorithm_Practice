#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> userId;
    map <string,string> id_nick;

    stringstream s; 
    string action; string id; string nickname;

    

    for (auto rec : record){
        s.str(rec);
        s>>action;

        if(action == "Enter"){
            s>>id;
            s>>nickname;

            userId.push_back(id);
            id_nick[id] = nickname;
            answer.push_back("님이 들어왔습니다.");


        }
        else if(action == "Leave"){

            s>>id;
            userId.push_back(id);
            answer.push_back("님이 나갔습니다.");
        }
        else{
            s>>id;
            s>>nickname;
            id_nick[id] = nickname;

        }

        s.clear();



    }

    for(int i = 0; i <answer.size(); i++){
        answer[i] = id_nick[userId[i]] + answer[i];

    }

    
    return answer;


}