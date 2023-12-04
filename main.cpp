#include <iostream>
#include <climits>
#include <vector>
#include "Board.cpp"
using namespace std;


/**
* La función evalúa la puntuación en función de los valores de cuatro variables del tablero.
*
* @param board1 El valor del primer tablero.
* @param board2 El código anterior evalúa las puntuaciones de cuatro tableros diferentes. Los parametros
* tablero1, tablero2, tablero3 y tablero4 representan las puntuaciones de cada tablero respectivamente.
* @param board3 El código anterior es una función llamada `scoreEvaluate` que toma cuatro parámetros enteros
* `tablero1`, `tablero2`, `tablero3` y `tablero4`. Evalúa la puntuación en función de los valores de estos
* parámetros.
* @param board4 El código anterior es una función llamada `scoreEvaluate` que toma cuatro parámetros enteros
* `tablero1`, `tablero2`, `tablero3` y `tablero4`. Evalúa la puntuación en función de los valores de estos
* parámetros.
*
* @return la puntuación, que es un valor entero.
*/
int scoreEvaluate(int board1, int board2, int board3, int board4) {
    int score = 0;

    if (board1 == 2) score++;
    if (board2 == 2) score++;
    if (board3 == 2) score++;
    if (board4 == 2) score++;

    if (board1 == 1) score--;
    if (board2 == 1) score--;
    if (board3 == 1) score--;
    if (board4 == 1) score--;

    return score;
}

/**
* La función heurística devuelve un valor de 1 si valueBoard es igual a numPlayer, -1 si es igual
* no es igual a 0 y 0 en caso contrario.
*
* @param valueBoard El valor del estado actual del tablero de juego.
* @param numPlayer El parámetro `numPlayer` representa el número de jugador para quien se aplica la heurística.
* en proceso de cálculo.
*
* @return un valor entero.
*/
int heuristic(int valueBoard, int numPlayer) {
    if (valueBoard == numPlayer) {
        return 1;
    } else if (valueBoard != 0) {
        return -1;
    }
    return 0;
}

/**
* La función de evaluación calcula la puntuación de un estado determinado del tablero evaluando las filas, columnas,
* y diagonales para posibles movimientos ganadores y aplicando una función heurística.
*
* @param board El parámetro "board" es un puntero a un objeto de tipo "Tablero". representa el juego
* tablero en el que se está realizando la evaluación.
* @param numPlayer El parámetro `numPlayer` representa el número de jugador para quien se está calculando la puntuación.
* evaluado. Se utiliza en la función "heurística" para calcular la puntuación en función de la puntuación del jugador.
*perspectiva.
*
* @return una puntuación entera.
*/
int evaluate(Board* board, int numPlayer) {

    int score = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i, j + 1), board->getPosition(i, j + 2), board->getPosition(i, j + 3));
            score += heuristic(board->getPosition(i, j), numPlayer);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j), board->getPosition(i + 2, j), board->getPosition(i + 3, j));
            score += heuristic(board->getPosition(i, j), numPlayer);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j + 1), board->getPosition(i + 2, j + 2), board->getPosition(i + 3, j + 3));
            score += heuristic(board->getPosition(i, j), numPlayer);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            score += scoreEvaluate(board->getPosition(i, j), board->getPosition(i + 1, j - 1), board->getPosition(i + 2, j - 2), board->getPosition(i + 3, j - 3));
            score += heuristic(board->getPosition(i, j), numPlayer);
        }
    }

    return score;
}


/**
 * La función minimax es un algoritmo recursivo que evalúa el mejor movimiento para un estado de juego determinado mediante
 * considerando todos los movimientos posibles y sus resultados.
 *
 * @param board Un puntero al tablero de juego actual.
 * @param profundidad El parámetro de profundidad representa la profundidad actual del algoritmo minimax. Él
 * determina cuántos movimientos por delante considerará el algoritmo.
 * @param alpha El parámetro alfa es el mejor valor que el jugador maximizador puede garantizar en ese momento.
 * nivel o superior. Se utiliza para la poda alfa-beta, que es una técnica para reducir el número de
 * nodos que deben evaluarse en el algoritmo minimax.
 * @param beta El parámetro beta se utiliza en el algoritmo de poda alfa-beta. Representa el
 * puntuación mínima que el jugador maximizador tiene garantizado alcanzar. A medida que avanza el algoritmo, el
 * El valor beta se actualiza para que sea el mínimo del valor beta actual y las puntuaciones obtenidas del
 * nodos secundarios. Si en algún momento la beta
 * @param maxiPlayer Una variable booleana que indica si es el turno del jugador maximizador o no.
 * Si es cierto, significa que es el turno del jugador que maximiza, en caso contrario es el turno del jugador que minimiza
 * doblar.
 * @param id El parámetro "id" representa el ID del jugador. En este código, se utiliza para determinar qué
 * Es el turno del jugador. El valor 2 representa el jugador maximizador y el valor 1 representa el jugador maximizador.
 * reproductor minimizador.
 * @param poda Una variable booleana que indica si se debe utilizar la poda alfa-beta o no. Si
 * poda es verdadero, entonces se usa la poda alfa-beta; de lo contrario, no se usa.
 *
 * @return un valor entero.
 */
