#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<bool> > isVisited;


int dfs(int fm, int fn,vector<vector<int> > picture,int value){
    
    int result = 1;
    isVisited[fm][fn] = true;

    
    if (fn<picture[0].size()-1){
        if(picture[fm][fn+1] == value && isVisited[fm][fn+1]==false){
            result += dfs(fm,fn+1,picture,value);
        }
    }

    if(fm<picture.size()-1){
        if(picture[fm+1][fn] == value && isVisited[fm+1][fn]==false){
            result += dfs(fm+1,fn,picture,value);
        }
    }
   
    return result;
}


vector<int> findNext(int m, int n){
    vector<int> res;
    for(int i = 0; i <m; i++){
        for(int j = 0; j <n; j++){
            if(isVisited[i][j]== false){
                res.push_back(i);
                res.push_back(j);
                return res;
            }

        }

    }

    res.push_back(-1); res.push_back(-1);
    return res;


}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    
    
    isVisited.assign(m,vector<bool> (n,false));

    for(int i = 0; i <m; i++){
        for(int j = 0; j <n; j++){
            if(picture[i][j]== 0){
                isVisited[i][j] = true;
            }

        }

    }



    vector<int> next;
    next.assign(2,0);

    while(next[0]!= -1){
        number_of_area += 1;
        max_size_of_one_area = max(max_size_of_one_area,dfs(next[0],next[1],picture,picture[next[0]][next[1]]));
        next = findNext(m,n);
        // cout<<"next: " << next[0]<< " "<<next[1]<<endl;
    }

    
    


    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main() {
    int m = 6;
    int n = 4;


    vector<vector<int> > picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};


    vector<int> res = solution(m,n,picture);

    cout<<res[0]<<res[1]<<endl;


}
