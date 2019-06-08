#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<conio.h>

int IniciarMenu();
void gerenciar();
void incluir();
void IncluirAssentosEspeciais();
void IncluirConvidados();
void IncluirParticipante();
void exibir();
void limpar();
void excluir();
void iniciar();
void listar(int i);
void sorteio();

struct assentos
{
    char nome[100];
    char email[100];
    char CPF[11];
    int ocupado;
    int numero;
};

struct assentos reservados[3];
struct assentos participantes[3][9];
struct assentos convidados[10];

int main()
{
    iniciar();
    int menu1 = 0;
    char user[100];
    char senha[100];

    int acesso = 0 ;
    do
        {
    printf(" ");
	printf("\t\t\t\tPalestra-UNIP\n");
    printf(" ");
    printf("\t\t\t\tSeja Bem Vindo\n");
    printf("================================================================================\n");
    printf("Digite seu usuario: \n");
    scanf("%s%*c", user);
    printf("Digite sua senha:");
    scanf("%s%*c", senha);
                if ( strcmp(user, "bemvindo") == 0 && strcmp(senha, "bemvindo") == 0  )
                    {
                        acesso = 1 ;{printf("SENHA CORRETA SEJA BEM VINDO\n\n\n\n");system("color 0a");system("color f3");Beep(400,300);}
                    }
                    else
                        {
                             {printf("usuário ou senha invalida, tente novamente!\n"); system("color 0c");system("color 0c");Beep(300,200);} system ("pause"); system ("cls");
                        }

        }
        while(acesso != 1 );
        while (menu1 != 4)
        {
        menu1 = menuInicial();
        }
}

int menuInicial()
{
    int menuprincipal;
    printf("Escolha uma opcao: \n");
    printf("1- Gerenciar Visitante\n");
    printf("2- Realizar Sorteio\n");
    printf("3- Enviar comunicado por email\n");
    printf("4- Sair\n");

    scanf("%d", &menuprincipal); system("cls");

    switch (menuprincipal)
     {
        case 1:
            gerenciar();
            break;
        case 2:
            sorteio();
            break;
        case 3:
            printf("E-mail enviado com sucesso.");
     }
    return menuprincipal;
}

void gerenciar()
{
    int opcao = 0;
    while (opcao != 6)
        {
        printf("1 -Incluir participante\n");
        printf("2- Excluir participante\n");
        printf("3- Listar Lugares livres\n");
        printf("4- Listar lugares ocupados\n");
        printf("5- Mostrar todos os lugares\n");
        printf("6- Voltar ao menu anterior\n");
        scanf("%d", &opcao);system("cls");
        switch (opcao)
            {
            case 1:
                incluir();
                break;
            case 2:
                excluir();
                break;
            case 3:
                listar(0);
                break;
            case 4:
                listar(1);
                break;
            case 5:
                listar(2);
                break;
            }
        }
}

void incluir()
{
    int opcao = 0;
    printf("\n=======\n");
    printf("Escolha uma opcao: \n");
    printf("1 - Assento especial\n");
    printf("2 - Convidado\n");
    printf("3 - Participante\n");
    printf("4- Voltar ao menu anterior\n");
    scanf("%d", &opcao); system("cls");
    switch (opcao)
    {
        case 1:
            IncluirAssentosEspeciais();
            break;
        case 2:
            IncluirConvidados();
            break;
        case 3:
            IncluirParticipante();
            break;
    }
}

void IncluirAssentosEspeciais()
{
       int cadastrado = 0;
       for (int i = 0; i < 3; i++)
        {
            if (reservados[i].ocupado == 0)
            {
                printf("Informe o nome: ");
                scanf("%s", reservados[i].nome);
                printf("Informe o email: ");
                scanf("%s", reservados[i].email);
                printf("Informe o CPF: ");
                scanf("%s", reservados[i].CPF);

                reservados[i].ocupado = 1;
                exibir(reservados[i]);
                cadastrado = 1; system("pause"); system ("cls");
                break;
            }
        }
    if (cadastrado == 0)
        {
        printf("Todos os assentos acessiveis reservados\n"); system("pause"); system ("cls");
        }
}

