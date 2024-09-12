/*Desenvolva um programa em linguagem C que leia uma matriz de caracteres e uma string representando uma palavra. 
O programa deverá verificar se a palavra está presente na matriz, considerando que ela pode ser formada horizontalmente ou verticalmente.
 As dimensões da matriz (número de linhas e colunas) são definidas usando a diretiva #define. O programa deve exibir a posição inicial (linha e coluna) 
 onde a palavra começa, ou -1 caso a palavra não seja encontrada na matriz.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>

 #define N 10
 #define K 50


void gerador(char m[N][N])
{
    int i,j;

    srand(time(NULL));

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            do
            {
                m[i][j]=rand()%124;
            } while (!(m[i][j]>='a' && m[i][j]<='z' || m[i][j]>='A' && m[i][j]<='Z'));
        }
    }
}
 void mostra(const char m[N][N])
 {
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("% 4c",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 }

 int verify(const char m[N][N], char pal[K])
 {
    int i,j,k,l;
    int c=0;
    int w;


    c=strlen(pal);

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(pal[0]==m[i][j])
            {
                l=0;
                w=0;
                for(k=j;pal[k]!='\0' || k<N ;k++) // testa pra direita
                {
                    if(pal[l++]==m[i][k]) w++;
                    else break;
                    if(w==c) 
                    {
                        printf("\nPosicao %d %d ",i,j);
                        return 1;
                    }
                }
                l=0;
                w=0;
                for(k=j;pal[k]!='\0' || k>=0 ;k--) //testa pra esquerda
                {
                    if(pal[l++]==m[i][k]) w++;
                    else break;
                    if(w==c) 
                    {
                        printf("\nPosicao %d %d ",i,j);
                        return 1;
                    }
                }
                l=0;
                w=0;
                for(k=i;pal[k]!='\0' || k<N ;k++) //testa pra baixo
                {
                    if(pal[l++]==m[k][j]) w++;
                    else break;
                    if(w==c) 
                    {
                        printf("\nPosicao %d %d ",i,j);
                        return 1;
                    }
                }
                l=0;
                w=0;
                for(k=i;pal[k]!='\0' || k>=0 ;k--) //testa pra cima
                {
                    if(pal[l++]==m[k][j]) w++;
                    else break;
                    if(w==c) 
                    {
                        printf("\nPosicao %d %d ",i,j);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
 }

 int main()
 {
   /*char mat[N][N] = {{'B','a','n','a','n','a'},
                    {'a','j',65,69,79,90},
                    {'c',112,'a','t','a',122},
                    {'a',84,111,97,'k','y'},
                    {'n','s',81,99,103,97},
                    {'a',97,65,85,105,120}};*/
    char mat[N][N];
    char pal[K];

    gerador(mat);

    mostra(mat);

    printf("Digite uma PALAVRA: ");
    scanf("%s", pal);

    if(verify(mat,pal)) printf("\nEsta Contido");
    else printf("\n-1");
 }
