#include <SDL_events.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "view.h"
#include "struct.h"
#include "physic.h"
#include "logic.h"
//
// Created by Css on 12/22/2018.
//
#include <SDL_events.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "view.h"
#include "struct.h"
#include "physic.h"
#include "logic.h"
//
// Created by Css on 12/22/2018.
//
//struct bullet bullet[20];
SDL_Renderer* renderer;
int flag;
int *run;
double tempmine_x;
double tempmine_y;
int menuper;
int circle = 15;
const int step = 5;
const int bulletstep = 6;
SDL_Event event;
int menu_flag;
int user_score;
int* start_menu;
int putmine_flag1;
int putmine_flag2;
int mine_powerflag1;
SDL_RWops *file;
SDL_RWops *rw;
void move_bullet(struct bullet* bullet, int x[], int y[], int n);
void move_bullet1(struct bullet* bullet, int x[], int y[], int n);
int mine1_x, mine1_y, mine2_x, mine2_y, mine3_x, mine3_y, mine4_x, mine4_y;
int ran;
int begining_of_time;
void get_score(){
    int i =  1;
    char *score = malloc(sizeof(char) * 100);
    sprintf(score, "%s", "** enter the score **");
    stringRGBA(renderer, 250, 100, score, rand()%1, rand()%1, rand()%255, 255);
    i++;
    if(i == 255)
        i = 1;
    SDL_Event score_num;
    while(SDL_PollEvent(&score_num)) {

        if (score_num.type == SDL_QUIT){
            *run = 0;
            break;
        }

        else if (score_num.type == SDL_KEYDOWN){
            switch(score_num.key.keysym.sym){
                case SDLK_KP_MINUS:
                    user_score = SDLK_KP_MINUS;
                    //stringRGBA(renderer, 404, 404, "salam", 0, 0, 0 ,255);
                    menuper = 1;
                    menu_flag = 0;
                    *run = 1;
                    break;
                case SDLK_ESCAPE:
                    //stringRGBA(renderer, 404, 404, "salam", 0, 0, 0 ,255);
                    menuper = 1;
                    menu_flag = 0;
                    *run = 1;
                    break;
                case SDLK_q:
                    menu_flag = 0;
                    SDL_Quit();
                    break;

            }
        }

    }

}
void show_menu(struct Tank* tank1, struct Tank* tank2){
    menu_flag =1;
    char *ulter = malloc(sizeof(char) * 100);
    sprintf(ulter, "%s", "       *** U L T E R  T A N K ***");
    stringRGBA(renderer, 200, 55, ulter, rand()%256, rand()%1, rand()%1, 255);
    // SDL_RenderSetScale(renderer, 3, 3);
    //   SDL_RenderSetScale(renderer, 1, 1);
    char *start = malloc(sizeof(char) * 100);
    sprintf(start, "%s", "     * press \"s\" to start new game *");
    stringRGBA(renderer, 200, 100, start, 0, 0, 0, 255);

    char *continu = malloc(sizeof(char) * 100);
    sprintf(continu, "%s", "* press \"c\" to continue or start this game*");
    stringRGBA(renderer, 200, 155, continu, 0, 0, 0, 255);
    //SDL_RenderSetScale(renderer, 3, 3);
    // SDL_RenderSetScale(renderer, 1, 1);
    char *load = malloc(sizeof(char) * 100);
    sprintf(load, "%s", "         * press \"l\" to load *");
    stringRGBA(renderer, 200, 200, load, 0, 0, 0, 255);
    // SDL_RenderSetScale(renderer, 3, 3);
    //SDL_RenderSetScale(renderer, 1, 1);
    char *quit = malloc(sizeof(char) * 50);
    sprintf(quit, "%s", "         * press \"q\" to quit *");
    stringRGBA(renderer, 200, 245, quit, 0, 0, 0, 255);
    //SDL_RenderSetScale(renderer, 3, 3);
    //(renderer, 1, 1);
    while(SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT){
            *run = 0;
            break;
        }

        else if (event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_s:
                    ran = rand()%3;
                    begining_of_time = SDL_GetTicks();
                    tank1 -> mine = 0;
                    tank1 -> hurt = 0;
                    tank1 -> bullet_counter = 0;
                    tank1 -> score = 0;
                    tank1 -> direction = rand() % 7;
                    tank2 -> mine = 0;
                    tank2 -> hurt = 0;
                    tank2 -> bullet_counter = 0;
                    tank2 -> score = 0;
                    tank2 -> direction = rand() % 7;
                    switch (ran){
                        case 0 :
                            tank1->x = rand() % 410;
                            tank1->y = rand() % 485;
                            tank2->x = rand() % 410;
                            tank2->y = rand() % 485;
                            mine1_x = rand() % 400;
                            mine1_y = rand() % 470;
                            mine2_x = rand() % 400;
                            mine2_y = rand() % 470;
                            mine3_x = rand() % 400;
                            mine3_y = rand() % 470;
                            mine4_x = rand() % 400;
                            mine4_y = rand() % 470;
                            break;
                        case 1 :
                            tank1->x = rand() % 635;
                            tank1->y = rand() % 635;
                            tank2->x = rand() % 635;
                            tank2->y = rand() % 635;
                            mine1_x = rand() % 630;
                            mine1_y = rand() % 630;
                            mine2_x = rand() % 630;
                            mine2_y = rand() % 630;
                            mine3_x = rand() % 630;
                            mine3_y = rand() % 630;
                            mine4_x = rand() % 630;
                            mine4_y = rand() % 630;
                            break;
                        case 2 :
                            tank1->x = rand() % 635;
                            tank1->y = rand() % 485;
                            tank2->x = rand() % 635;
                            tank2->y = rand() % 485;
                            mine1_x = rand() % 620;
                            mine1_y = rand() % 470;
                            mine2_x = rand() % 620;
                            mine2_y = rand() % 470;
                            mine3_x = rand() % 620;
                            mine3_y = rand() % 470;
                            mine4_x = rand() % 620;
                            mine4_y = rand() % 470;
                            break;
                    }
                    break;
                case SDLK_c:

                    menuper = 1;
                    menu_flag = 0;
                    *run = 1;
                    // get_score();
                    break;


                case SDLK_ESCAPE:

                    menuper = 1;
                    menu_flag = 0;
                    *run = 1;
                    break;
                case SDLK_q:
                    menu_flag = 0;
                    SDL_Quit();
                    break;

            }
        }

    }

}

