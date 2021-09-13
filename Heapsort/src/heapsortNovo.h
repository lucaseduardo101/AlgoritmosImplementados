#ifndef HEAPSORTNOVO_H
#define HEAPSORTNOVO_H

#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;
/*Função que imprime um vetor de char na tela*/
void imprimirVetorChar(int m, void *v);
/*Função que imprime um vetor de inteiros na tela*/
void imprimirVetorInt(int m, void *v);
/*Função que compara dois chars e retorna -1 se o primeiro for menor que o segundo, 0
 se forem iguais  e 1 se o primeiro for maior que o segundo*/
int charComp(void* x,void* y);
/* Função que compara dois inteiros e retorna um numero negativo se o primeiro for menor que
 o segundo, retorna 0 se forem iguais e retorna um numero positivo se o primeiro for maior que o segundo */
int intComp(void *x,void *y);
/*Função que recebe um vetor qualquer o transforma em um heap utilizando como critério a funcao compara e
retorna o endereço para esse novo vetor*/
void* constroi_heap (int n, void *v,size_t size, int(*compara)(void*, void*));
/*Função que recebe um vetor qualquer  o transforma em um heap ordena-o e depois retorna o endereço para esse vetor*/
void* heapsort (void *v, int n,size_t size, int(*compara)(void*, void*));

int doubleComp(void* x,void* y);
void imprimirVetorDouble(int m, void *v);

#endif // HEAPSORTNOVO_H
