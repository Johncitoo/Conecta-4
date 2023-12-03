#include <iostream>
#include <climits>
#include <vector>
#include "Board.cpp"
#include "NodoBoard.cpp"



using namespace std;

/**
 * The function evaluates the score based on the values of four cells, where a value of 2 adds 1 to the
 * score and a value of 1 subtracts 1 from the score.
 * 
 * @param cell1 The value of the first cell in the game.
 * @param cell2 The above code is a function called `scoreEvaluate` that takes in four integer
 * parameters `cell1`, `cell2`, `cell3`, and `cell4`. It evaluates the score based on the values of
 * these parameters.
 * @param cell3 The above code is a function named `scoreEvaluate` that takes four integer parameters
 * `cell1`, `cell2`, `cell3`, and `cell4`. It evaluates the score based on the values of these
 * parameters.
 * @param cell4 The above code defines a function called `scoreEvaluate` that takes four integer
 * parameters: `cell1`, `cell2`, `cell3`, and `cell4`. The function calculates a score based on the
 * values of these parameters.
 * 
 * @return the score, which is an integer value.
 */
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


/**
 * The function evaluates the score of a given board by checking for winning combinations in rows,
 * columns, and diagonals.
 * 
 * @param board The "board" parameter is a pointer to an object of type "Board". It is used to access
 * the positions on the game board.
 * 
 * @return an integer score.
 */
int evaluate(Board* board) {
    int score = 0;

    // FILAS
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i, j + 1), board->getPosition(i, j + 2), board->getPosition(i, j + 3));
        }
    }

    // COLUMNAS
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j), board->getPosition(i + 2, j), board->getPosition(i + 3, j));
        }
    }

    // DIAGONAL DERECHA
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j + 1), board->getPosition(i + 2, j + 2), board->getPosition(i + 3, j + 3));
        }
    }

    // DIAGONAL IZQUIERDA
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j - 1), board->getPosition(i + 2, j - 2), board->getPosition(i + 3, j - 3));
        }
    }

    return score;
}

/**
 * The minimax function is a recursive algorithm that evaluates the best move for a given game state by
 * considering all possible moves and their outcomes.
 * 
 * @param board A pointer to the current game board.
 * @param depth The depth parameter represents the current depth of the minimax algorithm. It
 * determines how many moves ahead the algorithm will consider. A higher depth value means the
 * algorithm will consider more moves ahead, but it will also increase the computation time.
 * @param alpha The alpha parameter is the best value that the maximizing player can guarantee at this
 * point or above. It is used to keep track of the maximum value found so far during the search.
 * @param beta The beta parameter in the minimax function is used for alpha-beta pruning. It represents
 * the maximum value that the minimizing player (opponent) is assured of. It is initially set to
 * positive infinity (INT_MAX) and is updated during the search to keep track of the minimum value
 * found so far.
 * @param maxiPlayer A boolean variable indicating whether it is the maximizing player's turn or not.
 * If it is true, it means it is the maximizing player's turn, otherwise it is the minimizing player's
 * turn.
 * 
 * @return an integer value.
 */
int minimax(Board* board, int depth, int alpha, int beta, bool maxiPlayer) {
    
    if (depth == 0 || board->checkWinner()) {
        return evaluate(board);
    }
    
    if (maxiPlayer) {
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
            
        } 
        return maxAct;
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

/**
 * The function `getBestMove` returns the best move (column) for a player in a given board state using
 * the minimax algorithm with alpha-beta pruning.
 * 
 * @param board A pointer to the current game board.
 * @param depth The depth parameter represents the depth of the search tree in the minimax algorithm.
 * It determines how many moves ahead the algorithm will consider. A higher depth value will result in
 * a more thorough search, but it will also increase the computation time.
 * 
 * @return the best move (column number) for the current player to make on the given board.
 */
int getBestMove(Board* board, int depth) {

    int bestMove = -1;
    int maxEval = INT_MIN;

    for (int colmn = 0; colmn < board->getCols(); colmn++) {
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

/**
 * The function "playerVsCpu" allows a player to play against a computer opponent with a specified
 * difficulty level.
 * 
 * @param difficulty The "difficulty" parameter in the "playerVsCpu" function is used to determine the
 * level of difficulty for the CPU player. It is an integer value that can be passed to the function to
 * specify how smart or challenging the CPU player should be. The exact meaning and range of the
 * "difficulty
 */
void playerVsCpu(int difficulty) {

    Player* player1 = new Player(1);
    Player* player2 = new Player(2);
    Board* board = new Board();
    Board* auxBoard = new Board();

    board->printBoard();

    int currPlayer = player1->getDisk();
    int col;

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

            board->addDisk(col--,player1->getDisk());
            auxBoard->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner())
            {
                currPlayer = player2->getDisk();
            }
            
            
            

        } else if (currPlayer == player2->getDisk()) {
            col = getBestMove(auxBoard,difficulty);
            board->addDisk(col,player2->getDisk());
            auxBoard->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner())
            {
                currPlayer = player1->getDisk();
            }
            

        }

    if (board->checkWinner()) {
        cout << "¡El jugador " << currPlayer << " ha ganado!" << endl;
    } else if (!board->checkWinner()) {
        cout << "El juego ha terminado en empate." << endl;
    }

    }

    delete player1;
    delete player2;
    delete board;
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
            playerVsCpu(depth);
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