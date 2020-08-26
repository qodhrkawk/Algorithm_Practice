#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;



int main(){


    int n;
    cin>>n;


    int tmp =-1;
    
    for(int i = 0; i<= 1000000; i++){

        if(i/10 == 0){
            tmp++;
        }

        else {
            string s = to_string(i);
            bool isNot = false;
            for(int i = 1 ;i  < s.length() ;i++){
                if(s[i-1] <= s[i]){
                    isNot = true;
                    break;
                }
            }
            if(isNot){
                continue;
            }
            else{
                tmp++;
            }
        }


        if(tmp==n){
            cout<<i<<endl;
            return 0;
        }


    }


    cout<<-1<<endl;
    

    return 0;
}