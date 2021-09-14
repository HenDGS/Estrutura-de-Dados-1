#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void carregapalavras(vector<string>& palavras){
	int i;
	string rr, arquivo = "Historia.txt";
	ifstream infile;
	infile.open(arquivo);
	for (i = 0; i < 1000; i++){
        infile >> rr;
		palavras.push_back(rr);
	}
}

void buscasequencial(vector<string>& palavras, string busca, int& cont){
    int i=0;
	while (cont > 0){
        if (palavras[i] == busca){
            cout << "Achei " << busca << " na posicao " << i + 1 << endl;
        }
        i++;
        cont--;
	}
	if (cont == 0){
		cout << "Não achei a palavra\n";
	}
}

int main(){
	vector<string> palavras(0);
    carregapalavras(palavras);
    int cont = palavras.size();
    string busca;
    cout << "Digite a sua palavra: ";
    getline(cin, busca);
    int i=0;
    while (1){
        cout << "Digite 1 para busca sequencial, 2 para busca binaria e 3 para arvore e 4 para sair.\n";
        cin >> i;
        switch(i){
            case 1:
                buscasequencial(palavras, busca, cont);
            case 2:
                cout << "";
            case 4:
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
