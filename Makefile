OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

program.exe: category.o program.o player.o set_categories.o set_players.o set_tournament.o tournament.o
	g++ -o program.exe *.o
	
category.o: category.cc
	g++ -c category.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

set_categories.o: set_categories.cc
	g++ -c set_categories.cc $(OPCIONS)

set_players.o: set_players.cc
	g++ -c set_players.cc $(OPCIONS)
set_tournament.o: set_tournament.cc
	g++ -c set_tournament.cc $(OPCIONS)

tournament.o: tournament.cc
	g++ -c tournament.cc $(OPCIONS)

player.o: player.cc
	g++ -c player.cc $(OPCIONS)

clean:
	rm *.o *.exe
	
tar: 
	tar -cvf practica.tar Makefile *.cc *.hh html.zip
