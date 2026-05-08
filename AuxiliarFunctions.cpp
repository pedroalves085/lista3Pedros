#include "AuxiliarFunctions.hpp"
#include "Player.hpp"

using namespace std;

Player* merge_list(Player arr1[], int n, Player arr2[], int m){

    Player* mArr = new Player[m + n];

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (arr1[i].getScore() <= arr2[j].getScore()) {
            mArr[i + j] = arr1[i];
            i++;
        } else {
            mArr[i + j] = arr2[j];
            j++;
        }
    }

    while (i < n) {
        mArr[i + j] = arr1[i];
        i++;
    }

    while (j < m) {
        mArr[i + j] = arr2[j];
        j++;
    }

    return mArr;
}

Player* merge_sort(Player arr[], int n){
    if (n == 1) {                                   
        Player* single = new Player[1];                   
        single[0] = arr[0];                         
        return single;                              
    }

    int mid = n / 2;                                

    Player* left = merge_sort(arr, mid);                
    Player* right = merge_sort(arr + mid, n - mid);     

    Player* sorted = merge_list(left, mid, right, n - mid); 

    delete[] left;                                  
    delete[] right;                                 

    return sorted;   
}