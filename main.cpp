#include "Matchmaking.hpp"
#include "Player.hpp"

int main(){
    Matchmaking sistem;

    Player p1(101, "João", 100, 1);
    Player p2(102, "Evandro", 500, 2);
    Player p3(103, "Marcos", 200, 3);


    bool c = sistem.insert(p1);
    bool a = sistem.insert(p2);
    bool b = sistem.insert(p3);

    // bool d = sistem.removePlayer(104);

    sistem.sortByScoreMerge();

    sistem.printWaitingPlayers();
}