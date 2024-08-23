#include <stdio.h>
#include <stdlib.h>
#include "xdb_structs.h"
int main()
{

    char *ips = "1.0.1.0";

    uint4 ip = ip_to_uint4(ips);
    printf("ip: %x\n", ip);

    Vector_entry v_entry = get_vector_entry(ip);

    uint4 start = v_entry.region_index_start;

    uint4 end = v_entry.region_index_end;

    char buffer[1024] = {0};

    binary_search(start, end, ip, buffer);

    char *p = buffer;
    printf("%s\n", p);

    return 0;
}