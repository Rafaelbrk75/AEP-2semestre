#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

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
int buscaU(char y[]);
void alterarS();
void excluirU();    
void creditos();
void leituraf4();
void leituraf5();

/*---------------------------------------*/

int main() {   
	setlocale(LC_ALL, "Portuguese");
	
	int key, fim, cadastro, op = 1;
	fim = 0;
	
	do{
		system("cls");
		
		printf("\n\n\n");
        printf("\033[34m                                        ___  ___    _____  __   __     ___  ___  __ \033[0m\n");
        printf("\033[34m                                       /  |  /  /   /   _____/  /  | /  /  /  / /  / \033[0m\n");
        printf("\033[34m                                      /  /|_/  /   /  ___/     /   |/  /  /  / /  / \033[0m\n");
        printf("\033[34m                                     /  /  /  /   /  /____    /  /|   /  /  /_/  / \033[0m\n");
        printf("\033[34m                                    /__/  /__/   / ______/   /_ / |_ /   \_____  / \033[0m\n");
        printf("\n\n\n\n");                                
		
		
		printf("                                               %s 1 - ADICIONAR\n", op == 1 ? "->" : "  ");
        printf("                                               %s 2 - LISTAR\n", op == 2 ? "->" : "  ");
        printf("                                               %s 3 - ALTERAR\n", op == 3 ? "->" : "  ");
        printf("                                               %s 4 - REMOVER\n", op == 4 ? "->" : "  ");
        printf("                                               %s 5 - CRÉDITOS\n", op == 5 ? "->" : "  ");
        printf("                                               %s 6 - SAIR\n", op == 6 ? "->" : "  ");
        
        key = getch();
	    
	    if (key == 224) {  
            key = getch(); 
            if (key == 72) {   /* Seta para cima*/
                op--;
                if (op < 1) op = 6;  
            } else if (key == 80) {  /* Seta para baixo*/
                op++;
                if (op > 6) op = 1;  
            }
        } else if (key == 13) {
        	system("cls");
        	switch(op){
		        case 1:
		    	    system("cls");
		    	    adicionar();
		    	    printf("\n\n\n");
		    	    printf("Pressione qualquer tecla para sair...\n");
		        break;
		
		        case 2:
		    	    system("cls");
		    	    leitura();
		    	    printf("\n\n\n");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 3:
		    	    system("cls");
		    	    alterarS();
		    	    printf("\n\n\n");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 4:
		    	    system("cls");
		    	    excluirU();
		    	    printf("\n\n\n");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		
		        case 5:
		    	    system("cls");
		    	    creditos();
		    	    printf("\n\n\n");
		    	    printf("Pressione qualquer tecla para sair...\n");
		    	    getch();
		        break;
		    
		        case 6:
		    	    system("cls");
		    	    printf("\n\n\n\n");
		    	    printf("            ¦¦¦¦¦¦¦ ¦¦ ¦¦¦    ¦¦  ¦¦¦¦¦  ¦¦      ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦    ¦¦ ¦¦¦¦¦¦   ¦¦¦¦¦¦ \n");
                    printf("            ¦¦      ¦¦ ¦¦¦¦   ¦¦ ¦¦   ¦¦ ¦¦      ¦¦    ¦¦¦  ¦¦   ¦¦ ¦¦¦¦   ¦¦ ¦¦   ¦¦ ¦¦    ¦¦\n");
                    printf("            ¦¦¦¦¦   ¦¦ ¦¦ ¦¦  ¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦   ¦¦¦   ¦¦¦¦¦¦¦ ¦¦ ¦¦  ¦¦ ¦¦   ¦¦ ¦¦    ¦¦\n");
                    printf("            ¦¦      ¦¦ ¦¦  ¦¦ ¦¦ ¦¦   ¦¦ ¦¦      ¦¦  ¦¦¦    ¦¦   ¦¦ ¦¦  ¦¦ ¦¦ ¦¦   ¦¦ ¦¦    ¦¦\n");
                    printf("            ¦¦      ¦¦ ¦¦   ¦¦¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦¦¦ ¦¦¦¦¦¦   ¦¦¦¦¦¦\n");
                    printf("            +-+     +-++-+  +---++-+  +-++------++-++------++-+  +-++-+  +---++-----+  +-----+ \n");                                                                                                                                                                                                                    
            		
					fim = 1;           
				break;
		
		        default:
		    	    printf("Opção invalida!!!");
		    	    getch();
		        break;
	        }
		}  
		
		if (GetAsyncKeyState(VK_F4) & 0x8000) {  /* F4 */
            system("cls");
            leituraf4();
            Sleep(1500);
            getch();
        } 
        else if (GetAsyncKeyState(VK_F5) & 0x8000) {  /* F5 */
            system("cls");
            leituraf5();
            Sleep(1500);
            getch();
        }
		    
	}while(fim != 1);
	
	return 0;
}
/*---------------------------------------*/
void adicionar(){
	char senha_confirm[70], nomeT[70];
	int i,teste,cadastro;
	
	
	printf("-----------------------------------------------------------------------------------------------------------------------"); 
	printf("\n\033[34m");
    printf("\n				     ____   ______ ______ ____ _____ ______ ____   ____ \n");
    printf("				    / __ | / ____// ____//  _// ___//_  __// __ | / __ |\n");
    printf("				   / /_/ // __/  / / __  / /  |__ |  / /  / /_/ // / / /\n");
    printf("				  / _  _// /___ / /_/ /_/ /  ___/ / / /  / _  _// /_/ / \n");
    printf("				 /_/ |_|/_____/ |____//___/ /____/ /_/  /_/ |_| |____/  \n");
    printf("\033[0m\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
		
	do{
		printf("\n\n                             INFORME SEU USER: ");
	    fgets(nomeT, sizeof(nomeT), stdin);
	    nomeT[strcspn(nomeT, "\n")] = '\0';
	    
	    i = buscaU(nomeT);
	    
	    if(i != -1){
	    	printf("                             ESSE USER JÁ EXISTE! TENTE OUTRO NOME. ");
		}else{
		    strcpy(nome[totuser], nomeT);	
		}		
		
	}while(i!= -1);
		    	    
	do {	
        printf("\n                             INFORME UMA SENHA (FORTE!): ");
        fgets(senha[totuser], sizeof(senha[totuser]), stdin);
        senha[totuser][strcspn(senha[totuser], "\n")] = '\0';

        printf("\n                             CONFIRME SUA SENHA: ");
        fgets(senha_confirm, sizeof(senha_confirm), stdin);
        senha_confirm[strcspn(senha_confirm, "\n")] = '\0';

        if (strcmp(senha[totuser], senha_confirm) != 0) {
            printf("\n                             AS SENHAS NÃO COINCIDEM. TENTE NOVAMENTE.\n");
            continue;
        }

        teste = verificaSenha(senha[totuser]);
        if (teste == 0) {
            printf("\n                             SENHA FRACA! TENTE NOVAMENTE.\n");
        }
    } while (teste != 1 || strcmp(senha[totuser], senha_confirm) != 0);
	
	cripto(nome[totuser]); 
	cripto(senha[totuser]);
		    	    
	cadastro = armazena(nome[totuser], senha[totuser]);
		    	    
	if(cadastro == 1){
		printf("\n\n\n");
	    printf("\n\033[32m                             CADASTRO CONCLUÍDO! Pressione qualquer tecla para sair...\033[0m\n");
	    totuser++;
		getch();

	}
}
/*---------------------------------------*/
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
		if(sen[i] >= 48 && sen[i] <= 57){
			temN = 1;
		}else if(sen[i] >= 65 && sen[i] <= 90){
			temMai = 1; 
		}else if(sen[i] >= 97 && sen[i] <= 122){
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
/*---------------------------------------*/
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
/*---------------------------------------*/
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
/*---------------------------------------*/
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
/*---------------------------------------*/
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
        printf("USUÁRIO                                         SENHA\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        
        for(i=0; i < totuser; i++){
        	printf("%s\n", nome[i]);
		}
	}
}
/*---------------------------------------*/
void alterarS(){
	char nome1[100],senha1[100];
	int p;
	
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\033[34m\n");
	printf("                        ___    __  ________________  ___    ____     _____ _______   ____  _____ \n");
    printf("                       /   |  / / /_  __/ ____/ __ \\/   |  / __ \\   / ___// ____/ | / / / / /   | \n");
    printf("                      / /| | / /   / / / __/ / /_/ / /| | / /_/ /   \\__ \\/ __/ /  |/ / /_/ / /| | \n");
    printf("                     / ___ |/ /___/ / / /___/ _, _/ ___ |/ _, _/   ___/ / /___/ /|  / __  / ___ | \n");
    printf("                    /_/  |_/_____/_/ /_____/_/ |_/_/  |_/_/ |_|   /____/_____/_/ |_/_/ /_/_/  |_| \n");
    printf("                                                                                                  \n");
    printf("\033[0m\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    
	printf("\n  NOME DO USUÁRIO: ");
	fgets(nome1, sizeof(nome1), stdin);
	nome1[strcspn(nome1, "\n")] = '\0'; 
	
	p = buscaU(nome1);
	
	if(p != -1){
		printf("  Informe a nova senha: ");
		fgets(senha[p], sizeof(senha[p]), stdin);
		senha[p][strcspn(senha[p], "\n")] = '\0';
		printf("\n\033[32m  SENHA ATUALIZADA COM SUCESSO!\033[0m\n");
	}else{
		printf("\033[31m  USUÁRIO NÃO IDENTIFICADO!\033[0m");
	}
}
/*---------------------------------------*/
int buscaU(char y[]){
	int i;
	
	for(i=0; i < totuser; i++){
		if(strcmp(y, nome[i]) == 0){
			return i;
		}
	}
	
	return -1;
}
/*--------------------------------------*/
void excluirU(){
	char nomeX[70];
    int pos, i;
    
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\033[31m");
    printf("                      _____   ______  __  __    ______      ________ _____ ____\n");   
    printf("                     |  __ \\ |  ____||  \\/  | /  __  \\ \\     / /|  ____||  __ \\ \n");    
    printf("                     | |__)  | |__   | \\  / | | |  | | \\ \\  / / | |__   | |__) |  \n");   
    printf("                     |  _  / |  __|  | |\\/| | | |  | |  \\ \\/ /  |  __|  |  _  / \n");    
    printf("                     | | \\ \\ | |____ | |  | | | |__| |   \\  /   | |____ | | \\ \\ \n");  
    printf("                     |_|  \\_\\|______||_|  |_| \\______/    \\/    |______||_|  \\_\\ \n");   
    printf("\n");                                            
    printf("\033[0m\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
	                                                                                                                 
    printf("  INFORME O NOME DO USUÁRIO PARA EXCLUIR: ");
    fgets(nomeX, sizeof(nomeX), stdin);
    nomeX[strcspn(nomeX, "\n")] = '\0';
    
    pos = buscaU(nomeX);
    
    if (pos != -1) {
        for (i = pos; i < totuser - 1; i++) {
            strcpy(nome[i], nome[i + 1]);
            strcpy(senha[i], senha[i + 1]);
        }
        totuser--;  

       
        pont_arq = fopen("DadosDoUsuario.txt", "w");
        if (pont_arq == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }
        
        for (i = 0; i < totuser; i++) {
            cripto(nome[i]);  
            cripto(senha[i]);
            fprintf(pont_arq, "%s\n", nome[i]);
            fprintf(pont_arq, "%s\n", senha[i]);
            descripto(nome[i]);  
            descripto(senha[i]);
        }
        
        fclose(pont_arq);

        printf("\033[32m\n  USUÁRIO EXCLUÍDO COM SUCESSO!\033[0m\n");
    } else {
        printf("\033[31m\n  USUÁRIO NÃO ENCONTRADO.\033[0m\n");
    }
}

void creditos() {
	printf("\n\n\n");
    printf("                                **********************************************************\n");
    printf("                                *" "\033[33m                        CRÉDITOS \033[0m" "                       *\n");                                                                              
    printf("                                **********************************************************\n");                                                                             
    printf("                                *  Kauan Marcolino Garcia                                *\n"); 
    printf("                                *  Rafael Rodrigues Oliveira Santos                      *\n");
    printf("                                *  Pedro Henrique Gameleira Cavalini                     * \n");
    printf("                                **********************************************************\n");
    printf("                                *  Instituição: Unicesumar - Engenharia de Software      *\n");
    printf("                                *  Turma: B                                              *\n");
    printf("                                *  Semetre: 2º                                           *\n");
    printf("                                **********************************************************"); 
    printf("\n\n\n\n");
}

void leituraf4(){
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
        printf("USUÁRIO                                                                         SENHA\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        
        for(i=0; i < totuser; i++){
        	printf("%s                                                                   %s\n", nome[i], senha[i]);
		}
	    printf("\n\n\n\n\n\n");
	}
}

void leituraf5(){
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
              }
            else {
            	strcpy(senha[totuser],linha); 
                totuser++;
			}
            x++;  
        } 
        fclose(pont_arq);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("USUÁRIO                                                                         SENHA\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        
        for(i=0; i < totuser; i++){
        	printf("%s                                                                   %s\n", nome[i], senha[i]);
		}
		printf("\n\n\n\n\n\n");
	}
}
