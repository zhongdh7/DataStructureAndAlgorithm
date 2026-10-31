#ifndef POINT_H
#define POINT_H

typedef struct Point
{
    char* name;
    double x;
    double y;
}Point;

struct Hero
{
    char hero_name[32];
    double health;
    double magic;
    double attack;
    double attack_frequency;
};

#endif