#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int combination(int n, int k){
    int up = 1;
    int down = 1;

    if(k>n)
        return 0;

    for(int i = n; i >= n-k+1; i--){
        up *= i;
    }
    for(int i = k; i >=1; i--){
        down *=i;
    }

    return up/down;


}



int main(){

    int n;
    cin>>n;

    int add = 10;
    int comb = 1;
    int now = 10;
    int nums = 10;
    int ans = 0;

    while(nums <= n){
        
        int front = now/add;

        nums += combination(front,comb);

        
        if(nums>=n){
            break;
        }

        if(front == 9){
            add = add*10;
            now = add;
            comb++;
        }
        else{
            now += add;
        }

        if(now > 1000000){
            ans = -1;
            break;
        }

        
    }

    





    cout<<now<<endl;



    return 0;
}