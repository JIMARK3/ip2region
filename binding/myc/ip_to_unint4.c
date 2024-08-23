#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xdb_structs.h"
uint4 ip_to_uint4(char *ip)
{
    long int ip_arr[4]={0};
    char *p = ip;
    char *end;
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        /* code */
        ip_arr[i] = strtol(p, &p, 10);
        p++;
    }
    ret = (ip_arr[0] << 24) | (ip_arr[1] << 16) | (ip_arr[2] << 8) | ip_arr[3];
    return ret;
};