#include <iostream>
#include <vector>
#include "Board.cpp"
#include "NodoBoard.cpp"



using namespace std;

int main()
{
    int opcion;
    cout << "Seleccione una opción:" << endl;
    cout << "1. Jugar contra la IA" << endl;
    cout << "2. IA vs IA" << endl;
    cout << "3. Jugador contra Jugador" << endl;
    cin >> opcion;

    while (opcion < 0 || opcion > 3) {
        cout << "ERROR!!! OPCION INVALIDA" << "\n" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Jugar contra la IA" << endl;
        cout << "2. IA vs IA" << endl;
        cout << "3. Jugador contra Jugador" << endl;
        cin >> opcion;
    }

    return 0;
} 