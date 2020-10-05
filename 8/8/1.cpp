#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> doub; 


    for(int i = 0 ; i< s.length(); i++){

        if (doub.empty()){
            doub.push(s[i]);
        }

        else if(doub.top() == s[i]){
            doub.pop();
        }
        else{
            doub.push(s[i]);
        }
    }

    if(doub.empty()){
        answer = 1;
    }

    

    return answer;
}




// int solution(string s)
// {
//     int answer = 0;

//     bool inLoop = true;
//     while(inLoop){
        
//         char tmp = '1';
//         bool erased = false;
//         for(int i = 0; i < s.length(); i++){
//             if(tmp == s[i]){
           
//                 s = s.substr(0,i-1) + s.substr(i+1,s.length()-1);
//                 tmp = '1';
//                 erased = true;
//             }
//             else{
//                 tmp = s[i];
//             }


//         }

//         if(erased == false){
//             inLoop = false;
//         }


//     }

//     if(s.length() == 0){
//         answer = 1;
//     }



//     return answer;
// }
