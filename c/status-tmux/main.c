#include "status.h"
#include <stdio.h>

int main(void)
{
    char *name_temp = "/sys/class/thermal/thermal_zone0/temp";
    char *name_light_now = "/sys/class/backlight/intel_backlight/brightness";
    char *name_light_max = "/sys/class/backlight/intel_backlight/max_brightness";

    printf("[%sC][%sL][%s]",
            temp(name_temp),
            light(name_light_now, name_light_max),
            timer()
          );
    return 0;
}
