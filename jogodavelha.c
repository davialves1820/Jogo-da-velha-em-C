#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//JOGO DA VELHA


void preencher_jogo(char jogo[][3]) { // inicializar cada posição da matriz com espaço em branco
    for (int i = 0;i < 3; i++) {
        for(int j = 0;j < 3; j++) {
            jogo[i][j] = ' ';
        }
    }
}

void imprimir_jogo(char jogo[][3]) { // exibe o jogo para o usuario
    
    printf("\ncolunas\t  0  1   2\tlinhas\n\n");

    for (int i = 0;i < 3; i++){

        printf("\t");

        for (int j = 0;j < 3; j++) {
            printf(" %c ",jogo[i][j]);
            if(j < 2)
                printf("|");
            if(j == 2)
                printf("\t%d",i);
        }
        if (i < 2)
            printf("\n\t------------\n");
        else
            printf("\n\n");
    }
}

int jogada_valida(int linha,int coluna,char jogo[][3]) { // verifica se a jogada é valida
    // analisa se as coordenas são validas e se o campo ja esta preenchido
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ') {
        return 1; // retorna 1 se invalida
    }
    else
        return 0; // retorna 0 se for valida
}

void jogada(char jogo[][3],char c) { // função para realizar jogada

    int i,j;

    printf("digite a linha e coluna que voce quer jogar(nessa ordem): ");
    scanf("%d %d",&i, &j);

    while (jogada_valida(i,j,jogo) == 1) { // looping so acaba quando a jogada for valida
        printf("COORDENADA INVALIDA! tente novamente ;-;\n");
        scanf("%d %d",&i, &j);
    }
    jogo[i][j] = c; // preenche o campo com a letra do jogador
}

int vitoria_linha(int i,char jogo[][3],char c) { // verifica vitoria em um linha, tem como parametro o numero da linha
    if (jogo[i][0] == c && jogo[i][1] == c && jogo[i][2] == c)
        return 1;
    else    
        return 0;
}

int vitoria_linhas(char jogo[][3],char c) { // verifica vitoria em todas as linhas
    int soma = 0;
    for (int i = 0;i < 3; i++) {
        soma += vitoria_linha(i,jogo, c); // passa o numero da linha para verificar se ocorreu vitoria
    }
    return soma;
}

int vitoria_coluna(int i,char jogo[][3],char c) { // verifica vitoria em uma coluna, tem como parametro o numero da coluna
    if (jogo[0][i] == c && jogo[1][i] == c && jogo[2][i] == c)
        return 1;
    else    
        return 0;
}

int vitoria_colunas(char jogo[][3],char c) { // verifica vitoria em todas as colunas
    int soma = 0;
    for(int i = 0;i < 3; i++){
        soma += vitoria_coluna(i,jogo, c); // passa o numero da coluna para verificar se ocorreu vitoria
    }
    return soma;
}

int vitoria_diagonalP(char jogo[][3],char c) { // verifica vitoria na diagonal principal
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

int vitoria_diagonalS(char jogo[][3],char c) { // verifica vitoria na diagonal secundaria
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

int vitoria_geral(char jogo[][3], char c) { // verifica se o jogador ganhou o jogo
    int vitoria = vitoria_colunas(jogo, c) + vitoria_linhas(jogo, c) + vitoria_diagonalP(jogo, c) + vitoria_diagonalS(jogo, c);
    return vitoria;
}

void gameplay() { // função que executa o jogo
    int again;
    do{

    char jgX = 'X', jgO = 'O', jogo[3][3];
    int jogadas = 0, jogador = 0, vx = 0, vo = 0;
    preencher_jogo(jogo); // inicia o jogo

    do {
        imprimir_jogo(jogo);
        if (jogador == 0) { // verifica de quem é a vez de jogar, se jogador = 0 é o jogador X, caso contrario jogador O
            jogada(jogo, jgX);
            jogador++;
            vx = vitoria_geral(jogo, jgX);
        }
        else {
            jogada(jogo, jgO);
            jogador--;
            vo = vitoria_geral(jogo, jgO);
        }
        jogadas++;

    } while (jogadas < 9 && vx == 0 && vo == 0); // enquanto não forem preenchidos todos os espaços da matriz ou quando um dos jogadores não tiver ganho
    
    imprimir_jogo(jogo); // exibe a situação do jogo após o fim
    
    if (jogadas == 9) // caso do empate
        printf("JOGO TERMINOU EMPATADO");
    else if (vx != 0) { // vitoria do X
        printf("PARABENS JOGADOR X :)"); 
    }
    else // vitoria do O
        printf("PARABENS JOGADOR O :)");
    do { // verificar se os jogadores querem jogar de novo
    printf("\n1- jogar novamente :)\n0- ir embora :(\n");
    scanf("%d",&again);
    } while (again > 1 || again < 0);

    } while (again == 1);
    printf("\n ;-_-;");
}

int main(){
    gameplay(); // execução do jogo
}
