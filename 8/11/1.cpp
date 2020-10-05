#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    int answer = 0;

    vector<int> minimums(number+1,9);

    int tmp = N;
    int tries = 1;
    while(tmp<=number){
        minimums[tmp] = tries;
        
        int mult = 0;
        for(int i = tmp; i <= number; i*= N){
            minimums[i] = min(minimums[i],minimums[tmp]+mult); 
            mult++; 
        }

        int div = 0;
        for(int i = tmp; i > 0; i/= N){
            minimums[i] = min(minimums[i],minimums[tmp]+mult); 
            div++; 
        }
        
        tmp = tmp+N*pow(10,tries);



        tries++;      
    }







    return answer;
}