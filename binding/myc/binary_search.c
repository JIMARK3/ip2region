#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xdb_structs.h"
void binary_search(uint4 start, uint4 end, uint4 ip, char *ret)
{
    FILE *f = fopen("./mydata/ip2region.xdb", "r");
    if (f == NULL)
    {
        printf("open file failed\n");
        exit(EXIT_FAILURE);
    }
    if (fseek(f, start, SEEK_SET) == -1)
    {
        printf("seek file start failed\n");
        fclose(f);
        exit(EXIT_FAILURE);
    };
    int elements = (end - start) / SegmentIndexSize;
    char *buffer = (char *)malloc((elements + 1) * SegmentIndexSize);
    size_t len = fread(buffer, sizeof(char), (elements + 1) * SegmentIndexSize, f);
    printf("elements: %x\n", elements);
    printf("len: %x\n", len);
    if (len = 0)
    {
        printf("read file failed\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    // binary search buffer
    int low = 0;
    int high = elements;
    uint4 data=-1;
    uint2 data_len;

    while (low < high)
    {
        // middle
        int middle_ele = (low + high) >> 1;
        char *p = buffer + middle_ele * SegmentIndexSize;
        if (((uint4 *)p)[0] > ip)
        {
            high = middle_ele - 1;
        }
        else if (((uint4 *)p)[1] < ip)
        {
            low = middle_ele + 1;
        }
        else
        {
            data_len = ((uint2 *)(p + 8))[0];
            data = ((uint4 *)(p + 10))[0];
            break;
        }
    }
    if (data == -1)
    {
        char *p = buffer + low * SegmentIndexSize;
        data_len = ((uint2 *)(p + 8))[0];
        data = ((uint4 *)(p + 10))[0];
    }
    printf("data_len: %x\n", data_len);
    printf("data: %x\n", data);
    fseek(f, data, SEEK_SET);
    fread(ret, data_len, 1, f);
    fclose(f);
    return;
}
