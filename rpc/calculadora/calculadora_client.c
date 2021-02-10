/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"


void
calculadora_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	operando  somar_1_arg;
	int  *result_2;
	operando  subtrair_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, CALCULADORA_VERSAO, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = somar_1(&somar_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = subtrair_1(&subtrair_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

    // copiado la de cima
    CLIENT *clnt;
	int *result;
	operando ops;

	if (argc < 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
	
    // ip
    host = argv[1];

    // x e y
	ops.x = atoi(argv[2]);
	ops.y = atoi(argv[3]);

    // conectando
    clnt = clnt_create (host, 
                        CALCULADORA, 
                        CALCULADORA_VERSAO, 
                        "tcp");

    // chamada remota pra soma
    result = somar_1(&ops, clnt);
    printf("A SOMA: %d\n", *result);


    // chamada remota pra subtracao
    result = subtrair_1(&ops, clnt);
    printf("A SUBTRACAO: %d\n", *result);

	//calculadora_1 (host);

    exit (0);
}
