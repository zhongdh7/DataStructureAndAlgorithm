#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, const char **argv)
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    int fun(int);
    // fun();
    printf("The sum of the first 100 natural numbers is: %d\n", fun(888));

    return 0;
}

int fun(int max)
{
    int sum = 0;
    for (int i = 1; i <= max; i++)
    {
        sum += i;
    }
    // printf("The sum of the first 100 natural numbers is: %d\n", sum);
    return sum;
}
