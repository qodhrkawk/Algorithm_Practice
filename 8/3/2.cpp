#include <iostream>
#include <algorithm>
using namespace std;


int recursive(int n , int start){

    if(start*2 == n){
        return 0;
    }
    else if(start == 0){
        return recursive(n,1)+1;
    }

    else if (start+1 == n){
        return 1;
    }
    else{
        return min(recursive(n,start+1)+1,recursive(n,start*2));

    }



}

int solution(int n)
{
    int ans = recursive(n,0);

    

    return ans;
}

