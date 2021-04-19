#include <iostream>
#include <string>
using namespace std;

string movies[5];

enum Gender {
    MALE,
    FEMALE

};


class Client {
public:
    int point = 0;
    int gender = MALE;
    string name = "";
};

class Seat {
public:
    bool reserved = false;
    Client reserver;

};

Client logIn(){
    cout<<"셩별 입력 : "<<endl;
    cout<<"1.남 2.여"<<endl;

    Client client;
    int gender = 0;
    cin>>gender;
    cout<<endl;
    gender == 1 ? client.gender = MALE : client.gender = FEMALE;

    cout<<"고객 이름 입력: "<<endl;
    cin>>client.name;
    cout<<endl;

    return client;

}

int selectSeat(Seat** seats){
    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 5; j++){
            if(seats[i][j].reserved){
                cout<<"x";
            }
            else{
                cout<<"O";
            }


        }
        cout<<endl;
    }

}

int selectAction(){
    cout<<"Select Action"<<endl;
    cout<<"1. 예매하기 2. 예매 취소하기"<<endl;
    int result = 0;
    cin>>result;
    return result;

}

int selectMovie(){
    cout<<"영화 선택"<<endl;
    for(int i = 0; i < 5; i++ ) {
        cout<<movies[i];
    }
    cout<<endl;
    int result;
    cin>>result;
    return result;

}





int main(){

    movies[0] = "1번";
    movies[1] = "2번";
    movies[2] = "3번";
    movies[3] = "4번";
    movies[4] = "5번";

    Client *clients = new Client[100];
    int clientNum = 0;
    
    Seat** seat = new Seat*[5];
    for(int i = 0 ; i < 5; i++){
        seat[i] = new Seat[5];
    }




    while(true) {
        Client client;
        client = logIn();
        int clientIdx = -1;
        for(int i = 0; i < clientNum; i++){
            if(clients[i].name == client.name && clients[i].gender == client.gender){
                clientIdx = i;
            }
        }
        if(clientIdx == - 1) {
            clientIdx = clientNum;
            clientNum += 1;
        }


        int action = selectAction();
        switch(action) {
            case 1 :
                int movie = selectMovie();
                



        }


    }


    return 0;
}