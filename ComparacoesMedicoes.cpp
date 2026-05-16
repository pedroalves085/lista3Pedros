#include "Matchmaking.hpp"
#include "Player.hpp"

#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int score_aleatorio(){

    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<> dist(0, 1000);

    return dist(gen);
}

Player gerar_player_aleatorio(int id, int timestamp){

    return Player(id, "JogadorAleatorio", score_aleatorio(), timestamp);
}

int main(){

    const int MEDICOES = 10;
    const int REPETICOES = 5;

    int tamanhos[MEDICOES] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

    int resultados[MEDICOES][3];

    for(int t = 0; t < MEDICOES; t++){

        int n = tamanhos[t];

        Player* base = new Player[n];

        for(int i = 0; i < n; i++){
            base[i] = gerar_player_aleatorio(i, i);
        }

        int somaInsertion = 0;
        int somaMerge = 0;

        for(int r = 0; r < REPETICOES; r++){

            Matchmaking sistema1;

            for(int i = 0; i < n; i++){
                sistema1.insert(base[i]);
            }

            auto inicio1 = high_resolution_clock::now();

            sistema1.sortByScoreInsertion();

            auto fim1 = high_resolution_clock::now();

            somaInsertion +=
                duration_cast<microseconds>(fim1 - inicio1).count();


            Matchmaking sistema2;

            for(int i = 0; i < n; i++){
                sistema2.insert(base[i]);
            }

            auto inicio2 = high_resolution_clock::now();

            sistema2.sortByScoreMerge();

            auto fim2 = high_resolution_clock::now();

            somaMerge +=
                duration_cast<microseconds>(fim2 - inicio2).count();
        }

        resultados[t][0] = n;

        resultados[t][1] =
            somaInsertion / REPETICOES;

        resultados[t][2] =
            somaMerge / REPETICOES;

        delete[] base;
    }

    cout << "Tamanho | Insertion(us) | Merge(us)\n";

    for(int i = 0; i < MEDICOES; i++){

        cout << resultados[i][0] << " | "
             << resultados[i][1] << " | "
             << resultados[i][2] << "\n";
    }

    return 0;
}