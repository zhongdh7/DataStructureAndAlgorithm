#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    int a=5;
    int *b=(int*)malloc(sizeof(int)*2);
    if(!b)return -1;
    b[0]=a;
    b[1]=90;
    printf("%p\n",&a);
    printf("%p\n",b);
    printf("%p\n",&b);
    printf("%d\n",*b);
    printf("%d\n",sizeof(b));
    printf("%d\n",b[1]);
    free(b);
    int*b2=b+1;
    printf("%d\n",(b2-b));
    

    return 0;
}