//
// Created by Css on 12/21/2018.
//
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>

#include <SDL2_gfxPrimitives.h>

#include "view.h"
#include "struct.h"
#include "physic.h"
#include "logic.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* screen;
int circlerad = 15;
int ellipsmallrad = 8;
int ellipbigrad = 40;
int bulletrad = 2;
int minerad = 5;
int mine_powerflag1;
int mine_powerflag2;
int mine1_x, mine1_y, mine2_x, mine2_y, mine3_x, mine3_y, mine4_x, mine4_y;
int putmine_flag1;
int putmine_flag2;
int mine_timer;
int start_ticks;
int begining_of_time;
void init_window(void){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Ulter_Tank!!!", 400, 80, 677, 718, SDL_WINDOW_OPENGL);

}
void destroy_window(void){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void set_renderer(void){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
void draw_renderer(void){
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
    SDL_RenderClear(renderer);

}
void renderer_present(void){
    SDL_RenderPresent(renderer);
}
void draw_tanks2( struct Tank* tank){
    int i, j;

    filledCircleRGBA(renderer, tank -> x + circlerad * cos(tank -> direction), tank -> y - circlerad * sin(tank -> direction) , circlerad/3, 100, 100, 100, 255);
    filledCircleRGBA(renderer, tank -> x, tank -> y , circlerad,  75 , 119 , 175 , 255);
    filledCircleRGBA(renderer, tank -> x, tank -> y , circlerad / 2, 42 , 64 , 98, 255);

}
void draw_tanks( struct Tank* tank){
    int i, j;

    filledCircleRGBA(renderer, tank -> x + circlerad * cos(tank -> direction), tank -> y - circlerad * sin(tank -> direction) , circlerad/3, 100, 100, 100, 255);
    filledCircleRGBA(renderer, tank -> x, tank -> y , circlerad, 0, 100, 100, 255);
    filledCircleRGBA(renderer, tank -> x, tank -> y , circlerad / 2, 0, 50, 50, 255);

}
void draw_bullet(double bullet_x, double bullet_y) {
    filledCircleRGBA(renderer, bullet_x, bullet_y, bulletrad,  0, 100, 100, 255);
}
void draw_bullet1(double bullet_x, double bullet_y) {
    filledCircleRGBA(renderer, bullet_x, bullet_y, bulletrad,  75 , 119 , 175 , 255);
}
void draw_walls(struct Wall* walls){
    SDL_RenderDrawLine(renderer, walls -> x1, walls -> y1, walls -> x2, walls -> y2);
}

int saved_walls1_x[44] = {0, 1, 1, 2, 2, 3, 4, 4, 5, 0, 3, 0, 4, 1, 5, 2, 4, 1, 3, 0, 6, 0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 1, 5, 4, 6, 3, 5, 2, 4, 1, 6, 6};
int saved_walls1_y[44] = {0, 1, 3, 2, 4, 2, 2, 5, 4, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 0, 7, 7 ,2, 4, 3, 6, 3, 3, 6, 6, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7};
int saved_walls2_x[72] = {0, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 8, 0, 4, 0, 3, 6, 1, 0, 5, 3, 5, 1, 4, 6, 2, 7, 1, 9, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 8, 9, 8, 1, 4, 9, 5, 3, 6, 4, 6, 2, 5, 8, 4, 8, 4, 9, 9};
int saved_walls2_y[72] = {0, 5, 1, 4, 0, 4, 6, 3, 7, 1, 6, 2, 6, 8, 3, 8, 2, 6, 0, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 0, 9, 9, 7, 3, 5, 2, 5, 7, 4, 8, 2, 8, 4, 7, 9, 6, 9, 5, 8, 0, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9, 9};
int saved_walls3_x[62] = {0, 2, 3, 3 ,4, 4, 5, 6, 6, 6, 7, 7, 8, 8, 0, 1, 5, 8, 1, 0, 3, 0, 4, 6, 1, 3, 8, 0, 2, 9, 0, 0, 2, 3, 3, 4, 4, 5, 6, 6, 6, 7, 7, 8, 8, 9, 3, 6, 9, 8, 2, 4, 3, 5, 8, 2, 6, 9, 1, 8, 9, 9};
int saved_walls3_y[62] = {0, 5, 0, 3, 1, 4, 3, 0, 2, 4, 1, 3, 2, 4, 0, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 0, 7, 7, 6, 1, 4, 3, 5, 4, 1, 3, 5, 2, 4, 3, 5, 0, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7};
//srand(time(0));

void read_map_array(struct Wall* saved_Walls, int random_num1){

    int i = 0;
    switch(random_num1) {
        case 0:

            for (i = 0; i < 22; i++) {
                saved_Walls->x1 = saved_walls1_x[i] * 75;
                saved_Walls->y1 = saved_walls1_y[i] * 75;
                saved_Walls->x2 = saved_walls1_x[i + 22] * 75;
                saved_Walls->y2 = saved_walls1_y[i + 22] * 75;
                draw_walls(saved_Walls);
            }
            break;
        case 1:
            for (i = 0; i < 36; i++) {
                saved_Walls->x1 = saved_walls2_x[i] * 75;
                saved_Walls->y1 = saved_walls2_y[i] * 75;
                saved_Walls->x2 = saved_walls2_x[i + 36] * 75;
                saved_Walls->y2 = saved_walls2_y[i + 36] * 75;
                draw_walls(saved_Walls);
            }
            break;
        case 2:
            for (i = 0; i < 31; i++) {
                saved_Walls->x1 = saved_walls3_x[i] * 75;
                saved_Walls->y1 = saved_walls3_y[i] * 75;
                saved_Walls->x2 = saved_walls3_x[i + 31] * 75;
                saved_Walls->y2 = saved_walls3_y[i + 31] * 75;
                draw_walls(saved_Walls);
            }
            break;
    }

}
void printscore(struct Tank* tank1, struct Tank* tank2){

    char* tank1score = malloc(50 * sizeof(char));
    char* tank2score = malloc(50 * sizeof(char));
    char* tank1bullet = malloc(50 * sizeof(char));
    char* tank2bullet = malloc(50 * sizeof(char));
    char* tank1hurt = malloc(50 * sizeof(char));
    char* tank2hurt = malloc(50 * sizeof(char));
    char tank1writing[100] = "Tank1 score is : ";
    char tank2writing[100] = "Tank2 score is : ";
    sprintf(tank1score,"%d", tank1 -> score);
    sprintf(tank1bullet,"%s" "%d", "Tank1's bullet: ", 40 - tank1 -> bullet_counter);
    sprintf(tank1hurt, "%s""%d", "Tank1's health: ",10 - tank1 -> hurt);
    stringRGBA(renderer, 100, 680, tank1writing, 0, 100, 100 , 255);
    stringRGBA(renderer, 240, 680, tank1score, 0, 100, 100 , 255);
    stringRGBA(renderer, 100, 710, tank1hurt, 0, 100, 100 , 255);
    if(tank1 -> bullet_counter <= 20){
        stringRGBA(renderer, 100, 695, tank1bullet, 0, 100, 100 , 255);
    }
    else{
        stringRGBA(renderer, 100, 695, "you have no bullet", 0, 100, 100 , 255);
    }
    sprintf(tank2score, "%d", tank2 -> score);
    sprintf(tank2bullet, "%s""%d",  "Tank2's bullet: ",40 - tank2 -> bullet_counter);
    sprintf(tank2hurt, "%s""%d", "Tank2's health: ", 10 - tank2 -> hurt);
    stringRGBA(renderer, 439, 680, tank2writing,  75 , 119 , 175, 255);
    stringRGBA(renderer, 579, 680, tank2score, 75 , 119 , 175 , 255);
    stringRGBA(renderer, 439, 710, tank2hurt, 75 , 119 , 175 , 255);
    if(tank2 -> bullet_counter <= 20){
        stringRGBA(renderer, 439, 695, tank2bullet, 75 , 119 , 175 , 255);
    }
    else{
        stringRGBA(renderer, 439, 695, "you have no bullet", 75 , 119 , 175 , 255);
    }



}
void draw_bmine(double mine_x, double mine_y) {
    filledCircleRGBA(renderer, mine_x, mine_y, minerad,  1, 1, 1, 255);
}

void draw_cmine(double mine_x, double mine_y, struct Tank* tank, struct Tank* tankp) {
    // filledCircleRGBA(renderer, mine_x, mine_y, minerad,  255, 255, 255, 0);
    if(sqrt(pow(tank -> x - mine_x, 2) + pow(tank -> y - mine_y, 2)) < 30 ){
        filledCircleRGBA(renderer, mine_x, mine_y, 40,  255, 10, 10, 100);
        filledCircleRGBA(renderer, mine_x, mine_y, 10,  255, 0, 0, 255);
        tank -> hurt += 5;
        mine_timer ++;
        if(1){
            putmine_flag1 = 0;
            putmine_flag2 = 0;
        }


    }

    if (tank->hurt >= 10) {
        tank->hurt = 0;
        tankp->score += 1;
    }

}
//mine_powerflag1 = 1;

void mine_power(int mine_x, int mine_y, struct Tank* tank1, struct Tank* tank2){
    mine_powerflag1 = 1;
   if(mine_powerflag1 == 1){
       draw_bmine(mine_x, mine_y);
   }
    if(sqrt(pow(tank1 -> x - mine_x, 2) + pow(tank1 -> y - mine_y, 2)) < 8 && tank1 -> mine == 0){
        mine_powerflag1 = 0;
        tank1 -> mine = 1;
    }

    else if(sqrt(pow(tank2 -> x - mine_x, 2) + pow(tank2 -> y - mine_y, 2)) < 8 && tank2 -> mine == 0){
        mine_powerflag1 = 0;
        tank2 -> mine = 1;
    }

}
void show_mine(struct Tank* tank1, struct Tank* tank2){
    if(start_ticks - begining_of_time > 20000 && start_ticks - begining_of_time < 40000){
        mine_power(mine1_x, mine1_y, tank1, tank2);
    }
    if(start_ticks - begining_of_time > 60000 && start_ticks - begining_of_time < 80000){

        mine_power(mine2_x, mine2_y, tank1, tank2);
    }
    if(start_ticks - begining_of_time > 100000 && start_ticks - begining_of_time < 120000){
        //mine_powerflag1 = 1;
        mine_power(mine3_x, mine3_y, tank1, tank2);
    }
    if(start_ticks - begining_of_time > 1400000 && start_ticks - begining_of_time < 160000){
        //mine_powerflag1 = 1;
        mine_power(mine4_x, mine4_y, tank1, tank2);
    }
}
double smokerad;
double i;
void draw_smoke(struct Tank* tank){
    smokerad = smokerad + 0.7;
    filledCircleRGBA(renderer, tank -> x - 15 *cos(tank -> direction) -i, tank -> y + 15 *sin(tank -> direction) + i, smokerad, 128, 128, 128, 200);
    i += 0.5;
    if(smokerad >= 5){
        smokerad = 0;
    }
    if(i >= 7){
        i = 0;
    }

}