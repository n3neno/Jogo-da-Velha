#include<iostream>
#include<cstdlib> 
#include<ctime>  

int checar_repeticao(int linha, int coluna, char tabuleiro[3][3]){
    int resposta;
    if (tabuleiro[linha - 1][coluna - 1] != ' '){
        std::cout << "Este quadrado já foi preenchido! Tente novamente\n";
        resposta = 1;
    } else {
        std::cout << "Quadrado preenchido com sucesso!\n";
        resposta = 0;
    }
    return resposta;
}

void jogada1(int linha, int coluna, char tabuleiro[3][3]){
    tabuleiro[linha - 1][coluna - 1] = 'X';
}

void jogada2 (int linha, int coluna, char tabuleiro[3][3]){
    tabuleiro[linha - 1][coluna - 1] = 'O';
}

char checar_vitoria(char tabuleiro[3][3]){
    char vitoria = 'N';

   if (tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X') {
    vitoria = 'X';
   } else if (tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O') {
    vitoria = 'O';
    } else if (tabuleiro[2][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[0][2] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[2][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[0][2] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'){
    vitoria = 'O';
    } else if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
    vitoria = 'X';
    } else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
    vitoria = 'O';
    }
    
    return vitoria;
}

void desenharTabuleiro(char tabuleiro[3][3]) {
    std::cout << "\n";
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            std::cout << " " << tabuleiro[linha][coluna] << " ";
            if (coluna < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n"; 
        if (linha < 2) {
            std::cout << "---|---|---\n";
        }
    }
    std::cout << "\n";
}

int main(){
    srand(time(NULL)); 
    
    int resposta, continuar;
    int contador_jogadas = 0;
    char jogo[3][3];

    std::cout << "--========JOGO DA VELHA========--\n";
    int jogada_sucesso = 0;
    
    do{
        contador_jogadas = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                jogo[i][j] = ' ';
            }
        }
        
        do{
            std::cout << "Voce deseja jogar com a maquina ou com um amigo ? [0 - Maquina // 1 - Amigo]\n";
            if (std::cin >> resposta && (resposta == 1 || resposta == 0)){
                break; 
            } else {
                std::cout << "Valor invalido!\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        } while (true);

        int linha = 0, coluna = 0;

        
        while(contador_jogadas < 9 && checar_vitoria(jogo) == 'N'){
            desenharTabuleiro(jogo);
            
            char jogador_atual;
            if (contador_jogadas % 2 == 0){
                jogador_atual = 'X';
            } else {
                jogador_atual = 'O';
            }
            
            jogada_sucesso = 0;
            do{
                std::cout << "JOGADOR " << jogador_atual << std::endl;
                
                
                if (jogador_atual == 'X' || (jogador_atual == 'O' && resposta == 1)) {
                    
                    std::cout << "Voce deve especificar o numero da linha e da coluna onde voce deseja fazer a jogada.\n";
                    while(true){
                        std::cout << "Linha: \n";
                        if (std::cin >> linha && (linha >= 1 && linha <= 3)){ 
                            break; 
                        } else {
                            std::cout << "Linha invalida, digite uma linha valida\n";
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                        }
                    }
                
                    while(true){
                        std::cout << "Coluna: \n";
                        if (std::cin >> coluna && (coluna >= 1 && coluna <= 3)){
                            break;
                        } else {
                            std::cout << "Coluna invalida, digite uma coluna valida\n";
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                        }
                    }
                } else {
                    
                    std::cout << "A maquina esta pensando...\n";
                    linha = (rand() % 3) + 1; 
                    coluna = (rand() % 3) + 1; 
                }

                
                if (checar_repeticao(linha,coluna,jogo) == 0){
                    jogada_sucesso = 1;
                    if (jogador_atual == 'X'){
                        jogada1(linha, coluna, jogo);
                    } else {
                        jogada2(linha,coluna, jogo);
                        
                        if (resposta == 0) {
                            std::cout << "=> A MAQUINA jogou na Linha " << linha << ", Coluna " << coluna << "!\n";
                        }
                    }
                    contador_jogadas++;
                } 
                
                
            } while (jogada_sucesso == 0);
        }
        
        char resultado = checar_vitoria(jogo);
        desenharTabuleiro(jogo); 
        
        if (resultado == 'X') {
            std::cout << "\n PARABENS! O Jogador X VENCEU! \n\n";
        } else if (resultado == 'O') {
            if (resposta == 0) {
                std::cout << "\n GAME OVER! A Maquina VENCEU! \n\n";
            } else {
                std::cout << "\n PARABENS! O Jogador O VENCEU! \n\n";
            }
        } else {
            std::cout << "\n DEU VELHA! O jogo empatou! \n\n";
        }

        do {
            std::cout << "Deseja jogar outra partida ? [0 - Sim // 1 - Nao]\n";
            if (std::cin >> continuar && (continuar == 1 || continuar == 0)){
                break;
            } else {
                std::cout << "Valor invalido!\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        } while (true);
        
    } while (continuar == 0);
    
    return 0;
}