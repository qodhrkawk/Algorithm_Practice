#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;



int main() {
	
    int testcase;

    cin>>testcase;

    for(int t = 0; t < testcase; t++){

        string s;
        cin>>s;
        int os = 1;
        int answer = 0;

        for(int i = 0; i< s.length(); i++){

            if(s[i] == 'O'){
                answer += os;
                os++;
            }
            else{
                os = 1;
            }



        }

        cout<<answer<<endl;



    }
    



	return 0;
}