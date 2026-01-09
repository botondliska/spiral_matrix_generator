#include "func.h"
#include <stdio.h>
#include <string.h>

void userGuide()
{
    printf("\n\n\nA fomenuben szamokkal navigalhat, az 1-es gomb ide juttatja.\nA 2-es gombbal generalhat egy uj matrixot, melynek menete a kovetkezo:\nA program beker harom erteket:\nMeret (1-20)\nIndulasi irany (balra/fel/jobbra/le)\nForgasirany (cw/ccw)\nA matrix ezen parameterek megadasa utan automatikusan legeneralodik.\nA 3-mas gombbal az eppen aktualis matrixot elmentheti egy, a parametereinek megfelelo nevu fajlba,\namit kesobb a program forraskodja mellett talal majd.\nA 4-es gomb segitsegevel egy mar megevo, fajlban szereplo matrixot tud betolteni.\nAz 5-os gomb hasznalataval automatikusan megjelenitheti az eppen aktualis matrixot!\n\nKerem nyomjon egy entert a fomenube valo visszajutashoz!\n\n");
}

void genMatrix(int** matrix, int n, int dir, int clock)
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            matrix[i][j]=0;

    int szam=1,i,j;
    if(n%2)//PARATLAN N
    {
        i=n/2;
        j=n/2;
    }
    else //PAROS N
    {
        if(clock)//ccw
        {
            i=(dir==2||dir==3)?n/2:n/2-1;
            j=(dir==0||dir==3)?n/2:n/2-1;
        }
        else//cw
        {
            i=(dir==0||dir==3)?n/2:n/2-1;
            j=(dir==0||dir==1)?n/2:n/2-1;
        }
    }
    matrix[i][j]=1;
    while(szam<n*n)
    {
        switch (dir)
        {
            case 0://balra
                j--;
                dir=(clock && matrix[i+1][j]==0)?1:(!clock && matrix[i-1][j]==0)?3:dir;
                break;
            case 1://le
                i++;
                dir=(clock && matrix[i][j+1]==0)?2:(!clock && matrix[i][j-1]==0)?0:dir;
                break;
            case 2://jobbra
                j++;
                dir=(clock && matrix[i-1][j]==0)?3:(!clock && matrix[i+1][j]==0)?1:dir;
                break;
            case 3://fel
                i--;
                dir=(clock && matrix[i][j-1]==0)?0:(!clock && matrix[i][j+1]==0)?2:dir;
                break;
            default:
                break;
        }
        matrix[i][j]=++szam;
    }
}

void printMatrix(int** matrix, int n)
{
    printf("\n\n\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(n<10)
                printf("%3d",matrix[i][j]);
            else if(n<32)
                printf("%4d",matrix[i][j]);
            else
                printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void saveToFile(int** matrix, int cn, char* cd, char* cc)
{
    char fajlnev[13];
    sprintf(fajlnev,"spiral%d%c%s.txt",cn,cd[0],cc);
    FILE *out;
    out=fopen(fajlnev,"w");
    for(int i=0;i<cn;++i)
    {
        for(int j=0;j<cn;++j)
        {
            if(cn<10)
                fprintf(out,"%3d",matrix[i][j]);
            else if(cn<32)
                fprintf(out,"%4d",matrix[i][j]);
            else
                fprintf(out,"%5d",matrix[i][j]);
        }
        fprintf(out,"\n");
    }
    fclose(out);
}

void loadFromFile(int** matrix, char* fajlnev, int n)
{
    FILE *in=fopen(fajlnev,"r");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            fscanf(in,"%d",&matrix[i][j]);
        fscanf(in,"\n");
    }
    fclose(in);
}
