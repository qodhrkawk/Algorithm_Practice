#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int rp,gp,bp;
string s;

char dp[100000];



int main() {
	
    cin>>rp>>gp>>bp;

    cin>>s;

    vector<pair<int, int> > rgb;

    int r,g,b;
    int len = s.length();

    int res_price = 0;
    int res_num = 0;

    for(int i = 0; i< len; i++){
        if(s[i] == 'R'){
            r++;
        }
        else if(s[i] == 'G'){
            g++;
        }
        else{
            b++;
        }

    }
    
    rgb.push_back(make_pair(r,-rp));
    rgb.push_back(make_pair(g,-gp));
    rgb.push_back(make_pair(b,-bp));

    sort(rgb.begin(),rgb.end());

    int nLen = rgb[0].first;

    if(nLen > rgb[1].first){
        nLen = nLen - rgb[1].first;

        if(nLen >= rgb[2].first){
            nLen = nLen - rgb[2].first;
            res_num += nLen;
            if(rgb[0].second == -rp){
                res_price += res_num * min(bp,gp);
            }
            else if(rgb[0].second == -bp){
                res_price += res_num * min(rp,gp);
            }
            else{
                res_price += res_num * min(rp,bp);
            }

        }
        else{
            int no = rgb[2].first - nLen;
            res_num += 2*no;

            if(rgb[0].second == -rp){
                res_price += no * rp;
                res_price += no * (-1)*rgb[2].second;
            }
            else if(rgb[0].second == -bp){
                res_price += no * bp;
                res_price += no * (-1)*rgb[2].second;
            }
            else{
                res_price += no * gp;
                res_price += no * (-1)*rgb[2].second;
            }
        }

    }

    else{





    }

    



    cout<<res_price<<" "<<res_num<<endl;




	return 0;
}