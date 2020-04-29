#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main()
{
    system("title CYPHER X");
    system("color A");
    char msg[999];
    char crip_msg[999];
    char condicao = 's';
    int tam_chave = 8;
    int chave[tam_chave];
    int tam_msg;
    int i;
    int escolha;

    for(i=0; i<tam_chave; i++)
    {
        if (i==0 || i==3)
        {
            chave[i] = 4;
        }

        if(i==1 || i==6)
        {
            chave[i] = 1;
        }
        if (i==2 || i==7)
        {
            chave[i] = 8;
        }

        if(i==4 || i==5)
        {
            chave[i] = 7;
        }
    }

    //Condição de repetição
    while(condicao == 's' || condicao == 'S')
    {


        // menu
        printf("\nDigite 1-Criptografar texto");
        printf("\nDigite 2-Descriptografar texto");
        scanf("%d%*c", &escolha);

        if(escolha == 1)
        {

            int j = 0;
            //Criptografia de frases
            printf("\nDigite texto ou palavra a ser criptografado: ");
            gets(msg);
            tam_msg = strlen(msg);
            for(i=0; i<tam_msg; i++)
            {
                if(j >= tam_chave)
                {
                    j = 0;
                }
                crip_msg[i] = msg[i] + chave[j];
                j++;
            }

            printf("\nA mensagem criptografada e : %s\n\n",crip_msg);

            puts(crip_msg);

            //TENTAR IMPRIMIR EM ARQUIVO TXT
            FILE *fp;
            fp = fopen("testeaps.txt","a");    /* Arquivo ASCII, para escrita */
            if(!fp)
            {
                printf("Erro na abertura do arquivo");
                exit(0);
            }
            //para contatenar
            for(int r=0; (crip_msg)[r]; r++) fputc((crip_msg)[r], fp); /* Grava a string, caractere a caractere */
            fclose(fp);

        }
        //descriptografia de frases
        else if(escolha == 2)
        {
            int j = 0;
            //Criptografia de frases
            printf("\nDigite texto ou palavra a ser criptografado: ");
            gets(msg);
            tam_msg = strlen(msg);
            for(i=0; i<tam_msg; i++)
            {
                if(j >= tam_chave)
                {
                    j = 0;
                }
                crip_msg[i] = msg[i] - chave[j];
                j++;
            }

            printf("\nA mensagem criptografada e : %s\n\n",crip_msg);

        }
        else if(escolha == 3)
        {

            //login
            char login[999];
            char crip_login[999];
            int tam_login;

            printf("\nDigite o login a ser criptografado: ");
            gets(login);

            tam_login = strlen(login);
            for(i=0; i<tam_login; i++)
            {
                crip_login[i] = login[i] + 1;
            }
            //senha
            char senha[999];
            char crip_senha[999];
            int tam_senha;

            printf("\nDigite a senha a ser criptografado: ");
            gets(senha);

            tam_senha = strlen(senha);
            for(int j=0; j<tam_senha; j++)
            {
                crip_senha[j] = senha[j] + 1;
            }

            puts(crip_login);
            puts(crip_senha);

//TENTAR IMPRIMIR EM ARQUIVO TXT
            FILE *fp;
            fp = fopen("testeaps.txt","a");    /* Arquivo ASCII, para escrita */
            if(!fp)
            {
                printf("Erro na abertura do arquivo");
                exit(0);
            }
            //para contatenar (crip_login,crip_senha)
            for(int r=0; (crip_login,crip_senha)[r]; r++) fputc((crip_login,crip_senha)[r], fp); /* Grava a string, caractere a caractere */
            fclose(fp);



        }
        else if(escolha == 4)
        {

//login
            char login[999];
            char crip_login[999];
            int tam_login;

            printf("\nDigite o login a ser Descriptografado: ");
            gets(crip_login);

            tam_login = strlen(crip_login);
            for(i=0; i<tam_login; i++)
            {
                login[i] = crip_login[i] - 1;
            }
            //senha
            char senha[999];
            char crip_senha[999];
            int tam_senha;

            printf("\nDigite a senha a ser Descriptografado: ");
            gets(crip_senha);

            tam_senha = strlen(crip_senha);
            for(int j=0; j<tam_senha; j++)
            {
                senha[j] = crip_senha[j] - 1;
            }

            puts(login);
            puts(senha);

            //TENTAR IMPRIMIR EM ARQUIVO TXT
            FILE *fp;
            fp = fopen("testeaps.txt","a");    /* Arquivo ASCII, para escrita */
            if(!fp)
            {
                printf("Erro na abertura do arquivo");
                exit(0);
            }
            //para contatenar (login,senha)
            for(int r=0; (login,senha)[r]; r++) fputc((login,senha)[r], fp); /* Grava a string, caractere a caractere */
            fclose(fp);

        }

        printf("\nDESEJA CONTINUAR? S/N:\n");
        scanf (" %c", &condicao);
        system("cls");

    }
    return 0;

}
