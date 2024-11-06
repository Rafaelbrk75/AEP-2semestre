#include <stdio.h>
#include <conio.h>  // Para getch()
#include <stdlib.h> // Para system("cls")

int main() {
    int option = 1;  // Op��o inicial
    int key;

    while (1) {
        // Limpa a tela
        system("cls");

        // Mostra o menu, destacando a op��o selecionada
        printf("Use as setas para navegar e Enter para selecionar:\n\n");

        printf("%s 1 - Adicionar\n", option == 1 ? "->" : "  ");
        printf("%s 2 - Listar\n", option == 2 ? "->" : "  ");
        printf("%s 3 - Cr�ditos\n", option == 3 ? "->" : "  ");
        printf("%s 4 - Remover\n", option == 4 ? "->" : "  ");
        printf("%s 5 - Pesquisar\n", option == 5 ? "->" : "  ");
        printf("%s 6 - Sair\n", option == 6 ? "->" : "  ");

        // Captura a entrada do teclado
        key = getch();

        // Detecta as setas do teclado
        if (key == 224) {  
            key = getch(); 
            if (key == 72) {   
                option--;
                if (option < 1) option = 6;  
            } else if (key == 80) {  
                option++;
                if (option > 6) option = 1;  
            }
        } else if (key == 13) {  
            
            switch (option) {
                case 1:
                    printf("\nOp��o Adicionar selecionada\n");
                    break;
                case 2:
                    printf("\nOp��o Listar selecionada\n");
                    break;
                case 3:
                    printf("\nOp��o Cr�ditos selecionada\n");
                    break;
                case 4:
                    printf("\nOp��o Remover selecionada\n");
                    break;
                case 5:
                    printf("\nOp��o Pesquisar selecionada\n");
                    break;
                case 6:
                    printf("\nSaindo...\n");
                    return 0;
            }
            // Pausa para o usu�rio ver a mensagem antes de voltar ao menu
            printf("Pressione qualquer tecla para continuar...\n");
            getch();
        }
    }

    return 0;
}

