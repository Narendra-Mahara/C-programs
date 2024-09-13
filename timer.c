#include <stdio.h>
#include <unistd.h> // for sleep function
#include <stdlib.h> // for system function

int main()
{
    int hour, minute, second;
    hour = minute = second = 0;
    while (1)
    {
        system("clear");
        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
        if (hour == 24)
        {
            hour = 0;
        }

        printf(" %02dH::%02dM::%02dS\n", hour, minute, second);

        sleep(1);
        second++;
    }
    return 0;
}