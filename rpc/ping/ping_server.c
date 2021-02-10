#include "ping.h"

int * ping_back_1_svc(int *num, struct svc_req *rqstp)
{
    static int result;

    // codigo
    result = *num;

    return &result;
}


int * ping_back_2_svc(int *num, struct svc_req *rqstp)
{
    static int result;

    // codigo
    result = *num * *num;

    return &result;
}


