../librerie/funzioni/funzioni.o: ../librerie/funzioni/funzioni.C ../librerie/funzioni/funzioni.h
	g++ -c ../librerie/funzioni/funzioni.C 
../librerie/random/random.o: ../librerie/random/random.C ../librerie/random/random.h
	g++ -c ../librerie/random/random.C

es1.o: es1.C
	g++ -c es1.C

a.out: es1.o ../librerie/funzioni/funzioni.o
	g++ es1.o ../librerie/funzioni/funzioni.o
compila: a.out

esegui: compila 
	./a.out

es3.o: es3.C
	g++ -c es3.C
es3.x: es3.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o
	g++ es3.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o -o es3.x
compila_es3: es3.x

esegui_es3: compila_es3
	./es3.x

es4.o: es4.C
	g++ -c es4.C
es4.x: es4.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o
	g++ es4.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o -o es4.x
compila_es4: es4.x

esegui_es4: compila_es4
	./es4.x

es5.o: es5.C
	g++ -c es5.C
es5.x: es5.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o
	g++ es5.o ../librerie/funzioni/funzioni.o ../librerie/random/random.o -o es5.x
compila_es5: es5.x

esegui_es5: compila_es5
	./es5.x