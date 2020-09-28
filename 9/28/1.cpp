#include <string>
#include <vector>
#include <iostream>

using namespace std;



int main(){

    long long int div,up;


    int n, k;
    cin>>n>>k;

    div = 1;
    for(int i = 1; i<= k; i++){
        div *= i;
    }
    up = 1;
    for(int i = 0; i < k; i++){
        up *= (n-i);

    }

    cout<<up/div<<endl;




    return 0;
}