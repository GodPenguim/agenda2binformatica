#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;

struct Tagenda
{
    int codigo;
    char nome[40];
    char telefone[15];
} Agenda[20];
void fLimpa()
{
    int I;
    for(I=0; I < 30; I++)
    {
        cout << "\n";
    }
}
int fPosicao(void)
{
    int I;
    for(I=0; I < 20; I++)
    {
        if (Agenda[I].codigo == 0)
                    return I;

    }
    return I;
}
void fCadastra()//murilo
{
    int Posicao = fPosicao();
    cin.ignore();

    if (Posicao < 20)
    {
        fLimpa();
        cout<<"==================CADASTRO======================\n";
        Agenda[Posicao].codigo = Posicao+1;
        cout << "\nNOME:\t";
        cin.getline(Agenda[Posicao].nome, sizeof(Agenda[Posicao].nome));
        while (strlen(Agenda[Posicao].nome)< 40)
        {
            strcat(Agenda[Posicao].nome, ".");
        }

        cout << "\nTELEFONE:\t";
        cin.getline(Agenda[Posicao].telefone, sizeof(Agenda[Posicao].telefone));
        while(strlen(Agenda[Posicao].telefone) < 15)
        {
            strcat (Agenda[Posicao].telefone, " ");
        }

    } else
    {
        cout<<"agenda cheia\n";
    }

}
int fPesquisa( char Nome[40])
{
    int I;
    for(I=0;Agenda[I].codigo !=0; I++)
    {
        if(strcmp(Nome, Agenda[I].nome))
        {
            return I;
        }

    }

    return -1;
}
void fEdita()
{
    char NomeEdita[40];
    cout<<"NOME DO CONTAO:\t";
    cin.getline(NomeEdita, 40);
    int Ind = fPesquisa(NomeEdita);
    if(Ind != -1)
        {

            cout << "NOVO NOME:\t";
            cin.ignore();
            cin.getline(Agenda[Ind].nome, 40);

            cout<<"NOVO TELEFONE\n";
            cin.getline(Agenda[Ind].telefone, 15);
            cout <<"CONTATO EDITADO!";
        } else
        cout << "CÓDIGO DE INVOCADOR NÃO ENCONTRADO!\n"<<endl;
}
void fLista()
{
    cin.ignore();
    int I, J;
    fLimpa();
    cout << "========================LISTAGEM=========================\n";

    for(I=0;  Agenda[I].codigo!=0; I++)
    {
        cout << Agenda[I].codigo << "\t"<<Agenda[I].nome<<"\t" << Agenda[I].telefone<<"\n\n"<<endl;
    }

    cout<<"precione uma tecla para continuar";
    cin.get();

}
void fApaga()
{
    cin.ignore();
    char Nome[40];
    cout<<"NOME DO CONTATO A SER EXCLUÍDO:\t";
    cin.getline(Nome, 40);

    int Indice = fPesquisa(Nome);
    if(Indice != -1)
    {
        Agenda[Indice].codigo = 0;
        cout << "CONTATO APAGADO COM SUCESSO!\n"<<endl;
    } else
    {
        cout << "CONTATO NAO ENCONTRADO\n"<<endl;
    }

}

void fSalva()
{

}


int main()
{
    //variaveis
    int I, J, Op = 0, X = 0;
    char Buff[58];

    for(I=0; I < 20; I++)
    {
        Agenda[I].codigo = 0;
    }
    ifstream leitura;
    leitura.open("Agenda.txt");
    if(!leitura.is_open( ))
    {
        cout<<"Não foi possível abrir arquivo! agenda vazia\n";
        leitura.clear( );
    } else
    {
        J=0;
        while(leitura.getline(Buff, 58))
        {
            Agenda[J].codigo = Buff[0];
            for (I=0; I < 40; I++)
            {
                Agenda[J].nome[I] = Buff[I+2];
            }
            for(I = 0; I < 15; I++)
            {
                Agenda[J].telefone[I] = Buff[I+43];
            }
            J++;
        }
    }

        while (Op != 6)
        {

            cout << "================AGENDA==================\n"<<endl;
            cout << "1) CADASTRAR\n2) PESQUISAR\n3) EDITAR\n4) LISTAR\n5) APAGAR\n6) SALVAR\n7) SAIR\n\n";
            cin >> Op;
            if(Op == 1)
            {
                fCadastra();
            }
            else
            {
                if (Op == 2)
                {
                    char Nome2[40], Op2;
                    cout<<"DIGITE O NOME DO CONTATO A SER PESQUISADO:\t";
                    cin.getline(Nome2, 40);

                    int Integer = fPesquisa(Nome2);
                    if(Integer!= -1)
                    {
                        cout<<"CONTATO ENCONTRDO!\nDESEJA IMPRIMIR SEUS DADOS?\nS/N: ";
                        cin >> Op2;
                        if (Op2 == 'S')
                            cout<<"\n"<<Agenda[Integer].codigo<<"\t"<<Agenda[Integer].nome<<"\t"<<Agenda[Integer].telefone<<endl;
                    }
                }

                else
                {
                    if (Op==3)
                    {
                        fEdita();
                    }

                    else
                    {
                        if (Op==4)
                        {
                            fLista();
                        }

                        else
                        {
                            if(Op==5)
                            {
                                fApaga();
                            }

                            else
                            {
                                if (Op==6)
                                {
                                    fSalva();
                                }


                                else
                                {
                                    if (Op==7)
                                    {
                                        cout<<"DESEJA SALVAR ANTES DE SAIR?";
                                        cout<<"S/N?";
                                        char Decisao;
                                        cin >> Decisao;
                                        if(Decisao == 'S')
                                            fSalva();
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }




    return 0;
}

