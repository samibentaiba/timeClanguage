#include <stdio.h>

int main()
{
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;
    int ageYears, ageMonths, ageDays;
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
    int isLeapYear = (birthYear % 4 == 0 && birthYear % 100 != 0) || (birthYear % 400 == 0);
    int daysInBirthMonth;
    if (birthMonth == 2)
    {
        daysInBirthMonth = isLeapYear ? 29 : 28;
    }
    else if (birthMonth == 4 || birthMonth == 6 || birthMonth == 9 || birthMonth == 11)
    {
        daysInBirthMonth = 30;
    }
    else
    {
        daysInBirthMonth = 31;
    }
    if (currentDay < birthDay)
    {
        currentDay += (birthMonth == 3 && isLeapYear) ? 29 : daysInBirthMonth;
        currentMonth--;
    }
    ageDays = currentDay - birthDay;
    if (currentMonth < birthMonth)
    {
        currentMonth += 12;
        currentYear--;
    }
    ageMonths = currentMonth - birthMonth;
    ageYears = currentYear - birthYear;
    printf("Your age is: %d years, %d months, and %d days.\n", ageYears, ageMonths, ageDays);
    return main();
}
