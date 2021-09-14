#include "listaencadeada.h"
#include "sort.h"


void incluirNovoNodeInicio(Node *head, Dados info, int imprime){

    Node *novoNode = new node;
    clock_t ticks[2];
    ticks[0] = clock();
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;

    if(novoNode != NULL){
        if(head->proximo == NULL){
            head->proximo = novoNode;
            numeroCopias++;
            novoNode->proximo = NULL;
            numeroCopias++;
            novoNode->dados = info;
            numeroCopias++;
        }else{
            novoNode->proximo = head->proximo;
            numeroCopias++;
            head->proximo = novoNode;
            numeroCopias++;
            novoNode->dados = info;
            numeroCopias++;
        }
        numeroIfs++;
    }
    numeroIfs++;

    if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro 1:\n\n";
            cout << " Nome: " << novoNode->dados.nome << "\n";
            cout << " RG: " << novoNode->dados.rg << "\n\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);
            OpcoesListaEncadeada(head);
        }

}

void incluirNovoNodeFim(Node *head, Dados info, int imprime){

    clock_t ticks[2];
        unsigned long int numeroIfs = 1;
        unsigned long int numeroCopias = 0;
    ticks[0] = clock();
    Node *novoNode = new node;
    if(novoNode != NULL){

        novoNode->dados = info;
        novoNode->proximo = NULL;
        Node *aux = head;

        while(aux->proximo != NULL){
            aux = aux->proximo;
            numeroCopias++;
        }
        aux->proximo = novoNode;
        numeroCopias++;

        if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro 1:\n\n";
            cout << " Nome: " << novoNode->dados.nome << "\n";
            cout << " RG: " << novoNode->dados.rg << "\n\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);
            OpcoesListaEncadeada(head);
        }
    }
}


void incluirNovoNodeN(Node *head, Dados info, unsigned long int posicaoN, int imprime){

    clock_t ticks[2];
    unsigned long int numeroIfs = 1;
    unsigned long int numeroCopias = 0;
    unsigned long int numero = 1;
    ticks[0] = clock();

    Node *novoNode = new node;
    if(novoNode != NULL){
        unsigned long int cont = 1;
        novoNode->dados = info;
        Node *aux = head;
        numeroCopias++;

        while(cont < posicaoN){
            aux = aux->proximo;
            cont++;
            numeroCopias++;
            numero++;
        }
        Node *auxProximo = aux->proximo;
        novoNode->proximo = auxProximo;
        aux->proximo = novoNode;

        if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro 1:\n\n";
            cout << " Nome: " << novoNode->dados.nome << "\n";
            cout << " RG: " << novoNode->dados.rg << "\n\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);

            OpcoesListaEncadeada(head);
        }
    }

}

void imprimeListaEncadeada(Node *head){
    Node *elemento = head->proximo;
    unsigned long int cont = 1;
    int i;
    while(elemento != NULL){
        cout << "\nCadastro " << cont << ":\n\n";
        cout << " Nome: " << elemento->dados.nome << "\n";
        cout << " RG: " << elemento->dados.rg << "\n\n";
        elemento = elemento->proximo;
        cont++;
    }
    OpcoesListaEncadeada(head);
}

int verificaPosicao(Node *head, int n){

    if(n < 1)
        return 0;

    Node *elemento = head->proximo;
    int cont = 0;

    while(elemento != NULL){

        elemento = elemento->proximo;
        cont++;
        if(cont == n)
            return 1;
    }
    return 0;

}

void lerListaEncadeada(char *nomeArquivo, Node *head){
    char ch;
    char buffer[TAMANHO];
    int cont = 0;
    int pular = 0;
    int escrever = 0;
    Dados info;
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "r");
	if(arquivo == NULL){
	    cout << "Não foi possível abrir o arquivo "<< nomeArquivo << "\n";
	}else{
	    while( (ch = fgetc(arquivo))!= EOF ){

            if(pular == 0)
                buffer[cont] = ch;

            if(ch == ','){
                buffer[cont] = '\0';
                strcpy(info.nome,buffer);
                cont = 0;
            }
            if(ch == '\n'){
                pular = 1;
                buffer[cont] = '\0';
                info.rg = atol(buffer);
            }
            if(ch != ','){
                cont++;
            }

            if(pular == 1){
                pular = 0;
                cont = 0;
                escrever = 1;
            }

            if(escrever == 1){
                incluirNovoNodeInicio(head, info, 0);
                escrever = 0;
                cont = 0;
            }
	    }

	}
	fclose(arquivo);
	cout << "Arquivo lido com sucesso.\n";
}

