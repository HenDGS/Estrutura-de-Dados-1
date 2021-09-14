#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <new>
#include <string.h>
#include <time.h>
#include <fstream>
#include "listasequencial.h"
#include "listaencadeada.h"

using namespace std;

int main(){
    int i;
    Node *listaEnc = new node;
    listaEnc->proximo = NULL;
    Lista *listaSeq;
    listaSeq = criarLista(TAMANHO_LISTA);

    while (i !=3){
        cout << "Qual lista deseja escolher?\n";
        cout << "Para encadeada, digite 1\n";
        cout << "Para sequencial, digite 2\n";
        cout << "Digite 3 para sair\n";

        cin >> i;

        switch(i){
            case 1:
                OpcoesListaEncadeada(listaEnc);
            case 2:
                OpcoesListaSequencial(listaSeq);
        }
    }
    return 0;
}

