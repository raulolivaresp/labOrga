CC = gcc 

all: pFactorial pExp pExpMejora pFizz pSuma

pFactorial: factorial.c
	$(CC) factorial.c -o pFactorial

pExp:	exp_aprox.c
	$(CC) exp_aprox.c -o pExp_aprox

pExpMejora: exp_aprox_mejora.c
	$(CC) exp_aprox_mejora.c -o pExp_mejorado

pFizz: fizz_buzz.c
	$(CC) fizz_buzz.c -o pFizz_buzz

pSuma: suma_arreglo.c
	$(CC) suma_arreglo.c -o pSuma_arreglo

clean:
	rm pFactorial pExp pExpMejora pFizz pSuma
