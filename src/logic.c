
//logic.c
//
// Created by Css on 12/27/2018.
//
#include <SDL_events.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <time.h>
#include "physic.h"
#include "view.h"
#include "struct.h"
#include "logic.h"
SDL_Renderer* renderer;
int *run;
int tankrad = 15;
int tankstep = 5;
int user_score;
int timer_flag;
int begining_of_time;
int start_ticks;
int flag;
int logic( struct Tank* tank, int x[], int y[], int n, SDL_Keycode key){
    int i, j, x1[80], y1[80], flag = 1 ;
    for(j = 0 ; j <  2*n ; j++){
        x1[j] = x[j] * 75;
        y1[j] = y[j] * 75;
    }
    for(i = 0 ; i < n ; i++){
        if(x1[i] == x1[i + n]){
            if((tank -> y >= y1[i] && tank -> y <= y1[n + i]))
                if(tank -> x + tankrad < x1[i]) {
                    if(key == SDLK_UP) {
                        if (tank->x + tankrad + (tankstep * cos(tank->direction)) >= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_DOWN) {
                        if (tank->x + tankrad - (tankstep * cos(tank->direction)) >= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }

                }
                else if(tank -> x - tankrad >= x1[i]) {
                    if(key == SDLK_UP) {
                        if (tank->x - tankrad + (tankstep * cos(tank->direction)) <= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_DOWN) {
                        if (tank->x - tankrad - (tankstep * cos(tank->direction)) <= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }

        }
        else if(y1[i] == y1[i + n]){
            if((tank -> x >= x1[i] && tank -> x <= x1[n + i]))
                if(tank -> y + tankrad < y1[i]) {
                    if(key == SDLK_UP) {
                        if (tank->y + tankrad - (tankstep * sin(tank->direction)) >= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_DOWN) {
                        if (tank->y + tankrad + (tankstep * sin(tank->direction)) >= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }

                }
                else if(tank -> y - tankrad >= y1[i]) {
                    if(key == SDLK_UP) {
                        if (tank->y - tankrad - (tankstep * sin(tank->direction)) <= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_DOWN) {
                        if (tank->y - tankrad + (tankstep * sin(tank->direction)) <= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }

        }
        else{
            flag = 1;
        }
    }
    if(flag == 0){
        flag = 1;
        return 0;
    }
    flag = 1;
    return 1;

}
int logic1( struct Tank* tank2, int x[], int y[], int n, SDL_Keycode key){
    int i, j, x1[80], y1[80], flag = 1 ;
    for(j = 0 ; j <  2*n ; j++){
        x1[j] = x[j] * 75;
        y1[j] = y[j] * 75;
    }
    for(i = 0 ; i < n ; i++){
        if(x1[i] == x1[i + n]){
            if((tank2 -> y > y1[i] && tank2 -> y < y1[n + i]))
                if(tank2 -> x + tankrad < x1[i]) {
                    if(key == SDLK_w) {
                        if (tank2->x + tankrad + (tankstep * cos(tank2->direction)) >= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_s) {
                        if (tank2->x + tankrad - (tankstep * cos(tank2->direction)) >= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }

                }
                else if(tank2 -> x - tankrad >= x1[i]) {
                    if(key == SDLK_w) {
                        if (tank2->x - tankrad + (tankstep * cos(tank2->direction)) <= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_s) {
                        if (tank2->x - tankrad - (tankstep * cos(tank2->direction)) <= x1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }

        }
        else if(y1[i] == y1[i + n]){
            if((tank2 -> x > x1[i] && tank2 -> x < x1[n + i]))
                if(tank2 -> y + tankrad < y1[i]) {
                    if(key == SDLK_w) {
                        if (tank2->y + tankrad - (tankstep * sin(tank2->direction)) >= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_s) {
                        if (tank2->y + tankrad + (tankstep * sin(tank2->direction)) >= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }

                }
                else if(tank2 -> y - tankrad >= y1[i]) {
                    if(key == SDLK_w) {
                        if (tank2->y - tankrad - (tankstep * sin(tank2->direction)) <= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else if(key == SDLK_s) {
                        if (tank2->y - tankrad + (tankstep * sin(tank2->direction)) <= y1[i]) {
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }

        }
    }
    if(flag == 0){
        flag = 1;
        return 0;
    }
    flag = 1;
    return 1;

}
int times;
times = 0;
int tankscore(struct bullet* bullet, struct bullet* bullet1, struct Tank* tank, struct Tank* tank1, int ran, int start_ticks) {
    // int start_ticks = SDL_GetTicks();
    if (sqrt(pow((bullet->x) - (tank->x), 2) + pow((bullet->y) - (tank->y), 2)) < 16 ||
        sqrt(pow((bullet1->x) - (tank->x), 2) + pow((bullet1->y) - (tank->y), 2)) < 16) {
        tank->hurt += 1;
    }
    if (tank->hurt >= 10) {
        tank->hurt = 0;
        tank1->score += 1;
        switch (ran) {
            case 0 :
                tank1->x = rand() % 410;
                tank1->y = rand() % 485;
                tank->x = rand() % 410;
                tank->y = rand() % 485;
                //  windowcomp  -> window_x = 450;
                // windowcomp -> window_y = 525;
                break;
            case 1 :
                tank1->x = rand() % 635;
                tank1->y = rand() % 635;
                tank->x = rand() % 635;
                tank->y = rand() % 635;
                // windowcomp  -> window_x = 675;
                // windowcomp -> window_y = 675;
                break;
            case 2 :
                tank1->x = rand() % 635;
                tank1->y = rand() % 485;
                tank->x = rand() % 635;
                tank->y = rand() % 485;
                // windowcomp  -> window_x = 675;
                //windowcomp -> window_y = 525;
                break;
        }

    }
    if (sqrt(pow((bullet->x) - (tank1->x), 2) + pow((bullet->y) - (tank1->y), 2)) < 16 ||
        sqrt(pow((bullet1->x) - (tank1->x), 2) + pow((bullet1->y) - (tank1->y), 2)) < 16) {
        tank1->hurt += 1;
    }
    if (tank1->hurt >= 10) {
        tank1->hurt = 0;
        tank->score += 1;
        switch (ran) {
            case 0 :
                tank1->x = rand() % 410;
                tank1->y = rand() % 485;
                tank->x = rand() % 410;
                tank->y = rand() % 485;
                //  windowcomp  -> window_x = 450;
                // windowcomp -> window_y = 525;
                break;
            case 1 :
                tank1->x = rand() % 635;
                tank1->y = rand() % 635;
                tank->x = rand() % 635;
                tank->y = rand() % 635;
                // windowcomp  -> window_x = 675;
                // windowcomp -> window_y = 675;
                break;
            case 2 :
                tank1->x = rand() % 635;
                tank1->y = rand() % 485;
                tank->x = rand() % 635;
                tank->y = rand() % 485;
                // windowcomp  -> window_x = 675;
                //windowcomp -> window_y = 525;
                break;
        }

    }
    int time = start_ticks - begining_of_time;
    int i = 0;
    char *tankscore = malloc(sizeof(char) * 50);
    char *tank1score = malloc(sizeof(char) * 50);
    char* time_buffer = malloc(sizeof(char) * 50);
    if (tank->score == 5 || tank1 -> score == 5) {
       // int time = start_ticks - begining_of_time;
        //while (i < 10000) {
            if (tank->score == 5 && times < 100000 ) {
                timer_flag = 0;
                sprintf(tankscore, "%s" "%d", "tank1 win!, score = ", tank->score);
                sprintf(tank1score, "%s" "%d", "tank2 lose!, score = ", tank1->score);
                stringRGBA(renderer, 200, 300, tankscore, 0, 100, 100, 255);
                stringRGBA(renderer, 200, 350, tank1score, 75, 119, 175, 255);
                sprintf(time_buffer, "game time is: " "%d ms", time);
                stringRGBA(renderer, 200, 400, time_buffer, 0, 0, 0, 255);
                stringRGBA(renderer, 200, 450, "press \"esc\"  ", 0, 0, 0, 255);
                times++;
            }


             else if (tank1->score == 5 && times < 100000) {
                timer_flag = 0;
                char* i = malloc(sizeof(char) * 50);
                sprintf(i, "%s" "%d", "i : ", times);
                stringRGBA(renderer, 200, 30, i, 0, 100, 100, 255);
                sprintf(tank1score, "%s" "%d", "tank2 win!, score = ", tank1->score);
                sprintf(tankscore, "%s" "%d", "tank1 win!, score = ", tank->score);
                stringRGBA(renderer, 200, 300, tankscore, 0, 100, 100, 255);
                stringRGBA(renderer, 200, 350, tank1score, 75, 119, 175, 255);
                sprintf(time_buffer, "game time is: " "%d ms",time );
                stringRGBA(renderer, 200, 400, time_buffer, 0, 0, 0, 255);
                stringRGBA(renderer, 200, 450, "press \"esc\"  ", 0, 0, 0, 255);
                times++;
            }
            if(times >= 100000){
                flag = 0;
            }
    }

}

int bulllog_flag;
int bullet_logic(struct bullet* bullet, int x[], int y[], int n) {
    int i, j;
    int x1[80], y1[80] ;
    for(j = 0 ; j <  2*n ; j++){
        x1[j] = x[j] * 75;
        y1[j] = y[j] * 75;
    }
    for( i = 0 ; i < n ; i++){
        if(x1[i] ==  x1[n+i]){
            if(bullet -> y > y1[i] && bullet -> y < y1[i+n]){
                if( (bullet -> x < x1[i] &&bullet -> x + 1  >= x1[i]) ||  (bullet -> x > x1[i] && bullet -> x - 1 <= x1[i])){
                    bulllog_flag = 0;
                    break;
                }
                else{
                    bulllog_flag = 0;
                }

            }
            else{
                bulllog_flag = 1;
            }


        }
        else if(y1[i] == y1[i+n]){
            if(bullet -> x < x1[i] && bullet -> x > x1[i+n]){
                if((bullet -> y < y1[i] && bullet -> y + 1  >= y1[i]) ||  (bullet -> y > y1[i] && bullet -> y - 1 <= y1[i])){
                    bulllog_flag = 0;
                    break;
                }
                else{
                    bulllog_flag = 0;
                }
            }
            else{
                bulllog_flag = 1;
            }



        }

    }
    if(bulllog_flag == 0){
        bulllog_flag = 1;
        return 0;
    }
    bulllog_flag = 1;
    return 1;
}
