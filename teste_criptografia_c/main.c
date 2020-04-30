#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main()
{
    system("title CYPHER X");
    system("color A");

    char condicao = 's';
    int tam_chave = 8;
    int chave[tam_chave];
    int tam_msg;
    int i;
    int escolha;
    //char Linha[999];
    char *result;

    //GERANDO A CHAVE
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
        printf("\nDigite 2-Descriptografar texto\n");
        scanf("%d%*c", &escolha);

        //CRIPTOGRAFIA DE FRASES
        if(escolha == 1)
        {
            char msg[999];
            char crip_msg[999];
            int j = 0;

            printf("\nDigite texto ou palavra a ser criptografado: ");
            gets(msg);
            tam_msg = strlen(msg);
            for(i=0; i<tam_msg; i++)
            {
                if(j >= tam_chave)
                {
                    j = 0;         //Se j > tamanho do vetor chave, volta para o inicio do vetor chave
                }
                if(msg[i] == ' ')
                {
                    crip_msg[i] = ' '; //Se o char for um espaço, não criptografa esse char
                }
                else
                {
                    crip_msg[i] = msg[i] + chave[j];  //Senão, criptografa a char, somando-o com o valor atual da chave
                }
                j++;
            }

            printf("\nA mensagem criptografada e : %s\n\n",crip_msg);

            //TENTAR IMPRIMIR EM ARQUIVO TXT
            FILE *fp;
            fp = fopen("testeaps.txt","a");    // Arquivo ASCII, para escrita
            if(!fp)
            {
                printf("Erro na abertura do arquivo");
                exit(0);
            }

            for(int r=0; (crip_msg)[r]; r++)
            {
                fputc((crip_msg)[r], fp); // Grava a string, caractere a caractere
            }

            fclose(fp); //Fecha o arquivo

        }

        //DESCRIPTOGRAFIA DE FRASES
        else if(escolha == 2)
        {
            char msg[999];
            char crip_msg[999];
            int j = 0;
            int ch = 0;

            //TENTAR LER O ARQUIVO TXT
            FILE *fp;
            fp = fopen("testeaps.txt","r");    // Arquivo ASCII, para leitura
            ch = fgetc( fp );
            for( i=0; (i < 80 ) && ( feof( fp ) == 0 ); i++ )
            {
                crip_msg[i] = (char)ch;
                ch = fgetc( fp );
            }
            tam_msg = strlen(crip_msg);

            // Add null to end string
            //crip_msg[i] = '\0';

            for(i=0; i<tam_msg; i++)
            {
                if(j >= tam_chave)
                {
                    j = 0;          //Se j > tamanho do vetor chave, volta para o inicio do vetor chave
                }
                if(crip_msg[i] == ' ')
                {
                    msg[i] = ' ';   //Se o char for um espaço, não criptografa esse char
                }
                else
                {
                    msg[i] = crip_msg[i] - chave[j]; //Senão, criptografa a char, somando-o com o valor atual da chave
                }
                j++;
            }

            printf( "\n------------------\n%s \n==>\n%s \n------------------", crip_msg, msg);
            fclose( fp ); //Fecha o arquivo

        }

        printf("\nDESEJA CONTINUAR? S/N:\n");
        scanf (" %c", &condicao);
        system("cls");

    }
    return 0;

}
