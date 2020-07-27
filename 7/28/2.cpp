#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    string ans = "";

    int mid = s.length()/2;

    int mini = s.length();

    for(int n = 2; n<= mid ; n++){
        

        for(int i = 1; i <n; i++){
            string ntmp = "";
            int first = i-1;
            string temp = "";
            vector<string> stringVec;

            for(int j = first; j<s.length()-n; j+=n){
                temp = s.substr(j,n);
                stringVec.push_back(temp);
            }

            string now = stringVec[0];

            int nums = 1;
            for(int k = 1; k<stringVec.size(); k++){
                if(stringVec[k] == now){
                    nums++;

                }
                else {
                    if(nums>1){
                        
                        ntmp += to_string(nums);
                        ntmp += now;
                        now = stringVec[k];
                    }
                    else{
                        
                        ntmp += stringVec[k];
                    }
                    nums = 1;

                }

               

            }
            cout << ntmp<<endl;

             if(nums > 1){
                    ntmp += to_string(nums);
                    ntmp += now;
                }

            if(mini > ntmp.length()+first){
                cout << ntmp << endl;
                mini = ntmp.length()+first;
            }
           
        }        



    }

    answer = mini;




    return answer;
}


int main(){

    string s= "abcabcabcabcdededededede";




    cout<<solution(s)<<endl;



    return 0;



}