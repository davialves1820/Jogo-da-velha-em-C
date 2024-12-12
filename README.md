# 🎮 Jogo da Velha em C

Este é um simples **Jogo da Velha** (ou Tic-Tac-Toe) implementado em C. Dois jogadores se alternam para preencher o tabuleiro até que um vença ou o jogo termine em empate.

---

## 📋 Regras do Jogo

1. O tabuleiro é uma matriz 3x3.
2. Os jogadores se alternam para fazer suas jogadas:
   - Jogador **X**
   - Jogador **O**
3. Um jogador vence ao alinhar 3 símbolos iguais em:
   - Uma **linha**
   - Uma **coluna**
   - Ou uma das **diagonais**
4. Se todas as posições forem preenchidas e nenhum jogador vencer, o jogo termina em **empate**.

---

## 🎮 Como Jogar

Quando o jogo começar, o tabuleiro será exibido com coordenadas para as linhas e colunas:

```
colunas     0   1   2       linhas

             |   |           0
         ------------
             |   |           1
         ------------
             |   |           2
```
O jogador da vez deve digitar a linha e a coluna onde deseja jogar. Exemplo:

```
digite a linha e coluna que voce quer jogar(nessa ordem): 1 1
```
O tabuleiro será atualizado automaticamente após cada jogada.

O jogo termina quando:
- Um dos jogadores vencer.
- Todas as posições forem preenchidas (empate).

---

## ✨ Recursos Implementados
- Inicialização do tabuleiro vazio.
- Verificação de jogadas válidas.
- Identificação de vitória em:
- Linhas
- Colunas
- Diagonais
- Detecção de empate.
- Opção para jogar novamente após o término do jogo.

---

## 🎮 Demonstração

```
colunas     0   1   2       linhas

                |   |           0
            ------------
                |   |           1
            ------------
                |   |           2
```
Após algumas jogadas
```
colunas     0   1   2       linhas

            X |   |  O        0
            ------------
            O | X |           1
            ------------
              |   | X         2
```
Resultado final
```
PARABENS JOGADOR X :)
```
---

## 🖥️ Estrutura do Código
- preencher_jogo: Inicializa o tabuleiro.
- imprimir_jogo: Exibe o estado atual do tabuleiro.
- jogada_valida: Verifica se a jogada é válida.
- jogada: Realiza a jogada no tabuleiro.
- vitoria_linha, vitoria_coluna, vitoria_diagonal: Verificam condições de vitória.
- gameplay: Controla a lógica principal do jogo.
