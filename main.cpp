#include <iostream>
#include <climits>
#include <vector>
#include "Board.cpp"
#include "NodoBoard.cpp"



using namespace std;

int scoreEvaluate(int cell1, int cell2, int cell3, int cell4) {
    int score = 0;

    if (cell1 == 2) score++;
    if (cell2 == 2) score++;
    if (cell3 == 2) score++;
    if (cell4 == 2) score++;

    if (cell1 == 1) score--;
    if (cell2 == 1) score--;
    if (cell3 == 1) score--;
    if (cell4 == 1) score--;

    return score;
}


int evaluate(Board* board) {
    int score = 0;

    // Evaluar las filas
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i, j + 1), board->getPosition(i, j + 2), board->getPosition(i, j + 3));
        }
    }

    // Evaluar las columnas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j), board->getPosition(i + 2, j), board->getPosition(i + 3, j));
        }
    }

    // Evaluar diagonales hacia la derecha
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j + 1), board->getPosition(i + 2, j + 2), board->getPosition(i + 3, j + 3));
        }
    }

    // Evaluar diagonales hacia la izquierda
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j - 1), board->getPosition(i + 2, j - 2), board->getPosition(i + 3, j - 3));
        }
    }

    return score;
}

int minimax(Board* board, int depth, int alpha, int beta, bool maxiPlayer) {
    
    if (depth == 0 || board->checkWinner()) {
        return evaluate(board);
    }
    
    if (maxiPlayer) {
        int bestMov = -1;
        int maxAct = INT_MIN;
        for (int column = 0; column < board->getCols(); column++)
        {
            if (!board->isColumnFull(column)) {
                Board* auxBoard = new Board(*board);
                auxBoard->addDisk(column,2);
                int rev = minimax(auxBoard,depth-1,alpha,beta,false);
                maxAct = max(maxAct, rev);
                alpha = max(alpha,rev);
                delete auxBoard;

                if (beta <= alpha) {
                    break;
                }   
            }
            return maxAct;
        } 
    } else {
            int minEval = INT_MAX;
            for (int col = 0; col < 7; col++) {
                if (!board->isColumnFull(col)) {
                    Board* newBoard = new Board(*board);
                    newBoard->addDisk(col, 1);
                    int eval = minimax(newBoard, depth - 1, alpha, beta, true);
                    minEval = min(minEval, eval);
                    beta = min(beta, eval);
                    delete newBoard;

                    if (beta <= alpha) {
                        break; 
                    }
                }
            }
            return minEval;  
    }
 
}

int getBestMove(Board* board, int depth) {
    int bestMove = -1;
    int maxEval = INT_MIN;

    for (int colmn = 0; colmn < 7; colmn++) {
        if (!board->isColumnFull(colmn)) {
            Board* newBoard = new Board(*board);
            newBoard->addDisk(colmn, 2);
            int eval = minimax(newBoard, depth - 1, INT_MIN, INT_MAX, false);

            if (eval > maxEval) {
                maxEval = eval;
                bestMove = colmn;
            }

            delete newBoard;
        }
    }

    return bestMove;
}

void playerVsCpu(const vector<NodoBoard*>& movList, int difficulty) {

    Player* player1 = new Player(1);
    Player* player2 = new Player(2);
    Board* board = new Board();
    NodoBoard* nodoBoard = new NodoBoard(board,player1->getDisk());

    board->printBoard();

    int currPlayer = player1->getDisk();
    int col = 0;

    while (!board->checkWinner()) {

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

            board->addDisk(col,player1->getDisk());
            currPlayer = player2->getDisk();
            board->printBoard();

        } else if (currPlayer == player2->getDisk()) {
            col = getBestMove(board,difficulty);
            board->addDisk(col,player2->getDisk());
            currPlayer = player1->getDisk();

        }

    if (board->checkWinner()) {
        cout << "¡El jugador " << currPlayer << " ha ganado!" << endl;
    } else {
        cout << "El juego ha terminado en empate." << endl;
    }


    delete player1;
    delete player2;
    delete board;
    delete nodoBoard;


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
            int difficulty;
            cout << "Seleccione la dificultad:" << endl;
            cout << "1. Facil" << endl;
            cout << "2. Medio" << endl;
            cout << "3. Dificil" << endl;
            cin >> difficulty;

            while (difficulty < 0 || difficulty > 3) {
                cout << "ERROR!!! OPCION INVALIDA" << "\n" << endl;
                cout << "Seleccione la dificultad:" << endl;
                cout << "1. Facil" << endl;
                cout << "2. Medio" << endl;
                cout << "3. Dificil" << endl;
                cin >> difficulty;
            }

            int depth;

            switch (difficulty)
            {
            case 1:
                depth = 3;
                break;
            case 2:
                depth = 6;
                break;
            case 3:
                depth = 9;
                break;
            
            default:
                break;
            }
            playerVsCpu(movList, depth);
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