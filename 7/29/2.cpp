#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";


    while(k>0){

        if(number.length() == k){
            k = 0;
            answer += number;
        }
        
        else{
            if(number[0]<number[1]){
                number = number.substr(1,number.length()-1);
                k --;
            }
            else if (number[0] == number[1]){
                 bool erase = false;
                for(int i = 2; i < k-2; i++){
                    if(number[i]>number[0]){
                        erase = true;
                    }

                 }

                if(erase){
                    number = number.substr(2,number.length()-2);
                    k -=2;
                }   
                else{
                    answer += number[0]; answer += number[1];
                    number = number.substr(2,number.length()-2);
                }



            }
            else{
                number = number[0]+ number.substr(2,number.length()-2);
                k--;

           }




        }


    }

    

    




    if(k == 0) {
        return number;
    }

    if(number.length()<k){

        return "";
    }

    if(number[0]<number[1]){
        answer = solution(number.substr(1,number.length()-1),k-1);
    }
    else if (number[0]==number[1]){
        bool erase = false;
        for(int i = 2; i < k-2; i++){
            if(number[i]>number[0]){
                erase = true;
            }

        }

        if(erase){
            answer = solution(number.substr(2,number.length()-2),k-2);
        }   
        else{
            string doub = "";
            doub += number[0]; doub += number[1];
            answer = doub + solution(number.substr(2,number.length()-2),k);
        }



    }
    else{
        answer = solution(number[0]+ number.substr(2,number.length()-2),k-1);
    }


    return answer;
}