#include <stdio.h>
int main()
{
    int hourstart, minutestart, hourend, minuteend;
    int hourduration, minuteduration;
    do
    {
        printf("Give me the start hour (0-23): ");
        scanf("%d", &hourstart);
    } while (hourstart < 0 || hourstart > 23);
    do
    {
        printf("Give me the start minute (0-59): ");
        scanf("%d", &minutestart);
    } while (minutestart < 0 || minutestart > 59);
    do
    {
        printf("Give me the hour (0-23): ");
        scanf("%d", &hourduration);
    } while (hourduration < 0 || hourduration > 23);
    do
    {
        printf("Give me the minute (0-59): ");
        scanf("%d", &minuteduration);
    } while (minuteduration < 0 || minuteduration > 59);
    minuteend = minutestart + minuteduration;
    if (minuteend > 59)
    {
        minuteend -= 60;
        hourduration++;
    }
    hourend = hourstart + hourduration;
    if (hourend > 23)
    {
        hourend -= 24;
    }
    printf("Arrive at: %02dh %02dm", hourend, minuteend);
    return main();
}