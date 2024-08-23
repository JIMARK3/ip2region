#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xdb_structs.h"
Vector_entry get_vector_entry(uint4 ip)
{

    FILE *f = fopen("./mydata/ip2region.xdb", "r");
    if (f == NULL)
    {
        printf("open file failed\n");
        exit(EXIT_FAILURE);
    }
    // Header header;
    // size_t len = fread(&header, sizeof(Header),1, f);
    // printf("sizeof(header): %d\n", sizeof(header));
    // printf("len: %x\n", len);
    // if (len<1)
    // {
    //     printf("debug1\n");
    //     printf("read file failed\n");
    //     fclose(f);
    //     exit(EXIT_FAILURE);
    // }
    // printf("header.version: %x\n", header.version);
    // printf("header.strategy: %x\n", header.strategy);
    // printf("header.create_time: %x\n", header.create_time);
    // printf("header.vector_table_start: %x\n", header.vector_table_start);
    // printf("header.vector_table_end: %x\n", header.vector_table_end);

    // fseek(f, 256, SEEK_SET);
    uint4 row = ((ip >> 24) & 0xff);
    uint4 column = ((ip >> 16) & 0xff);
    uint4 index = (row * COLUMN_SIZE * VectorIndexSize + column * VectorIndexSize);
    printf("index: %x\n", index);
    fseek(f, index + 256, SEEK_SET);
    Vector_entry v_entry;
    printf("ftell is %x\n", ftell(f));
    fread(&(v_entry.region_index_start), 4, 1, f);
    fread(&(v_entry.region_index_end), 4, 1, f);
    printf("vector_entry: %x\n", sizeof(v_entry));
    fclose(f);
    printf("v_entry.region_index_start: %x\n", v_entry.region_index_start);
    printf("v_entry.region_index_end: %x\n", v_entry.region_index_end);
    return v_entry;
};