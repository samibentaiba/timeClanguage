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
        printf("Give me the end hour (0-23): ");
        scanf("%d", &hourend);
    } while (hourend < 0 || hourend > 23);
    do
    {
        printf("Give me the end minute (0-59): ");
        scanf("%d", &minuteend);
    } while (minuteend < 0 || minuteend > 59);
    if (hourend < hourstart || (hourend == hourstart && minuteend < minutestart))
    {
        hourend += 24;
    }
    hourduration = hourend - hourstart;
    minuteduration = minuteend - minutestart;
    if (minuteduration < 0)
    {
        minuteduration += 60;
        --hourduration;
    }
    printf("Duration: %dh %dm\n", hourduration, minuteduration);
    return main();
}
