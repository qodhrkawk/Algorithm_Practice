#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    vector<int> dealer;
    vector<int> player;
    vector<int> playerPossible;
    vector<int> dealerPossible;
    int playerSum = 0;
    int dealerSum = 0;
    int showen;

    int playerAce = 0;
    int dealerAce = 0;

    bool playerGetTurn = true;
    

    for(int i = 0; i < cards.size(); i++){
        if(cards[i] > 10){
            cards[i] = 10;
        }
    }

    int start = 0;

    for(int i = 0; i < cards.size(); i++){
        int k = i - start;
        if(k<4){
            if(k %2 == 0){
                
                if(cards[i] == 1){
                    playerAce++;
                    player.push_back(11);
                }
                else{
                    player.push_back(cards[i]);
                }
            }
            else if(k == 1){
                dealer.push_back(cards[i]);
                if(cards[i] == 1){
                    dealerAce++;
                }
            }
            else if(k == 3){
                dealer.push_back(cards[i]);
                showen = cards[i];
                if(cards[i] == 1){
                    dealerAce++;
                    dealer.push_back(11);
                }
                else{
                    dealer.push_back(cards[i]);
                }


                
                for(int c = 0; c < player.size(); c++){
                    playerSum += player[c];

                }
                

                
                for(int c = 0; c < dealer.size(); c++){
                    dealerSum += player[c];

                }
                
                if(playerSum == 21){
                    answer+=2;
                    start = i+1;

                }


                playerGetTurn = true;




            }


        }
        

        if(k > 4){


            sort(playerPossible.rbegin(),playerPossible.rend());
            sort(dealerPossible.rbegin(),dealerPossible.rend());

            if(playerGetTurn){
                if(showen == 1 || showen >= 7){
                    playerSum += cards[i];
                    if(playerSum > 21){
                        

                    }                


                }
                else if(showen == 4 || showen == 5 || showen == 6){
                    
                }


            }
            







        }

        
        
        


    }





    return answer;
}