#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    // Matrizes e variaveis
    int sudokuMain[9][9] = {{8,5,3,4,9,1,7,6,2},
                            {1,9,6,7,8,2,4,5,3},
                            {7,4,2,6,5,3,1,9,8},
                            {9,3,1,2,4,8,6,7,5},
                            {5,8,4,3,6,7,2,1,9},
                            {6,2,7,5,1,9,3,8,4},
                            {4,1,9,8,2,6,5,3,7},
                            {2,7,8,1,3,5,9,4,6},
                            {3,6,5,9,7,4,8,2,1}};
    int sudokuGabarito[9][9];
    int sudokuGame[9][9];

    string difficultyChoices[3] = {"Facil", "Medio", "Dificil"}; 
    float difficultyChoicesPercentage[3] = {0.5, 0.35, 0.15}; 
    //Criação do loop de jogo e menu
    bool gameRunning = true;
    int difficultyChoice = 2;
    int tipoDeRandomizacao;
    int linhaJogada;
    int colunaJogada;
    int valorJogada;
    bool jogoRodando;
    int casasPreenchidas;
    int linhaRandom;
    int colunaRandom;
    // Contador das jogadas( totais e validas)
    int movimentosTotais;
    int movimentosValidos;


    while(gameRunning){
        srand(time(nullptr));
        //Menu (Jogar, Dificuldade, Sobre, Sair)
        cout << endl;
        cout << "Bem vindo ao Sudoku!" << endl;
        cout << "Dificuldade: " << difficultyChoices[difficultyChoice-1] << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Dificuldade" << endl;
        cout << "3 - Sobre" << endl;
        cout << "4 - Sair" << endl;
        cout << "Digite sua escolha: ";
        int menuChoice = 0;
        cin >> menuChoice;
        while(menuChoice < 1 || menuChoice > 4){
            // .good() checa se a string é de um dtype esperado como int(caso ao contrario ele retorna false)
            // .clear() limpa os erros no input
            // .ignore() ignora o input com o dype invalido, armazenando a input em outro buffer
            if(!cin.good()){
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Opcao invalida! Digite novamente: ";
            cin >> menuChoice;
        }
        cout << endl;
        system("cls");
        switch(menuChoice){

            case 1:
                // Contador das jogadas( totais e validas)
                movimentosTotais = 0;
                movimentosValidos = 0;
                tipoDeRandomizacao = rand() % 3;
                switch(tipoDeRandomizacao){
                    case 0:
                        //Invertida por linha
                        for(int i = 0; i < 9; i++){
                            for(int j = 0; j < 9; j++){
                                sudokuGabarito[i][j] = sudokuMain[i][8-j];
                            }
                        }
                        break;
                    case 1:
                        //Invertida por coluna
                        for(int i = 0; i < 9; i++){
                            for(int j = 0; j < 9; j++){
                                sudokuGabarito[i][j] = sudokuMain[8-i][j];
                            }
                        }
                        break;
                    case 2:
                        //Transposta
                        for(int i = 0; i < 9; i++){
                            for(int j = 0; j < 9; j++){
                                sudokuGabarito[i][j] = sudokuMain[j][i];
                            }
                        }
                        break;
                    case 3:
                        //Sem alteração
                        for(int i = 0; i < 9; i++){
                            for(int j = 0; j < 9; j++){
                                sudokuGabarito[i][j] = sudokuMain[i][j];
                            }
                        }
                        break;
                }
                //Criação da matriz de jogo (com base na dificuldade)
                //Facil: 50% das casas preenchidas
                //Medio: 35% das casas preenchidas
                //Dificil: 15% das casas preenchidas
                casasPreenchidas = 0;
                casasPreenchidas = 81 * difficultyChoicesPercentage[difficultyChoice-1]; //Por ser int, o valor é arredondado para baixo (truncado)
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 9; j++){
                        sudokuGame[i][j] = 0;
                    }
                }


                
                //Preenchimento da matriz de jogo

                while(casasPreenchidas > 0){
                    linhaRandom = rand() % 9;
                    colunaRandom = rand() % 9;
                    if(sudokuGame[linhaRandom][colunaRandom] == 0){
                        sudokuGame[linhaRandom][colunaRandom] = sudokuGabarito[linhaRandom][colunaRandom];
                        casasPreenchidas--;
                    }
                }


                //Loop de jogo
                jogoRodando = true;
                while(jogoRodando){


                    //Apresentação do jogo
                    cout << "Sudoku:" << endl;
                    //Apresentação da matriz de jogo, com bordas e separadores, e indices de linha e coluna e cores
                    cout << "  ";
                    //Indices de coluna
                    for(int i = 0; i < 9; i++){
                        if(i == 3 || i == 6){
                            cout << "|";
                        }
                        cout << i+1 << " ";
                    }
                    cout << endl;
                    cout << "  ";
                    for(int i = 0; i < 9; i++){
                        if(i == 3 || i == 6){
                            cout << "|";
                        }
                        cout << "- ";
                    }
                    cout << endl;
                    //Matriz de jogo
                    for(int i = 0; i < 9; i++){
                        //Indices de linha
                        if(i == 3 || i == 6){
                            //Separador de bloco
                            cout << "  ";
                            for(int j = 0; j < 9; j++){
                                if(j == 3 || j == 6){
                                    cout << "|";
                                }
                                cout << "- ";
                            }
                            cout << endl;
                        }
                        cout << i+1 << "|";
                        //Matriz de jogo
                        for(int j = 0; j < 9; j++){
                            //Separador de bloco
                            if(j == 3 || j == 6){
                                cout << "|";
                            }
                            // '\033' usada para marcar o inicio da seq
                            // '1' é o texto em bold
                            // '31m' indica o codigo para cor vermelha
                            // '\033[0m' finaliza a seq e exclui as alteraçoes feitas para nao interferir nos proximos textos
                            if(sudokuGame[i][j] == 0){
                                cout << "\033[1;31m" << sudokuGame[i][j] << "\033[0m ";
                            }else{
                                cout << "\033[1;32m" << sudokuGame[i][j] << "\033[0m ";
                            }
                        }
                        cout << endl;
                    }
                    cout << endl;

                    //Jogada
                    //Para sair do jogo, digite 0 0 0
                    cout << "Para sair do jogo, digite 0 0 0" << endl;
                    cout << "Digite a linha, coluna e valor da jogada (1-9): ";
                    linhaJogada = -1;
                    colunaJogada = -1;
                    valorJogada = -1;
                    cin >> linhaJogada >> colunaJogada >> valorJogada;
                    movimentosTotais++; // conta os movimentos totais
                    while(linhaJogada < 1 || linhaJogada > 9 || colunaJogada < 1 || colunaJogada > 9 || valorJogada < 1 || valorJogada > 9){
                        if(!cin.good()){
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }

                        if(linhaJogada == 0 && colunaJogada == 0 && valorJogada == 0)break;

                        cout << "Jogada invalida! Digite novamente: ";
                        cin >> linhaJogada >> colunaJogada >> valorJogada;
                    }
                    if(linhaJogada == 0 && colunaJogada == 0 && valorJogada == 0){
                        jogoRodando = false;
                        break;
                    }
                    system("cls");
                    //Verificação da jogada
                    if(sudokuGame[linhaJogada-1][colunaJogada-1] == 0){
                        if(sudokuGabarito[linhaJogada-1][colunaJogada-1] == valorJogada){
                            sudokuGame[linhaJogada-1][colunaJogada-1] = valorJogada;
                            cout << "Jogada valida!" << endl;
                            movimentosValidos++; // contador dos movimentos validos
                        }else{
                            cout << "Jogada invalida!" << endl;
                        }
                    }else{
                        cout << "Jogada invalida!" << endl;
                    }
                    //Verificação de vitória
                    bool vitoria = true;
                    for(int i = 0; i < 9; i++){
                        for(int j = 0; j < 9; j++){
                            if(sudokuGame[i][j] != sudokuGabarito[i][j]){
                                vitoria = false;
                            }
                        }
                    }
                    if(vitoria){
                        cout << "Parabens, voce venceu!" << endl;
                        cout<< "De " << movimentosTotais << " jogadas totais, " << movimentosValidos << " foram validas " << endl;
                        cout<< "Dificuldade: " << difficultyChoices[difficultyChoice-1] << endl;
                        jogoRodando = false;
                    }
                }
                break;
            case 2:
                cout << "Dificuldade\n";
                //Fácil, Médio, Difícil
                cout << "1 - Facil\n";
                cout << "2 - Medio\n" ;
                cout << "3 - Dificil\n";
                cout << "Digite sua escolha: ";
                cin >> difficultyChoice;
                while(difficultyChoice < 1 || difficultyChoice > 3){
                    if(!cin.good()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Opcao invalida! Digite novamente: ";
                    cin >> difficultyChoice;
                }
                break;
            case 3:
                cout << "Sobre:" << endl;
                //Equipe de desenvolvimento, mes ano, professor, disciplina
                cout << "Equipe de desenvolvimento: Lucas Losekann Rosa, Ian Callegari Aragao, Bryan Jardim Morais " << endl;
                cout << "Mes/Ano: Junho de 2023" << endl;
                cout << "Professora: Cristina Ono Horita" << endl;
                cout << "Disciplina: Algoritmos e Programacao" << endl;
                break;
            case 4:
                cout << "Obrigado por jogar!" << endl;
                gameRunning = false;
                break;
        }
        
    }

    return 0;
}
