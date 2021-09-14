#include "listasequencial.h"

void lerListaSequencial(char *nomeArquivo, Lista *lista){
    char ch;
    char buffer[TAMANHO];
    int cont = 0;
    int pular = 0;
    int escrever = 0;
    unsigned long int quantidade = lista->numeroElementos;
    Dados info;
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "r");
	if(arquivo == NULL){
        cout << "Não foi possível abrir o arquivo " << nomeArquivo << "\n";
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

            if(escrever == 1 && lista->numeroElementos < lista->tamanhoDaLista){
                lista->dados[quantidade] = info;
                lista->numeroElementos++;
                escrever = 0;
                quantidade++;
            }
	    }

	}
	fclose(arquivo);
	cout << "Arquivo lido com sucesso.\n";
}

void imprimeListaSequencial(Lista* lista){
    if(lista != NULL){
        for(unsigned long int i=0; i < lista->numeroElementos; i++){

            cout << "Cadastro: " << i+1 << "\n";
            cout << " Nome: " << lista->dados[i].nome << "\n";
            cout << " RG: " << lista->dados[i].rg << "\n\n";
        }
    }
    OpcoesListaSequencial(lista);
}

Lista* criarLista(unsigned long int tamanhoDaLista){
    Lista* lista;
    lista = new Lista;
    lista->dados = (Dados*)malloc(sizeof(Dados)*tamanhoDaLista);

    lista->numeroElementos = 0;
    lista->tamanhoDaLista = tamanhoDaLista;
    return lista;
}

int checarListaCheia(Lista* lista){

    if(lista->tamanhoDaLista == lista->numeroElementos)
        return 1;
    else
        return 0;
}

int checarListaVazia(Lista* lista){
    if(lista->numeroElementos == 0)
        return 1;
    else
        return 0;
}

void inserirDadoInicioListaSequencial(Lista* lista, Dados info, int imprime){

    if((lista->numeroElementos < lista->tamanhoDaLista) && lista != NULL){

        Dados aux;
        aux = lista->dados[0];
        lista->dados[0] = info;
        unsigned long int numeroIfs = 1;
        unsigned long int numeroCopias = 0;
        numeroCopias++;

        clock_t ticks[2];
        ticks[0] = clock();

        for(unsigned long int i = (lista->numeroElementos); i > 1; i--){
            lista->dados[i] = lista->dados[i-1];
            numeroCopias++;
        }
        lista->dados[1] = aux;
        numeroCopias++;
        lista->numeroElementos++;

        if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro 1:\n\n";
            cout << " Nome: " << lista->dados[0].nome << "\n";
            cout << " RG: " << lista->dados[0].rg << "\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);
            OpcoesListaSequencial(lista);
        }

    }

}

void inserirDadoFimListaSequencial(Lista* lista, Dados info, int imprime){

    clock_t ticks[2];
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;

    ticks[0] = clock();
    if((lista->numeroElementos < lista->tamanhoDaLista) && lista != NULL){
        lista->dados[lista->numeroElementos] = info;
        lista->numeroElementos++;
        numeroIfs++;

        if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro " << lista->numeroElementos << "\n\n";
            cout << " Nome: " << lista->dados[lista->numeroElementos-1].nome << "\n";
            cout << " RG: " << lista->dados[lista->numeroElementos-1].rg << "\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);
            OpcoesListaSequencial(lista);
        }
    }

}

void inserirDadoNListaSequencial(Lista* lista, Dados info, unsigned long int numero, int imprime){

    clock_t ticks[2];
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias = 0;

    ticks[0] = clock();

    if((lista->numeroElementos < lista->tamanhoDaLista) && lista != NULL && numero > 0 && numero <= lista->numeroElementos){

        Dados aux;
        aux = lista->dados[numero-1];
        lista->dados[numero-1] = info;
        numeroIfs++;

        for(unsigned long int i = (lista->numeroElementos); i > numero-1; i--){
            lista->dados[i] = lista->dados[i-1];
            numeroCopias++;
        }
        lista->dados[numero] = aux;
        lista->numeroElementos++;
        numeroCopias++;

        if(imprime){
            ticks[1] = clock();
            double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

            cout << "\nCadastro " << numero << "excluido:\n\n";
            cout << " Nome: " << lista->dados[numero].nome << "\n";
            cout << " RG: " << lista->dados[numero].rg << "\n";

            cout << "  Tempo:  " << tempo << "ms\n";
            cout << "  Comparacoes:  " << numeroIfs << "\n";
            cout << "  Copias:  " << numeroCopias << "\n";

            fflush(stdin);
            OpcoesListaSequencial(lista);
        }

    }

}

