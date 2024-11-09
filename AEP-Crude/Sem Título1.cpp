#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <cstdlib>  
#include <conio.h>

FILE *pont_arq;

int totuser=0;
char nome[100][18]; 
char senha[100][18];

int verificaSenha(char sen[70]);
int armazena(char nome1[70], char senha2[70]);
void adicionar();
void cripto(char x[70]);
void descripto(char nomeC[]);
void leitura();



int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int key, fim, cadastro, op = 1;
	fim = 0;
	
	do{
		system("cls");
		
		printf("\n\n\n");
        printf("\n                                         ___  ___    _____  __   __     ___  ___  __ \n");
        printf("                                       /  |  /  /   /   _____/  /  | /  /  /  / /  / \n");
        printf("                                      /  /|_/  /   /  ___/     /   |/  /  /  / /  / \n");
        printf("                                     /  /  /  /   /  /____    /  /|   /  /  /_/  / \n");
        printf("                                    /__/  /__/   / ______/   /_ / |_ /   \_____  / \n");
        printf("\n\n\n\n");                                
		
		
		printf("                                               %s 1 - ADICIONAR\n", op == 1 ? "->" : "  ");
        printf("                                               %s 2 - LISTAR\n", op == 2 ? "->" : "  ");
        printf("                                               %s 3 - ALTERAR\n", op == 3 ? "->" : "  ");
        printf("                                               %s 4 - REMOVER\n", op == 4 ? "->" : "  ");
        printf("                                               %s 5 - CR�DITOS\n", op == 5 ? "->" : "  ");
        printf("                                               %s 6 - SAIR\n", op == 6 ? "->" : "  ");
        
        key = getch();
	    
	    if (key == 224) {  
            key = getch(); 
            if (key == 72) {   
                op--;
                if (op < 1) op = 6;  
            } else if (key == 80) {  
                op++;
                if (op > 6) op = 1;  
            }
        } else if (key == 13) {
        	system("cls");
        	switch(op){
		        case 1:
		    	    system("cls");
		    	    adicionar();
		    	    
		        break;
		
		        case 2:
		    	    system("cls");
		    	    leitura();
		    	    
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 3:
		    	    system("cls");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 4:
		    	    system("cls");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 5:
		    	    system("cls");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		    
		        case 6:
		    	    system("cls");
		    	    printf("\n\n\n\n");
		    	    printf("            ������� �� ���    ��  �����  ��      �� �������  �����  ���    �� ������   ������ \n");
                    printf("            ��      �� ����   �� ��   �� ��      ��    ���  ��   �� ����   �� ��   �� ��    ��\n");
                    printf("            �����   �� �� ��  �� ������� ��      ��   ���   ������� �� ��  �� ��   �� ��    ��\n");
                    printf("            ��      �� ��  �� �� ��   �� ��      ��  ���    ��   �� ��  �� �� ��   �� ��    ��\n");
                    printf("            ��      �� ��   ���� ��   �� ������� �� ������� ��   �� ��   ���� ������   ������\n");
                    printf("            +-+     +-++-+  +---++-+  +-++------++-++------++-+  +-++-+  +---++-----+  +-----+ \n");                                                                                                                                                                                                                    
            		
					fim = 1;           
				break;
		
		        default:
		    	    printf("Op��o invalida!!!");
		    	    getch();
		        break;
	        }
		}      
	}while(fim != 1);
	
	return 0;
}

void adicionar(){
	int i,teste,cadastro;
		
	printf("Informe seu nome: ");
	fgets(nome[totuser], sizeof(nome[totuser]), stdin);
	nome[totuser][strcspn(nome[totuser], "\n")] = '\0';
		    	    
	do{
		printf("Informe uma senha (forte!): ");
		fgets(senha[totuser], sizeof(senha[totuser]), stdin);
		senha[totuser][strcspn(senha[totuser], "\n")] = '\0';
		teste = verificaSenha(senha[totuser]);
		if (teste == 0) printf("Senha fraca! Tente novamente.\n");
	}while(teste != 1);
	
	cripto(nome[totuser]); 
	cripto(senha[totuser]);
		    	    
	cadastro = armazena(nome[totuser], senha[totuser]);
		    	    
	if(cadastro == 1){
	    printf("\nCadastro conclu�do! Pressione qualquer tecla para sair...\n");
	    totuser++;
		getch();

	}
}

int verificaSenha(char sen[70]){
	int temMai, temMin, temN, temE;
	int i;
	temMai =0;
	temMin =0;
	temN = 0;
	temE = 0;
	
	if(strlen(sen) < 8){
		return 0;
	}
	
	for(i = 0; i < strlen(sen); i++){
		if(int(sen[i]) >= 48 && int(sen[i]) <= 57){
			temN = 1;
		}else if(int(sen[i]) >= 65 && int(sen[i]) <= 90){
			temMai = 1; 
		}else if(int(sen[i]) >= 97 && int(sen[i]) <= 122){
			temMin = 1;
		}else {
			temE = 1;
		}
	}
	
	if(temMin && temMai && temN && temE){
		return 1;
	}else{
		return 0;
	}
}

int armazena(char nome1[70], char senha2[70]){
	pont_arq = fopen("DadosDoUsuario.txt", "a+");
	
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 0;
	}else{
		fprintf(pont_arq, "%s\n", nome1);
		fprintf(pont_arq, "%s\n", senha2);
		
		fclose(pont_arq);
		
		return 1;
	}
}

void cripto(char x[70]){
	int i,j;
	char tmp;
	int len = strlen(x);
	
	j=0;
	
	for(i=0; i < len; i++){
		x[i] += 3;
	}
	
	for(i = 0, j = len-1; i < j; i++, j--){
		tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
	}
	
	
}

void descripto(char nomeC[]){
	int i, j;
	char tmp;
	int len = strlen(nomeC);
	
	for(i=0; i< len; i++){
		nomeC[i] -= 3;
	}
	
	for(i=0, j= len-1; i < j; i++, j--){
		tmp = nomeC[i];
		nomeC[i] = nomeC[j];
		nomeC[j] = tmp;
	}
}

void leitura(){
	pont_arq = fopen("DadosDoUsuario.txt", "r");
	if (pont_arq == NULL){
		printf("Erro ao abrir o arquivo!\n");
		return;
	}
	int x,i;
	char linha[15];
	
	totuser=0;
    x=0;
	
	if (pont_arq != NULL) { 
        
        while (fgets(linha, sizeof(linha), pont_arq) != NULL && strlen(linha)>0) { 
          linha[strcspn(linha, "\n" )]='\0'; 
            if (x%2==0){  
              strcpy(nome[totuser],linha);
			  descripto(nome[totuser]); 
              }
            else {
            	strcpy(senha[totuser],linha); 
            	descripto(senha[totuser]);
                totuser++;
			}
            x++;  
        } 
        fclose(pont_arq);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("USU�RIO                                         SENHA\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        
        for(i=0; i < totuser; i++){
        	printf("%s\n", nome[i]);
		}
	}
}

/*void alterarS(){
	char nome1,senha1,;
	int p;
	
	printf("Informe o nome do Usu�rio: ");
	fgets(nome1, sizeof(nome1), stdin);
	
	if()
}

int buscaU(char y){
	int i;
	
	for(i=0; i < totuser; i++){
		if(strcmp(y, nome[i]) == 0){
			return 1;
		}else return 0;
	}
}*/