void removerNodeFim(Node **head){

    clock_t ticks[2];
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;
    unsigned long int numero = 1;
    ticks[0] = clock();

    if((*head)->proximo != NULL){

        numeroIfs++;
        Node *nodeAtual = (*head)->proximo;
        numeroCopias++;
        Node *nodeAnterior = (*head)->proximo;
        numeroCopias++;

        while(nodeAtual->proximo != NULL){
            nodeAnterior = nodeAtual;
            numeroCopias++;
            nodeAtual = nodeAtual->proximo;
            numeroCopias++;
            numero++;
        }

        if(nodeAnterior == nodeAtual){
            (*head) = nodeAtual->proximo;
        }else{
            nodeAnterior->proximo = nodeAtual->proximo;
        }
        numeroIfs++;

        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        cout << "\nCadastro 1:\n\n";
        cout << " Nome: " << nodeAtual->dados.nome << "\n";
        cout << " RG: " << nodeAtual->dados.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        free(nodeAtual);
        OpcoesListaEncadeada(*head);
    }

}

void removerNodeInicio(Node **head){

    clock_t ticks[2];
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;
    unsigned long int numero = 1;
    ticks[0] = clock();

    if((*head)->proximo != NULL){

        numeroIfs++;
        Node *aux = *head;
        numeroCopias++;
        *head = aux->proximo;
        numeroCopias++;


        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        cout << "\nCadastro 1:\n\n";
        cout << " Nome: " << aux->dados.nome << "\n";
        cout << " RG: " << aux->dados.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        free(aux);
        OpcoesListaEncadeada(*head);
    }
}

void removerNodeN(Node **head, unsigned long int numero){

    clock_t ticks[2];
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;
    unsigned long int numeroNode = 1;
    ticks[0] = clock();

    if((*head)->proximo != NULL && verificaPosicao(*head, numero)){

        numeroIfs++;
        Node *nodeAtual = (*head)->proximo;
        Node *nodeAnterior = (*head)->proximo;
        numeroCopias++;
        numeroCopias++;

        for(unsigned long int i=1; i < numero; i++){
            nodeAnterior = nodeAtual;
            numeroCopias++;
            nodeAtual = nodeAtual->proximo;
            numeroCopias++;
            numeroNode++;
        }

        if(nodeAnterior == nodeAtual){
            (*head) = nodeAtual->proximo;
        }else
            nodeAnterior->proximo = nodeAtual->proximo;
        numeroIfs++;

        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        cout << "\nCadastro 1:\n\n";
        cout << " Nome: " << nodeAtual->dados.nome << "\n";
        cout << " RG: " << nodeAtual->dados.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        free(nodeAtual);
        OpcoesListaEncadeada(*head);
    }
}

void buscaRGEncadeado(Node *head){
    clock_t ticks[2];

    int encontrou = 0;
    unsigned long int numero = 1;
    long int rg;
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias= 1;
    Node *aux = head->proximo;

    cout << "Digite um numero de RG para busca:\n";
    fflush(stdin);
    cin >> rg;

    ticks[0] = clock();
    for(unsigned long int i = 1; aux != NULL; i++){

        if(rg == aux->dados.rg){
            encontrou = 1;
            numero = i;
            break;
        }
        aux = aux->proximo;
        numeroCopias++;
        numeroIfs++;
    }

    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "\n*PROCURA EM LISTA ENCADEADA*\n";
    if(encontrou){
        cout << "\nCadastro "<< numero << " encontrado:\n\n";
        cout << " Nome: " << aux->dados.nome << "\n";
        cout << " RG: " << aux->dados.rg << "\n\n";
    }else{
        cout << "Cadastro de RG numero " << rg << " nao encontrado.\n\n";
    }
        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

    fflush(stdin);
    OpcoesListaEncadeada(head);
}

