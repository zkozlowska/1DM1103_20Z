all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students

test-dodajstud: all
	./mydb baza.csv add_student Małgosia Jakubowska 007 nikt@nigdzie.pl
  
test-dodajprzedmiot: all
	./mydb baza.csv add_przedmiot 1DE2103 "Metody numeryczne" 2020Z
  
test-dodajstuddoprzedmiotu: all
	./mydb baza.csv add_stud_do_przed 1DE2103 007
