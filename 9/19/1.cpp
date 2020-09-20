#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

string s;



int main() {
	

    getline(cin,s);
    string word;

    int answer = 0;
    for(stringstream sts(s); (sts>>word);){
        answer++;
    }

    cout<<answer<<endl;



	return 0;
}