#include <iostream>
#include <vector>
#include <algorithm> // para std::max y std::min
using namespace std;

int busqueda_dos_en_dos(const vector<int>& lista, int objetivo) {
    int n = lista.size();
    int i = 0;

    // Avanzar de 2 en 2 mientras el elemento sea menor al objetivo
    while (i < n && lista[i] < objetivo) {
        i += 2;
    }

    // Retroceder 1 posición
    i = i - 1;

    // Revisar hasta 2 posiciones a partir de i
    for (int j = max(0, i); j <= min(i + 1, n - 1); j++) {
        if (lista[j] == objetivo) {
            return j; // encontrado
        }
    }

    return -1; // no encontrado
}

int main() {
    vector<int> lista = {2, 5, 8, 11, 14, 17, 20};
    int objetivo = 15;

    int resultado = busqueda_dos_en_dos(lista, objetivo);

    if (resultado != -1)
        cout << "Elemento encontrado en la posicion: " << resultado << endl;
    else
        cout << "Elemento no encontrado" << endl;

    return 0;
}