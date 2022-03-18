#include <iostream>
#include <list>
#include <math.h>

using namespace std;

int costo(int N, int M, int x[], int y[]) {

}

void radixSort(int *arr, int n, int max) {

    // f(n) = 2 + 1 + max(3 + 5 + 4 + n(3 + 3 + 2 + 4 + 1 + 10(3 + 5 + 5 + 2)))
    // O(max * n)
    // Loop invariant = Al principio del for, el array va a estar ordenado en los últimos i - 1 digitos.

   int i, j, m, p = 1, index, temp, count = 0; //2 tiempos
   list<int> pocket[10]; // 1 tiempo    //radix of decimal number is 10

   for(i = 0; i < max; i++) { //3 tiempos
      m = pow(10, i + 1); //5 tiempos
      p = pow(10, i); //4 tiempos

      for(j = 0; j < n; j++) { // 3 tiempos
         temp = arr[j] % m; // 3 tiempos
         index = temp / p; //2 tiempos     //find index for pocket array
         pocket[index].push_back(arr[j]); // 4 tiempos
      }

      count = 0; // 1 tiempo

      for(j = 0; j < 10; j++) { // 3 tiempos
         //delete from linked lists and store to array
         while(!pocket[j].empty()) { // 3 tiempos
            arr[count] = *(pocket[j].begin()); // 5 tiempos
            pocket[j].erase(pocket[j].begin()); // 5 tiempos
            count++; // 2 tiempos
         }
      }
   }
}

int main() {

    return 0;
}