FLAG=-pedantic-errors -std=c++11
map.o: map.cpp map.h
	g++ $(FLAG) -c $<

help.o: help.cpp help.h
	g++ $(FLAG) -c $<

danger.o: danger.cpp danger.h
	g++ $(FLAG) -c $<

chestandstore.o: chestandstore.cpp chestandstore.h
	g++ $(FLAG) -c $<
store.o: store.cpp store.h
	g++ $(FLAG) -c $<
main.o: main.cpp map.h help.h chestandstore.h store.h danger.h
	g++ $(FLAG) -c $<

main: main.o map.o help.o chestandstore.o store.o danger.o
	g++ $(FLAG) $^ -o main
