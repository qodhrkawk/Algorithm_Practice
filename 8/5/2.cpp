#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> userIds;
    vector<string> names;
    vector<string> elses;
    vector<int> userIdIndex;
    vector<int> nameIndex;
   

    
    for (auto rec : record){
        vector<string> line;
        
        int prev = 0;
        int split = rec.find(' ');
        while(split != string::npos){
            line.push_back(rec.substr(prev,split-prev));
            prev = split+1;
            split = rec.find(' ',prev);

        }
        
        line.push_back(rec.substr(prev,split-prev));

        if(line[0] == "Enter"){
           
            bool wasin = false;
            int newIdx = names.size();  
            for(int i = 0 ; i < userIds.size(); i++){
                if(line[1] == userIds[i]){
                    newIdx = i;
                    names[i] = line[2];
                    wasin = true;
                    break;
                }
            }

            // 처음 들어온 id일 때
            if(wasin == false){
                userIds.push_back(line[1]);
                names.push_back(line[2]);
            }

            userIdIndex.push_back(newIdx);
            nameIndex.push_back(newIdx);
            elses.push_back("님이 들어왔습니다.");

        }
        else if(line[0] == "Leave"){
            int newIdx = names.size();
            for(int i = 0; i < userIds.size(); i++){
                if(userIds[i] == line[1]){
                    newIdx = i;
                    break;
                }
            }
            userIdIndex.push_back(newIdx);
            nameIndex.push_back(newIdx);
            elses.push_back("님이 나갔습니다.");
        }
        else if(line[0] == "Change"){
            for(int i = 0 ; i< userIds.size(); i++){
                if(line[1] == userIds[i]){
                    names[i] = line[2];
                    break;
                }
            }

        }




    }

    for(int i = 0; i < nameIndex.size(); i++){
        string tmp = names[nameIndex[i]];
        tmp += elses[i];
        answer.push_back(tmp);
    }
    

    
    return answer;
}



int main() {

    vector<string> record;

    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid1244 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Change uid1244 Ryan");

    vector<string> ans = solution(record);

    for(int i = 0; i <ans.size(); i++){
        cout<< ans[i]<<endl;
    }


}