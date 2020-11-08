#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz {
    int r;
    int c;
    float tab[50][50];
};
void wczytaj(char nazwa[], struct Macierz *m) {
    FILE * fin = fopen(nazwa, "r");
    int i,j;
    
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for (i=0; i < m->r; i++) {
        for (j=0; j < m->c; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}
void wypisz(struct Macierz X) {
    int i, j;
        printf("[ ");
    for (i = 0; i < X.r; i++) {
        for (j=0; j < X.c; j++) {
            printf("%5.1f ", X.tab[i][j]);
        }
        if (i < (X.r-1))
            printf("\n  ");
    }
        printf("]\n");
}
void zapisz(char nazwa[], struct Macierz m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            fprintf(fout, "%f\n", m.tab[i][j]);
        }
    }
    fclose(fout);
}


float norm(struct Macierz A) {
    float s = 0;
    int i,j;

    for (i = 0; i < A.r; i++) {
        for (j=0; j < A.c; j++) {
            s += A.tab[i][j] * A.tab[i][j];
        }
    }
    return sqrt(s);
}


void sum(struct Macierz A, struct Macierz B, struct Macierz *X)
{
    int i,j;
    float p;
    X->c = A.c;
    X->r = A.r;
    if (A.r != B.r)
    {
       printf("Nie można dodawać macierzy o różnych rozmiarach\n");
    }
    if (A.c != B.c)
    {
       printf("Nie można dodawać macierzy o różnych rozmiarach\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                p = A.tab[i][j] + B.tab[i][j];
                X -> tab[i][j] = p;            
            }
        }
    }    
}

void subtract(struct Macierz A, struct Macierz B, struct Macierz *X)
{
    int i,j;
    float p;
    X->c = A.c;
    X->r = A.r;
    if (A.r != B.r) 
    {
        printf("Nie można odejmować macierzy o różnych rozmiarach\n");
    }
    if (A.c != B.c)
    {
        printf("Nie można odejmować macierzy o różnych rozmiarach\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                p = (A.tab[i][j]) - (B.tab[i][j]);
                X -> tab[i][j] = p;
            }
        }
    }    
}

void prod(struct Macierz A, struct Macierz B, struct Macierz *X)
{
    int i,j,k;
    float p;
    X->c = A.c;
    X->r = A.r;
    if(A.c != B.r)
    {
        printf("Rozmiary macierzy są nieprawidłowe\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < B.c; j++)
            {
                for (k = 0; k < B.r; k++){
                    p = p + (A.tab[i][k]) * (B.tab[k][j]);
                    X -> tab[i][j] = p;
                }         
            }
        }
    }    
}

void multiply(struct Macierz A, struct Macierz *X, double a)
{
    int i,j;
    float p;
    X->c = A.c;
    X->r = A.r;
    for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                p = A.tab[i][j] * a;
                X -> tab[i][j] = p;
            }
        }
}

int main(int argc, char *argv[]) {
    struct Macierz A;
    struct Macierz B;
    struct Macierz X;

    wczytaj(argv[2], &A);
   
    if ( strcmp( argv[1], "norm") == 0) 
    {
        if (argc == 4)
        {
            FILE * fin = fopen(argv[3], "w");
            fprintf(fin,"[%f]", norm(A));
        }
           else 
            {
                printf("Norma podanej macierzy = [%f]", norm(A));
            }
    }
    else if ( strcmp( argv[1], "sum") == 0) 
    {
        wczytaj(argv[3], &B);
        sum(A,B,&X);
        if (argc == 5)
        {
            zapisz(argv[4], X);
        }   else 
            {
                wypisz(X);
            }
    } 
    
    else if ( strcmp( argv[1], "subtract") == 0) 
    {
        wczytaj(argv[3], &B);
        subtract(A,B,&X);
        if (argc == 5)
        {
            zapisz(argv[4], X);
        }   else 
            {
                wypisz(X);
            }
    }    
    else if ( strcmp( argv[1], "prod") == 0) 
    {
        wczytaj(argv[3], &B);
        prod(A,B,&X);
        if (argc == 5)
        {
            zapisz(argv[4], X);
        }   else 
            {
                wypisz(X);
            }
    }
    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        multiply(A, &X, atof(argv[3]));
        if (argc == 5)
        {
            zapisz(argv[4], X);
        }   else 
            {
                wypisz(X);
            }
    }
    else {
        printf("Podane argumenty są nieprawidłowe :(\n");
    }
    return 0;

}