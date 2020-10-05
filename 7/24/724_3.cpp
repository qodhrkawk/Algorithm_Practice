#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    bool* prime = new bool[n+1];
    fill_n(prime,n+1,true);

    for(int i = 2; i <= n/2; i++){

        for(int j = 2; j <= n/i; j++){
            prime[i*j] = false;
        }
        
    }

    for(int i = 2; i<= n; i++){
        if(prime[i] == true){

            answer += 1;
        }

    }




    return answer;
}


int main(){

    cout<<solution(5)<<endl;


    return 0;
}