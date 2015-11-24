/* CAÇA-PALAVRAS */

#include <stdio.h>
#include <time.h>
#include <locale.h>
main(){
	char P1[50], P2[50], P3[50];
	int x=0, y=0, N1=0, N2=0, N3=0;
	int mat[21][80], i, j, Loc1Linha, Loc1Coluna, Loc1Aux, Loc2Linha, Loc2Coluna, Loc2Aux, Loc3Linha, Loc3Coluna, Loc3Aux, Continuar;
	
	setlocale(LC_ALL, "Portuguese");
	printf("\n\t\t\t      :: CAÇA-PALAVRAS  ::\n\n");
	
	/*SELECIONANDO PALAVRAS PARA JOGAR DENTRO DO CAÇA-PALAVRAS*/
	for(x=0; x<=50;x++){
		P1[x]=0;
		P2[x]=0;
		P3[x]=0;
	}
	
	printf("Digite uma palavra em letras maiúsculas, com um espaço após cada letra digitada:");
	scanf("%[^\n]", P1);
	_flushall();
	printf("Digite outra palavra, da mesma maneira: ");
	scanf("%[^\n]", P2);
	_flushall();
	printf("Digite outra palavra, da mesma maneira: ");
	scanf("%[^\n]", P3);
	_flushall();
	printf("\nPalavras inseridas: %s  %s  %s\nAgora encontre-as no caça-palavras!\n\n", P1, P2, P3);
	/*Conta o número de letras em cada palavra*/
	x=0;
	while(P1[x]!=0){
		N1++;
		x++;
	}
	x=0;
	while(P2[x]!=0){
		N2++;
		x++;
	}
	x=0;
	while(P3[x]!=0){
		N3++;
		x++;
	}
	
	srand (time(NULL));
	
	Loc1Linha=rand()%21;
	Loc1Coluna=rand()%(40-N1/2);
	
	Loc2Linha=rand()%21;
	Loc2Coluna=rand()%(40-N1/2);
	while(Loc2Linha==Loc1Linha || Loc2Coluna==Loc1Coluna){
		Loc2Linha=rand()%21;
		Loc2Coluna=rand()%(40-N1/2);
	}
	
	Loc3Linha=rand()%21;
	Loc3Coluna=rand()%(40-N1/2);
	while(Loc3Linha==Loc2Linha || Loc3Coluna==Loc2Coluna || Loc3Linha==Loc1Linha || Loc3Coluna==Loc1Coluna){
		Loc3Linha=rand()%21;
		Loc3Coluna=rand()%(40-N1/2);
	}
	//printf("%d\n", Loc1Linha);
	//printf("%d\n", Loc1Coluna);
	//printf("%d\n", N1);
	
	/*MONTANDO E EXIBINDO O CAÇA-PALAVRAS*/
	for(i=0; i<21; i++){
		
		//Palavra 1
		if(i==Loc1Linha){
			for(j=0; j<Loc1Coluna; j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
				Loc1Aux=j;
			}
			printf("%s", P1);
			for(j=Loc1Aux; j<39-(N1/2); j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
			}
		//Palavra 2	
		}else if(i==Loc2Linha){
			for(j=0; j<Loc2Coluna; j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
				Loc2Aux=j;
			}
			printf("%s", P2);
			for(j=Loc2Aux; j<39-(N1/2); j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
			}
		//Palavra 3
		}else if(i==Loc3Linha){
			for(j=0; j<Loc3Coluna; j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
				Loc3Aux=j;
			}
			printf("%s", P3);
			for(j=Loc3Aux; j<39-(N1/2); j++){
				mat[i][j]=65 + rand()%26;
				//printf("%c ", j+60);
				printf("%c ", mat[i][j]);
			}
		}else{
			for(j=0; j<40; j++){
				mat[i][j]=65 + rand()%26;
				printf("%c ", mat[i][j]);
			}
		}
	}
	/*
	printf("\n\nDeseja ver a resposta?  ( 1-SIM  ou  2-NAO ): ");
	scanf("%d", &continuar);
	while((continuar!=1) && (continuar!=2)){
		printf("Opcao invalida! \nDeseja ver a resposta?  ( 1-SIM  ou  2-NAO ): ");
		scanf("%d", &continuar);
	}
	if(continuar==2) printf("\n\n\t\tOBRIGADO!\n\n");
	*/
	
	getch();
	return 0;
}
