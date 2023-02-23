run : exe

exe : main.o info.o edit.o
	gcc main.o info.o edit.o -o exe

main.o : main.c
	gcc -c main.c

info.o : info.c
	gcc -c info.c

edit.o : edit.c
	gcc -c edit.c

clean : 
	rm *.o exe
