../librerie/funzioni/funzioni.o: librerie/funzioni/funzioni.C librerie/funzioni/funzioni.h
	g++ -c librerie/funzioni/funzioni.C -o librerie/funzioni/funzioni.o
#../librerie/random/random.o: librerie/random/random.C librerie/random/random.h
#	g++ -c librerie/random/random.C -o librerie/random/random.o
#../librerie/array/array.o: librerie/array/array.C librerie/array/array.h
#	g++ -c librerie/array/array.C -o librerie/array/array.o
../librerie/lib.o: librerie/lib.C librerie/lib.h
	g++ -c librerie/lib.C -o librerie/lib.o


esame.o: esame.C
	g++ -c esame.C 
esame.x: esame.o   librerie/funzioni/funzioni.o
	g++ esame.o   librerie/funzioni/funzioni.o -o esame.x
compila: esame.x

esegui: esame.x
	./esame.x