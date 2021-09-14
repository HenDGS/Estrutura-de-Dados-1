#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <new>
#include <string.h>
#include <time.h>
#include <fstream>
#include <string>


using namespace std;

#define TAMANHO 50
#define TAMANHO_LISTA 15000000
#define LISTAGRAVADASEQ "listaseq.txt"
#define clrscr() cout <<"\n\n\n\n\n\n\n\n\n\n"

typedef struct listasequencial Lista;
typedef struct data Dados;
typedef struct node Node;

struct data{
    char nome[TAMANHO];
    long int rg;
};

struct node{
    Dados dados;
    Node *proximo;
};

struct listasequencial{
    unsigned long int numeroElementos;
    unsigned long int tamanhoDaLista;
    Dados *dados;
};

void lerListaSequencial(char *nomeArquivo, Lista *lista);
void imprimeListaSequencial(Lista* lista);
Lista* criarLista(unsigned long int tamanhoDaLista);
int checarListaCheia(Lista* lista);
int checarListaVazia(Lista* lista);
void inserirDadoInicioListaSequencial(Lista* lista, Dados info, int imprime);
void inserirDadoFimListaSequencial(Lista* lista, Dados info, int imprime);
void inserirDadoNListaSequencial(Lista* lista, Dados info, unsigned long int numero, int imprime);
void removerDadoInicioListaSequencial(Lista* lista);
void removerDadoFimListaSequencial(Lista* lista);
void removerDadoNListaSequencial(Lista* lista, unsigned long int numero);
void buscaRGSequencial(Lista* lista);
void gravarArquivoSequencial(Lista* lista);
void incluirNovoDadoSequencial(Lista *lista);
void OpcoesListaSequencial(Lista *listaSeq);
#endif // LISTASEQUENCIAL_H_INCLUDED
