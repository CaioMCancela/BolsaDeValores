#include <iostream>
#include <cstring>

using namespace std;

struct StockExchange {
    char ticket[7];
    int quantidade;
    float SomaValor;
};

int PesquisaBinaria(StockExchange vetor[250], char nome[7]){
    for(int i=0; i<250; i++){
        if(strcmp(vetor[i].ticket, nome) == 0){
            return i;
        }
    }
    return -1;
}

void ComprarTicket(StockExchange vetor[250], int &totalTickets) {
    char CodBuscado[7];
    int quantidade;
    float valor;

    cout << "Digite o codigo da acao que pretende comprar: ";
    fflush(stdin);
    cin.getline(CodBuscado, size(CodBuscado));
    cout << "Digite a quantidade da acao: ";
    cin >> quantidade;
    cout << "Digite o valor da acao: ";
    cin >> valor;

    int resultado = PesquisaBinaria(vetor, CodBuscado);

    if (resultado < 0) {
        strcpy(vetor[totalTickets].ticket, CodBuscado);
        vetor[totalTickets].quantidade = quantidade;
        vetor[totalTickets].SomaValor = valor * quantidade;
        totalTickets++;
    } else {
        StockExchange &acao = vetor[resultado];
        acao.SomaValor += valor * quantidade;
        acao.quantidade += quantidade;
    }
}

void RetirarTicket(StockExchange vetor[250], int &totalTickets) {
    char CodBuscado[7];
    int quantidade;
    float valor;

    cout << "Digite o codigo da acao que pretende vender: ";
    fflush(stdin);
    cin.getline(CodBuscado, size(CodBuscado));
    cout << "Digite a quantidade a ser vendida: ";
    cin >> quantidade;
    cout << "Digite o valor da acao no momento da venda: ";
    cin >> valor;

    int resultado = PesquisaBinaria(vetor,CodBuscado);

    if (resultado >= 0) {
        StockExchange &acao = vetor[resultado];
        if (acao.quantidade >= quantidade) {
            acao.quantidade -= quantidade;
            cout << "Venda registrada com sucesso!" << endl;

            if (acao.quantidade == 0) {
                for (int i = resultado; i < totalTickets - 1; i++) {
                    vetor[i] = vetor[i + 1];
                }
                totalTickets--;
                cout << "Ticket removido, pois a quantidade chegou a zero." << endl;
            }
        } else {
            cout << "Erro: Quantidade insuficiente para venda!" << endl;
        }
    } else {
        cout << "Erro: Ativo nao encontrado!" << endl;
    }
    system("pause");
}

void PesquisarTicket(StockExchange vetor[250]) {
    char item[7];
    cout << "Digite o item pesquisado: ";
    fflush(stdin);
    cin.getline(item, size(item));

    int resultado = PesquisaBinaria(vetor,item);

    if (resultado >= 0) {
        StockExchange &acao = vetor[resultado];
        float media = acao.SomaValor / acao.quantidade;
        cout << endl << "Codigo: " << acao.ticket << " ,Quantidade: " << acao.quantidade<< " ,Valor medio: " << media << endl;
    } else {
        cout << "Ativo nao encontrado!" << endl;
    }
    system("pause");
}

void ListarPatrimonio(StockExchange vetor[250], int totalTickets) {
    for (int i = 0; i < totalTickets; i++) {
        float media = vetor[i].SomaValor / vetor[i].quantidade;
        cout << "Codigo: " << vetor[i].ticket<< " ,Quantidade: " << vetor[i].quantidade<< " ,Valor medio: " << media << endl;
    }
    system("pause");
}

int main() {
    StockExchange acao[250];
    int selecao,totalTickets = 0;

    while (true) {
        system("cls");
        cout <<  "SISTEMA DE CONTROLE DE BOLSA DE VALORES" << endl << endl << "Menu Principal" << endl;
        cout << "1. Adicionar tickets" << endl << "2. Retirar tickets" << endl << "3. Saldo do tickets" << endl;
        cout << "4. Listar Patrimonio" << endl << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> selecao;

        switch (selecao) {
            case 1:
                ComprarTicket(acao, totalTickets);
                break;
            case 2:
                RetirarTicket(acao, totalTickets);
                break;
            case 3:
                PesquisarTicket(acao);
                break;
            case 4:
                ListarPatrimonio(acao, totalTickets);
                break;
            case 5:
                exit(0);
            default:
                cout << "Opcao não encontrada, por favor tente novamente";
                break;
        }
    }
    return 0;
}
