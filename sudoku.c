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
			matriz[linha][coluna] = 10;
			linha++;
		}
		linha = 0;
		coluna++;
	}
}
void PrintSudoku (){
	system("clear");
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
				if (matriz[linha][coluna] != 10){
					printf(" %d ║", matriz[linha][coluna]);
				}
				else{
					printf("   ║", matriz[linha][coluna]);
				}
				cont=0;
			}
			else{
				if (matriz[linha][coluna] != 10){
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

int VerificarSeONumeroJaExiste(int matriz[][DIM], int vetor1[], int vetor2[], int vetor3[], int vetor4[], int vetor5[], int vetor6[], int vetor7[], int vetor8[], int vetor9[], int linha, int coluna, int valor){
	int contador = 0, verificacaolinha = 0, verificacaocoluna = 0, saida=0;
	while (contador < 9){
		if (valor == matriz[linha][contador]){
			verificacaolinha++;
			contador = 10;
		}
		contador++;

	}

	if (verificacaolinha==1){
		saida = 1;
	}

	else {
		contador = 0;
		while (contador < 9){
			if (valor == matriz[contador][coluna]){
				verificacaocoluna++;
				contador = 10;
			}
			contador++;
		}

		if(verificacaocoluna==1){
				saida=2;
		}

		else{
				contador = 0;
				 if ((linha>=0 && linha<3) && (coluna>=0 && coluna<3)){
				 	contador=0;
				 	while(contador<9){
				 		if(valor == vetor1[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

				 }
			else if ((linha>=3 && linha<6) && (coluna>=0 && coluna<3)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor2[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if ((linha>=6 && linha<9) && (coluna>=0 && coluna<3)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor3[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if ((linha>=0 && linha<3) && (coluna>=3 && coluna<6)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor4[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if ((linha>=3 && linha<6) && (coluna>=3 && coluna<6)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor5[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if ((linha>=6 && linha<9) && (coluna>=3 && coluna<6)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor6[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if((linha>=0 && linha<3) && (coluna>=6 && coluna<9)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor7[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if((linha>=3 && linha<6) && (coluna>=6 && coluna<9)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor8[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}

			}
			else if ((linha>=6 && linha<9) && (coluna>=6 && coluna<9)){
				contador=0;
				 	while(contador<9){
				 		if(valor == vetor9[contador]){
				 			saida = 3;
				 			contador = 10;
				 		}
				 		contador++;
				 	}
			}

		}
	}

	return saida;
}

int VerificarNumerosDaMatriz (int linha, int coluna, int vetoraleatorio1[], int vetoraleatorio2[]){
	int contador = 0;

	while (contador < 8){
		if ((linha == vetoraleatorio1[contador]) && (coluna == vetoraleatorio2[contador])){
			contador = 9;
		}
		contador++;
	}
	return contador;
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

void VerificacaoDaEntrada (int matriz[][DIM], char trocarounao, int linha, int coluna, int valor, int vetoraleatorio1[], int vetoraleatorio2[], int vetor1[], int vetor2[], int vetor3[], int vetor4[], int vetor5[], int vetor6[], int vetor7[], int vetor8[], int vetor9[]){
	
	int contador = 0;
	int teste = 0;
	__fpurge(stdin);

	if (VerificarNumerosDaMatriz(linha, coluna, vetoraleatorio1, vetoraleatorio2) == 10){
		MostrarMatriz(matriz);
		printf("\tValor Predefinido da matriz.\n\n");
	}
	else if((valor>0) && (valor<10)
		&& ((linha >= 0) && (linha <=8))
		&& ((coluna >= 0) && (coluna <=8))){
	
		if((VerificarSeONumeroJaExiste(matriz, vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7, vetor8, vetor9, linha, coluna, valor) == 1)){
			MostrarMatriz(matriz);
			printf("\tValor já existe na linha. \n\tDeseja Colocar/Substituir assim mesmo? (S ou N)\n");
			printf("\t--> ");
			teste = 1;
		}
		else if((VerificarSeONumeroJaExiste(matriz, vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7, vetor8, vetor9, linha, coluna, valor) == 2)){
			MostrarMatriz(matriz);
			printf("\tValor já existe na coluna. \n\tDeseja Colocar/Substituir assim mesmo? (S ou N)\n");
			printf("\t--> ");
			teste = 1;
		}
		else if((VerificarSeONumeroJaExiste(matriz, vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7, vetor8, vetor9, linha, coluna, valor) == 3)){
			MostrarMatriz(matriz);
			printf("\tValor já existe na matriz 3x3. \n\tDeseja Colocar/Substituir assim mesmo? (S ou N)\n");
			printf("\t--> ");
			teste = 1;
		}
		else{
			TrocarValor(matriz,linha,coluna,valor);
			MostrarMatriz(matriz);
			printf("\tValor inserido com sucesso.\n\n");
		}	
	}
	else if((valor==0)
		&& ((linha >= 0) && (linha <=8))
		&& ((coluna >= 0) && (coluna <=8))){
		TrocarValor(matriz,linha,coluna,10);
		MostrarMatriz(matriz);
		printf("\tValor apagado com sucesso.\n\n");
	}
	else{
		MostrarMatriz(matriz);
		printf("\tEntrada Incorreta!\n\n");
	}

	if (teste == 1){
		scanf("%c", &trocarounao);
		if (trocarounao == 's' || trocarounao == 'S'){
			TrocarValor(matriz,linha,coluna,valor);
			MostrarMatriz(matriz);
			printf("\tValor inserido/substituído com sucesso.\n\n");
		}
		else if (trocarounao == 'n' || trocarounao == 'N'){
			MostrarMatriz(matriz);
			printf("\tContinuando jogo!\n\n");
		}
		else {
			MostrarMatriz(matriz);
			printf("\tA letra inserida está incorreta. Na próxima insira S ou N.\n\n");
		}
	}
	//printf("%c | %d %d %d \n",trocarounao, linha, coluna, valor );

	//VerificarSeONumeroJaExiste(matriz, vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7, vetor8, vetor9, linha, coluna, valor);
}

void LerDados (int matriz[][DIM], char trocarounao, int linha, int coluna, int valor, int vetoraleatorio[], int vetoraleatorio1[], int vetor1[], int vetor2[], int vetor3[], int vetor4[], int vetor5[], int vetor6[], int vetor7[], int vetor8[], int vetor9[]){
	printf("\tInforme a linha, coluna e o valor separados por espaço (exemplo: 1 2 3): \n");
	printf("\tValor 0 apagará o valor na posição correspondente!\n");
	printf("\t--> ");
	setbuf(stdin,NULL);
	scanf("%d %d %d", &linha, &coluna, &valor);
	VerificacaoDaEntrada(matriz, trocarounao, (linha-1),(coluna-1),valor, vetoraleatorio, vetoraleatorio1, vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7, vetor8, vetor9 );
}

void Vitoria(int matriz[][DIM]){
	MostrarMatriz(matriz);
	printf("  █▀▀ █  █ █▀▀▄ █▀▀█ █ █ █  █ 　 █▀▀ ▀█▀ █▀▀▄ █▀▀█ █   ▀█▀ ▀▀█ █▀▀█ █▀▀▄ █▀▀█ █ \n");
	printf("  ▀▀█ █  █ █  █ █  █ █▀▄ █  █ 　 █▀▀  █  █  █ █▄▄█ █    █  ▄▀  █▄▄█ █  █ █  █ ▀ \n");
	printf("  ▀▀▀ ▀▀▀▀ ▀▀▀  ▀▀▀▀ ▀ ▀ ▀▀▀▀ 　 ▀   ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀  ▀ ▀▀▀  ▀▀▀▀ ▄ \n");
	printf("\n");
	printf("\t   █▀▀▄ █▀▀█ █▀▄▀█ 　 ▀▀█▀▀ █▀▀█ █▀▀█ █▀▀▄ █▀▀█ █   █  █ █▀▀█ █ \n");
	printf("\t   █▀▀▄ █  █ █ ▀ █ 　   █   █▄▄▀ █▄▄█ █▀▀▄ █▄▄█ █   █▀▀█ █  █ ▀ \n");
	printf("\t   ▀▀▀  ▀▀▀▀ ▀   ▀ 　   ▀   ▀ ▀▀ ▀  ▀ ▀▀▀  ▀  ▀ ▀▀▀ ▀  ▀ ▀▀▀▀ ▄ \n\n");
}

void main (){

	srand(time(NULL));

	int matrizsudoku[DIM][DIM],
		vetor[DIM],	vetoraleatorio1[9], vetoraleatorio2[9],vetoraleatorio3[DIM],
		vetormatriz3x3_1[9], vetormatriz3x3_2[9], vetormatriz3x3_3[9], vetormatriz3x3_4[9], vetormatriz3x3_5[9], vetormatriz3x3_6[9], vetormatriz3x3_7[9], vetormatriz3x3_8[9], vetormatriz3x3_9[9],
		linha, coluna, valor;
	char trocarounao;

	DarValoresParaMatriz(matrizsudoku);
	CriarVetorAleatorioDeZeroAteOito (vetoraleatorio1);
	CriarVetorAleatorioDeZeroAteOito (vetoraleatorio2);
	CriarVetorAleatorioDeUmAteNove (vetoraleatorio3);
	ValoresAleatoriosNaMatriz(matrizsudoku,vetoraleatorio1,vetoraleatorio2,vetoraleatorio3);
	MostrarMatriz(matrizsudoku);
	while(!VerificacaoDaMatriz(matrizsudoku,vetor)){
		Matrizes3x3(matrizsudoku, vetormatriz3x3_1, vetormatriz3x3_2, vetormatriz3x3_3, vetormatriz3x3_4, vetormatriz3x3_5, vetormatriz3x3_6, vetormatriz3x3_7, vetormatriz3x3_8, vetormatriz3x3_9);
		LerDados(matrizsudoku, trocarounao, linha, coluna, valor, vetoraleatorio1, vetoraleatorio2,  vetormatriz3x3_1, vetormatriz3x3_2, vetormatriz3x3_3, vetormatriz3x3_4, vetormatriz3x3_5, vetormatriz3x3_6, vetormatriz3x3_7, vetormatriz3x3_8, vetormatriz3x3_9);
		if (VerificacaoDaMatriz(matrizsudoku,vetor)) Vitoria(matrizsudoku);
	}
}