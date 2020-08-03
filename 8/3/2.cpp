#include <iostream>
#include <algorithm>
using namespace std;


int firstMethod(int n){
    int res = 1;
    int tmp = 1;

    while(tmp<=n){
        if(tmp*2>n){
            break;
        }
        else{
            tmp*= 2;
        }
    }

    res += n-tmp;
    


    return res;
}

int secondMethod(int n){
    int res = 0;

    if(n == 0){
        
        return n+1;
    }
    if(n==1){
        
        return 1;
    }

    if(n%2==0){
       

        while(n%2==0){
            n = n/2;
        }

        res = min(firstMethod(n),secondMethod(n-1)+1);
 


    }
    else {
        res = secondMethod(n-1)+1;

    }
   

    return res;
}

int solution(int n)
{
    int ans = min(firstMethod(n),secondMethod(n));
    

    return ans;
}



int main(){

    cout<<solution(5)<<endl;




    return 0;
}