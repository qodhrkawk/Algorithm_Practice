#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

string s;
vector<int> dp;
vector<bool> mal(10,false);

void dyn(int start, string now){


    if(start == s.length()){
        dp.push_back(stoi(now));
    }
    else{
        
        int num = s[start] - 48;
        if(mal[num] == false){            
            dyn(start+1,now+to_string(num));
        }
        else{
            
            int up = num+1;
            int down = num-1;
            bool upAble = false;
            bool downAble = false;
            
            for(int i = up; i< 10; i++){
                if(mal[i] == false){
                    up = i;
                    upAble = true;
                    break;
                }
            }
            for(int i = down; i >= 0; i--){
                if(mal[i] == false){
                    down = i;
                    downAble = true;
                    break;
                }
            }
            if(upAble){
                dyn(start+1,now+to_string(up));

            }
            if(downAble){
                dyn(start+1,now+to_string(down));
            }
            
        }

    }

}



int main(){

    int n,c;
    cin>>n>>c;

    int tmp;

    for(int i = 0; i < c; i++){
        cin>>tmp;
        mal[tmp] = true;
    }

    
    

    s = to_string(n);


    dyn(0,"");

    for(int i = 0; i <dp.size();i++){
        dp[i] = abs(n-dp[i]) + s.length();
    }

    int minimum = abs(n-100);
    for(int i = 0; i <dp.size(); i++){
        minimum = min(dp[i],minimum);

    }


    cout<<minimum<<endl;


    return 0;
}