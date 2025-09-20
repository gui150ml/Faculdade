/*
* Editor simples de imagens PPM/P3.
* Use este código como ponto de partida para sua implementação.
*
* Somente para propósitos educacionais. Pode conter erros.
*/
#include <stdlib.h>
#include <stdio.h>
#include "editorPPM.h"


char *readPPMline(char *buffer){
	do{
		fgets(buffer, 256, stdin);
	}while(buffer[0] == '#');
	return buffer;
}

int readPPMHeader(tPPMFile *f){
	char buffer[256];
	readPPMline(buffer);
	if(buffer[0] != 'P' || buffer[1] != '3')
		return 1;
	f->tipoPPM = buffer[1]-'0';
	readPPMline(buffer);
	if(sscanf(buffer, "%d %d", &f->matrX, &f->matrY) == EOF)
		return 1;
	readPPMline(buffer);
	if(sscanf(buffer, "%d", &f->maxCor) == EOF)
		return 1;
	
	return 0;
}

int readPPMFile(tPPMFile *f){
	if(readPPMHeader(f) == 0){ /* cabecalho PPM/P3 válido */
		/* leitura dos pixels deve ser feita aqui */
		

	} else { /* cabecalho PPM/P3 inválido */
		return 1;
	}
	return 0;
}

void printPPMFile(tPPMFile *f){
	fprintf(stdout,"P%d\n#gerado por <editorPPM.c>\n%d %d\n%d\n", f->tipoPPM, f->matrX, f->matrY, f->maxCor);
	/* escrita dos pixels para a saída padrão (stdout) aqui */
	
	
	return;
}

int main(int argc, char *argv[]){
	tPPMFile PPMfile;

	if(readPPMFile(&PPMfile) == 1){
		fprintf(stderr, "%s: arquivo invalido. Somente arquivos PPM/P3\n", argv[0]);
		exit(1);
	}
	printPPMFile(&PPMfile);
	/* seus filtros/processamentos aqui */

	exit(0);
}
