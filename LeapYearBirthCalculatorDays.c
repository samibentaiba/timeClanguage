#include <stdio.h>
int main()
{
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;
    int totalDays = 0;
    printf("Enter your birth date (day month year): ");
    scanf("%d %d %d", &birthDay, &birthMonth, &birthYear);
    printf("Enter the current date (day month year): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);
    if (birthYear <= 0 || birthMonth < 1 || birthMonth > 12 || birthDay < 1 || birthDay > 31 ||
        currentYear <= 0 || currentMonth < 1 || currentMonth > 12 || currentDay < 1 || currentDay > 31)
    {
        printf("Invalid date.\n");
        return 1;
    }
    if (currentYear < birthYear || (currentYear == birthYear && currentMonth < birthMonth) ||
        (currentYear == birthYear && currentMonth == birthMonth && currentDay < birthDay))
    {
        printf("Current date cannot be earlier than birth date.\n");
        return 1;
    }
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((birthYear % 4 == 0 && birthYear % 100 != 0) || (birthYear % 400 == 0))
    {
        daysInMonth[1] = 29;
    }
    totalDays += daysInMonth[birthMonth - 1] - birthDay;
    for (int i = birthMonth; i < 12; i++)
    {
        totalDays += daysInMonth[i];
    }
    for (int i = birthYear + 1; i < currentYear; i++)
    {
        totalDays += (i % 4 == 0 && i % 100 != 0) || (i % 400 == 0) ? 366 : 365;
    }
    if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0))
    {
        daysInMonth[1] = 29;
    }
    else
    {
        daysInMonth[1] = 28;
    }
    for (int i = 0; i < currentMonth - 1; i++)
    {
        totalDays += daysInMonth[i];
    }
    totalDays += currentDay;
    printf("Your total age in days is: %d days.\n", totalDays);
    return main();
}
