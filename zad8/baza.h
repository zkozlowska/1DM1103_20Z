#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student 
{
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *poprz;
    struct _Student *nast;

} Student;

typedef struct _Przedmiot 
{
    char * kod_przed;
    char * nazwa_przed;
    char * sem;

    struct _Przedmiot *poprz;
    struct _Przedmiot *nast;

} Przedmiot;

typedef struct _Ocena
{
    char * nr_albumu;
    char * kod_przed;
    char *ocena;
    char * komentarz;

    struct _Ocena *poprz;
    struct _Ocena *nast;

}Ocena;

typedef struct _SBaza 
{
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;

} SBaza;

Student * ostatni_student(Student *glowa);

Przedmiot * ostatni_przed(Przedmiot *glowa);

Ocena * ostatnia_ocena(Ocena *glowa);

void wypisz_rekurencyjnie(Student *glowa);

void wypisz_alfabet(Student *glowa);

void wyswietl_przedmiot(Przedmiot *glowa);

void listuj_studentow_od_konca(SBaza *b);

void oceny_po_nazwie(SBaza *baza, char *kod_przed);

void oceny_po_numerze_albumu(SBaza *baza, char *nr_albumu);

Student * usun_student(Student *glowa, Student *el);

Student * najwiekszy_stud(Student *el);

Student * najmniejszy_stud(Student *el);

Student * sortuj_przez_wybieranie_stud_najwiekszy(Student *glowa);

Student * sortuj_przez_wybieranie_stud_najmniejszy(Student *glowa);

Student * zwroc(Student *glowa, int i);

Przedmiot * usun_przedmiot(Przedmiot *glowa, Przedmiot *el);

Przedmiot * najwiekszy_kod(Przedmiot *el);

Przedmiot * najmniejszy_kod(Przedmiot *el);

Przedmiot * sortuj_przez_wybieranie_kod_najwiekszy(Przedmiot *glowa);

Przedmiot * sortuj_przez_wybieranie_kod_najmniejszy(Przedmiot *glowa);

Przedmiot * najwiekszy_nazwa(Przedmiot *el);

Przedmiot * najmniejszy_nazwa(Przedmiot *el);

Przedmiot * sortuj_przez_wybieranie_nazwa_najwiekszy(Przedmiot *glowa);

Przedmiot * sortuj_przez_wybieranie_nazwa_najmniejszy(Przedmiot *glowa);

Student * wczytaj_studentow(FILE *fin);

Przedmiot * wczytaj_przedmioty(FILE *fin);

Ocena * wczytaj_oceny(FILE *fin);

SBaza * wczytaj_baze(char *nazwa);

int ile_studentow(SBaza *baza);

int ile_przedmiotow(SBaza *baza);

int ile_ocen (SBaza *baza);

void zapisz_baze(char *nazwa, SBaza *baza);

Student *dodaj_studentow (SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);

Przedmiot *dodaj_przedmiot (SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem);

Ocena *dodaj_oceny (SBaza *baza, char *kod_przed, char *nr_albumu, char *ocena, char *komentarz);

void listuj_studentow(SBaza *baza);

void listuj_przedmiot(SBaza *baza);

void listuj_oceny(SBaza *baza);

void zwolnij_student(Student *s);

void zwolnij_przedmioty(Przedmiot *s);

void zwolnij_oceny(Ocena *s);

void zwolnij_liste_studentow(Student *s);

void zwolnij_liste_przedmiotow(Przedmiot *s);

void zwolnij_liste_ocen(Ocena *s);

void zwolnij(SBaza *baza); 

Ocena *ostatnia (Ocena *glowa);

Ocena * filtrowanie_po_kodzie (Ocena *glowa, char * kod, SBaza *baza);

void wypisz_oceny(Ocena *glowa);

Ocena * filtrowanie_po_albumie(Ocena *glowa, char *album, SBaza *baza);

#endif