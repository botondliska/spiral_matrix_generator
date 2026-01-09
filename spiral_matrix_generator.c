#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
    #include <windows.h>
    #define TOROL system("cls");
    #define WAIT system("pause");
#endif
#ifdef __linux__
    #define TOROL system("clear");
    #define WAIT system("read -p \"Press any key to continue . . . \"");
#endif

void printTitle()
{
    printf("\n .d8888b.  8888888b. 8888888 8888888b.         d8888 888           888b     d888        d8888 88888888888 8888888b.  8888888 Y88b   d88P \nd88P  Y88b 888   Y88b  888   888   Y88b       d88888 888           8888b   d8888       d88888     888     888   Y88b   888    Y88b d88P  \nY88b.      888    888  888   888    888      d88P888 888           88888b.d88888      d88P888     888     888    888   888     Y88o88P   \n  Y888b.   888   d88P  888   888   d88P     d88P 888 888           888Y88888P888     d88P 888     888     888   d88P   888      Y888P    \n     Y88b. 8888888P    888   8888888P      d88P  888 888           888 Y888P 888    d88P  888     888     8888888P     888      d888b    \n       888 888         888   888 T88b     d88P   888 888           888  Y8P  888   d88P   888     888     888 T88b     888     d88888b   \nY88b  d88P 888         888   888  T88b   d8888888888 888           888       888  d8888888888     888     888  T88b    888    d88P Y88b  \n  Y8888P   888       8888888 888   T88b d88P     888 88888888      888       888 d88P     888     888     888   T88b 8888888 d88P   Y88b \n\n .d8888b.  8888888888 888b    888 8888888888 8888888b.         d8888 88888888888 .d88888b.  8888888b.                                    \nd88P  Y88b 888        8888b   888 888        888   Y88b       d88888     888    d88P   Y88b 888   Y88b                                   \n888    888 888        88888b  888 888        888    888      d88P888     888    888     888 888    888                                   \n888        8888888    888Y88b 888 8888888    888   d88P     d88P 888     888    888     888 888   d88P                                   \n888  88888 888        888 Y88b888 888        8888888P      d88P  888     888    888     888 8888888P                                     \n888    888 888        888  Y88888 888        888 T88b     d88P   888     888    888     888 888 T88b                                     \nY88b  d88P 888        888   Y8888 888        888  T88b   d8888888888     888    Y88b. .d88P 888  T88b                                    \n  Y8888P88 8888888888 888    Y888 8888888888 888   T88b d88P     888     888      Y88888P   888   T88b\n\n\n\n");
}

int main()
{
     
    int input=6;
    int n=0;
    char dir[7],clock[4];
    int** matrix;
    int d,c;
    bool alreadyCreated=0;
    char* dirptr=dir;
    char* clockptr=clock;
    do
    {
        TOROL
        //system("color 0a");
        printTitle();

        printf("| [1] -> User Guide\n");
        printf("| [2] -> Generate a matrix\n");
        printf("| [3] -> Save a matrix\n");
        printf("| [4] -> Load a matrix\n");
        printf("| [5] -> Print actual matrix\n");
        printf("| [0] -> Exit\n\n\n");
        printf("Choice >> ");
        scanf("%d",&input);
        switch (input)
        {
        case 0:
            TOROL
            printf("\n\n\n                    vege:)\n\n\n");
            break;
        case 1:
            TOROL
            userGuide();
            WAIT
            break;
        case 2:
            TOROL
            int tempn=n;
            char* tempdir=dirptr;
            char* tempclock=clockptr;
            printf("\n\n\nMatrix generalas:\n\nKerlek add meg a matrix meretet(NxN) >> ");
            scanf("%d",&n);
            printf("Melyik iranyba induljon a matrix? (balra/fel/jobbra/le) >> ");
            scanf("%s",dir);
            printf("Oramutato jarasaval megegyezoen(cw) vagy ellentetesen(ccw) haladjon a spiral? >> ");
            scanf("%s",clock);
            if(!(strcmp(dir,"balra")*strcmp(dir,"fel")*strcmp(dir,"jobbra")*strcmp(dir,"le"))&&!(strcmp(clock,"cw")*strcmp(clock,"ccw"))&&n>0)
            {
            if(alreadyCreated)
            {
                for(int i=0;i<tempn;++i)
                    free(matrix[i]);
                free(matrix);
            }
            matrix = (int**)malloc(n*sizeof(int*));
            for(int i=0;i<n;++i)
                matrix[i] = (int*)malloc(n*sizeof(int));
            c=(clock[1]=='w')?0:1;
            d=(dir[0]=='b')?0:(dir[0]=='l')?1:(dir[0]=='j')?2:(dir[0]=='f')?3:0;
            genMatrix(matrix,n,d,c);
            alreadyCreated=1;
            TOROL
            printf("\n\n\nA matrix generalasa megtortent!\n\n\n");
            WAIT
            }
            else
            {
                TOROL
                n=tempn;dirptr=tempdir;clockptr=tempclock;
                printf("\n\n\nHibas parameter(ek)!\n\n\n");
                WAIT
            }
            break;
        case 3:
            if(n==0)
            {
                printf("\n\n\nMeg nincs aktualis matrix!\n\n\n");
                WAIT
            }
            else
            {
                saveToFile(matrix,n,dir,clock);
                TOROL
                printf("\n\n\nA matrixot sikeresen elmentetted!\n\n\n");
                WAIT
            }
                
            break;
        case 4:
            TOROL
            char fajlnev[12];
            printf("\n\n\nMelyik fajlt szeretned betolteni? >> ");
            scanf("%s",fajlnev);
            FILE *fajl=fopen(fajlnev,"r");
            if(fajl!=NULL)
            {
                fclose(fajl);
                if(n>0)
                {
                    for(int i=0;i<n;++i)
                        free(matrix[i]);
                    free(matrix);
                }
                if(fajlnev[7]>='0' && fajlnev[7]<='9')
                    n=(fajlnev[6]-'0')*10+fajlnev[7]-'0';
                else
                    n=fajlnev[6]-'0';
                matrix = (int**)malloc(n*sizeof(int*));
                for(int i=0;i<n;++i)
                    matrix[i] = (int*)malloc(n*sizeof(int));
                loadFromFile(matrix,fajlnev,n);
                TOROL
                printf("\n\n\nA matrixot sikeresen betoltotted!\n\n\n");
            }
            else
            {
                fclose(fajl);
                //TOROL
                printf("\n\n\nA fajl nem letezik!\n\n\n");
            }
            WAIT
            break;
        case 5:
            TOROL
            if(n)
                printMatrix(matrix,n);
            else
                printf("\n\n\nMeg nincs aktualis matrix!\n\n\n");
            WAIT
            break;
        
        default:
            break;
        }
    } while (input!=0);
    
    if (n)
    {
        for(int i=0;i<n;++i)
            free(matrix[i]);
        free(matrix);
    }

    return 0;
}