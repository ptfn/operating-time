#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    struct tm date = {
        .tm_mday = atoi(argv[1]),
        .tm_mon = atoi(argv[2])-1,
        .tm_year = atoi(argv[3])-1900
    };
    time_t now = time(NULL), date_time = mktime(&date), diff = date_time-now;

    while (diff > 0) {
        diff = date_time-now;
        struct tm *diff_date = gmtime(&diff);
        now = time(NULL);
        printf("%d/%d/%d/%d\n", diff_date->tm_mday, diff_date->tm_hour, diff_date->tm_min, diff_date->tm_sec);
        usleep(1e5);
    }
    return 0;
}

