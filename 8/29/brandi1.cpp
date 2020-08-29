#include <iostream>
using namespace std;


int rest =0 ;
int warming = 0;
int concent = 0;
int middle = 0;
int high = 0;
int highest = 0;

int main() {


    int age;
    cin>>age;

    double maximum = 220-age;
    double tmp;

    while(cin>>tmp){
        double per = tmp/maximum;
        if(per >= 0.9){
            highest++;
        }
        else if (per >= 0.8){
            high++;
        }
        else if (per >= 0.75){
            middle++;
        }
        else if (per >= 0.68){
            concent++;
        }
        else if (per >= 0.6){
            warming++;
        }
        else{
            rest++;
        }

    }



    cout<< highest <<" "<<high << " "<< middle << " "<<concent<< " " <<warming<< " "<<rest<<endl;


	return 0;
}