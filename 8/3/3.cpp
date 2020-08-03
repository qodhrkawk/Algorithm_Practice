#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<bool>> bossible(build_frame.size(),vector<bool>(build_frame.size(),false));
    vector<vector<bool>> gissible(build_frame.size(),vector<bool>(build_frame.size(),false));
    
    

    for(int i = 0 ; i<build_frame.size();i++){
        gissible[i][0] = true;
    }

    for(auto bf : build_frame){
        // 삭제일 때 
        if(bf[3] == 0){


        }

        
        // 기둥
        if(bf[2] == 0){
            if(gissible[bf[0]][bf[1]] == true){
                vector<int> newgidung{bf[0],bf[1],bf[2]};
                answer.push_back(newgidung);
                
                gissible[bf[0]][bf[1]+1] = true;
                bossible[bf[0]][bf[1]+1] = true;
                gissible[bf[0]][bf[1]] = false;
                bossible[bf[0]][bf[1]] = false;

            }
            else{
                continue;
            }

        }


        // 보
        else if (bf[2] == 1){
             if(bossible[bf[0]][bf[1]] == true){
                vector<int> newbo{bf[0],bf[1],bf[2]};
                answer.push_back(newbo);
                gissible[bf[0]+1][bf[1]] = true;
                bossible[bf[0]][bf[1]+1] = true;
                gissible[bf[0]][bf[1]] = false;
                bossible[bf[0]][bf[1]] = false;


            }
            else{
                continue;
            }




        }

    }




    return answer;
}