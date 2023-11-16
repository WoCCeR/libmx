#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file) {
        return NULL;
    }

    int f = open(file, O_RDONLY);
    if (f < 0) return NULL;

    char c;
    int len = 0;

    while (read(f, &c, 1) != 0) {
        len++;
    }
    close(f);

    f = open(file, O_RDONLY);
    char *result = mx_strnew(1);

    read(f, result, len);

    close(f);
    return result;
}
