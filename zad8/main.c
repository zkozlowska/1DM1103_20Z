#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) 
{
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) 
    {
        listuj_studentow(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    } 
    
    else if (strcmp("add_student", argv[2]) == 0) 
    {
        dodaj_studentow (baza, argv[3], argv[4], argv[5], argv[6]);
        if (argv[7])
        {
            zapisz_baze(argv[7], baza);
        }
    } 

    else if (strcmp("add_subject", argv[2]) == 0) 
    {
        dodaj_przedmiot (baza, argv[3], argv[4], argv[5]);
        if (argv[6])
        {
            zapisz_baze(argv[6], baza);
        }
    } 

    else if (strcmp ("add_ocena", argv[2]) == 0)
    {
        dodaj_oceny(baza, argv[3], argv[4], argv[5], argv[6]);
        if (argv[7])
        {
            zapisz_baze(argv[7], baza);
        }
    }

    else if (strcmp("count_students", argv[2]) == 0) 
    {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    }

    else if (strcmp("szukaj_oceny_po_kodzie", argv[2]) == 0) 
    {
        baza->lista_ocen=filtrowanie_po_kodzie(baza->lista_ocen, argv[3], baza); 
        listuj_oceny(baza);
        if (argv[4])
        {
            zapisz_baze(argv[4], baza);
        }
        
    }

    else if (strcmp("szukaj_oceny_po_albumie", argv[2]) == 0) 
    {
        baza->lista_ocen = filtrowanie_po_albumie(baza->lista_ocen, argv[3], baza); 
        listuj_oceny(baza);
        if (argv[4])
        {
            zapisz_baze(argv[4], baza);
        }
    }

    else if (strcmp("sortuj_rosnaco_student", argv[2]) == 0) 
    {
        baza->lista_studentow = sortuj_przez_wybieranie_stud_najmniejszy(baza->lista_studentow); 
        listuj_studentow(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    } 
    else if (strcmp("sortuj_malejaco_student", argv[2]) == 0)
    {
        baza->lista_studentow = sortuj_przez_wybieranie_stud_najwiekszy(baza->lista_studentow); 
        listuj_studentow(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    }
    else if (strcmp("sortuj_rosnaco_przedmiot_kod", argv[2]) == 0) 
    {
        baza->lista_przedmiotow = sortuj_przez_wybieranie_kod_najmniejszy(baza->lista_przedmiotow); 
        listuj_przedmiot(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    }
    else if (strcmp("sortuj_malejaco_przedmiot_kod", argv[2]) == 0) 
    {
        baza->lista_przedmiotow = sortuj_przez_wybieranie_kod_najwiekszy(baza->lista_przedmiotow); 
        listuj_przedmiot(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    }
    else if (strcmp("sortuj_rosnaco_przedmiot_nazwa", argv[2]) == 0) 
    {
        baza->lista_przedmiotow = sortuj_przez_wybieranie_nazwa_najmniejszy(baza->lista_przedmiotow); 
        listuj_przedmiot(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    }
    else if (strcmp("sortuj_malejaco_przedmiot_nazwa", argv[2]) == 0) 
    {
        baza->lista_przedmiotow = sortuj_przez_wybieranie_nazwa_najwiekszy(baza->lista_przedmiotow); 
        listuj_przedmiot(baza);
        if (argv[3])
        {
            zapisz_baze(argv[3], baza);
        }
    }
    zwolnij(baza);
    return 0;
}


    
    