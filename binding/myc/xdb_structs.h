#ifndef XDB_STRUCTS_H
#define XDB_STRUCTS_H
#include <stdio.h>
typedef unsigned int uint4;
typedef unsigned short uint2;
#pragma pack(1)
typedef struct Header
{
    /* data */
    uint2 version;
    uint2 strategy;
    uint4 create_time;
    uint4 vector_table_start;
    uint4 vector_table_end;
} Header;
#pragma pack()

#pragma pack(1)
typedef struct Vector_entry
{
    uint4 region_index_start;
    uint4 region_index_end;
} Vector_entry;
#pragma pack()

typedef struct Binary_search_entry{
    uint4 start_ip;
    uint4 end_ip;
    uint2 data_len;
    uint4 data_point;
}Binary_search_entry;

uint4 getint(FILE *f);
uint2 getshort(FILE *f);
uint4 ip_to_uint4(char * ip);
Vector_entry get_vector_entry(uint4 ip);
void binary_search(uint4 start, uint4 end,uint4 ip,char *ret);
#define SegmentIndexSize 14
#define ROW_SIZE 256
#define COLUMN_SIZE 256
#define VectorIndexSize 8
#endif