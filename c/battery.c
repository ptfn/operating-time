#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_BATTERY 30
#define MAX_NOTIFY_TEXT 50

void notify(char *message)
{
    char command[MAX_NOTIFY_TEXT] = "notify-send ";
    strcat(command, message);
    system(command);
}

int main()
{
    char *fname_percent = "/sys/class/power_supply/BAT0/capacity";
    char *fname_status = "/sys/class/power_supply/BAT0/status";
    char *fname_choice = "/home/ptfn/.local/bin/bat.txt";
    char percent[3], status[12], choice[12];
    FILE *fperc, *fstatus, *fchoice;

    if ((fperc = fopen(fname_percent, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    if ((fstatus = fopen(fname_status, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    if ((fchoice = fopen(fname_choice, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    fgets(percent, 3, fperc);
    fgets(status, 12, fstatus);
    fgets(choice, 12, fchoice);

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
            system("brightnessctl set 25 > /dev/null");
        } else if (bperc > 30 && bperc <= 65) {
            printf(" %d%%", bperc);
        } else if (bperc > 65 && bperc <= 85) {
            printf(" %d%%", bperc);
        } else {
            printf(" %d%%", bperc);
        }
    }

    if (strcmp(choice, status) != 0) {
        if (strcmp(status, "Charging\n") == 0) {
            notify("'Battery Charging!'");
            system("echo Charging > /home/ptfn/.local/bin/bat.txt");
        } else {
            if (bperc <= MIN_BATTERY) {
                notify("'Battery Low!'");
                system("echo Discharging > /home/ptfn/.local/bin/bat.txt");
            }
        }
    }

    fclose(fperc);
    fclose(fstatus);
    fclose(fchoice);
}