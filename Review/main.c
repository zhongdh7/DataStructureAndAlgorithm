#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "Point.h"
#ifdef _WIN32
#include <windows.h>
#endif

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

int main(int argc, const char **argv)
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    void fun2();
    int fun(int);
    // fun();
    printf("The sum of the first 100 natural numbers is: %d\n", fun(888));
    printf("下面是指针的学些\n");
    printf("%s\n", *(argv + argc - 1));
    int a = 99;
    int *p = &a;
    printf("%p\n", p);
    printf("%p\n", &p);
    printf("%d\n", *p);
    printf("%zu\n", sizeof(p));
    int q = 90;
    printf("%p\n", &q);
    *p = 820393;
    printf("%d\n", a);
    fun2();

    void fun3();
    fun3();

    Point p1;
    p1.x=90;
    p1.name=(char*)malloc(sizeof(char)*30);
    if(p1.name==NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    strcpy(p1.name,"name");
    printf("%.2f\n",p1.x);
    printf("%s\n",p1.name);
    free(p1.name);

    struct Hero hs[4];
    for (int i=0;i<sizeof(hs)/sizeof(struct Hero);i++)
    {
        strcpy(hs[i].hero_name,"hero_name");
    }
    for(int i = 0; i < sizeof(hs)/sizeof(struct Hero); i++)
    {
        printf("%s\n", hs[i].hero_name);
    }
    typedef struct Hero Hero;
    Hero h1;
    strcpy(h1.hero_name,"李信");
    h1.attack=999;
    printf("%s\n", h1.hero_name);

    Hero* hp=&h1;

    printf("%f\n",hp->attack);
    hp->health=4500;
    printf("%f\n", h1.health);

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
    int a[] = {16, 17, 27, 89, 90};
    printf("%p\n", (void *)a);
    printf("%zu\n", sizeof(a));
    printf("%lld\n", sizeof(a) / sizeof(a[0]));

    int len = sizeof(a) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");

    return sum;
}

void fun2()
{
    int a[] = {16, 17, 27, 89, 90};
    int *p = a;
    printf("%p\n", (void *)a);
    printf("%zu\n", sizeof(a));
    printf("%lld\n", sizeof(a) / sizeof(a[0]));
    printf("%d\n", *a);
    printf("%d\n", *p);
    printf("%d\n", p == a);
    bool flag = true;
    printf("%d\n", flag);
}

void fun3()
{
    int a = 9, b = 10;
    printf("before swap: a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("after swap: a: %d, b: %d\n", a, b);
}