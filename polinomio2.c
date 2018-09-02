#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int coe;
	int expp;
	struct nodo *siguiente;
};

nodo *inicio = NULL;
nodo *inicio2 = NULL;
nodo *inicio3 = NULL;
nodo *inicio4 = NULL;
nodo *inicio5 = NULL;
nodo *inicio6 = NULL;
nodo *ultimo=NULL;
nodo *ultimo2=NULL;
nodo *ultimo3 = NULL;
nodo *ultimo4 = NULL;
nodo *ultimo5 = NULL;
nodo *ultimo6 = NULL;

nodo *crearnodo(int coe, int expp){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->coe=coe;
		nuevo->expp=expp;
		nuevo->siguiente = NULL;
	}
	return nuevo;
}

void insertarFinal(int coe, int expp){
	nodo *nuevo=NULL;
	nuevo= crearnodo(coe,expp);
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
	}
}

void insertarFinal2(int coe, int expp){
	nodo *nuevo=NULL;
	nuevo= crearnodo(coe,expp);
	if(inicio2 == NULL){
		inicio2=nuevo;
		ultimo2=nuevo;
	}
	else{
		ultimo2->siguiente=nuevo;
		ultimo2=nuevo;
	}
}
void simplificar(nodo *inicion){
	if(inicion!=NULL){
		nodo *pivote=inicion;
		while(pivote!=NULL){
		nodo *aux=pivote->siguiente;
		nodo *ant=pivote;
		while(aux!=NULL){
		while((aux!=NULL)&&(aux->expp!=pivote->expp)){
		ant=aux;
		aux=aux->siguiente;
		}
		if(aux!=NULL){
			pivote->coe+=aux->coe;
			ant->siguiente=aux->siguiente;
			aux->siguiente=NULL;
			free(aux);
			aux=ant->siguiente;
		}
		}
		pivote=pivote->siguiente;
	}
}	
}

void simplificar2(){
	if(inicio2!=NULL){
		nodo *pivote=inicio2;
		while(pivote!=NULL){
		nodo *aux=pivote->siguiente;
		nodo *ant=pivote;
		while(aux!=NULL){
		while((aux!=NULL)&&(aux->expp!=pivote->expp)){
		ant=aux;
		aux=aux->siguiente;
		}
		if(aux!=NULL){
			pivote->coe+=aux->coe;
			ant->siguiente=aux->siguiente;
			aux->siguiente=NULL;
			free(aux);
			aux=ant->siguiente;
		}
		}
		pivote=pivote->siguiente;
	}
}	
}

