#include "ping.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    CLIENT *clnt;

    int vai, vem;

    if (argc != 3)
    {
        printf("Uso correto: ./ping_client host num\n");
        return(1);
    }

    //clnt = clnt_create(argv[1], PROGRAMAPING, PING_VERSAO1, "udp");
    clnt = clnt_create(argv[1], PROGRAMAPING, PING_VERSAO2, "udp");

    vai = atoi(argv[2]);

    vem = *ping_back_1(&vai, clnt);
    
    printf("O servidor retornou: %d\n", vem);

    return(0);
}

