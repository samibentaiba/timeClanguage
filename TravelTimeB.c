#include <stdio.h>
int main()
{
    int hourstart, minutestart, hourend, minuteend;
    int hourduration, minuteduration;
    do
    {
        printf("Give me the arrival hour (0-23): ");
        scanf("%d", &hourend);
    } while (hourend < 0 || hourend > 23);
    do
    {
        printf("Give me the arrival minute (0-59): ");
        scanf("%d", &minuteend);
    } while (minuteend < 0 || minuteend > 59);
    do
    {
        printf("Give me the duration hour (0-23): ");
        scanf("%d", &hourduration);
    } while (hourduration < 0 || hourduration > 23);
    do
    {
        printf("Give me the duration minute (0-59): ");
        scanf("%d", &minuteduration);
    } while (minuteduration < 0 || minuteduration > 59);
    minuteend -= minuteduration;
    if (minuteend < 0)
    {
        minuteend += 60;
        hourend--;
    }
    hourend -= hourduration;
    if (hourend < 0)
    {
        hourend += 24;
    }
    printf("Train started at: %02dh %02dm\n", hourend, minuteend);
    return main();
}
