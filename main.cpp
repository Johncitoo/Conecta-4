#include <iostream>
#include <vector>
#include "Board.cpp"
#include "NodoBoard.cpp"



using namespace std;



void playerVsCpu(const vector<NodoBoard*>& movList) {

    Player* player1 = new Player(1);
    Player* player2 = new Player(2);
    Board* board = new Board();
    NodoBoard* nodoBoard = new NodoBoard(board,player1->getDisk());

    board->printBoard();

    int currPlayer = player1->getDisk();
    int col = 0;

    while (!board->checkWinner(player1,player2)) {

        if (currPlayer == player1->getDisk()) {

            cout << "COLUMNA: " << endl;
            cin >> col;

            while (col > 6 || col < 0 || !board->isColumnFull(col)) {

                if (!board->isColumnFull(col)) {
                cout << "LA COLUMNA SE ENCUENTRA LLENA!!! SELECCIONE OTRA COLUMNA:" << endl;
                cout << "COLUMNA: " << endl;
                cin >> col;
                } else {
                    cout << "COLUMNA FUERA DE LOS MARGENES, INGRESE UNA COLUMNA VALIDA" << endl;
                    cout << "COLUMNA: " << endl;
                    cin >> col;
                }

            }

        } else if (currPlayer == player2->getDisk()) {

        }



    }




}

int main()
{

    vector <NodoBoard*> movList;
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

    switch (opcion) {
        case 1:
            playerVsCpu(movList);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
    }

    return 0;
} 