void recorrer(){
	nodo* aux = inicio;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void ordenar(nodo *inicion){
    nodo *externo = inicion;
    while(externo != NULL){
        nodo *interno = externo->siguiente;
        while(interno != NULL){
            if(externo->expp < interno->expp){
                int aux = externo->expp;
                int coef = externo->coe;
                externo->expp = interno->expp;
                interno->expp = aux;
                externo->coe = interno->coe;
                interno->coe = coef;
            }
            interno = interno->siguiente;
        }
        externo = externo->siguiente;
    }
}

void recorrer2(){
	nodo* aux = inicio2;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void recorrerSum(){
	nodo* aux = inicio3;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void recorrerMult(){
	nodo* aux = inicio5;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void recorrerRes(){
	nodo* aux = inicio4;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void recorrerResultado(nodo *iniciom){
	nodo* aux = iniciom;
	while(aux!=NULL){
		printf("%i",aux->coe);
		printf("x");
		printf("%i\t",aux->expp);
		aux = aux->siguiente;
	}
	
}

void sumar(){
    int suma;
    nodo *aux1 = inicio;
    nodo *aux2 = inicio2;
    nodo *aux3 = inicio3;
    if(inicio!=NULL && inicio2!=NULL){
        while(aux1!=NULL && aux2!=NULL){
            if(aux1->expp==aux2->expp){
                suma = aux1->coe+aux2->coe;
                nodo *nuevo = crearnodo(suma,aux1->expp);
                if(inicio3 == NULL){
                    inicio3=nuevo;
                    ultimo3=nuevo;
                }
                else{
                    ultimo3->siguiente=nuevo;
                    ultimo3=nuevo;
                }
                aux1=aux1->siguiente;
                aux2=aux2->siguiente;
            }else{
                ordenar(inicio);
                ordenar(inicio2);
            }
        }
    }
}

void restar(){
    int suma;
    nodo *aux1 = inicio;
    nodo *aux2 = inicio2;
    nodo *aux4 = inicio4;
    if(inicio!=NULL && inicio2!=NULL){
        while(aux1!=NULL && aux2!=NULL){
            if(aux1->expp==aux2->expp){
                suma = aux1->coe-aux2->coe;
                nodo *nuevo = crearnodo(suma,aux1->expp);
                if(inicio4 == NULL){
                    inicio4=nuevo;
                    ultimo4=nuevo;
                }
                else{
                    ultimo4->siguiente=nuevo;
                    ultimo4=nuevo;
                }
                aux1=aux1->siguiente;
                aux2=aux2->siguiente;
            }else{
                ordenar(inicio);
                ordenar(inicio2);
            }
        }
    }
}

void multiplicar(){
    int mult,exppn;
    if(inicio!=NULL && inicio2!=NULL){
        nodo *aux2 = inicio2;
        while(aux2!=NULL){
            nodo *aux1 = inicio;
            while(aux1!=NULL){
                mult = (aux1->coe)*(aux2->coe);
                exppn = (aux1->expp)+(aux2->expp);
                nodo *nuevo = crearnodo(mult,exppn);
                if(inicio5 == NULL){
                    inicio5=nuevo;
                    ultimo5=nuevo;
                }
                else{
                    ultimo5->siguiente=nuevo;
                    ultimo5=nuevo;
                }
                aux1 = aux1->siguiente;
            }
            aux2 = aux2->siguiente;
        }
        simplificar(inicio5);
    }
}

void dividir(){
    int dividir,exppm,multn,exppx;
    if(inicio!=NULL && inicio2!=NULL){
        nodo *aux2 = inicio2;
        nodo *aux1 = inicio;
        ordenar(inicio);
        ordenar(inicio2);
        while((aux2->expp<=aux1->expp) && (aux1!=NULL)){
            printf("Entro\n");
            dividir = aux1->coe / aux2->coe;
            exppm = aux1->expp - aux2->expp;
            printf("%d %d\n", dividir, exppm);
            nodo *nuevo = crearnodo(dividir,exppm);
            if(inicio6 == NULL){
                inicio6=nuevo;
                ultimo6=nuevo;
            }
            else{
                ultimo6->siguiente=nuevo;
                ultimo6=nuevo;
            }
            recorrerResultado(inicio6);
            nodo *aux3 = ultimo6;
            while(aux2!=NULL){
                multn = aux3->coe*(aux2->coe*-1);
                exppx = aux3->expp+aux2->expp;
                insertarFinal(multn,exppx);
                recorrerResultado(inicio);
                printf("\n");
                aux2 = aux2->siguiente;
            }
            simplificar(inicio);
            if(inicio->coe==0){
                inicio = inicio->siguiente;
                aux1->siguiente = NULL;
                free(aux1);
                aux1 = inicio;
            }else{
                inicio = inicio;
                aux1 = inicio;
            }
        }

    }
}

int main()
{
   	insertarFinal(2,2);
	insertarFinal(3,3);
	insertarFinal(3,4);
	insertarFinal(2,2);
    insertarFinal(2,3);
    insertarFinal(2,4);
    insertarFinal(2,3);
    
    insertarFinal2(5,3);
	insertarFinal2(5,2);

    simplificar(inicio);
    simplificar(inicio2);

    ordenar(inicio);
    ordenar(inicio2);
    
    recorrer();
    printf("\n");
    recorrer2();
    printf("\n");

    dividir();
    recorrerResultado(inicio6);
    printf("\n");



    return 0;
}

