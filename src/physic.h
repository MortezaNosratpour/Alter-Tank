//
// Created by Css on 12/22/2018.
//

#ifndef PROJECT_PHYSIC_H
#define PROJECT_PHYSIC_H

void movetank(SDL_Keycode keycode , struct Tank* tank1, int x[], int y[], int num);
void movetank2(SDL_Keycode keycode , struct Tank* tank1, int x[], int y[], int num, struct Tank* tank2);
void fire(struct Tank* tank);
void fire1(struct Tank* tank);
void move_bullet( struct bullet* bullet, int x[], int y[], int n);
void move_bullet1( struct bullet* bullet, int x[], int y[], int n);
void show_menu(struct Tank* tank1, struct Tank* tank2);
void get_score(void);
//physics.c

#endif //PROJECT_PHYSIC_H
