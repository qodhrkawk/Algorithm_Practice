#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;





int main(){
    
    int n1,n2;


    while(1){
        cin>>n1>>n2;

        if(n1 == 0){
            break;
        }

        if(n1<n2 && n2%n1 ==0){
            cout<<"factor"<<endl;

        }
        else if(n1>= n2 && n1%n2 ==0){
            cout<<"multiple"<<endl;
        }
        else{
            cout<<"neither"<<endl;
        }
        



    }

    return 0;
}