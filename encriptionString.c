#include <stdio.h>
#include <stdlib.h>

FILE *file;

typedef struct nodo nodo;
struct nodo{
    char pw;
    nodo *siguiente;
};

nodo *inicio=NULL;

nodo *crearnodo(char pw){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
        nuevo->pw=pw;
		nuevo->siguiente=nuevo;
	}
	return nuevo;
}

void insertar(char pw){
    nodo *nuevo = crearnodo(pw);
    if(inicio==NULL){
        inicio = nuevo;
    }else{
        nodo *aux = inicio;
        while(aux->siguiente!=inicio){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->siguiente = inicio;
    }
}

void recorrer(){
    if(inicio!=NULL){
        nodo *aux = inicio;
        do{
            printf("%c", aux->pw);
            aux = aux->siguiente;
        }while(aux != inicio);
    }
}

int main(){
    int o=0;
    char password[20];
    for(int i=0;i<20;i++){
        password[i]='*';
    }
    printf("Dame contrasena\n");
    scanf("%s",&password[0]);
    while(password[o]!='*'){
        insertar(password[o]);
        o+=1;
    }
    recorrer();

    file = fopen("mensaje.txt","wt");
    if(file==NULL){
        printf("Archivo inexistente");
    }else{
        fprintf(file, "Hola a todos este programa es clasificado para el profe Karim");
    }
    fclose(file);
    file = fopen("mensaje.txt", "rb");
    char caracter;
    while(feof(file)==0){
        caracter = fgetc(file);

    }
    return 0;
}