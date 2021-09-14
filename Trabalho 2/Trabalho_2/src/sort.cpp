#include "sort.h"

void selectionSort(Lista *lista) {
    //declaracao de auxiliar de dados
    Dados aux;
    unsigned long long menor;
    unsigned long int numeroIf = 0, numeroTrocas = 0;
    clock_t ticks[2];

    //selection sort
    ticks[0] = clock();
    for (unsigned long long int i = 0; i < lista->numeroElementos; i ++){
        //menor recebe o indice atual
        menor = i;
        //percorre o vetor procurando menores valores de rg para jogar no menor valor
        for(unsigned long long int j = i+1; j < lista->numeroElementos; j++){
            if(lista->dados[j].rg < lista->dados[menor].rg){
                menor = j;
                numeroIf++;
            }
        }
        /*transfere o valor do indice pra um auxiliar
        depois poe o menor valor no indice atual
        e enfim o menor valor recebe o auxiliar*/
        aux = lista->dados[i];
        lista->dados[i] = lista->dados[menor];
        lista->dados[menor] = aux;
        numeroTrocas = numeroTrocas+3;
    }

    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n -numero Ifs : %lu\n", numeroIf);
    printf("\n -numero Trocas : %lu\n", numeroTrocas);
    printf("\n -tempo : %g ms.\n", tempo);
}

void insertionSort(Lista *lista) {
    //declaracao de auxiliar de dados
    Dados aux;
    long long int j;
    unsigned long int numeroIf = 0, numeroTrocas = 0;
    clock_t ticks[2];


    ticks[0] = clock();
    for(long long int i = 1; i < lista->numeroElementos; i++){
        aux = lista->dados[i];
        j = i-1;
        numeroTrocas++;
        while((j>=0) && (lista->dados[j].rg > aux.rg)){
            lista->dados[j+1] = lista->dados[j];
            j--;
            numeroTrocas++;
        }

        lista->dados[j+1] = aux;
        numeroTrocas++;
    }

    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n -numero Ifs : %lu\n", numeroIf);
    printf("\n -numero Trocas : %lu\n", numeroTrocas);
    printf("\n -tempo : %g ms.\n", tempo);
}

void quickSort(Lista *lista, unsigned long int inicioVetor, unsigned long int fimVetor){

    unsigned long int i = inicioVetor;
    unsigned long int j = fimVetor;
    long int pivo = lista->dados[((i+j)/2)].rg;

    Dados aux;

    while( i < j){

        while(lista->dados[i].rg < pivo){
            i++;
        }

        while(lista->dados[j].rg > pivo){
            j--;
        }

        if(i <= j){

            aux = lista->dados[i];
            lista->dados[i] = lista->dados[j];
            lista->dados[j] = aux;
            i++;
            j--;

        }

    }

    if(j > inicioVetor)
        quickSort(lista, inicioVetor, j);
    if(i < fimVetor)
        quickSort(lista, i, fimVetor);

}

void mergeS(Dados *dados, unsigned long int comeco, unsigned long int meio, unsigned long int fim) {

    //declaracao de variaveis
    unsigned long int comIni = comeco, comMeio = meio+1, comAux = 0, tamanho = fim-comeco+1;
    Dados *aux;
    aux = (Dados*)malloc(tamanho * sizeof(Dados));

    /*percorre as metades e ordena eles
    caso seja necessario
    deixando os menores do lado do comeco
    e os maiores do lado do fim*/
    while(comIni <= meio && comMeio <= fim){

        if(dados[comIni].rg <= dados[comMeio].rg) {
            aux[comAux] = dados[comIni];
            comIni++;
        }else{
            aux[comAux] = dados[comMeio];
            comMeio++;
        }
        comAux++;
    }

    //se continuar tendo elementos na primeira metade
    while(comIni <= meio){
        aux[comAux] = dados[comIni];
        comAux++;
        comIni++;
    }
    //se continuar tendo elementos na segunda metade
    while(comMeio <= fim) {
        aux[comAux] = dados[comMeio];
        comAux++;
        comMeio++;
    }

    //move pro vetor de dados original
    for(comAux = comeco; comAux <= fim; comAux++){
        dados[comAux] = aux[comAux-comeco];
    }

    free(aux);
}

