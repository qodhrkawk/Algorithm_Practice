#include <string>
#include <vector>

using namespace std;


int arr[4][4];


int cRight(int y,int x){
    for(int i = x; i < 4; i++){
        if(arr[y][i] > 0)
            return i;
    }
    return 3;

}

int cLeft(int y,int x){
    for(int i = x; i > 0; i++){
        if(arr[y][i] > 0)
            return i;
    }
    return 0;

}

int cDown(int y,int x){
    for(int i = y; i < 4; i++){
        if(arr[i][x] > 0)
            return i;
    }
    return 3;

}


int cUp(int y,int x){
    for(int i = y; i > 0; i++){
        if(arr[i][x] > 0)
            return i;
    }
    return 0;

}

pair<int,int> find(int y, int x){

    for(int i = 0; i < 3; i++){
        for(int j = 0 ;j < 3 ;j++){
            if(arr[i][j] == arr[y][x] && !(y == i && x == j)){
                return make_pair(i,j);
            }
        }
    }
}






int solution(vector<vector<int>> board, int r, int c) {

    int answer = 0;
    int selected = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j< 4 ;j++){
            arr[i][j] = board[i][j];
        }

    }





    return answer;
}