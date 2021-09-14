#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

#include "listasequencial.h"
#define LISTAGRAVADAENC "listaenc.txt"

void incluirNovoNodeInicio(Node *head, Dados info, int imprime);
void incluirNovoNodeFim(Node *head, Dados info, int imprime);
void incluirNovoNodeN(Node *head, Dados info, unsigned long int posicaoN, int imprime);
void imprimeListaEncadeada(Node *head);
int verificaPosicao(Node *head, int n);
void lerListaEncadeada(char *nomeArquivo, Node *head);
void removerNodeFim(Node **head);
void removerNodeInicio(Node **head);
void removerNodeN(Node **head, unsigned long int numero);
void buscaRGEncadeado(Node *head);
void incluirNovoDadoEncadeado(Node *head);
void gravarArquivoEncadeado(Node *head);
void OpcoesListaEncadeada(Node *listaEnc);

#endif // LISTAENCADEADA_H_INCLUDED
