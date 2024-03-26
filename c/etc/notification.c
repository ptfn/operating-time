#include <libnotify/notification.h>
#include <unistd.h>
#include <glib.h>

int main(void)
{
    NotifyNotification *notif;
    notify_init("egewg");
    notif = notify_notification_new("hello", "2", NULL);
    notify_notification_show(notif, NULL);
    return 0;
}