void IncluirConvidados()
{
    int cadastrado = 0;
    for (int i = 0; i < 10; i++)
        {
             if (convidados[i].ocupado == 0)
             {
                 printf("Informe o nome: ");
                 scanf("%s", convidados[i].nome);
                 printf("Informe o email: ");
                 scanf("%s", convidados[i].email);
                 printf("Informe o CPF: ");
                 scanf("%s", convidados[i].CPF);

                 convidados[i].ocupado = 1;
                 exibir(convidados[i]);
                 cadastrado = 1; system("pause"); system ("cls");
                 break;
             }
        }
    if (cadastrado == 0)
        {
                 printf("Todos os assentos para convidados reservados\n"); system("pause"); system ("cls");
        }
}

void IncluirParticipante()
{
    int cadastrado = 0;
    for (int fileira = 0; fileira < 4; fileira++)
    {
        for (int ass = 0; ass < 10; ass++)
        {
            if (participantes[fileira][ass].ocupado == 0)
            {
                printf("Informe o nome: ");
                scanf("%s", participantes[fileira][ass].nome);
                printf("Informe o email: ");
                scanf("%s", participantes[fileira][ass].email);
                printf("Informe o CPF: ");
                scanf("%s", participantes[fileira][ass].CPF);
                participantes[fileira][ass].ocupado = 1;
                exibir(participantes[fileira][ass]);
                cadastrado = 1; system("pause"); system ("cls");
               break;
            }
        }
        if (cadastrado == 1)
            {
            break;
            }
    }
    if (cadastrado == 0)
        {
        printf("Todos os assentos para participantes ocupados\n"); system("pause"); system ("cls");
        }
}

void exibir(struct assentos assentos)
{
    printf("\n\n==========================\n\n");
    printf("Nome: %s", assentos.nome);
    printf("\nEmail: %s", assentos.email);
    printf("\nCPF: %s", assentos.CPF);
    printf("\nTicket: %d", assentos.numero);
    printf("\n\n===========================\n\n");
}

void excluir()
{
    int id = 0;
    printf("Informe o número do ticket\n");
    scanf("%d", &id);
        for (int i = 0; i < 3; i++)
        {
        if (reservados[i].numero == id)
           {
            limpar(reservados[i]);
           }
        }
    for (int i = 0; i < 10; i++)
    {
        if (convidados[i].numero == id)
        {
            limpar(convidados[i]);
        }
    }
    for (int f = 0; f < 4; f++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (participantes[f][i].numero == id)
            {
                limpar(participantes[f][i]);
            }
        }
    }
}
void limpar(struct assentos assentos)
{
    strcpy( assentos.nome , "" );
    strcpy( assentos.email , "");
    strcpy( assentos.CPF , "");
    assentos.ocupado = 0;
    exibir(assentos);
}
void iniciar()
{
    int id = 1;
    for(int i = 0 ; i < 3 ; i++ )
        {
        reservados[i].numero = id;
        reservados[i].ocupado = 0;
        id++;
        }
    for(int i = 0 ; i < 10 ; i++ )
        {
        convidados[i].numero = id;
        convidados[i].ocupado = 0;
        id++;
        }
        for(int i = 0 ; i < 4 ; i++ )
    {
        for(int f = 0 ; f < 10 ; f++ )
        {
            participantes[i][f].numero = id;
            participantes[i][f].ocupado = 0;
            id++;
        }
    }
}
void listar(int tipo)
{
   for(int i = 0 ; i < 3 ; i++ )
    {
        if ( reservados[i].ocupado == tipo || tipo == 2 )
        {
            printf("Fileira:1 Cadeira:%d -\n " , reservados[i].numero );
        }
    }
    for(int i = 0 ; i < 10 ; i++ )
    {
         if ( convidados[i].ocupado == tipo || tipo == 2 )
         {
            printf("Fileira:2 Cadeira:%d -\n " , convidados[i].numero );
        }

    }
    for(int i = 0 ; i < 4 ; i++ )
        {
        for(int f = 0 ; f < 10 ; f++ )
        {
            if ( participantes[i][f].ocupado == tipo || tipo == 2)
            {
                printf("Fileira:%d Cadeira:%d -\n " , i+3 ,participantes[i][f].numero );
            }
        }
    }
     printf("\n ============ \n"); system ("pause"); system ("cls");
}
void sorteio()
{
    struct assentos participante;
    int tentativa = 0;
    do
        {
        participante = participantes[(rand() % 3)] [ rand() % 9] ;
        tentativa++;
        }
        while(participante.ocupado != 1 || tentativa < 20);
        exibir(participante); system ("pause"); system ("cls");
}
