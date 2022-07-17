//
// Created by Css on 12/22/2018.
//

#ifndef PROJECT_STRUCT_H
#define PROJECT_STRUCT_H

struct Tank{
    double x;
    double y;
    double direction;
    //struct bullet* bullet;
    struct bullet* bullets[40];
    int bullet_counter;
    int hurt;
    int score;
    int mine;
};
struct bullet {
    double x;
    double y;
    double angle;
    int counter;
    int flag;
    int timer;
};
struct Wall{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct Map{
    struct Tank* tank;
    struct Wall* wall;
};
struct window{
    int window_x;
    int window_y;
};

#endif //PROJECT_STRUCT_H