void gravarArquivoEncadeado(Node *head){

    FILE *arquivo;
    char buffer[50];
    int virgula;
    Node *aux = head->proximo;

	arquivo = fopen(LISTAGRAVADAENC, "w");
	string s = to_string(aux->dados.rg);

    char *ss = new char [s.length()+1];
    strcpy (ss, s.c_str());

	if(arquivo == NULL)
		cout << "Erro, nao foi possivel abrir o arquivo\n";
	else{
        while(aux != NULL){
            strcpy(buffer, aux->dados.nome);
            virgula = strlen(buffer);
            buffer[virgula] = ',';
            buffer[virgula+1] = '\0';
            strncat(buffer, ss, 50);
            fprintf(arquivo, "%s\n", buffer);
            aux = aux->proximo;
        }

		fclose(arquivo);
	}
}

void incluirNovoDadoEncadeado(Node *head){
    char buffer[TAMANHO];
    Dados info;
    int i = 4;
    unsigned long int n;
    cout << "Digite o nome:\n";
    fflush(stdin);
    fgets(buffer,TAMANHO,stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(info.nome, buffer);

    cout << "Digite um numero de RG:\n";
    fflush(stdin);
    cin >> info.rg;

    while(i < 1 || i > 3){

        cout << "\nNovo Cadastro:\n\n";
        cout << " Nome: " << info.nome << "\n";
        cout << " RG: " << info.rg << "\n\n";
        cout << "Adicionar o novo cadastro no: (1-comeco da lista, 2-fim da lista, 3-meio da lista):\n";
        cin >> i;

        if(i == 1){
            incluirNovoNodeInicio(head, info, 1);
        }else if(i == 2){
            incluirNovoNodeFim(head, info, 1);
        }else if(i == 3){

            cout << "Em que posicao da lista deseja inserir o novo cadastro?\n";
            cin >> n;

            if(verificaPosicao(head, n))
                incluirNovoNodeN(head, info, n, 1);
            else
                cout <<"ERRO: posicao invalida.\n";

        }

    }

}

void OpcoesListaEncadeada(Node *listaEnc){

    int i;
    long long int numero;

    while (i!=7){
        cout << "\nSelecione a operacao: \n";
        cout << "1 para inserir um dado\n";
        cout << "2 para remover um dado\n";
        cout << "3 para busca\n";
        cout << "4 para mostrar a lista\n";
        cout << "5 para salvar a lista\n";
        cout << "6 para ler a lista\n";
        cout << "7 para sort\n";
        cout << "8 para sair\n";

        cin >> i;

        switch(i){
            case 1:
                incluirNovoDadoEncadeado(listaEnc);
                break;
            case 2:
                int n;
                cout << "1 para remover do inicio, 2 para remover do final, 3 para remover de uma posicao n\n";
                cin >> n;
                switch (n){
                    case 1:
                        removerNodeInicio(&listaEnc);
                        break;
                    case 2:
                        removerNodeFim(&listaEnc);
                        break;
                    case 3:
                        cout << "Que posicao deseja retirar?\n";
                        cin >> numero;
                        removerNodeN(&listaEnc, numero);
                        break;
                }
            case 3:
                buscaRGEncadeado(listaEnc);
                break;
            case 4:
                imprimeListaEncadeada(listaEnc);
                break;
            case 5:
                gravarArquivoEncadeado(listaEnc);
                break;
            case 6:
                long long int d;
                cout << "Qual lista voce deseja? (1 para 10, 2 para 50, 3 para 100, 4 para 1000, 5 para 10000, 6 para 100000, 7 para 1000000)\n";
                cin >> d;
                switch (d){
                    case 1:
                        lerListaEncadeada("NomeRG10.txt", listaEnc);
                        break;
                    case 2:
                        lerListaEncadeada("NomeRG50.txt", listaEnc);
                        break;
                    case 3:
                        lerListaEncadeada("NomeRG100.txt", listaEnc);
                        break;
                    case 4:
                        lerListaEncadeada("NomeRG1K.txt", listaEnc);
                        break;
                    case 5:
                        lerListaEncadeada("NomeRG10K.txt", listaEnc);
                        break;
                    case 6:
                        lerListaEncadeada("NomeRG1M.txt", listaEnc);
                        break;
                    case 7:
                        lerListaEncadeada("NomeRG100M.txt", listaEnc);
                        break;
                }
        }
    }
}
