#include <stdio.h>
int main()
{
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;
    int ageMonths, ageDays;
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
    ageMonths = currentMonth - birthMonth;
    ageDays = currentDay - birthDay;
    if (ageDays < 0)
    {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0))
        {
            daysInMonth[1] = 29;
        }
        ageDays += daysInMonth[currentMonth - 1];
        ageMonths--;
    }
    if (ageMonths < 0)
    {
        ageMonths += 12;
        currentYear--;
    }
    ageMonths += (currentYear - birthYear) * 12;
    printf("Your age is: %d months and %d days.\n", ageMonths, ageDays);
    return main();
}
