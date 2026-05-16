#include "Matchmaking.hpp"
#include "Player.hpp"
#include <iostream>

int main(){
    //Criação do sistema e dos players
    Matchmaking sistem;

    Player p1(101, "Joao", 100, 1);
    Player p2(102, "Evandro", 500, 2);
    Player p3(103, "Marcos", 200, 3);
    Player p4(104, "Gabriela", 370, 4);
    Player p5(105, "Patricia", 800, 5);
    Player p6(106, "Tiago", 200, 6);
    Player p7(107, "Leticia", 300, 7);
    Player p8(108, "Pedro", 520, 8);
    Player p9(109, "Laura", 140, 9);
    Player p10(110, "Ana Julia", 120, 10);
    Player p11(111, "Larisa", 110, 11);
    Player p12(112, "Matheus", 660, 12);
    Player p13(113, "Yoshida", 600, 13);
    Player p14(114, "Caetano", 1100, 14);
    Player p15(115, "Beatriz", 200, 15);
    Player p16(116, "Carla", 350, 16);
    Player p17(117, "Maria", 110, 17);
    Player p18(118, "Davi", 920, 18);
    Player p19(119, "Alice", 1000, 19);
    Player p20(120, "Samuel", 550, 20);


    //Inserção do primeiro grupo de players para ordenação com insertion
    sistem.insert(p1);
    sistem.insert(p2);
    sistem.insert(p3);
    sistem.insert(p4);
    sistem.insert(p5);
    sistem.insert(p6);
    sistem.insert(p7);
    sistem.insert(p8);
    sistem.insert(p9);
    sistem.insert(p10);
    sistem.insert(p11);
    sistem.insert(p12);

    sistem.removePlayer(109);

    sistem.sortByScoreInsertion();

    sistem.removePlayer(101);

    //Inserção do segundo grupo de players para ordenação com Merge
    sistem.insert(p13);
    sistem.insert(p14);
    sistem.insert(p15);
    sistem.insert(p16);
    sistem.insert(p17);
    sistem.insert(p18);
    sistem.insert(p19);
    sistem.insert(p20);

    sistem.removePlayer(113);

    sistem.sortByScoreMerge();

    //Estado do sistema após adições, remoções e ordenações:
    sistem.printWaitingPlayers();
    cout << endl;

    //Formação de grupo válida:
    int n1;
    Player* group1 = sistem.formGroup(3, 50, &n1);
    cout << "Numero de jogadores do grupo 1: " << n1 << endl;

    //Formação de grupo sem sucesso:
    int n2;
    Player* group2 = sistem.formGroup(4, 20, &n2);
    cout << "Numero de jogadores do grupo 2: " << n2 << endl << endl;

    //Formação do primeiro grupo possível apesar de existirem outros:
    int n3;
    Player* group3 = sistem.formGroup(2, 40, &n3);

    //Quantidade de players ainda em espera:
    int n4;
    Player* players = sistem.getWaitingPlayers(&n4);
    cout << "Numero de jogadores em fila: " << n4 << endl << endl;

    //Estado final do sistema após operações:
    sistem.printWaitingPlayers();

}