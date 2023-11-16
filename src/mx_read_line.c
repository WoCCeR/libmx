#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char* rem;
    if(fd < 0 || buf_size < 1) {
        return -2;
    }

    char *str = mx_strnew(buf_size);
    char *ptr = *lineptr;
    int len = read(fd, str, buf_size);
    int cnt = 0;

    if(!len) {
        return -1;
    }

    if (rem) {
        mx_strcpy(ptr, rem);
        cnt += mx_strlen(rem);
        ptr += cnt;
        free (rem);
    }

    for (; len != 0; len = read(fd, str, buf_size)) {
        int ind = mx_get_char_index(str, delim);
        if (ind >= 0) {
            mx_strncpy(ptr, str, ind);
            cnt += ind;
            ptr += ind;
            if (ind < len) {
                rem = mx_strnew(len - ind - 1);
                str += ind + 1;
                mx_strcpy(rem, str);
            }
            break;
        }
        mx_strncpy(ptr, str, len);
        ptr += len;
        cnt += len;
    }
    return cnt;
}
