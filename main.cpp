#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int     Codigo, I;
char    Nome[40], NomeComp[40];
char    Telefone[15];
char    Buff[58];


void fLimpa()
{
    int I;
    for(I=0; I < 30; I++)
    {
        cout << "\n";
    }
}

void fCadastra()
{
    int J, Encontrou ;
    fstream AGENDATXT ("Agenda.txt", ios_base::app);


    do
    {
         Encontrou = 0;
        //le o nome, coloa em maiusculo e preenche com pontos
        fLimpa();
        cout<<"=======================CADASTRO=============================\n";
        cin.ignore();
        cout<< "NOME:\t";
        cin.getline(Nome, 40);
        strupr(Nome);
        while (strlen(Nome)< 40)
        {
            strcat(Nome, ".");
        }

        fstream Pesquisa;
        Pesquisa.open("Agenda.txt");
        J=1;
        while(!Pesquisa.eof() && Encontrou == 0)
        {
            Pesquisa.getline(Buff, 58);
            for(I=0; I<40; I++)
            {
                NomeComp[I] = Buff[I];
            }

            if (!strcmp(NomeComp, Nome))
            {
                Encontrou = 1;
                cout<<"NOME JÁ CADASTRADO! TENTE NOVAMENTE\nPRECIONE ENTER PARA CONTINUAR\n";
                cin.ignore();

            }
            J++;

        }

        Pesquisa.close();
    } while (Encontrou == 1);


    cout<<"TELEFONE:\t";
    cin.getline(Telefone, 15);
    while (strlen(Telefone)< 15)
    {
        strcat(Telefone, ".");
    }
    AGENDATXT <<J-1<<"\t"<< Nome << "\t" << Telefone<< "\n";
    AGENDATXT.close();
    cout<<"CADASTRADO COM SUCESSO!!\nTECLE ENTER PARA CONTINUAR\n";
    cin.get();

}
void fPesquisa()
{
    int Encontrou = 0;
    fLimpa();
    cout<<"digite o nome a ser pesquisado:\n";
    cin.ignore();
    cin.getline(Nome, 40);
    strupr(Nome);
    while (strlen(Nome)< 40)
    {
        strcat(Nome, ".");
    }
    fstream Pesquisa;
    Pesquisa.open("Agenda.txt");
    while(!Pesquisa.eof() && Encontrou == 0)
    {
        Pesquisa.getline(Buff, 58);
        for(I=0; I<40; I++)
        {
            NomeComp[I] = Buff[I];
        }

        if (!strcmp(NomeComp, Nome))
        {
            Encontrou = 1;
        }

    }
    if(Encontrou)
        cout<<"NOME EXISTENTE\n"; else cout << "NOME NAO ENCONTRADO\n";
        cout<< "PRECIONE ENTER PARA COTINUAR\n";
        cin.get();
        Pesquisa.close();

}
void fEdita()
{
    int Encontrou = 0, J;
    fLimpa();
    cout<<"========================EDIÇAO=======================\n";
    cout<<"DIGITE O NOME DO CONTATO A SER EDITADO:\n";
    cin.ignore();
    cin.getline(Nome, 40);
    strupr(Nome);
    while(strlen(Nome) < 40)
    {
        strcat(Nome, ".");

    }
    fstream Leitura;
    Leitura.open("Agenda.txt");

    J=0;
    while(!Leitura.eof() && Encontrou == 0)
    {
        Leitura.getline(Buff, 58);
        for(I=0; I<40; I++)
        {
            NomeComp[I] = Buff[I];
        }

        if (!strcmp(NomeComp, Nome))
        {
            Encontrou = 1;


        }
        J++;

    }
    if(Encontrou)
    {
            cout<< "NOVO NOME:\n";
            cin.ignore();
            cin.getline(Nome, 40);
            strupr(Nome);
            while(strlen(Nome) < 40)
            {
                strcat(Nome, ".");

            }
            cout<<"NOVO TELEFONE:\n";
            cin.getline(Telefone, 15);
            while (strlen(Telefone)< 15)
            {
                strcat(Telefone, ".");
            }
            Leitura << Nome<<"\t"<<Telefone;

    } else
    {
        cout<<"NOME NAO ENCONTRADO\n\n";

    }
    cout<<"precione enter para continuar\n";
    cin.get();
    Leitura.close();


}
void fLista()
{
    char Buff[58];
    ifstream Leitura;
    Leitura.open("Agenda.txt");
    while(!Leitura.eof())
    {

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
    int Op = 0;
    while (Op != 7)
    {
        fLimpa();
        cout << "================AGENDA==================\n"<<endl;
        cout << "1) CADASTRAR\n2) PESQUISAR\n3) EDITAR\n4) LISTAR\n5) APAGAR\n6) SALVAR\n7) SAIR\n\n";
        cin >> Op;

        if(Op == 1)
        {
            fCadastra();
        } else
        {
            if(Op == 2)
            {
                fPesquisa();
            } else
            {
                if(Op==3)
                {
                    fEdita();
                }
            }

        }
    }


    return 0;
}

