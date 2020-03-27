2048:	main.o	array_manipulation.o	graphical_functions.o
	g++	main.o	array_manipulation.o	graphical_functions.o	-o	2048	-lncurses

main.o:	main.cpp	array_manipulation.h	graphical_functions.h
	g++	-c	main.cpp

array_manipulation.o:	array_manipulation.cpp	array_manipulation.h
	g++	-c	array_manipulation.cpp

graphical_functions.o:	graphical_functions.cpp	graphical_functions.h
	g++	-c	graphical_functions.cpp

.PHONY:	clean
clean:
	rm	2048
	rm	main.o	array_manipulation.o	graphical_functions.o
