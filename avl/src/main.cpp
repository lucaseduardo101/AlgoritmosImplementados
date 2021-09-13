/*
 * main.cpp
 *
 *  Created on: 26/12/2012
 *      Author: Lucas
 *
 *
 */
#include <iostream>
#include "avl.h"

using namespace std;

int main (){
	avl teste;
	teste.inserir( &teste.raiz, 2 );
	teste.inserir( &teste.raiz, 1 );
	teste.inserir( &teste.raiz, 3 );
	teste.inserir( &teste.raiz, 4 );
	teste.inserir( &teste.raiz, 5 );


	teste.imprimir(teste.raiz);
	return 0;

}



