#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {
    int answer = -1;

    vector<int> dealer;
    vector<int> player;
    vector<int> playerPossible;
    vector<int> dealerPossible;

    int showen;

    int playerAce = 0;
    int dealerAce = 0;

    
    

    for(int i = 0; i < cards.size(); i++){
        if(cards[i] > 10){
            cards[i] = 10;
        }
    }



    for(int i = 0; i < cards.size(); i++){
        if(i<4){
            if(i %2 == 0){
                player.push_back(cards[i]);
                if(cards[i] == 1){
                    playerAce++;
                }
            }
            else if(i == 1){
                dealer.push_back(cards[i]);
                if(cards[i] == 1){
                    dealerAce++;
                }
            }
            else if(i == 3){
                dealer.push_back(cards[i]);
                showen = cards[i];
                if(cards[i] == 1){
                    dealerAce++;
                }
            }


        }
        

        if(i == 4){
            int playerSum = 0;
            for(int c = 0; c < player.size(); c++){
                playerSum += player[c];

            }
            playerPossible.push_back(playerSum);

            int dealerSum = 0;
            for(int c = 0; c < dealer.size(); c++){
                dealerSum += player[c];

            }
            dealerPossible.push_back(dealerSum);

            for(int c = 1; c <=playerAce; c++){
                playerPossible.push_back(playerSum+10*c);
            }

            for(int c = 0; c < playerPossible.size(); c++){
                if(playerPossible[c] == 21){
                    
                }

            }

            for(int c = 1; c <=dealerAce; c++){
                dealerPossible.push_back(playerSum+10*c);
            }







        }

        
        
        


    }





    return answer;
}