#ifndef __DATA_T_H__
#define __DATA_T_H__ 

#include <string.h>
typedef struct{
    char id[16];
    char name[40];
    int grade;

} data_sv;

void showData(const data_sv data);
