#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    int i = 0;
    if (delim == NULL)
        return;
    while(arr[i] != NULL){
        mx_printstr(arr[i]);
        mx_printstr(delim);
        i++;
    }
}
