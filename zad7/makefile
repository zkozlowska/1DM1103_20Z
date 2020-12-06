all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-dodstud: all
	./mydb baza.csv add_student Kasia Nowak 007 cos@cos.pl
  
test-dodprzedmiot: all
	./mydb baza.csv add_przedmiot 1DE2103 "Metody numeryczne" 2020Z
  
test-dodstuddoprzed: all
	./mydb baza.csv add_stud_do_przed 1DE2103 007

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students