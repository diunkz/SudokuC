#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#define DIM 9

void TrocarValor(int matriz[][DIM],int linha,int coluna,int valor){

	matriz[linha][coluna] = valor;
}

void ValoresAleatoriosNaMatriz(int matriz[][DIM], int vetor1[], int vetor2[], int vetor3[]){
	int cont=0, linha, coluna, valor;

	while (cont<8){
		linha = vetor1[cont];
		coluna = vetor2[cont];
		valor = vetor3[cont];
		matriz[linha][coluna] = valor;
		cont++;
	}
}

void Matrizes3x3 (int matriz[][DIM], int vetor1[], int vetor2[], int vetor3[], int vetor4[], int vetor5[], int vetor6[], int vetor7[], int vetor8[], int vetor9[]){
	int contador1=0, contador2=0, contador3=0;

	//primeiras 3 matrizes
	while (contador1 < 3){
		while (contador2 < 3){
			vetor1[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=0;
		contador1++;
	}

	
	contador1 = 3;
	contador2 = 0;
	contador3 = 0;

	while (contador1 < 6){
		while (contador2 < 3){
			vetor2[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=0;
		contador1++;
	}

	contador1 = 6;
	contador2 = 0;
	contador3 = 0;

	while (contador1 < 9){
		while (contador2 < 3){
			vetor3[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=0;
		contador1++;
	}

	//3 matrizes

	contador1 = 0;
	contador2 = 3;
	contador3 = 0;

	while (contador1 < 3){
		while (contador2 < 6){
			vetor4[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=3;
		contador1++;
	}

	contador1 = 3;
	contador2 = 3;
	contador3 = 0;

	while (contador1 < 6){
		while (contador2 < 6){
			vetor5[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=3;
		contador1++;
	}

	contador1 = 6;
	contador2 = 3;
	contador3 = 0;

	while (contador1 < 9){
		while (contador2 < 6){
			vetor6[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=3;
		contador1++;
	}

	contador1 = 0;
	contador2 = 6;
	contador3 = 0;

	while (contador1 < 3){
		while (contador2 < 9){
			vetor7[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=6;
		contador1++;
	}

	contador1 = 3;
	contador2 = 6;
	contador3 = 0;

	while (contador1 < 6){
		while (contador2 < 9){
			vetor8[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=6;
		contador1++;
	}

	contador1 = 6;
	contador2 = 6;
	contador3 = 0;

	while (contador1 < 9){
		while (contador2 < 9){
			vetor9[contador3] = matriz[contador1][contador2];
			contador2++;
			contador3++;
		}
		contador2=6;
		contador1++;
	}
}

void CriarVetorUmAteNove (int vetor[]){
	int cont = 0;
	while (cont<9){
		vetor[cont] = cont+1;
		cont++;
	}
}

void CriarVetorZeroAteOito (int vetor[]){
	int cont = 0;
	while (cont<10){
		vetor[cont] = cont;
		cont++;
	}
}

void CriarVetorAleatorioDeUmAteNove(int vetoraleatorio[]){
	int vetor[9],
	numeroaleatorio,teste,indiceVetorAleatorio=0,indiceVetorNormal;
	CriarVetorUmAteNove(vetor);

	while (indiceVetorAleatorio < 9){
		teste = 0;
		indiceVetorNormal = 0;
		numeroaleatorio = rand() % 10;
		while (numeroaleatorio==0){
			numeroaleatorio = rand() % 10;
		}

		while (teste == 0){
			if (indiceVetorNormal == 9){
				indiceVetorNormal = 0;
				numeroaleatorio = rand() % 10;
				while (numeroaleatorio==0){
					numeroaleatorio = rand() % 10;
				}
			}
			else{
				if (numeroaleatorio == vetor[indiceVetorNormal]){
					vetor[indiceVetorNormal] = 10;
					vetoraleatorio[indiceVetorAleatorio] = numeroaleatorio;
					teste = 1;
				}
				else {
					indiceVetorNormal++;
				}
			}
			
		}
		indiceVetorAleatorio++;
	}
}

void CriarVetorAleatorioDeZeroAteOito(int vetoraleatorio[]){
	int vetor[9],
	numeroaleatorio,teste,indiceVetorAleatorio=0,indiceVetorNormal;
	CriarVetorZeroAteOito(vetor);

	while (indiceVetorAleatorio < 9){
		teste = 0;
		indiceVetorNormal = 0;
		numeroaleatorio = rand() % 9;

		while (teste == 0){
			if (indiceVetorNormal == 9){
				indiceVetorNormal = 0;
				numeroaleatorio = rand() % 9;
			}
			else{
				if (numeroaleatorio == vetor[indiceVetorNormal]){
					vetor[indiceVetorNormal] = 10;
					vetoraleatorio[indiceVetorAleatorio] = numeroaleatorio;
					teste = 1;
				}
				else {
					indiceVetorNormal++;
				}
			}
			
		}
		indiceVetorAleatorio++;
	}
}

void DarValoresParaMatriz (int matriz[][DIM]){
	int linha=0,coluna=0;
	while (coluna<DIM){
		while(linha<DIM){
			matriz[linha][coluna] = 88;
			linha++;
		}
		linha = 0;
		coluna++;
	}
}

void PrintSudoku (){
	//printf("\33[H\33[2J"); 
	printf("\n\t\t       █　  █▀▀▀█ █  █ █▀▀▄ █▀▀█ █ █ █  █ 　 █");
	printf("\n\t\t       ▀　  ▀▀▀▄▄ █  █ █  █ █  █ █▀▄ █  █ 　 ▀");
	printf("\n\t\t       ▄　  █▄▄▄█  ▀▀▀ ▀▀▀  ▀▀▀▀ ▀ ▀ ▀▄▄▀ 　 ▄\n\n");
}

void MostrarMatriz (int matriz[][DIM]){
	PrintSudoku();
	int linha = 0, coluna = 0, cont=0;
	//printf("\t      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐\n");
	printf("\t\t\t  1   2   3   4   5   6   7   8   9  \n" );
	printf("\t\t\t╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
	while (linha < DIM){
		printf("\t\t      %d ║",linha+1);
		while (coluna<DIM){
			if (cont%2 == 0  && cont!=0){
				if (matriz[linha][coluna] != 88){
					printf(" %d ║", matriz[linha][coluna]);
				}
				else{
					printf("   ║", matriz[linha][coluna]);
				}
				cont=0;
			}
			else{
				if (matriz[linha][coluna] != 88){
					printf(" %d │", matriz[linha][coluna]);
				}
				else{
					printf("   │", matriz[linha][coluna]);
				}
				cont++;
			}
			coluna++;
		}
		cont=0;

		linha++;
		coluna = 0;
		if (linha<9){
			if (linha%3 ==  0) printf("\n\t\t\t╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
			else printf("\n\t\t\t╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
		}
		//if (linha < 9) printf("\n\t      ├───┼───┼───┼───┼───┼───┼───┼───┼───┤\n");
	}
	printf("\n\t\t\t╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n\n");
	//printf("\n\t      └───┴───┴───┴───┴───┴───┴───┴───┴───┘\n\n");
}

void Vitoria(int matriz[][DIM]){
	system("clear");
	MostrarMatriz(matriz);
	printf("  █▀▀ █  █ █▀▀▄ █▀▀█ █ █ █  █ 　 █▀▀ ▀█▀ █▀▀▄ █▀▀█ █   ▀█▀ ▀▀█ █▀▀█ █▀▀▄ █▀▀█ █ \n");
	printf("  ▀▀█ █  █ █  █ █  █ █▀▄ █  █ 　 █▀▀  █  █  █ █▄▄█ █    █  ▄▀  █▄▄█ █  █ █  █ ▀ \n");
	printf("  ▀▀▀ ▀▀▀▀ ▀▀▀  ▀▀▀▀ ▀ ▀ ▀▀▀▀ 　 ▀   ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀  ▀ ▀▀▀  ▀▀▀▀ ▄ \n");
	printf("\n");
	printf("\t   █▀▀▄ █▀▀█ █▀▄▀█ 　 ▀▀█▀▀ █▀▀█ █▀▀█ █▀▀▄ █▀▀█ █   █  █ █▀▀█ █ \n");
	printf("\t   █▀▀▄ █  █ █ ▀ █ 　   █   █▄▄▀ █▄▄█ █▀▀▄ █▄▄█ █   █▀▀█ █  █ ▀ \n");
	printf("\t   ▀▀▀  ▀▀▀▀ ▀   ▀ 　   ▀   ▀ ▀▀ ▀  ▀ ▀▀▀  ▀  ▀ ▀▀▀ ▀  ▀ ▀▀▀▀ ▄ \n\n");
}

void TransformarLinhaOuColunaEmVetor(int matriz[][DIM], int vetor[], int posicaolinhaoucoluna, int linhaoucoluna){
	int cont = 0;
	if (linhaoucoluna == 0){
		while (cont < DIM){
				vetor[cont] = matriz[posicaolinhaoucoluna][cont];
				cont++;
		}
	}
	if (linhaoucoluna == 1){
		while (cont < DIM){
				vetor[cont] = matriz[cont][posicaolinhaoucoluna];
				cont++;
		}
	}
}

int VerificarLinhaouColuna (int matriz[][DIM], int vetor[], int posicaolinhaoucoluna, int linhaoucoluna){

	int contador=0, contador2=0, teste, vetorcomparacao[9];
	CriarVetorUmAteNove(vetor);

	if (linhaoucoluna == 0){

		TransformarLinhaOuColunaEmVetor(matriz, vetorcomparacao, posicaolinhaoucoluna, linhaoucoluna);


		while (contador < DIM){
			contador2 = 0;
			teste = 0;
			while (contador2 < DIM && teste == 0){
				if (vetorcomparacao[contador] == vetor[contador2]){
					vetor[contador2] = 0;
					teste = 1;

				}
				else contador2++;
			}
			contador++;
		}
	}

	if (linhaoucoluna == 1){
		
		TransformarLinhaOuColunaEmVetor(matriz, vetorcomparacao, posicaolinhaoucoluna, linhaoucoluna);

		while (contador < DIM){
			contador2 = 0;
			teste = 0;
			while (contador2 < DIM && teste == 0){
				if (vetorcomparacao[contador] == vetor[contador2]){
					vetor[contador2] = 0;
					teste = 1;

				}
				else contador2++;
			}
			contador++;
		}
	}

	contador = 0;

	while (contador < DIM){
		if (vetor[contador] == 0) contador++;
		else contador = 10;
	}

	if (contador!=9) return 0;
	else return 1;
}

int VerificacaoDaMatriz (int matriz[][DIM], int vetor[]){
	int cont=0, cont2 = 0, verificacao=0,linhaoucoluna=0;
	while (cont < 18){

		if (cont2 == 9){
			cont2 = 0;
			linhaoucoluna = 1;
		}
		verificacao = verificacao + VerificarLinhaouColuna(matriz, vetor, cont2, linhaoucoluna);
		cont2++;
		cont++;
	}
	if (verificacao == 18) return 1;
	else return 0;
}


void LerValor(int valor){
	printf("Insira o valor: \n");
	scanf("%d", &valor);
}

int VerificarNumerosDaMatriz (int linha, int coluna, int vetoraleatorio1[], int vetoraleatorio2[]){
	int contador = 0;

	while (contador < 8){
		if ((linha == vetoraleatorio1[contador]) && (coluna == vetoraleatorio2[contador])){
			return 77;
		}
		contador++;
	}
	return contador;
}

void ClonarVetor(int vet1[DIM], int vet2[DIM]){
	int contador = 0;
	while (contador<DIM){
		vet1[contador] = vet2[contador];
		contador++;
	}
}

//FUNCOES PARA LISTAS

typedef struct TipoLista {
	int chave;
	struct TipoLista *prox;
} lista;

lista *CriarNovaLista (int valor){
	lista *novo;
	novo = (lista*) malloc(sizeof(lista));
	novo->chave = valor;
	novo->prox = NULL;

	return novo;
}

lista *VerificarUltimoDaLista(lista *primeiro){
	lista *aux;
	if (primeiro == NULL){
		aux = NULL;
	}
	else {
		aux = primeiro;
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox=NULL;
	}

	return aux;
}

lista *InsereNaLista(lista *primeiro, lista *listaprainserir){
	lista *aux, *fim;
	if (primeiro == NULL){
		primeiro=listaprainserir;
	}
	else{
		fim = VerificarUltimoDaLista(primeiro);
		fim->prox = listaprainserir;
	}

	return primeiro;
}

void MostrarElementosDaLista(lista *primeiro){
	if (primeiro == NULL){
		printf("Nenhum valor disponível!\n");
	}
	else{
		printf("\tValores disponiveis para a posição informada: ");
		while(primeiro){
			printf("%d ", primeiro->chave);
			primeiro = primeiro->prox;
		}
		printf(".\n");
	}
}

void ImprimirRecursivamente(lista *primeiro){
	if(primeiro){
		printf("%d ",primeiro->chave);
		ImprimirRecursivamente(primeiro->prox);
	}
	else{
		printf(".");
	}
}

lista *CriarListaDeUmAteNove(lista *primeiro){
		int num = 1;
		lista *aux;
		while (num <10){
			aux = CriarNovaLista(num);
			primeiro = InsereNaLista(primeiro,aux);
			num++;
		}
		return primeiro;

}

lista *RemoverTodosOsElementosDaLista(lista *primeiro){
	lista *fim, *aux;
	fim = VerificarUltimoDaLista(primeiro);
	while(primeiro!=NULL){
		if(primeiro == fim){
			free(primeiro);
			primeiro = NULL;
		}
		else{
			aux = primeiro;
			primeiro = primeiro->prox;
			free(aux);
		}
	}

	primeiro = NULL;

	return primeiro;

}

lista *RemoverDeterminadoElemento(lista *primeiro, int valor){
	lista *anterior, *atual, *fim;

	if (primeiro == NULL){
		return primeiro;
	}
	else{
		anterior = primeiro;
		atual = primeiro;
		fim = VerificarUltimoDaLista(primeiro);
		while (atual != NULL){
			if (atual->chave == valor){
				if(atual == primeiro){
					primeiro = primeiro->prox;
					free(atual);
					return primeiro;
				}
				else{
					if(atual == fim){
						fim = anterior;
					}

					anterior->prox = atual->prox;
					free(atual);
					return primeiro;
				}
			}
			else{
				anterior = atual;
				atual = atual->prox;
			}
		}
	}

	return primeiro;
}

lista *RemoverDeterminadoElementoRecursivamente(lista *primeiro, int valor){
	if (primeiro!=NULL){
		if(primeiro->chave == valor){
			lista *aux = primeiro;
			primeiro = primeiro->prox;
			free(aux);
		}
		else{
			primeiro->prox = RemoverDeterminadoElementoRecursivamente(primeiro->prox,valor);
		}
	}
}
lista *VerificarValoresDisponiveis(lista *inicio, int linha, int coluna, int matriz[][DIM], int vetor1[], int vetor2[], int vetor3[], int vetor4[], int vetor5[], int vetor6[], int vetor7[], int vetor8[], int vetor9[]){
	int vetorescolhido[DIM], contador=0;
	if ((linha>=0 && linha<3) && (coluna>=0 && coluna<3)){
		ClonarVetor(vetorescolhido,vetor1);
	}
	else if ((linha>=3 && linha<6) && (coluna>=0 && coluna<3)){
		ClonarVetor(vetorescolhido,vetor2);
	}
	else if ((linha>=6 && linha<9) && (coluna>=0 && coluna<3)){
		ClonarVetor(vetorescolhido,vetor3);
	}
	else if ((linha>=0 && linha<3) && (coluna>=3 && coluna<6)){
		ClonarVetor(vetorescolhido,vetor4);
	}
	else if ((linha>=3 && linha<6) && (coluna>=3 && coluna<6)){
		ClonarVetor(vetorescolhido,vetor5);
	}
	else if ((linha>=6 && linha<9) && (coluna>=3 && coluna<6)){
		ClonarVetor(vetorescolhido,vetor6);
	}
	else if((linha>=0 && linha<3) && (coluna>=6 && coluna<9)){
		ClonarVetor(vetorescolhido,vetor7);
	}		
	else if((linha>=3 && linha<6) && (coluna>=6 && coluna<9)){
		ClonarVetor(vetorescolhido,vetor8);
	}
	else if ((linha>=6 && linha<9) && (coluna>=6 && coluna<9)){
		ClonarVetor(vetorescolhido,vetor9);
	}

	while(contador < DIM){
		if (vetorescolhido[contador]!=88){
			inicio = RemoverDeterminadoElemento(inicio,vetorescolhido[contador]);
		}
		if (matriz[linha][contador]!= 88){
			inicio = RemoverDeterminadoElemento(inicio,matriz[linha][contador]);
		}
		if (matriz[contador][coluna] != 88){
			inicio = RemoverDeterminadoElemento(inicio,matriz[contador][coluna]);
		}
		contador++;
	}

	return inicio;
}

int BuscaDeElementos(lista *primeiro, int valor){
	lista *fim;
	if (primeiro == NULL){
		return 0;
	}
	else{
		while (primeiro){
			if(primeiro->chave == valor){
				return primeiro->chave;
			}
			else{
				primeiro = primeiro->prox;
			}
		}
	}
	return 0;
}

//Verificar se o valor está dentro da lista de valores disponíveis
void VerificarValor(lista *inicio, int matriz[][DIM], int linha, int coluna, int valor){
	if((valor>0)&&(valor<10)){
		system("clear");
		if(valor == BuscaDeElementos(inicio,valor)){
			TrocarValor(matriz,linha,coluna,valor);
			printf("\tValor adicionado na matriz!\n\n")
;		}
		else{
			printf("\tO valor informado não está dentro da lista de valores disponíveis.\n\n");
		}

	}
}

void main (){
	system("clear");
	srand(time(NULL));

	lista *inicio = NULL;

	int matrizsudoku[DIM][DIM],
		vetor[DIM],	vetoraleatorio1[8], vetoraleatorio2[8],vetoraleatorio3[8],
		vetormatriz3x3_1[9], vetormatriz3x3_2[9], vetormatriz3x3_3[9], vetormatriz3x3_4[9], vetormatriz3x3_5[9], vetormatriz3x3_6[9], vetormatriz3x3_7[9], vetormatriz3x3_8[9], vetormatriz3x3_9[9],
		linha, coluna, valor, posicaodamatriz;

	DarValoresParaMatriz(matrizsudoku);
	CriarVetorAleatorioDeZeroAteOito (vetoraleatorio1);
	CriarVetorAleatorioDeZeroAteOito (vetoraleatorio2);
	CriarVetorAleatorioDeUmAteNove (vetoraleatorio3);
	ValoresAleatoriosNaMatriz(matrizsudoku,vetoraleatorio1,vetoraleatorio2,vetoraleatorio3);
	MostrarMatriz(matrizsudoku);
	while(!VerificacaoDaMatriz(matrizsudoku,vetor)){
		//Gera um vetor para cada quadrante
		Matrizes3x3(matrizsudoku, vetormatriz3x3_1, vetormatriz3x3_2, vetormatriz3x3_3, vetormatriz3x3_4, vetormatriz3x3_5, vetormatriz3x3_6, vetormatriz3x3_7, vetormatriz3x3_8, vetormatriz3x3_9);
		
		inicio = CriarListaDeUmAteNove(inicio);		
		
		//LENDO AS POSIÇÕES (LINHA E COLUNA)
		do{
			setbuf(stdin,NULL);
			printf("\tInforme a linha e coluna: ");
			scanf("%d %d",&linha, &coluna);
			posicaodamatriz = (VerificarNumerosDaMatriz(linha-1,coluna-1,vetoraleatorio1,vetoraleatorio2));
			if (posicaodamatriz==77){
				printf("\tPosição predefinida da matriz!\n");
				linha = 10;
			}
		}while(!((linha>0 && linha<10)&&(coluna>0&&coluna<10)));

		linha=linha-1;
		coluna=coluna-1;

		//Vendo os valores disponiveis

		inicio = VerificarValoresDisponiveis(inicio,linha,coluna,matrizsudoku, vetormatriz3x3_1, vetormatriz3x3_2, vetormatriz3x3_3, vetormatriz3x3_4, vetormatriz3x3_5, vetormatriz3x3_6, vetormatriz3x3_7, vetormatriz3x3_8, vetormatriz3x3_9);
		printf("\tValores disponiveis para a posição informada: ");
		ImprimirRecursivamente(inicio);
		//MostrarElementosDaLista(inicio);
		// LENDO O VALOR 
		do{
			setbuf(stdin,NULL);
			printf("\n\tInforme o valor: ");
			scanf("%d",&valor);
			if((valor<1) || (valor>9)){
				printf("\tValor Incorreto!\n");
				valor = 10;
			}
		}while(!(valor>0 && valor<10));


		
		VerificarValor(inicio,matrizsudoku,linha,coluna,valor);

		inicio = RemoverTodosOsElementosDaLista(inicio);
		MostrarMatriz(matrizsudoku);

		if (VerificacaoDaMatriz(matrizsudoku,vetor)) Vitoria(matrizsudoku);
	}
}