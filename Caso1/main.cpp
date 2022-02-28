//Tarea Caso 1 Jesús Araya Chaves

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//En este algoritmo se utiliza un for loop, por lo que la cantidad de iteraciones e if's hacen lento al programa.
void compareTheTriplets(int a[], int b[]) {
    int score [2] = {0, 0};
    for(int i = 0; i < 3; i++) {
        if(a[i] > b[i]) {
            score[0] += 1;
        } if(a[i] < b[i]) {
            score[1] += 1;
        } else {
            continue;
        }
    } cout << score[0] << ", " << score[1] << endl;
}

//Este algoritmo realiza solamente 3 if's y el resto lo calcula mediante un calculo aritmético, por lo que es mas eficiente.
//Algoritmo de Estefania Delgado.
void compareTheTriplets2(int a[], int b[]) {
    int score [2] = {0, 0};
    if(a[0] != b[0]) {
        int point = ((a[0] - b[0])/abs(a[0] - b[0]));
        score[0] += point + 1;
        score[1] += point - 1;
    } if(a[1] != b[1]) {
        int point = ((a[1] - b[1])/abs(a[1] - b[1]));
        score[0] += point + 1;
        score[1] += point - 1;
    } if(a[2] != b[2]) {
        int point = ((a[2] - b[2])/abs(a[2] - b[2]));
        score[0] += point + 1;
        score[1] += point - 1;
    } 
    score[0] = score[0] / 2;
    score[1] = abs(score[1] / 2);

    cout << score[0] << ", " << score[1] << endl;
}

//Este algoritmo utiliza 3 comparaciones para realizar el cambio.
void timeConversion(string fecha) {
    int hora = stoi(fecha.substr(0, 2));
    string hora24;

    if(hora == 12 && fecha[8] == 'A') {
        hora = 0;
    } else if(fecha[8] == 'P') {
        hora += 12;
    }

    if(hora < 10) {
        hora24 = "0" + to_string(hora) + fecha.substr(2, 6);
    } else {
        hora24 = to_string(hora) + fecha.substr(2, 6);
    }

    cout << hora24 << endl;
}

//Este algoritmo utiliza 1 comparación para realizar el cambio de hora, luego se hacen 2 comparaciones para armar la hora. El cambio se calcula aritmeticamente.
//Algoritmo de Alonso Garita visto en clase.
void timeConversion2(string fecha) {
    string hora24;
    int hora = stoi(fecha.substr(0, 2));
    int factor = ((hora % 12) / hora);

    if(fecha[8] == 'A') {
        factor--;
    }

    hora += (12 * factor);

    if(hora < 10) {
        hora24 = "0" + to_string(hora) + fecha.substr(2, 6);
    } else {
        hora24 = to_string(hora) + fecha.substr(2, 6);
    }

    cout << hora24 << endl;
}

//Este algoritmo utiliza 2 ciclos y 3 comparaciones por cada vez que el ciclo avanza.
void subarrayDivision(int a[],int amount, int day, int month) {
    int total = 0;
    int sum = 0;

    for(int i = 0; i < amount; i++) {
        if(i + month <= amount) {
            for(int j = i; j < i + month; j++) {
                sum += a[j];
            } 
        }
        if(sum == day) {
            total += 1;
            sum = 0;
        } else {
            sum = 0;
        }
    }

    cout << total << endl;
}

//Este algoritmo solo utiliza un ciclo y 3 comparaciones en cada ciclo.
//Algoritmo de Pamela Gonzales visto en clase.
void subarrayDivision2(int a[], int amount, int day, int month) {
    int inicial = 0;
    int total = 0;
    int sum = 0;
    int control = 1;

    for(int i = 0; i < amount; i++) {
        sum += a[i];

        if(control == month && sum == day) {
            total += 1;
            sum -= a[inicial];
            inicial += 1;
        } else if(control == month) {
            sum -= a[inicial];
            inicial += 1;
        } else {
            control += 1;
        }
    } cout << total << endl;
}

