#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<string> myGenres;
    vector<vector<vector<int>>> groups;
    

    for(int i= 0; i < genres.size(); i++){
        string tmp = genres[i];
        int groupIdx = 100001;
        for(int j = 0; j <myGenres.size(); j++){
            if(myGenres[j] == tmp){
                groupIdx = j;
                break;
            }
        }

        if(groupIdx != 100001) {
            vector<int> tempVec;
            tempVec.push_back(plays[i]);
            tempVec.push_back(i); 
            groups[groupIdx].push_back(tempVec);

        }
        else{
            myGenres.push_back(tmp);
            vector<vector<int>> input; 
            vector<int> tempVec;
            
            tempVec.push_back(plays[i]);
            tempVec.push_back(i);

            input.push_back(tempVec);
            groups.push_back(input);
        }

    }

    for(int i = 0; i < groups.size();i++){
        int sum = 0;
        for(int j = 0; j <groups[i].size();j++){
            sum+= groups[i][j][0];
        }
        vector<int> tempVec;
        tempVec.push_back(sum);
        groups[i].push_back(tempVec);

    }

    for(int i = 0 ; i < groups.size();i++){
        sort(groups[i].rbegin(), groups[i].rend());
    }

    sort(groups.rbegin(),groups.rend());

    for(int i = 0; i<groups.size(); i++){
    

        if(groups[i].size() < 3){
            answer.push_back(groups[i][1][1]);
        }
        else{
            if(groups[i][1][0] == groups[i][2][0]){
                answer.push_back(min(groups[i][1][1],groups[i][2][1]));
                answer.push_back(max(groups[i][1][1],groups[i][2][1]));


            }
            else{
                answer.push_back(groups[i][1][1]);
                answer.push_back(groups[i][2][1]);
            }

        }


    }

    


    return answer;
}