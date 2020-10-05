#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double square = sqrt(n);

    if( square == int(square)){
        return answer = ((square+1)*(square+1));
    }
    else
    {
        return -1;
    }
    




    return answer;
}