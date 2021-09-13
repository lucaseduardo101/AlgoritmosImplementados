#include "heapsortNovo.h"

using namespace std;

int main()
{
    int tamanho = 10;
    char v2[tamanho] ;
    int v[tamanho] ;
    void *aux;
    double v3[] = {2.5, 3.2, 5.4, 2.1, 1.2, 5.0, 8.6, 8.6, 9.6, 7.8} ;

    srand ( 0 );
    /*Gerar valores aleatorios para o vetor de inteiros*/
    for( int i = 0; i < tamanho; i++ )
    {
        v[i] = ( rand()%tamanho ) + 1;
    }
     /*Gerar valores aleatorios para o vetor de char*/
    for( int i = 0;i < tamanho; i++ )
    {
        v2[i] = ( rand()% ('Z'-'a') ) + ('a');
    }


    cout << "Vetor de char" <<endl;
    imprimirVetorChar( tamanho, v2 );

    cout << "Vetor ordenado" << endl;
    aux = heapsort ( v2, tamanho, sizeof(char), charComp);
    imprimirVetorChar( tamanho, aux );

    cout<<"\n";
    cout <<"Vetor de inteiros"<<endl;
    imprimirVetorInt( tamanho, v );

    cout <<"Vetor ordenado"<<endl;
    aux = heapsort ( v, tamanho, sizeof(int), intComp );
    imprimirVetorInt( tamanho, aux );


    cout<<"\n";
    cout <<"Vetor de doubles"<<endl;
    imprimirVetorDouble( tamanho, v3 );

    cout <<"Vetor ordenado"<<endl;
    aux = heapsort ( v3, tamanho, sizeof(double), doubleComp );
    imprimirVetorDouble( tamanho, aux );



    return 0;


}
