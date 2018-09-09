#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	long dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;
nodo *inicio2=NULL;
nodo *ultimo2=NULL;
nodo *inicio3=NULL;
nodo *ultimo3=NULL;

nodo *crearnodo(long dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertaini(int dato, nodo *inicion, nodo *ultimon){
	int a=dato;
	nodo *nuevo=NULL;
	while(a!=0){
	a=dato%10;
	dato=(dato-a)/10;
	nuevo= crearnodo(a);
	if(inicion == NULL){
		inicion=nuevo;
		ultimon=nuevo;
	}
	else{
		nuevo->siguiente=inicion;
		inicion->anterior=nuevo;
		inicion=nuevo;
	}
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
        printf("La lista se encuentra vacía\n");
    }
}

void recorrer(nodo *inicion){
    nodo *tracker = inicion;
    if(inicion!=NULL){
        while(tracker!=NULL){
            printf("%ld\n", tracker->dato);
            tracker = tracker->siguiente;
        }
        //recorrerVuelta();
    }else{
        printf("La lista se encuentra vacia\n");
    }
}

void imprimirFI(nodo *ultimom){
	nodo *aux=ultimom;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->anterior;
	}
}

void imprimirIF(nodo *iniciom){
	nodo *aux=iniciom;
	while(aux!=NULL){
		printf("%ld\n",aux->dato);
		aux=aux->siguiente;
	}
}

void insertarInicio(int dato, nodo *inicion, nodo *ultimon){
    nodo *nuevo = crearnodo(dato);
    if(inicion==NULL){
        inicion = nuevo;
        ultimon = nuevo;
    }else{
        nuevo->siguiente = inicion;
        inicion->anterior = nuevo;
        inicion = nuevo;
    }
}

void suma(){
	int suma,acarreo;
	nodo *aux1 = ultimo;
	nodo *aux2 = ultimo2;
	if(inicio!=NULL && inicio2!=NULL){
        acarreo=0;
		while((aux1!=NULL) && aux2!=NULL){
            suma=(aux1->dato + aux2->dato)+acarreo;
            insertarInicio(suma, inicio3, ultimo3);
			if(suma>=10){
				acarreo=1;
			}else{
				acarreo=0;
			}
			aux1 = aux1->anterior;
			aux2 = aux2->anterior;
		}
	}
}


int main(int argc, char *argv[]) {
    insertaini(298372, inicio, ultimo);
    insertaini(298372, inicio2, ultimo2);
    imprimirIF(inicio);
    imprimirIF(inicio2);
    //suma();
    //recorrer(inicio3);
	return 0;
}

