#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


vector<int> knows;
int parents[51];

vector<vector<int> > parties(50);



int Find(int x){
    if(x == parents[x]){
        return x;
    }
    return x = Find(parents[x]);
}


void Union(int x, int y){

    x = Find(x);
    y = Find(y);

    parents[x] = y;

}





int main(){

    
    int n,m;

    cin>>n>>m;


    int ans = 0;

    int know;
    cin>>know;
    


    for(int i = 0; i <know ;i++){
        int tmp;
        cin>>tmp;
        knows.push_back(tmp);
    }

    for(int i = 1; i<=n;i++){
        parents[i] = i;
    }

    

    for(int i = 0 ;i < m; i++){
        int participants;
        cin>>participants;
        
        int num;
        int prev;

        for(int j = 0; j <participants; j++){
            if(j>=1){
                prev = num;
                cin>>num;
                Union(prev,num);
            }
            else{
                cin>>num;
            }
            parties[i].push_back(num);

        }
    }


    for(auto& p : parties){
        bool flag = false;
        for(auto& a : p){
            if(flag) break;
            for(auto& k : knows){
                if(Find(a) == Find(k)){
                    flag = true;
                    break;
                }

            }

        }
        if(flag)
            m--;

    }



    
    cout<<m<<endl;



    return 0;
}