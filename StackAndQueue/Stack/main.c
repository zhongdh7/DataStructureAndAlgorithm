#include <stdio.h>
#include "Stack.h"
#include <stdbool.h>
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
    SeqStack *s = initSeqStack();
    int e = 0;

    printf("初始化后 top 是: %d\n", s->top);
    if (s->top == -1)
        printf("此时栈为空\n");
    else
        printf("此时栈不为空\n");

    if (push(s, 10))
        printf("10 入栈成功\n");
    else
        printf("10 入栈失败\n");

    if (push(s, 20))
        printf("20 入栈成功\n");
    else
        printf("20 入栈失败\n");

    if (push(s, 30))
        printf("30 入栈成功\n");
    else
        printf("30 入栈失败\n");

    printf("三个元素入栈后 top 是: %d\n", s->top);

    if (getTop(s, &e))
        printf("当前栈顶元素是: %d\n", e);
    else
        printf("获取栈顶元素失败\n");
    printf("取栈顶元素后 top 是: %d\n", s->top);

    if (pop(s, &e))
        printf("出栈成功, 出栈元素是: %d\n", e);
    else
        printf("出栈失败\n");

    if (pop(s, &e))
        printf("出栈成功, 出栈元素是: %d\n", e);
    else
        printf("出栈失败\n");

    if (pop(s, &e))
        printf("出栈成功, 出栈元素是: %d\n", e);
    else
        printf("出栈失败\n");

    printf("全部出栈后 top 是: %d\n", s->top);
    if (s->top == -1)
        printf("此时栈为空\n");
    else
        printf("此时栈不为空\n");

    if (pop(s, &e))
        printf("空栈出栈成功, 出栈元素是: %d\n", e);
    else
        printf("空栈出栈失败\n");

    if (getTop(s, &e))
        printf("空栈取栈顶成功, 栈顶元素是: %d\n", e);
    else
        printf("空栈取栈顶失败\n");

    if (freeSeqStack(s))
        printf("栈释放成功\n");
    else
        printf("栈释放失败\n");

    return 0;
}
