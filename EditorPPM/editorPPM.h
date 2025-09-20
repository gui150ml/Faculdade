/*
* Editor simples de imagens PPM/P3.
* Use este código como ponto de partida para sua implementação.
*
* Somente para propósitos educacionais. Pode conter erros.
*/

#ifndef _EDITOR_PPM_H
#define _EDITOR_PPM_H

#define RED 	0
#define GREEN 	1
#define BLUE	2

/* estrutura que deve ser usada para descrever um pixel com 24 bits de cor (8 bits para cada canal de cor RGB) */
typedef struct stPixel{
  unsigned char RGB[3]; /* acessar cada canal com RGB[RED], RGB[GREEN], RGB[BLUE] */
  struct stPixel *prox;
} tPixel;

/* Estrutura que deve ser usada para manipular um arquivo PPM/P3 na memória */
typedef struct stPPMFile{
  int tipoPPM; /* 3 (P3) para arquivos PPM em ASCII */
  int matrX, matrY; /* dimensões da imagem em linhas e colunas de pixels */
  int maxCor; /* cor máxima de cada pixel por canal de cor (RGB) */
  tPixel *pixels; /* pixels deve apontar para um vetor de ponteiros do tipo tPixel. Cada posição do vetor deve apontar para uma linha de pixels da imagem */ 
} tPPMFile;


/* protótipos das funções que deverão ser usadas ou completadas */
void printPPMFile(tPPMFile *f);
int readPPMHeader(tPPMFile *f);
char *readPPMline(char *buffer);
int readPPMFile(tPPMFile *f);


#endif
