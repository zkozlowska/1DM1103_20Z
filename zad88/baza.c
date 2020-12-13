#include "baza.h"

Student * ostatni_student(Student *glowa) 
{
    Student *el = glowa;
    if (el != NULL) 
    {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Przedmiot * ostatni_przed(Przedmiot *glowa) 
{
    Przedmiot *el = glowa;
    if (el != NULL) 
    {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

void wypisz_rekurencyjnie(Student *glowa) 
{
    if (glowa != NULL) 
    {
        printf("%s %s %s %s\n", glowa->imie, glowa->nazwisko, glowa->nr_albumu, glowa->email);        
        wypisz_rekurencyjnie( glowa->nast );
    }
}

void wypisz_alfabet(Student *glowa) 
{
    if (glowa != NULL)
    {
        wypisz_rekurencyjnie( glowa->nast );
        printf("%s %s %s %s\n", glowa->imie, glowa->nazwisko, glowa->nr_albumu, glowa->email);        
    }
}
void listuj_studentow_od_konca(SBaza *b) 
{
    Student *c;
    
    int i;
    int n = ile_studentow(b);
    for (i=(n-1); i >= 0; i--) 
    {
        c = zwroc(b->lista_studentow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    }
}
Ocena *ostatnia (Ocena *glowa)
{
    if(glowa!=NULL)
    {
        while(glowa->nast !=NULL)
        {
            glowa=glowa->nast;
        }
        return glowa;
    }
    else
    {
        return NULL;
    }
}

Ocena * filtrowanie_po_kodzie (Ocena *glowa, char * kod, SBaza *baza)
{
    Ocena *a=NULL;
    Ocena *b=NULL;

    for (int i=0; i<ile_ocen(baza); i++)
    {
        if(strcmp(glowa->kod_przed, kod)==0)
        {

        Ocena *glowa2;
        glowa2=(Ocena*) malloc(sizeof(Ocena));

        glowa2->nast=NULL;
        glowa2->poprz=NULL;
        
            if(a == NULL)
            {
                a = glowa2;
            }
            else
            {
                b=ostatnia(a);
                ostatnia(a)->nast = glowa2;
                glowa2->poprz = b;
            }

            glowa2->kod_przed=glowa->kod_przed;
            glowa2->nr_albumu=glowa->nr_albumu;
            glowa2->ocena=glowa->ocena;
            glowa2->komentarz=glowa->komentarz;        
        }
        
        glowa=glowa->nast;
    }
    return a;
}

Ocena * filtrowanie_po_albumie (Ocena *glowa, char * album, SBaza *baza)
{
    Ocena *a=NULL;
    Ocena *b=NULL;

    for (int i=0; i<ile_ocen(baza); i++)
    {
        //printf ("okej\n");
        if(strcmp(glowa->nr_albumu, album)==0)
        {
        Ocena *glowa2;
        glowa2=(Ocena*) malloc(sizeof(Ocena));
        glowa2->nast=NULL;
        glowa2->poprz=NULL;
        
            if(a == NULL)
            {
                a = glowa2;
            }
            else
            {
                b=ostatnia(a);
                ostatnia(a)->nast = glowa2;
                glowa2->poprz = b;
            }

            glowa2->kod_przed=glowa->kod_przed;
            glowa2->nr_albumu=glowa->nr_albumu;
            glowa2->ocena=glowa->ocena;
            glowa2->komentarz=glowa->komentarz;        
        }
        
        glowa=glowa->nast;
    }

    return a;
}

Student * usun_student(Student *glowa, Student *el) 
{
    Student *c = glowa;
    if (glowa == el) 
    {
        glowa = glowa->nast;
    } 
    else  
    {
        while (c != NULL) 
        {
            if (c == el) 
            {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;
                break;
            }
            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Student * najwiekszy_stud(Student *el) 
{
    Student * max = NULL;
    while (el != NULL) 
    {
        if (max == NULL) 
        {
            max = el;
        } else 
        {
            if (strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * najmniejszy_stud(Student *el) 
{
    Student * min = NULL;
    while (el != NULL) 
    {
        if (min == NULL) 
        {
            min = el;
        } else 
        {
            if (strcmp(el->nazwisko, min->nazwisko) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Student * sortuj_przez_wybieranie_stud_najwiekszy(Student *glowa) 
{
    Student * nglowa = NULL;
    Student * m = NULL;
    Student * o = NULL;

    while (glowa != NULL) 
    {
        m = najwiekszy_stud(glowa);
        glowa = usun_student(glowa, m);        
        o = ostatni_student(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } 
        else 
        {
            o->nast = m;
            m->poprz = o;
        }
    
    }

    return nglowa;
}

Student * sortuj_przez_wybieranie_stud_najmniejszy(Student *glowa) 
{
    Student * nglowa = NULL;
    Student * m = NULL;
    Student * o = NULL;

    while (glowa != NULL) 
    {
        m = najmniejszy_stud(glowa);
        glowa = usun_student(glowa, m);
        
        o = ostatni_student(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } 
        else 
        {
            o->nast = m;
            m->poprz = o;
        }
    
    }

    return nglowa;
}

Student * zwroc(Student *glowa, int i) 
{
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->nast;    
    
    return glowa;
}

Przedmiot * usun_przedmiot(Przedmiot *glowa, Przedmiot *el) 
{
    Przedmiot *c = glowa;
    if (glowa == el) 
    {
        glowa = glowa->nast;
    } 
    else
    {
        while (c != NULL) 
        {
            if (c == el) 
            {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Przedmiot * najwiekszy_kod(Przedmiot *el) 
{
    Przedmiot * max = NULL;
    while (el != NULL) 
    {
        if (max == NULL) 
        {
            max = el;
        } else 
        {
            if (strcmp(el->kod_przed, max->kod_przed) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy_kod(Przedmiot *el) 
{
    Przedmiot * min = NULL;
    while (el != NULL) 
    {
        if (min == NULL) 
        {
            min = el;
        } else 
        {
            if (strcmp(el->kod_przed, min->kod_przed) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * sortuj_przez_wybieranie_kod_najwiekszy(Przedmiot *glowa) 
{
    Przedmiot * nglowa = NULL;
    Przedmiot * m = NULL;
    Przedmiot * o = NULL;

    while (glowa != NULL) 
    {
        m = najwiekszy_kod(glowa);
        glowa = usun_przedmiot(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } else 
        {
            o->nast = m;
            m->poprz = o;
        }
    
    }

    return nglowa;
}

Przedmiot * sortuj_przez_wybieranie_kod_najmniejszy(Przedmiot *glowa) 
{
    Przedmiot * nglowa = NULL;
    Przedmiot * m = NULL;
    Przedmiot * o = NULL;

    while (glowa != NULL) 
    {
        m = najmniejszy_kod(glowa);
        glowa = usun_przedmiot(glowa, m);        
        o = ostatni_przed(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } else 
        {
            o->nast = m;
            m->poprz = o;
        }    
    }
    return nglowa;
}

Przedmiot * najwiekszy_nazwa(Przedmiot *el) 
{
    Przedmiot * max = NULL;
    while (el != NULL) 
    {
        if (max == NULL) 
        {
            max = el;
        } else 
        {
            if (strcmp(el->nazwa_przed, max->nazwa_przed) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy_nazwa(Przedmiot *el) 
{
    Przedmiot * min = NULL;
    while (el != NULL) 
    {
        if (min == NULL) 
        {
            min = el;
        } else 
        {
            if (strcmp(el->nazwa_przed, min->nazwa_przed) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * sortuj_przez_wybieranie_nazwa_najwiekszy(Przedmiot *glowa) 
{
    Przedmiot * nglowa = NULL;
    Przedmiot * m = NULL;
    Przedmiot * o = NULL;

    while (glowa != NULL) 
    {
        m = najwiekszy_nazwa(glowa);
        glowa = usun_przedmiot(glowa, m);
        o = ostatni_przed(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } else 
        {
            o->nast = m;
            m->poprz = o;
        }    
    }
    return nglowa;
}

Przedmiot * sortuj_przez_wybieranie_nazwa_najmniejszy(Przedmiot *glowa) 
{
    Przedmiot * nglowa = NULL;
    Przedmiot * m = NULL;
    Przedmiot * o = NULL;

    while (glowa != NULL) 
    {
        m = najmniejszy_nazwa(glowa);
        glowa = usun_przedmiot(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) 
        {
            nglowa = m;
        } else 
        {
            o->nast = m;
            m->poprz = o;
        }
    
    }

    return nglowa;
}

Student * wczytaj_studentow(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;

    Student *last_student;
    Student *glowa = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (int i=0; i < n; i++) 
    {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else
        {
            last_student=ostatni_student(glowa);
            last_student->nast = stud;
            stud->poprz=last_student;
        }

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);
        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);
        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);
        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }
    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;

    Przedmiot *last_subject;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    for (int i=0; i < n; i++) 
    {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;
        przed->poprz = NULL;

        if (glowa == NULL)
        {
            glowa = przed;
        }
        else
        {
            last_subject = ostatni_przed(glowa); 
            last_subject->nast = przed; 
            przed->poprz = last_subject;
        }

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przed, s);
        s = strtok(NULL, ";");
        przed->nazwa_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa_przed, s);
        s = strtok(NULL, "\n");
        przed->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->sem, s);
    }

    return glowa;
}

Ocena * wczytaj_oceny(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (int i=0; i < n; i++) 
    {
        Ocena *ocen = (Ocena*) malloc(sizeof(Ocena));
        ocen->nast = NULL;

        if (last_ocena == NULL)
        {
            glowa = ocen;
        }
        else
            last_ocena->nast = ocen;
        last_ocena = ocen;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocen->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->kod_przed, s);
        s = strtok(NULL, ";");
        ocen->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->nr_albumu, s);
        s = strtok(NULL, ";");
        ocen->ocena = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->ocena, s);         
        s = strtok(NULL, "\n");
        ocen->komentarz = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->komentarz, s);    
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa) 
{
    FILE *fin = fopen(nazwa, "r");
    if (fin == NULL) 
    {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa);
        exit(-1);
    }
    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza-> lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) 
{
    int n = 0;
    Student * student = baza->lista_studentow;
    while (student != NULL) 
    {
        n++;
        student = student->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza)
{
    int n = 0;
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    while (przedmiot !=NULL)
    {
        n++;
        przedmiot = przedmiot->nast;
    }
    return n;
}

int ile_ocen (SBaza *baza)
{
    int n=0;
    Ocena * ocen = baza->lista_ocen;
    while (ocen != NULL)
    {
        if(ocen->ocena != 0)
        {
            n++;
            ocen = ocen->nast;
        } 
    }
    return n;
}

void zapisz_baze(char *nazwa, SBaza *baza) 
{
    FILE *fin = fopen (nazwa, "w+");

    Student *student = baza->lista_studentow;
    Przedmiot *przedmiot = baza->lista_przedmiotow;
    Ocena *ocen= baza->lista_ocen;

    
    fprintf(fin,"%d\n",ile_studentow(baza));
    while (student!=NULL)
    {
        fprintf (fin,"%s;%s;%s;%s\n", student->imie, student->nazwisko, student->nr_albumu, student->email);
        student=student->nast;
    }

    fprintf(fin,"%d\n",ile_przedmiotow(baza));
    while (przedmiot!=NULL)
    {
        fprintf (fin,"%s;%s;%s\n", przedmiot->kod_przed, przedmiot->nazwa_przed, przedmiot->sem);
        przedmiot=przedmiot->nast;
    }
    fprintf(fin,"%d\n",ile_ocen(baza));
    while (ocen!=NULL)
    { 
        fprintf (fin,"%s;%s;%s;%s\n", ocen->kod_przed, ocen->nr_albumu, ocen->ocena, ocen->komentarz);
        ocen=ocen->nast;   
    }
  
    fclose(fin);
}

Student *dodaj_studentow (SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *aktualnie = NULL;
  	nowy->nast = NULL;  
  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    aktualnie=baza->lista_studentow;    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }
    else
    {
      for(int i=1; i < ile_studentow(baza); i++)
      {
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }
     return baza->lista_studentow;
        
}

Przedmiot *dodaj_przedmiot (SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem)
{
    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
    Przedmiot *aktualnie = NULL;
  	nowy->nast = NULL;
  	nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);
    nowy->nazwa_przed = (char *)malloc(sizeof(char) * (strlen(nazwa_przed) + 1));
    strcpy(nowy->nazwa_przed, nazwa_przed);
    nowy->sem = (char*) malloc(sizeof(char) * (strlen(sem) + 1));
    strcpy(nowy->sem, sem);
    aktualnie = baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
      baza->lista_przedmiotow = nowy;
    }
    else
    {
      for(int i=1; i<ile_przedmiotow(baza); i++)
      {
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }    
    return baza->lista_przedmiotow;
}
Ocena *dodaj_oceny (SBaza *baza, char *kod_przed, char *nr_albumu, char *ocena, char *komentarz)
{
    Ocena *nowy=(Ocena*) malloc(sizeof(Ocena));
    Ocena *aktualnie=NULL;
    nowy->nast=NULL;
    nowy->kod_przed = (char*) malloc( sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);
    nowy->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->ocena = (char*) malloc( sizeof(char) * (strlen(ocena) + 1));
    strcpy(nowy->ocena, ocena);
    nowy->komentarz = (char*) malloc( sizeof(char) * (strlen(komentarz) + 1));
    strcpy(nowy->komentarz, komentarz);
    aktualnie=baza->lista_ocen;
    if(ile_ocen(baza)==0)
    {
        baza->lista_ocen=nowy;     
    }
    else
    {
        for(int i=1;i<ile_ocen(baza);i++)
        {
            aktualnie=aktualnie->nast;
        }
        aktualnie->nast=nowy;
    }    
    return baza->lista_ocen;    
}
void listuj_studentow(SBaza *baza) 
{
    Student * stud = baza->lista_studentow;

    printf("%d\n", ile_studentow(baza));
    while (stud != NULL) 
    {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}
void listuj_przedmiot(SBaza *baza) 
{
    Przedmiot * przed = baza->lista_przedmiotow;

    printf("%d\n", ile_przedmiotow(baza));
    while (przed != NULL) 
    {
        printf("%s %s %s \n", przed->kod_przed, przed->nazwa_przed, przed->sem);
        przed = przed->nast;
    }
}
void listuj_oceny(SBaza *baza) 
{
    Ocena * ocen = baza->lista_ocen;

    printf("%d\n", ile_ocen(baza));
    while (ocen != NULL) 
    {
        printf("%s %s %s %s\n", ocen->kod_przed, ocen->nr_albumu, ocen->ocena, ocen->komentarz);
        ocen = ocen->nast;
    }
}
void zwolnij_student(Student *s) 
{
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}
void zwolnij_przedmioty(Przedmiot *s) 
{
    free(s->kod_przed);
    free(s->nazwa_przed);
    free(s->sem);
    free(s);
}
void zwolnij_oceny(Ocena *s) 
{
    free(s->kod_przed);
    free(s->nr_albumu);
    free(s->komentarz);
    free(s);
}
void zwolnij_liste_studentow(Student *s) 
{
    Student *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}
void zwolnij_liste_przedmiotow(Przedmiot *s) 
{
    Przedmiot *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_przedmioty(s);
        s = n;
    }
}
void zwolnij_liste_ocen(Ocena *s) 
{
    Ocena *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_oceny(s);
        s = n;
    }
}
void zwolnij(SBaza *baza) 
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}