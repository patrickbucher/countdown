#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "timefmt.h"

int time_str_to_seconds(const char *time_str)
{
    int i, n, acc, seconds;
    char c;

    seconds = 0;
    acc = 0;
    n = strlen(time_str);

    for (i = 0; i < n; i++) {
        c = time_str[i];
        if (isdigit(c)) {
            acc = acc * 10 + c - '0';
        }
        if (isalpha(c)) {
            switch (c) {
                case 'h':
                    seconds += acc * 3600;
                    acc = 0;
                    break;
                case 'm':
                    seconds += acc * 60;
                    acc = 0;
                    break;
                case 's':
                    seconds += acc;
                    acc = 0;
                    break;
                default:
                    return -1;
            }
        }
    }

    return seconds;
}
