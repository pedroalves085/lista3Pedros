#include "Player.hpp"

using namespace std;

Player :: Player(int id, string name, int score, int timestamp){
    
    this -> id = id;
    this -> name = name;
    this -> score = score;
    this -> timestamp = timestamp;
}

Player :: Player(){}

Player :: ~Player(){}

int Player :: getId(){
    return this -> id;
}

string Player :: getName(){
    return this -> name;
}

int Player :: getScore(){
    return this -> score;
}

int Player :: getTimestamp(){
    return this -> timestamp;
}