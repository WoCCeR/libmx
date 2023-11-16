#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL)
        return NULL;
    for (int i = 0; i < mx_strlen(haystack) - mx_strlen(needle)+1; i++) {
        if (haystack[i] == needle[0]) {
            int j;
            for (j = 1; j < mx_strlen(needle); j++) {
                if (haystack[j + i] != needle[j]) {
                    break;
                }
            }
            if (j == mx_strlen(needle))
                return (char *) &haystack[i];

        }
    }
    return NULL;
}
