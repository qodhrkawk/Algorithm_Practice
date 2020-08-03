#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;

    sort(people.begin(),people.end());

    int onBoat = 0;
    while(people.size() > 0){
        if(onBoat + people[0] < limit){
            onBoat += people[0];
            people.erase(people.begin(),people.begin());
        }
        else{
            answer+= 1;
            onBoat = people[0];
            people.erase(people.begin(),people.begin()); 
        }


    }



    return answer;
}