int minimax(Board* board, int depth, int alpha, int beta, bool maxiPlayer,int id,bool poda) {
    
    if (depth == 0) {
        return evaluate(board,id);
    }
    
    if (maxiPlayer) {
        int maxAct = INT_MIN;
        for (int column = 0; column < board->getCols(); column++)
        {
            if (!board->isColumnFull(column)) {
                Board* auxBoard = new Board(*board);
                auxBoard->addDisk(column,2);
                int rev = minimax(auxBoard,depth-1,alpha,beta,false,id,poda);
                maxAct = max(maxAct, rev);
                
                delete auxBoard;

                if (poda) {
                    alpha = max(alpha,rev);
                    if (beta <= alpha) {
                        break;
                    }   
                }
                break;
                
            }
            
        } 
        return maxAct;
    } else {
            int minEval = INT_MAX;
            for (int col = 0; col < 7; col++) {
                if (!board->isColumnFull(col)) {
                    Board* newBoard = new Board(*board);
                    newBoard->addDisk(col, 1);
                    int eval = minimax(newBoard, depth - 1, alpha, beta, true,id,poda);
                    minEval = min(minEval, eval);
                    
                    delete newBoard;

                    if (poda) {
                        beta = min(beta, eval);
                        if (beta <= alpha) {
                            break;
                        }   
                    }
                }
            }
            return minEval;  
    }
 
}


/**
  * La función `getBestMove` devuelve el mejor movimiento (número de columna) para un estado determinado del tablero usando el
  * algoritmo minimax con poda alfa-beta.
  *
  * @param board Un puntero al tablero de juego actual.
  * @param profundidad El parámetro de profundidad representa la profundidad actual del algoritmo minimax. Él
  * determina cuántos movimientos por delante considerará el algoritmo. Un valor de profundidad más alto significa que
  * El algoritmo considerará más movimientos por delante, pero también tardará más en calcularse.
  * @param id El parámetro "id" se utiliza para determinar a qué jugador le toca el turno. En este caso, parece
  * que el valor 2 se utiliza para representar el turno del jugador actual.
  * @param poda El parámetro "poda" es una variable booleana que indica si se utiliza o no
  * poda alfa-beta durante el algoritmo minimax. Si "poda" es cierto, se utilizará la poda alfa-beta
  * mejorar la eficiencia del algoritmo eliminando ramas innecesarias del árbol del juego. Si
  * "poda
  *
  * @return el mejor movimiento (número de columna) para el estado del tablero dado.
  */
int getBestMove(Board* board, int depth,int id,bool poda) {

    int bestMove = 1;
    int maxEval = INT_MIN;

    for (int colmn = 0; colmn < board->getCols(); colmn++) {
        if (!board->isColumnFull(colmn)) {
            Board* newBoard = new Board(*board);
            newBoard->addDisk(colmn, 2);
            int eval = minimax(newBoard, depth - 1, INT_MIN, INT_MAX, false,id,poda);

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
  * La función "playerVsCpu" permite a un jugador jugar contra un oponente de la computadora con una determinada
  * nivel de dificultad.
  *
  * @param dificultad El parámetro "dificultad" en la función "playerVsCpu" se utiliza para determinar la
  * nivel de dificultad para el jugador de la CPU. Es un valor entero que se puede pasar a la función para
  * especificar qué tan inteligente o desafiante debe ser el jugador de la CPU. El significado exacto y el alcance de la
  * "dificultad
  */
void playerVsCpu(int difficulty, bool poda) {

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
           

            while (col > 7 || col < 0 || !board->isColumnFull(col)) {

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
            auxBoard->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner())
            {
                currPlayer = player2->getDisk();
            }

        } else if (currPlayer == player2->getDisk()) {
            col = getBestMove(auxBoard,difficulty,player2->getDisk(),poda);
            cout<<col<<endl;
            board->addDisk(col,player2->getDisk());
            auxBoard->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner())
            {
                currPlayer = player1->getDisk();
            }

        }

    if (board->checkWinner()) {
        cout << "El jugador " << currPlayer << " ha ganado!" << endl;
    } else if (!board->checkWinner()) {
        cout << "El juego ha terminado en empate." << endl;
    }

    }

    delete player1;
    delete player2;
    delete board;
}

//CPU VS CPU CREA UN BUCLE, NO ALCANCE A ARREGLARLO :(
/**
  * La función `cpuVsCpu` simula un juego entre dos jugadores de CPU con dificultades específicas y
  * opciones de poda.
  *
  * @param dificultad1 El nivel de dificultad para la CPU 1. Determina qué tan inteligente es el jugador de la CPU.
  * haciendo sus movimientos.
  * @param dificultad2 El parámetro `dificultad2` representa el nivel de dificultad para la segunda CPU
  * jugador. Determina qué tan inteligente o estratégico será el segundo jugador de la CPU al realizar sus movimientos. El
  * Cuanto mayor sea el nivel de dificultad, más desafiante será jugar contra el segundo jugador de la CPU.
  * @param poda1 El parámetro "poda1" es una variable booleana que determina si se utiliza o no
  * Poda alfa-beta en el proceso de toma de decisiones de la CPU 1. Si "poda1" es verdadero, poda alfa-beta
  * se utilizará; si es falso no se utilizará la poda alfa-beta.
  * @param poda2 El parámetro "poda2" es una variable booleana que determina si se utiliza o no
  * Poda alfa-beta en el cálculo de movimientos del segundo jugador de la CPU. Si "poda2" es verdadero, alfa-beta
  *se utilizará poda; si es falso no se utilizará la poda alfa-beta.
  */
