../librerie/funzioni/funzioni.o: ../librerie/funzioni/funzioni.C ../librerie/funzioni/funzioni.h
	g++ -c ../librerie/funzioni/funzioni.C 
../librerie/random/random.o: ../librerie/random/random.C ../librerie/random/random.h
	g++ -c ../librerie/random/random.C
../librerie/array/array.o: ../librerie/array/array.C ../librerie/array/array.h
	g++ -c ../librerie/array/array.C


bogoSort.o: bogoSort.C
	g++ -c bogoSort.C
a.out: bogoSort.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o
	g++ bogoSort.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o
compila_bogoSort: a.out 

esegui_bogoSort: compila 
	./a.out

mergeSort.o: mergeSort.C
	g++ -c mergeSort.C 
mergeSort.x: mergeSort.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o 
	g++ mergeSort.o  ../librerie/funzioni/funzioni.o ../librerie/random/random.o -o mergeSort.x
compila_mergeSort: mergeSort.x

esegui_mergeSort: mergeSort.x
	./mergeSort.x