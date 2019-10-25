#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define clean_Input() fflush(stdin)
#define clean_Tela() system("cls")

void printarJogo() {
    printf("                   ___              _   \n");
    printf("      /  _    _/_ (_   _ _ _   /   / /  \n");
    printf("   (_/()(/() (/(/ / ()/ ( (/  / . /_/   \n");
    printf("       _/                             \n\n");
}

void printarInicio() {
    printf("  ..__________________________________..  \n");
    printf("  ||           O P Ç Õ E S            ||  \n");
    printf("  ||                                  ||  \n");
    printf("  ||  1. DEFINIR PALAVRA E JOGAR      ||  \n");
    printf("  ||                                  ||  \n");
    printf("  ||  2. JOGAR COM PALAVRA ALEATÓRIA  ||  \n");
    printf("  ||                                  ||  \n");
    printf("  ||  3. SAIR DO JOGO                 ||  \n");
    printf("  ||                                  ||  \n");
    printf("  ||__________________________________||  \n");
    printf("  \\\\__________________________________//  \n");
    printf("             INSERIR OPÇÃO: ");
}

// Função que printa a forca de acordo com o num. de erros
void printarForca(int erros) {
    switch (erros) {
        case 0:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /                    \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 1:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||                \\/                  \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 2:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||           .____\\/                  \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 3:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||           .____\\/____.             \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 4:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||           .____\\/____.             \n");
            printf("  ||                ||                   \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 5:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||           .____\\/____.             \n");
            printf("  ||                ||                   \n");
            printf("  ||                /                    \n");
            printf("  ||               /                     \n");
            printf("  ||             ./                      \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
        case 6:
            clean_Tela();
            printarJogo();
            printf("  ..__________________                   \n");
            printf("  ||                 /                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||           .____\\/____.             \n");
            printf("  ||                ||                   \n");
            printf("  ||                /\\                  \n");
            printf("  ||               /  \\                 \n");
            printf("  ||             ./    \\.               \n");
            printf("  ||                                     \n");
            printf(" _||___                                  \n");
            printf("|_||___|                               \n\n");
            break;
    }
}

int main(void) {
    system("color 1F");
    setlocale(LC_ALL, "portuguese");
    int randomizer, erros, op_Inicio, num_LetrasCorretas = 0, k = 0;
    char op_Continuar, letra_Digitada,
        letras_aPreencher[25] = {""}, letras_Incorretas[6] = {""},
        palavra_Selecionada[25] = {""},
        palavras_Forca[15][25] = {
            "BANANA", "ABACAXI", "ACEROLA", "MORANGO", "GOIABA",
            "JABUTICABA", "MEXIRICA", "ABACATE", "FRAMBOESA", "KIWI",
            "CACAU", "MANGA", "AMORA", "UVA", "CAJU"};

    do {
        // Reset de variáveis
        k = 0;      // Variável contadora da variável letras_Incorretas
        erros = 0;  // Variável contadora de erros
        op_Continuar =
            false;  // Variável p/ guardar a opção de continuar ou não a jogar
        memset(letras_aPreencher, 0,
               sizeof letras_aPreencher);  // Variável que contém os espaços a
                                           // preencher c/ letras corretas digitadas
        memset(letras_Incorretas, 0,
               sizeof letras_Incorretas);  // Variável que guarda as letras
                                           // incorretas digitadas
        num_LetrasCorretas = 0;            // Variável contadora de letras corretas, se bater
                                           // com o tamanho da palavra, vence o jogo
        op_Inicio = 0;                     // Variável p/ seleção de modo de jogo (palavra randômica ou
                                           // definida pelo usuário)

        // Escolha de palavra ou aleatória p/ jogar
        while (op_Inicio != 1 && op_Inicio != 2 && op_Inicio != 3) {
            clean_Tela();
            printarJogo();
            printarInicio();
            clean_Input();
            scanf("%d", &op_Inicio);
            if (op_Inicio == 1) {
                int teste = 0;
                // Esse looping impede que o usuário coloque números ao invés de uma
                // palavra
                do {
                    if (teste != 0) {
                        printf(
                            "\n  Insira somente letras!\n  Insira novamente a palavra "
                            "desejada: ");
                    } else {
                        printf("\n  Insira a palavra desejada: ");
                    }
                    teste = 0;
                    clean_Input();
                    gets(palavra_Selecionada);
                    for (int i = 0; i < strlen(palavra_Selecionada); i++) {
                        palavra_Selecionada[i] = toupper(palavra_Selecionada[i]);
                        if (isdigit(palavra_Selecionada[i])) {
                            teste++;
                        }
                    }
                } while (teste != 0);
            } else if (op_Inicio == 2) {
                // Randomização da palavra
                srand(time(NULL));
                randomizer = rand() % 14;
                for (int i = 0; i < 25; i++) {
                    palavra_Selecionada[i] = palavras_Forca[randomizer][i];
                }
            } else if (op_Inicio == 3) {
                exit(0);
            } else {
                printf("\n  Opção inexistente, selecione uma válida!");
                Sleep(1000);
            }
        }
        for (int i = 0; i < strlen(palavra_Selecionada); i++) {
            letras_aPreencher[i] = '_';
            // Caça espaço e pontuações
            if (isspace(palavra_Selecionada[i]) != 0) {
                letras_aPreencher[i] = ' ';
                num_LetrasCorretas++;
            }
            if (ispunct(palavra_Selecionada[i]) != 0) {
                letras_aPreencher[i] = '-';
                num_LetrasCorretas++;
            }
        }
        // Começar jogo
        do {
            int sinal_Verde = 0;
            printarForca(erros);
            clean_Input();
            // Setar campo da palavra, erros e escolher letra
            for (int i = 0; i <= strlen(letras_aPreencher); i++) {
                printf("%-2c", letras_aPreencher[i]);
            }
            printf("\n\nErros: %d - %s\nVidas: %d", erros, letras_Incorretas,
                   (erros - 6) * (-1));
            printf("\nInsira uma letra: ");
            scanf("%c", &letra_Digitada);
            // Verifica se é um caractere alfabético
            if (isalpha(letra_Digitada) != 0) {
                clean_Input();
                /* Se a letra digitada for correta, preenche o espaço com a letra "_",
        soma ponto e ativa o sinal verde que será usado p/ verificar erros */
                for (int i = 0; i <= strlen(palavra_Selecionada); i++) {
                    if (toupper(letra_Digitada) == palavra_Selecionada[i]) {
                        if (letras_aPreencher[i] == toupper(letra_Digitada)) {
                            // Esse if evita contabilizar uma letra correta já digitada
                            sinal_Verde = 1;
                        } else {
                            letras_aPreencher[i] = toupper(letra_Digitada);
                            num_LetrasCorretas++;
                            sinal_Verde = 1;
                        }
                    }
                }
                /* Caso o sinal_Verde não seja 1, somar +1 a 'erros' e atribuir
        para a variável 'letras_Incorretas' o valor de 'letra_Digitada' */
                if (sinal_Verde != 1) {
                    erros++;
                    letras_Incorretas[k] = toupper(letra_Digitada);
                    k++;
                }
                // Printar tudo novamente para não deixar de mostrar a última letra/erro
                printarForca(erros);
                for (int i = 0; i <= strlen(letras_aPreencher); i++) {
                    printf("%-2c", letras_aPreencher[i]);
                }
                printf("\n\nErros: %d - %s\nVidas: %d", erros, letras_Incorretas,
                       (erros - 6) * (-1));
            } else {
                printf("\nDigite somente letras!");
                Sleep(750);
            }
            // Se uma das duas condições forem falsas, sai do while
        } while ((erros != 6) &&
                 (num_LetrasCorretas != strlen(palavra_Selecionada)));
        /* Aguarda 1 seg. antes de limpar a tela p/ permitir o jogador saber o que
    errou ou a palavra formada e depois apresentar a mensagem que correspondente
    a perder ou a ganhar dependendo da condição que se cumpriu */
        Sleep(1000);
        if (num_LetrasCorretas == strlen(palavra_Selecionada)) {
            printarForca(erros);
            printf("PARABÉNS, VOCÊ VENCEU!");
        } else {
            printarForca(erros);
            printf("TRISTE, VOCÊ PERDEU!\nPALAVRA CORRETA: %s", palavra_Selecionada);
        }
        printf("\n\nDESEJA JOGAR NOVAMENTE (S/N)? Resposta: ");
        scanf("%c", &op_Continuar);
        // Enquanto for diferente de 'S' ou 'N', pede para inserir de novo
        while (toupper(op_Continuar) != 'S' && toupper(op_Continuar) != 'N') {
            printf("\n\nOPÇÃO INVÁLIDA! DIGITAR NOVAMENTE (S/N)! Resposta: ");
            clean_Input();
            scanf("%c", &op_Continuar);
        }
    } while (toupper(op_Continuar) == 'S');
}
