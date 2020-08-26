#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;




int main(){


    int n;
    cin>>n;

    vector<int> left(11,0);
    vector<int> position(11,0);

    for(int i= 1;i <=n;i++){
        cin>> left[i];
    }

    for(int i= 1;i <=n;i++){
        int zeros = 0;

        for(int j = 1; j<= n; j++){
            if(position[j] == 0){
                if(zeros == left[i]){
                    position[j] = i;
                    break;
                }
                zeros++;

            }

        }
    }

    for(int i = 1;i <=n; i++){
        cout<<position[i]<< " ";
    }
    cout<<endl;







    return 0;
}