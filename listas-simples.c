#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;
struct nodo{
    int dato;
    nodo *siguiente;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;

void insertarNodo(int dato){
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo -> dato = dato;
    nuevo -> siguiente = NULL;
    if(inicio == NULL){
        inicio = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo -> siguiente = nuevo;
        ultimo = nuevo;
    }
}

void recorrer(){
    nodo *aux = inicio;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux = aux->siguiente;
    }
}

void comparar(){
    nodo *aux1 = inicio;
    nodo *aux2 = inicio;
    aux1 = aux1->siguiente;
    while(aux2->siguiente!=NULL){
            if(aux1->dato==aux2->dato){
                printf("Se repitio el numero: %d", aux1->dato);
            }
            if(aux1->siguiente!=NULL){
                aux1 = aux1->siguiente;
            }else{
                aux2 = aux2->siguiente;
                aux1 = aux2->siguiente;
            }
    }
}

void buscar(int numero){
    nodo *buscador = inicio;
    while(buscador->siguiente!=NULL && buscador->dato!=numero){
        buscador = buscador->siguiente;
    }
        if(buscador->dato==numero){
            printf("\nEl numero %d ya existe", numero);
        }
        else{
            printf("\nEl numero %d no se encuentra", numero);
        }
}

void pruebaOrden(){
    nodo *ordenado=inicio->siguiente;
    nodo *prueba = inicio;
    while((ordenado!=NULL)&&(prueba->dato>=ordenado->dato)){
		prueba=prueba->siguiente;	
		ordenado=ordenado->siguiente;
		}
	if(ordenado==NULL){
		printf("\nLa lista esta ordenada de forma descendente");	
    }
    nodo *ordenado2=inicio->siguiente;
    nodo *prueba2 = inicio;
    while((ordenado2!=NULL)&&(prueba2->dato<=ordenado2->dato)){
		prueba2=prueba2->siguiente;	
		ordenado2=ordenado2->siguiente;
		}
	if(ordenado2==NULL){
		printf("\nLa lista esta ordenada de forma descendente");	
    }
    if(ordenado2!=NULL && prueba2!=NULL){
        printf("\nLa lista esta desordenada");
    }
}

void eliminarInicio(){
    if(inicio!=NULL){
        nodo *aux = inicio;
        inicio = inicio->siguiente;
        aux->siguiente = NULL;
        free(aux);
    }
}

void eliminarFinal(){
    nodo *aux = inicio;
    nodo *ant = NULL;
    while((aux!=NULL)&&(aux->siguiente!=NULL)){
        ant = aux;
        aux = aux->siguiente;
    }
    if(aux!=NULL){
        if(ant!=NULL){
            ant->siguiente=NULL;
            free(aux);
        }else{
            inicio = NULL;
            free(aux);
        }
    }
}

void ordenar(){
    nodo *externo = inicio;
    while(externo != NULL){
        nodo *interno = externo->siguiente;
        while(interno != NULL){
            if(externo->dato < interno->dato){
                int aux = externo->dato;
                externo->dato = interno->dato;
                interno->dato = aux;
            }
            interno = interno->siguiente;
        }
        externo = externo->siguiente;
    }
}

int main(){
    insertarNodo(1);
    insertarNodo(2);
    insertarNodo(5);
    insertarNodo(4);
    insertarNodo(5);
    ordenar();
    recorrer();
    return 0;
}



