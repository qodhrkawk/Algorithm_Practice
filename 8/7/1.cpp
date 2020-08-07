#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> moves;

    int as = 0;
    int maxas = 0;
    int astart = -1; int aend = -1;
    int maxastart = -1; int maxaend = -1;

    for(int i = 0 ; i< name.length(); i++){
        // moves.push_back(min(name[i]-65,91-name[i]));
        answer += min(name[i]-65,91-name[i]);
        if(name[i] == 'A'){
            if(as == 0){
                astart = i;
                aend = i;
            }
            else{
                aend = i;
            }
            as++;
            
        }
        else{
            if(as>0){
                if(as > maxas){
                    maxas = as;
                    maxastart = astart;
                    maxaend = aend;
                }
                as = 0;
            }

        }

    }

    if(maxastart == -1){
        answer += name.length()-1;

    }

    else{
        
        int pos = (maxastart-1)*2+(name.length()-1-maxaend);
        int neg = (name.length()-1-maxaend)*2 + (maxastart-1);
        if(maxastart == 0 && maxaend == name.length()-1){
            pos = 0;
        }
        else if(maxaend == name.length() -1 )
            pos = (maxastart-1);
        else if(maxastart == 0 || maxastart == 1){
            neg = (name.length()-1-maxaend);
        }
        int s = name.length()-1;
        answer += min(min(pos,neg),s);
    }


    





    return answer;
}