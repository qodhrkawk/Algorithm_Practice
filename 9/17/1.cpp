#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<pair<string,int> > cache;
    int lru = 0;

    if(cacheSize == 0){
        return cities.size()*5;

    }


    for(int i = 0 ; i< cities.size(); i++){
        for(int j = 0; j< cities[i].length(); j++){
            if(cities[i][j] >= 65 && cities[i][j] <= 90){
                cities[i][j] += 32;
            }
        }
    }


    for(int t = 0; t< cities.size(); t++){

        bool hit = false;
        for(int i = 0 ;i < cache.size(); i++){
            if(cities[t] == cache[i].first){
                cache[i].second = t;
                answer+=1;
                hit = true;
                break;
            }
        }
        if(!hit){

            if(cache.size() < cacheSize){
                cache.push_back(make_pair(cities[t],t));
                answer+= 5;
                
            }
            else{

            cache[lru].first = cities[t];
            cache[lru].second = t;
            answer+=5;

            }
        }


        

        
        for(int i = 0; i < cache.size(); i++){
            if(cache[lru].second > cache[i].second){
                lru = i;
            }
        }
        



    }



    return answer;
}