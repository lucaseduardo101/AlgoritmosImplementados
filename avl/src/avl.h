/*
 * avl.h
 *
 *  Created on: 24/12/2012
 *      Author: Lucas
 */

#ifndef AVL_H_
#define AVL_H_

#include <iostream>


#define vacio -9999

using namespace std;
struct nodo {
	int valor ;
	int bal;
	struct nodo *drcha;
	struct nodo *izqda;
};

class avl {
public:
	avl();
	virtual ~avl();
	void imprimir( nodo *x );
	int	 inserir ( nodo **no, int x );
	nodo *raiz;
	void borrar();
private:

};

#endif /* AVL_H_ */
