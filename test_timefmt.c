#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "timefmt.h"

void test_time_str_to_seconds()
{
    typedef struct {
        char *time_str;
        int seconds;
    } test_case;
    const test_case table[] = {
        {"", 0},
        {"1s", 1},
        {"30s", 30},
        {"1m", 60},
        {"1m59s", 119},
        {"1h15m59s", 4559},
        {"1h0m59s", 3659},
    };
    for (int i = 0; i < sizeof(table)/sizeof(test_case); i++) {
        const char *input = table[i].time_str;
        const int expected = table[i].seconds;
        const int actual = time_str_to_seconds(input);
        if (actual != expected) {
            printf("time_str_to_seconds(%s): expected %d, got %d\n", input, expected, actual);
            exit(1);
        }
    }
}

int main()
{
    test_time_str_to_seconds();
    puts("test_time_str_to_seconds: ok");
}