void mergeSort(Lista *lista, unsigned long int comeco, unsigned long int fim){
    /*vai dividindo a lista em metades iguais
    depois ordena elas*/
    unsigned long int meio = (fim+comeco)/2;

    if (comeco < fim) {
        mergeSort(lista, comeco, meio);
        mergeSort(lista, meio+1, fim);
        mergeS(lista->dados, comeco, meio, fim);
    }
}

void bubbleSort(Lista *lista, unsigned long int tamanho){

    Dados aux;
    unsigned long int numeroIf = 0, numeroTrocas = 0;
    clock_t ticks[2];

    ticks[0] = clock();
    for(unsigned long int i=0; i < tamanho; i++){
        for(unsigned long int j=0; j < tamanho-i-1; j++){
            if(lista->dados[j].rg > lista->dados[j+1].rg){
                aux = lista->dados[j];
                lista->dados[j] = lista->dados[j+1];
                lista->dados[j+1] = aux;
                numeroIf++;
                numeroTrocas = numeroTrocas+3;
            }

        }
    }
    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n -numero Ifs : %lu\n", numeroIf);
    printf("\n -numero Trocas : %lu\n", numeroTrocas);
    printf("\n -tempo : %g ms.\n", tempo);


}

void shellSort(Lista *lista, unsigned long int tamanho){

    long int i, j, gap = 1;
    Dados aux;
    unsigned long int numeroIf = 0, numeroTrocas = 0;
    clock_t ticks[2];

    ticks[0] = clock();
    while(gap < tamanho){
        gap = 3*gap+1;
    }
    while(gap > 1){
        gap /=3;
        for(i = gap; i < tamanho; i++){
            aux = lista->dados[i];
            numeroTrocas++;
            j = i;
            while((j >= gap) && (aux.rg < lista->dados[j-gap].rg)){
                lista->dados[j] = lista->dados[j - gap];
                numeroTrocas++;
                j = j - gap;
            }
            lista->dados[j] = aux;
            numeroTrocas++;
        }

    }

    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n -numero Ifs : %lu\n", numeroIf);
    printf("\n -numero Trocas : %lu\n", numeroTrocas);
    printf("\n -tempo : %g ms.\n", tempo);
}

void buscaBinaria(Lista *lista, unsigned long int tamanho){
    //declaração de variaveis
    long int limiteInferior = 0;
    long int limiteSuperior = tamanho - 1;
    long int meio;
    int encontrou = 0;
    long int rgBuscado;
    unsigned long int numeroIf = 0;
    clock_t ticks[2];


    printf("Digite o RG que deseja encontrar:\n");
    scanf("%ld", &rgBuscado);

    ticks[0] = clock();
    //mecanismo de busca binaria
    while(!encontrou && limiteInferior <= limiteSuperior){
        meio = (limiteInferior + limiteSuperior)/2;
        if(rgBuscado == lista->dados[meio].rg){
            encontrou = 1;
            numeroIf++;
        }else if(rgBuscado < lista->dados[meio].rg){
            limiteSuperior= meio-1;
            numeroIf++;
        }else{
            limiteInferior = meio+1;
            numeroIf++;
        }
    }
    ticks[1] = clock();
    double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    //mostra o resultado
    if(encontrou){
        printf("Resultado encontrado\n\n");
        printf(" -NOME: %s\n", lista->dados[meio].nome);
        printf(" -RG: %lu\n", lista->dados[meio].rg);
    }else{
        printf("Resultado não encontrado para o RG: %lu\n\n", rgBuscado);
    }

    //saindo da busca
    printf("\n -numero Ifs : %lu\n", numeroIf);
    printf("\n -tempo : %g ms.\n", tempo);
    printf("digite qualquer numero para sair...");
    scanf("%lu", &rgBuscado);

}