void fire(struct Tank* tank1){

    tank1 -> bullets[tank1 -> bullet_counter] -> x = tank1 -> x + circle * cos(tank1 -> direction) ;
    tank1 -> bullets[tank1 -> bullet_counter]-> y = tank1 -> y - circle * sin(tank1 -> direction) ;
    tank1 -> bullets[tank1 -> bullet_counter] -> angle = tank1 -> direction;
    tank1 -> bullets[tank1 -> bullet_counter] -> flag = 1;
    tank1 -> bullet_counter ++;

}
void fire1(struct Tank* tank2){
    tank2 -> bullets[tank2 -> bullet_counter] -> x = tank2 -> x + circle * cos(tank2 -> direction) ;
    tank2 -> bullets[tank2 -> bullet_counter] -> y = tank2 -> y - circle * sin(tank2 -> direction) ;
    tank2 -> bullets[tank2 -> bullet_counter] -> angle = tank2 -> direction;
    tank2 -> bullets[tank2 -> bullet_counter] -> flag = 1;
    tank2 -> bullet_counter ++;
}
int bulllog_flag;
void move_bullet(struct bullet* bullet, int x[], int y[], int n){
    if((bullet_logic(bullet, x, y, n))){
        bullet -> x += bulletstep * cos(bullet -> angle);
        bullet -> y -= bulletstep * sin(bullet -> angle);
    }
    else if(!(bullet_logic(bullet, x, y, n))){
        bullet -> x += 0;
        bullet -> y -= 0;

    }
}

void move_bullet1(struct bullet* bullet, int x[], int y[], int n){
    if((bullet_logic(bullet, x, y, n))){
        bullet -> x += bulletstep * cos(bullet -> angle);
        bullet -> y -= bulletstep * sin(bullet -> angle);
    }
    else if(!(bullet_logic(bullet, x, y, n))){
        bullet -> x += 0;
        bullet -> y -= 0;

    }
}
putmine_flag1 = 0;
putmine_flag2 = 0;
void  movetank (SDL_Keycode key, struct Tank* tank1, int x[], int y[], int num){
    switch (key) {
        case SDLK_UP:
            if (logic(tank1, x, y, num, key)) {
                tank1->x += step * cos(tank1->direction);
                tank1->y -= step * sin(tank1->direction);
           }
            draw_smoke(tank1);
            break;
        case SDLK_DOWN:
           if (logic(tank1, x, y, num, key)) {
                tank1->x -= step * cos(tank1->direction);
                tank1->y += step * sin(tank1->direction);
           }
            draw_smoke(tank1);
            break;
        case SDLK_RIGHT:

            tank1->direction -= 0.2;
            break;
        case SDLK_LEFT:

            tank1->direction += 0.2;
            break;
        case SDLK_m:
            if(tank1 -> mine == 0 && tank1 -> bullet_counter <= 20){
                fire(tank1);
            }
            else if(tank1 -> mine == 1){
                mine_powerflag1 = 1;
                tank1 -> mine = 0;
                tempmine_x = tank1 -> x;
                tempmine_y = tank1 -> y;
                putmine_flag1 = 1;
            }
            break;
           }
}


void  movetank2(SDL_Keycode key, struct Tank* tank2, int x[], int y[], int num, struct Tank* tank1) {
    int i;
    switch (key) {
        case SDLK_w:
            if (logic1(tank2, x, y, num, key)) {
                tank2->x += step * cos(tank2->direction);
                tank2->y -= step * sin(tank2->direction);
            }
            draw_smoke(tank2);
            break;
        case SDLK_s:
            if (logic1(tank2, x, y, num, key)) {
                tank2->x -= step * cos(tank2->direction);
                tank2->y += step * sin(tank2->direction);
            }
            draw_smoke(tank2);
            break;
        case SDLK_d:

            tank2->direction -= 0.2;
            break;
        case SDLK_a:
            tank2->direction += 0.2;
            break;
        case SDLK_v:

            if(tank2 -> mine == 0 && tank2 -> bullet_counter <= 20){
                fire1(tank2);
            }
            else if(tank2 -> mine == 1){
                tank2 -> mine = 0;
                tempmine_x = tank2 -> x;
                tempmine_y = tank2 -> y;
                putmine_flag2 = 1;
            }

            break;
        case SDLK_ESCAPE:
            show_menu(tank1, tank2);
            break;

    }

}
