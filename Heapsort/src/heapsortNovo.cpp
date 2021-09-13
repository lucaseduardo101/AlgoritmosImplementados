#include "heapsortNovo.h"

using namespace std;
void imprimirVetorDouble(int m, void *v){
    int i;
    double aux[m], *aux2;
    aux2 = ( double* ) v;
    for(i = 0; i < m; i++)
    {
        aux[i] = *( aux2 + i );
        cout <<aux[i], cout<<" ";
    }
    cout<<"\n";
}



int doubleComp(void* x,void* y){
    double aux, aux2,test;

    aux = *( (double*) x );
    aux2 = *( (double*) y );
    test = aux - aux2;
    if(test>0)
        return 1;
    else
        if(test<0)
            return -1;
    return 0;
}


 void imprimirVetorInt (int m, void *v){
    int i, aux[m], *aux2;
    aux2 = ( int* ) v;
    for(i = 0; i < m; i++)
    {
        aux[i] = *(aux2 + i * sizeof ( char ) );
        cout << aux[i], cout<<" ";
    }
    cout<< "\n";
}

 void imprimirVetorChar (int m, void *v){
    int i;
    char aux[m], *aux2;
    aux2 = ( char* ) v;
    for(i = 0; i < m; i++)
    {
        aux[i] = *( aux2 + i * sizeof(char) );
        cout <<aux[i], cout<<" ";
    }
    cout<<"\n";
}

int charComp ( void* x, void* y )
{
    char *aux, *aux2;
    aux =  (char*) x;
    aux2 = (char*) y;
    return strcmp( aux, aux2 ) ;
}


int intComp ( void* x,void* y )
{
    int aux, aux2;
    aux = *( (int*) x );
    aux2 = *( (int*) y );
    return ( aux - aux2 );
}

 void* constroi_heap ( int n, void* v,size_t size,int(*compara)(void*, void*) )
{
    int m = 0, f = 0;
    char *t = new char[size];
    char *aux;
    aux = (char*)v;
    for (m = 0; m < n - 1; ++m) {
      f = m + 1;
      while (f > 0 && ( compara ( ( (char*)v + (f/2) * size),((char*)v + f * size ) ) )< 0 )
      {
        memcpy( t, aux + size*(f/2), size ); //t = aux[f/2]
        memcpy( aux + size * (f/2), aux+(size)*f, size );//aux[f/2] = aux[f]
        memcpy(aux + size*f, t, size );//aux[f] = t
        f = f/2;
      }
   }
   delete[] t;
   return v;
}

void* heapsort (void *v, int n,size_t size, int(*compara)(void*, void*))
{
   v = constroi_heap (n, v, size, compara);
   int m, f;
   char *max = new char[size];
   char *t = new char[size];
   char *aux;
   aux = (char*)v;
   for (m = n-1; m > 0; --m) {
      memcpy(max, aux, size);//a variavel max recebe a primeira posição do vetor v
      f = 1;
      while (f <= m)
      {
        if ( (f < m) && ( compara (aux + f * size, aux + (f+1) * size) < 0 ) )
            ++f;
        memcpy( aux + size * (f/2), aux + size * f,size);//aux[f/2] = aux[f]
        f *= 2;
      }
      f = f/2;
      if (f < m) {
         memcpy(t, aux + size * f, size);//t = aux[f]
         memcpy(aux + size * f , aux + size * m, size);//aux[f] = aux[m]
         memcpy(aux + size * m, t , size);//aux[m] = t
         while (f > 1 && ( compara ( (char*)v + (f/2) * size, (char*)v + f * size ) ) <0 ) {
            memcpy( t, aux + size * (f/2) , size );//t=aux[f/2]
            memcpy( aux + size * (f/2), aux + (size) * f, size);//aux[f/2]=aux[f]
            memcpy( aux + size * f, t, size );//aux[f]=t
            f = f/2;
         }
      }
      memcpy( (char*)v + size * (m), max, size );//v[m] = max
   }
   delete[] t;
   delete[] max;
   return v;
}