void theMinionGame(string word) {
    int kevin = 0;
    int stuart = 0;
    for(int i = 0; i < word.length(); i++) {
        if((word[i] == 'A') || (word[i] == 'E') || (word[i] == 'I') || (word[i] == 'O') || (word[i] == 'U')) {
            kevin += word.length() - i;
        } else {
            stuart += word.length() - i;
        }
    } 

    if(kevin > stuart) {
        cout << "Kevin " << kevin << endl;
    } else if(kevin < stuart) {
        cout << "Stuart " << stuart << endl;
    } else {
        cout << "Draw" << endl;
    }
}

//Algoritmo de Andrea Li Hernandez visto en clases.
string cipher(int n, int k, string s) {
    vector<char> result(n);

    result[0] = s[0]-48;

    for (int i = 1; i < k; i++) {
        result[i] = s[i-1] ^ s[i];
    }

    char aux;
    for (int i = k; i < n; i++) {
        aux = '0';
        for (int j = i-(k-1); j < i; j++) {
            aux = aux ^ result[j];
        }
        result[i] = aux ^ s[i];
    }

    string final_result = "";
    for (int i = 0; i < n; i++) {
        final_result += result[i]+48;
    }
    return final_result;
}

//Algoritmo de Deyner Navarro visto en clases.
int pairs_with_pointers(int k, vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    
    int pointers[] = {1, 0, 0};
    int result = 0;
    int valueDif = 0;
    
    while (pointers[0] < arr.size()) {
        
        valueDif = arr[pointers[0]] - arr[pointers[2]];
        
        if (valueDif == k) {
            result++;
            pointers[0]++;
            continue;
        }
        
        pointers[ ((valueDif - k)/abs(valueDif - k)) + 1 ]++;
    }
    
    return result;
}

int main() {
    int a[3] = {5, 6, 7};
    int b[3] = {3, 6, 10};

    int a2[3] = {17, 28, 30};
    int b2[3] = {99, 16, 8};

    cout << "Compare the triplets: " << endl;
    cout << "Utilizando el primer algoritmo: ";
    compareTheTriplets(a, b);
    compareTheTriplets(a2, b2);
    cout << "Utilizando el segundo algoritmo: ";
    compareTheTriplets2(a, b);
    compareTheTriplets2(a2, b2);
    cout << endl;

    string fecha = "07:05:45PM";
    string fecha2 = "08:50:20PM";
    cout << "Time conversion: " << endl;
    cout << "Utilizando el primer algoritmo: ";
    timeConversion(fecha);
    timeConversion(fecha2);
    cout << "Utilizando el Segundo algoritmo: ";
    timeConversion2(fecha);
    timeConversion2(fecha2);
    cout << endl;

    int s[] = {1, 2, 1, 3, 2};
    int s1[] = {1, 1, 1, 1, 1, 1};
    cout << "Subarray Division: " << endl;
    cout << "Utilizando el primer algoritmo: ";
    subarrayDivision(s, 5, 3, 2);
    subarrayDivision(s1, 6, 3, 2);
    cout << "Utilizando el segundo algoritmo: ";
    subarrayDivision2(s, 5, 3, 2);
    subarrayDivision2(s1, 6, 3, 2);
    cout << endl;

    cout << "The Minion Game: " << endl;
    cout << "La palabra es BANANA: ";
    theMinionGame("BANANA");
    cout << "La palabra es ARIAL: ";
    theMinionGame("ARIAL");
    cout << endl;

    cout << "Cipher: " << endl;
    cout << "Utilizando un n = 7, un k = 4 y un string 1110100110: " << cipher(7, 4, "1110100110") << endl;
    cout << "Utilizando un n = 6, un k = 2 y un string 1110001: " << cipher(6, 2, "1110001") << endl;
    cout << endl;

    vector<int> p = {1, 5, 3, 4, 2};
    vector<int> p1 = {1, 3, 5, 8, 6, 4, 2};
    cout << "Pairs: " << endl;
    cout << "Utilizando un K = 2 y un array {1, 5, 3, 4, 2}: " << pairs_with_pointers(2, p) << endl;
    cout << "Utilizando un K = 2 y un array {1, 3, 5, 8, 6, 4, 2}: " << pairs_with_pointers(2, p1) << endl;

    return 0;
}