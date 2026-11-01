#ifndef BOOK_H
#define BOOK_H
typedef struct Book
{
    char ISBN[10];
    char title[50];
    double price;
} Book;

#endif