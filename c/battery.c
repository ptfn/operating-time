#include <stdlib.h>
#include <stdio.h>

#define FULL "";
#define CHARGING ""
#define DISCHARGING ""

int main()
{
    char *fname_percent = "/sys/class/power_supply/BAT0/capacity";
    char *fname_status = "/sys/class/power_supply/BAT0/status";
    char percent[3], status[12];
    FILE *fperc, *fstatus;

    if ((fperc = fopen(fname_percent, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    
    if ((fstatus = fopen(fname_status, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    fgets(percent, 3, fperc);
    fgets(status, 12, fstatus);

    int bperc = atoi(percent);

    if (status == "Charging") {
        printf("%s %d", CHARGING, bperc);
    }

    printf("%s", status);

    fclose(fperc);
    fclose(fstatus);
}