void cpuVsCpu(int difficulty1, int difficulty2, bool poda1, bool poda2) {
    Player* cpu1 = new Player(1);
    Player* cpu2 = new Player(2);
    Board* board = new Board();
    Board* auxBoard1 = new Board();
    Board* auxBoard2 = new Board();

    board->printBoard();

    int currPlayer = cpu1->getDisk();
    int col;

    while (!board->checkWinner()) {
        if (currPlayer == cpu1->getDisk()) {
            col = getBestMove(auxBoard1, difficulty1, cpu1->getDisk(), poda1);
            cout << "CPU1 selecciona la columna: " << col << endl;
            board->addDisk(col, cpu1->getDisk());
            auxBoard1->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner()) {
                currPlayer = cpu2->getDisk();
            }
        } else if (currPlayer == cpu2->getDisk()) {
            col = getBestMove(auxBoard2, difficulty2, cpu2->getDisk(), poda2);
            cout << "CPU2 selecciona la columna: " << col << endl;
            board->addDisk(col, cpu2->getDisk());
            auxBoard2->copyBoard(board);
            board->printBoard();
            if (!board->checkWinner()) {
                currPlayer = cpu1->getDisk();
            }
        }
    }

    if (board->checkWinner()) {
        cout << "El jugador " << currPlayer << " ha ganado!" << endl;
    } else if (!board->checkWinner()) {
        cout << "El juego ha terminado en empate." << endl;
    }

    delete cpu1;
    delete cpu2;
    delete board;
}


/**
  * La función `playerVsPlayer` permite que dos jugadores se turnen para agregar discos a un tablero hasta que
  * Se determina el ganador o el juego termina en empate.
  */
void playerVsPlayer() {
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

            while (col > 7 || col < 0 || !board->isColumnFull(col)) {
                if (!board->isColumnFull(col)) {
                    cout << "LA COLUMNA SE ENCUENTRA LLENA!!! SELECCIONE OTRA COLUMNA:" << endl;
                } else {
                    cout << "COLUMNA FUERA DE LOS MARGENES, INGRESE UNA COLUMNA VALIDA" << endl;
                }

                cout << "COLUMNA: " << endl;
                cin >> col;
            }

            board->addDisk(col, player1->getDisk());
            auxBoard->copyBoard(board);
            board->printBoard();

            if (!board->checkWinner()) {
                currPlayer = player2->getDisk();
            }

        } else if (currPlayer == player2->getDisk()) {
            cout << "COLUMNA: " << endl;
            cin >> col;

            while (col > 7 || col < 0 || !board->isColumnFull(col)) {
                if (!board->isColumnFull(col)) {
                    cout << "LA COLUMNA SE ENCUENTRA LLENA!!! SELECCIONE OTRA COLUMNA:" << endl;
                } else {
                    cout << "COLUMNA FUERA DE LOS MARGENES, INGRESE UNA COLUMNA VALIDA" << endl;
                }

                cout << "COLUMNA: " << endl;
                cin >> col;
            }

            board->addDisk(col, player2->getDisk());
            auxBoard->copyBoard(board);
            board->printBoard();

            if (!board->checkWinner()) {
                currPlayer = player1->getDisk();
            }
        }
    }

    if (board->checkWinner()) {
        cout << "El jugador " << currPlayer << " ha ganado!" << endl;
    } else if (!board->checkWinner()) {
        cout << "El juego ha terminado en empate." << endl;
    }
}


int main()
{

    int opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Jugar contra la IA" << endl;
    cout << "2. IA vs IA" << endl;
    cout << "3. Jugador contra Jugador" << endl;
    cin >> opcion;

    while (opcion < 0 || opcion > 3) {
        cout << "ERROR!!! OPCION INVALIDA" << "\n" << endl;
        cout << "Seleccione una opcion:" << endl;
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
                depth = 20;
                break;
            case 3:
                depth = 35;
                break;
            
            default:
                break;
            }

            int opPoda;
            cout << "Activar poda alfa-beta:" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << "Opcion:" << endl;
            cin >> opPoda;

            while (opPoda < 0 || opPoda > 2) {
                cout << "Activar poda alfa-beta:" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                cout << "Opcion:" << endl;
                cin >> opPoda;    
            }
            bool poda;
            switch (opPoda)
            {
            case 1:
                poda = true;
                break;

            case 2:
                poda = false;
                break;
            
            default:
                break;
            }

            playerVsCpu(depth,poda);
            break;
        case 2:

            cpuVsCpu(20,20,true,true);
            break;
        case 3:
            playerVsPlayer();
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
    }

    return 0;
} 