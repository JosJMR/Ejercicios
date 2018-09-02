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

void crearArchivo(){
    
    file = fopen("mensaje.txt","wt");
    if(file==NULL){
        printf("Archivo inexistente");
    }else{
        fprintf(file, "Hola a todos este programa es clasificado para el profe Karim");
    }
    fclose(file);
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

void encriptado(){
    FILE *encript;
    file = fopen("mensaje.txt", "w+");
    char caracter;
    int suma=0;
    nodo *aux = inicio;
    while(feof(file)==0){
        caracter = fgetc(file);
        if (file==NULL)
        exit(1);
        int pas = aux->pw;
        int ff = caracter;
        int encription = ff-pas;
        fwrite(&encription, sizeof(encription), 1, file);
        aux = aux->siguiente;
    }
    fclose(file);
}

void desencriptado(){
    file = fopen("mensaje.txt", "r+");
    char caracter;
    int suma=0;
    nodo *aux = inicio;
    while(feof(file)==0){
        caracter = fgetc(file);
        int pas = aux->pw;
        int ff = caracter;
        int encript = caracter-pas;
        fwrite(&encript, sizeof(encript), 1, file);
        aux = aux->siguiente;
    }
    fclose(file);
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
    char cars;
    while(feof(file)==0){
        cars = fgetc(file);
        //printf("%d", caracter);
    }
    encriptado();
    return 0;
}