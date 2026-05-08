#include "Player.hpp"
#include "Matchmaking.hpp"
#include "AuxiliarFunctions.hpp"
#include <iostream>

using namespace std;

Matchmaking :: Matchmaking(){
    this -> size = 0;
}

Matchmaking :: ~Matchmaking(){}

bool Matchmaking :: insert(Player player){

    if(this -> size == MAX_PLAYERS){
        return false;
    }else{
        this -> players[size] = player;
        this -> size ++;
        return true;
    }
}

bool Matchmaking :: removePlayer(int id){

    for(int i = 0; i < this -> size; i++){
        if(this -> players[i].getId() == id){

            for(int j = i + 1; j < this -> size; j++){
                this -> players[j -1] = this -> players[j];
            }

            this -> size--;
            return true;
        }
    }

    return true;
}

void Matchmaking :: sortByScoreInsertion(){
    int i, j;
    Player current;
    for (i = 1; i < this->size; i++) {
        current = this->players[i];
        j = i - 1;
        
        while (j >= 0 && this->players[j].getScore() > current.getScore()) {   
            this->players[j+1] = this->players[j];
            j = j - 1;
        }
        this->players[j+1] = current;
    }
}

void Matchmaking :: sortByScoreMerge(){

    Player* sorted = merge_sort(this -> players, this -> size);
    for(int i = 0; i < this -> size; i++)
        this -> players[i] = sorted[i];

    delete[] sorted;
}


Player* Matchmaking:: getWaitingPlayers(int* n){

    *n = this -> size;

    return this -> players;
}

void Matchmaking :: printWaitingPlayers(){

    for(int i = 0; i < this -> size; i++){
        cout << "[" << i << " | " << this -> players[i].getName() << " | " << this -> players[i].getScore() << " | " << this -> players[i].getTimestamp() << "]\n";
    }
}