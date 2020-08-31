#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {



    int x;
    
    cin>>x;

    double n = 64;
    double small = 64;
    int res=  1;

    while(n>x){

        small = small/2;
        res++;
        if(n-small > x){
            n = n -small;
            res--;
        }
        else if(n-small == x){
            res--;
            break;
        }    
        
    }

    

    cout<<res<<endl;

	return 0;
}