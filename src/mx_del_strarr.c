#include "../inc/libmx.h"

void mx_del_strarr(char ***arr){
    if(arr && *arr){
        while (*arr){
            free(*arr);
        }
        *arr = NULL;
    }
}