void removerDadoInicioListaSequencial(Lista* lista){

    clock_t ticks[2];
    unsigned long int numeroIfs = 1;
    unsigned long int numeroCopias = 0;

    ticks[0] = clock();
    Dados aux = lista->dados[0];

    if((lista->numeroElementos > 0) && lista != NULL){

        for(unsigned long int i = 0; i < lista->numeroElementos; i++){
            lista->dados[i] = lista->dados[i+1];
            numeroCopias++;
        }
        lista->numeroElementos--;

        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;



        cout << "\nCadastro 1 excluido:\n\n";
        cout << " Nome: " << aux.nome << "\n";
        cout << " RG: " << aux.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        OpcoesListaSequencial(lista);
    }

}

void removerDadoFimListaSequencial(Lista* lista){

    clock_t ticks[2];
    unsigned long int numeroIfs = 1;
    unsigned long int numeroCopias = 0;

    ticks[0] = clock();
    Dados aux = lista->dados[lista->numeroElementos-1];

    if(lista != NULL && (lista->numeroElementos > 0)){
        lista->numeroElementos--;

        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

        cout << "\nCadastro "<< lista->numeroElementos << " excluido:\n\n";
        cout << " Nome: " << aux.nome << "\n";
        cout << " RG: " << aux.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        OpcoesListaSequencial(lista);
    }
}

void removerDadoNListaSequencial(Lista* lista, unsigned long int numero){

    clock_t ticks[2];
    unsigned long int numeroIfs = 1;
    unsigned long int numeroCopias = 0;

    ticks[0] = clock();
    Dados aux = lista->dados[numero-1];
    numeroCopias++;

    if((lista->numeroElementos > 0) && lista != NULL && numero > 0 && numero <= lista->numeroElementos){

        for(unsigned long int i = numero-1; i < lista->numeroElementos; i++){
            lista->dados[i] = lista->dados[i+1];
            numeroCopias++;
        }
        lista->numeroElementos--;

        ticks[1] = clock();
        double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

        cout << "\nCadastro " << numero << " excluido:\n\n";
        cout << " Nome: " << aux.nome << "\n";
        cout << " RG: " << aux.rg << "\n\n";

        cout << "  Tempo:  " << tempo << "ms\n";
        cout << "  Comparacoes:  " << numeroIfs << "\n";
        cout << "  Copias:  " << numeroCopias << "\n";

        fflush(stdin);
        OpcoesListaSequencial(lista);
    }

}

void buscaRGSequencial(Lista* lista){

    clock_t ticks[2];

    int encontrou = 0;
    unsigned long int numero = 1;
    long int rg;
    unsigned long int numeroIfs = 0;
    unsigned long int numeroCopias= 0;

    cout << "Digite um numero de RG para busca:\n";
    fflush(stdin);
    cin >> rg;

    ticks[0] = clock();
    for(unsigned long int i = 0; i < lista->numeroElementos; i++){

        if(rg ==  lista->dados[i].rg){
            encontrou = 1;
            numero = i;
            break;
        }
        numeroIfs++;
    }

    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "\n*PROCURA EM LISTA SEQUENCIAL*\n";
    if(encontrou){
        cout << "\nCadastro " << numero+1 << " encontrado:\n\n";
        cout << " Nome: " << lista->dados[numero].nome << "\n";
        cout << " RG: " << lista->dados[numero].rg << "\n";
    }
    else {
        cout << "Cadastro de RG numero " << rg << " nao encontrado.\n\n";
    }
    cout << "  Tempo:  " << tempo << "ms\n";
    cout << "  Comparacoes:  " << numeroIfs << "\n";
    cout << "  Copias:  " << numeroCopias << "\n";

    fflush(stdin);
    OpcoesListaSequencial(lista);
}

