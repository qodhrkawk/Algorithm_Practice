#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int n;

    cin>>n;

    for(int t  = 0; t< n; t++){
        string s;
        cin>>s;
        int depth = 0;
        bool able = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                depth++;
            else
            {
                depth--;
            }
            
            if(depth < 0){
                able = false;
                break;
            }



        }

        if(depth != 0){
            able = false;
        }

        if(able)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        

    }

	return 0;
}