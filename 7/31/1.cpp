#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> truckIdx;

    truckIdx.push(truck_weights[0]);
    int onRoad = truck_weights[0];
    truck_weights.erase(truck_weights.begin(),truck_weights.begin());
    

    while(truck_weights.size()>0){
        if(onRoad == 0){
            onRoad += truck_weights[0];
            truck_weights.erase(truck_weights.begin(),truck_weights.begin());
        }

        else if(onRoad + truck_weights[0] > 0){
            onRoad += truck_weights[0];
            truck_weights.erase(truck_weights.begin(),truck_weights.begin());
            

        }
        else{
            

        }



    }






    return answer;
}