void gravarArquivoSequencial(Lista* lista){

    FILE *arquivo;
    char buffer[50];
    int virgula;

	arquivo = fopen(LISTAGRAVADASEQ, "w");

	if(arquivo == NULL)
		cout << "Erro, nao foi possivel abrir o arquivo\n";
	else{
        for(unsigned long int i = 0; i < lista->numeroElementos; i++){
            strcpy(buffer, lista->dados[i].nome);
            virgula = strlen(buffer);
            buffer[virgula] = ',';
            buffer[virgula+1] = '\0';
            string s = to_string(lista->dados[i].rg);
            char *ss = new char [s.length()+1];
            strcpy (ss, s.c_str());
            strcat(buffer, ss);
            fprintf(arquivo, "%s", buffer);
            fprintf(arquivo, "%lu\n", lista->dados[i].rg);

        }

		fclose(arquivo);
	}
}

void incluirNovoDadoSequencial(Lista *lista){
    char buffer[TAMANHO];
    Dados info;
    int i = 4;
    long int rg;
    long int n;

    cout << "Digite o nome:\n";
    fflush(stdin);
    fgets(buffer,TAMANHO,stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(info.nome, buffer);

    cout << "Digite um numero de RG:\n";
    fflush(stdin);
    cin >> rg;
    info.rg = rg;

    while(i < 1 || i > 3){

        cout << "\nNovo Cadastro:\n\n";
        cout << " Nome: " << info.nome << "\n";
        cout << " RG: " << info.rg << "\n";
        cout << "Adicionar o novo cadastro no: (1-comeco da lista, 2-fim da lista, 3-meio da lista):\n";
        cin >> i;

        if(i == 1){
            if(!checarListaCheia(lista))
                inserirDadoInicioListaSequencial(lista, info, 1);
        }else if(i == 2){
            if(!checarListaCheia(lista))
                inserirDadoFimListaSequencial(lista, info, 1);
        }else if(i == 3){

            cout << "Em que posicao da lista deseja inserir o novo cadastro?\n";
            cin >> n;

            if(!checarListaCheia(lista))
                inserirDadoNListaSequencial(lista, info, n, 1);
        }

    }

}

void OpcoesListaSequencial(Lista *listaSeq){
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
    cout << "7 para sair\n";

    cin >> i;

    switch(i){
        case 1:
            incluirNovoDadoSequencial(listaSeq);
            break;
        case 2:
            int n;
                cout << "1 para remover do inicio, 2 para remover do final, 3 para remover de uma posicao n\n";
                cin >> n;
                switch (n){
                    case 1:
                        removerDadoInicioListaSequencial(listaSeq);
                        break;
                    case 2:
                        removerDadoFimListaSequencial(listaSeq);
                        break;
                    case 3:
                        clrscr();
                        cout << "Que posicao deseja retirar?\n";
                        cin >> numero;
                        removerDadoNListaSequencial(listaSeq, numero);
                        break;
                }
        case 3:
            buscaRGSequencial(listaSeq);
            break;
        case 4:
            imprimeListaSequencial(listaSeq);
            break;
        case 5:
            gravarArquivoSequencial(listaSeq);
            break;
        case 6:
            long long int d;
            cout << "Qual lista voce deseja? (1 para 10, 2 para 50, 3 para 100, 4 para 1000, 5 para 10000, 6 para 100000, 7 para 1000000)\n";
            cin >> d;
            switch (d){
                case 1:
                    lerListaSequencial("NomeRG10.txt", listaSeq);
                    break;
                case 2:
                    lerListaSequencial("NomeRG50.txt", listaSeq);
                    break;
                case 3:
                    lerListaSequencial("NomeRG100.txt", listaSeq);
                    break;
                case 4:
                    lerListaSequencial("NomeRG1K.txt", listaSeq);
                    break;
                case 5:
                    lerListaSequencial("NomeRG10K.txt", listaSeq);
                    break;
                case 6:
                    lerListaSequencial("NomeRG1M.txt", listaSeq);
                    break;
                case 7:
                    lerListaSequencial("NomeRG100M.txt", listaSeq);
                    break;
            }
        }
    }
}
