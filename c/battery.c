#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

    if (strcmp(status, "Charging\n") == 0) {
        printf(" %d%%", bperc);
    } else if (strcmp(status, "Full\n") == 0) {
        printf(" %d%%", bperc);
    } else {
         if (bperc >= 0 && bperc <= 20) {
            printf(" %d%%", bperc);
            system("systemctl suspend");
        } else if (bperc > 20 && bperc <= 30) {
            printf(" %d%%", bperc);
            system("brightnessctl set 25 > dev/null");
        } else if (bperc > 30 && bperc <= 65) {
            printf(" %d%%", bperc);
        } else if (bperc > 65 && bperc <= 85) {
            printf(" %d%%", bperc);
        } else {
            printf(" %d%%", bperc);
        }
    }
    fclose(fperc);
    fclose(fstatus);
}