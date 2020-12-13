DEPS=main.o baza.o 

mydb: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic 

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

test: 
	valgrind ./mydb baza.csv list_students

test-ile: 
	./mydb baza.csv count_students

test-memory: 
	 valgrind ./mydb baza.csv count_students 

test-dodajstudencika: 
	 ./mydb baza.csv add_student Małgorzata Pedantyczna 356660 margor@wpw.pl

test-dodajpprzedmiot: 
	 ./mydb baza.csv add_subject 1DE1409 grafika 2020Z

test-dodajocene: 
	 ./mydb baza.csv add_ocena 1DC2304 2020 5 swietnie

test-sortuj-rosnaco-student-nazwisko:
	./mydb baza.csv sortuj_rosnaco_student

test-sortuj-malejaco-student-nazwisko:
	./mydb baza.csv sortuj_malejaco_student

test-sortuj-rosnaco-przedmiot-kod:
	./mydb baza.csv sortuj_rosnaco_przedmiot_kod

test-sortuj-malejaco-przedmiot-kod:
	./mydb baza.csv sortuj_malejaco_przedmiot_kod

test-sortuj-rosnaco-przedmiot-nazwa:
	./mydb baza.csv sortuj_rosnaco_przedmiot_nazwa

test-sortuj-malejaco-przedmiot-nazwa:
	./mydb baza.csv sortuj_malejaco_przedmiot_nazwa

test-szukajoceny-pokodzie-przedm:
	./mydb baza.csv szukaj_oceny_po_kodzie 1DE2103

test-szukajoceny-ponralbumu:
	./mydb baza.csv szukaj_oceny_po_albumie 6666
