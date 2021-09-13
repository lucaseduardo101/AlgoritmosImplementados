/*
 * avl.cpp
 *
 *  Created on: 24/12/2012
 *      Author: Lucas
 */

#include "avl.h"

void rot_drcha(nodo **n){

	nodo *aux;
	aux = (*n)->izqda;
	(*n)->izqda = aux->drcha;
	aux->drcha = (*n);
	(*n)->bal = 0;
	(*n) = aux;

}

void rot_izq(nodo **n){
	nodo *aux;
	aux = (*n)->drcha;
	(*n)->drcha = aux->izqda;
	aux->izqda = (*n);
	(*n)->bal = 0;
	(*n) = aux;
}

void rot_izq_drcha(nodo **n){

	nodo *aux1, *aux2;
	aux1 = (*n)->izqda;
	aux2 = aux1->drcha;
	aux1->drcha = aux2->izqda;
	aux2->izqda =aux1;
	(*n)->izqda = aux2->drcha;
	aux2->drcha = (*n);
	if ( aux2->bal == -1 ){
		(*n)->bal = 1;
	}else{
		(*n)->bal = 0;
	}
	if (aux2->bal == 1 ){
		aux1->bal = -1;
	}else{
		aux1->bal = 0;
	}
	*n = aux2;
}



void rot_drcha_izq(nodo **n){
	nodo *aux1, *aux2;
	aux1 = (*n)->drcha;
	aux2 = aux1->izqda;
	aux1->izqda = aux2->drcha;
	aux2->drcha = aux1;

	(*n)->drcha = aux2->izqda;
	aux2->izqda = (*n);
	if (aux2->bal == 1)
		(*n)->bal = -1;
	else
		(*n)->bal = 0;
	if (aux2->bal == -1)
		(*n)->bal = 1;
	else
		(*n)->bal = 0;
	*n = aux2;
}

void caso1(nodo **n)
{
	/* item foi inserido à esquerda de T e causa desbalanceamento FB(T)=-2 */
	nodo *aux;
	aux = (*n)->izqda;
	if (aux->bal == -1)
		rot_drcha(&(*n)); /* Caso 1.1 sinais iguais e negativo */
	else
		rot_izq_drcha(&(*n)); /* Caso 1.2 sinais diferentes */
	(*n)->bal = 0;
}

void caso2(nodo **n)
{
	/* item foi inserido à direita de T e causa desbalanceamento FB(T)=2 */
	nodo *aux;
	aux = (*n)->drcha;
	if (aux->bal == 1)
		rot_izq(&(*n));		 /* Caso 2.1 sinais iguais e positivo */
	else{
		cout<<"teste"<<endl;
		rot_drcha_izq(&(*n));	 /* Caso 2.2 sinais diferentes */
	}
	(*n)->bal = 0;
}

avl::avl() {
	this->raiz  = NULL ;
}

avl::~avl() {
	// TODO Auto-generated destructor stub
}

void avl::imprimir( nodo *x ) {

	if ( x )
		cout<< "( ";
	cout<< x->valor << " ";

	if ( x->izqda ){
		imprimir( x->izqda );
	}
	if ( x->drcha ){
		imprimir( x->drcha );
	}
	cout << " )";
}

int avl::inserir(nodo **no,int x){
	int ok;
	if (  *no == NULL  ){
		nodo *novo;
		novo = new nodo;
		novo->bal   = 0;
		novo->valor = x;
		novo->drcha = NULL;
		novo->izqda = NULL;
		*no = novo;
		return 1;
	}else{
		if ( x >= (*no)->valor ){
			ok = inserir( &(*no)->drcha, x );
			if ( ok == 1 ){
				switch((*no)->bal){
				case -1 :
					(*no)->bal = 0;
					break;
				case 0 :
					(*no)->bal = 1;
					break;
				case 1:
					caso2(&(*no));
					break;
				}
			}
		}else{
			ok = inserir( &(*no)->izqda, x );
			if ( ok == 1 ){
				switch((*no)->bal){
				case 1 :
					(*no)->bal = 0;
					ok = 0;
					break;
				case 0 :
					(*no)->bal = -1;
					break;
				case -1:
					caso1(&(*no));
					ok = 0;
					break;
				}
			}
		}
	}
	return ok;
}

