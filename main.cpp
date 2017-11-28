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
}
void fCadastra()
{
    int Posicao = fPosicao();
    cin.ignore();

    if (Posicao < 20)
    {
        Agenda[Posicao].codigo = Posicao;
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

    }



}
void fPesquisa()
{

}
void fEdita()
{

}
void fLista()
{
    int I, J;
    fLimpa();
    count << "===============AGENDA===============\n"
    for(I=0; I< 20 || Agenda[I].codigo!=0; I++)
    {
        cout<<Agenda[I].codigo<<"\t"<<Agenda[I].nome<<"\t"<<Agenda[I].telefone<<endl();
    }

}
void fApaga()
{

}
void fSai()
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
    cout<<"caregando...\n";
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
            cout << "1) CADASTRAR\n2) PESQUISAR\n3) EDITAR\n4) LISTAR\n5) APAGAR\n6) SAIR\n\n";
            cin >> Op;
            if(Op == 1)
            {
                fCadastra();
            }

            else
            {
                if (Op == 2)
                {
                    fEdita();
                }

                else
                {
                    if (Op==3)
                    {
                        fLista();
                    }

                    else
                    {
                        if (Op==4)
                        {
                            fApaga();
                        }

                        else
                        {
                            if(Op==5)
                            {
                                fSai();
                            }
                        }
                    }
                }
            }

        }




    return 0;
}

