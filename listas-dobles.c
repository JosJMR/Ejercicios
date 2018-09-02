#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
    struct nodo *anterior;
    int dato;
    struct nodo *siguiente;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;

nodo *crearnodo(int dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertarFinal(int dato){
    nodo *nuevo = crearnodo(dato);
    if(inicio==NULL){
        inicio = nuevo;
        ultimo = nuevo;
    }else{
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        ultimo=nuevo;
    }
}

void insertarInicio(int dato){
    nodo *nuevo = crearnodo(dato);
    if(inicio==NULL){
        inicio = nuevo;
        ultimo = nuevo;
    }else{
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        inicio = nuevo;
    }
}

void recorrerVuelta(){
    nodo *tracker = ultimo;
    if(ultimo!=NULL){
        while(tracker!=NULL){
            printf("%d\n", tracker->dato);
            tracker = tracker->anterior;
        }
    }else{
        printf("La lista se encuentra vacía");
    }
}

void recorrer(){
    nodo *tracker = inicio;
    if(inicio!=NULL){
        while(tracker!=NULL){
            printf("%d\n", tracker->dato);
            tracker = tracker->siguiente;
        }
        recorrerVuelta();
    }else{
        printf("La lista se encuentra vacía");
    }
}

//Hacer una super calculadora: Suma,resta,multipliacion,division de numeros con muchos dígitos con listas dobles.


int main()
{
    insertarFinal(4);
    insertarFinal(6);
    insertarFinal(1);
    insertarFinal(3);
    insertarFinal(7);
    recorrer();
    return 0;
}