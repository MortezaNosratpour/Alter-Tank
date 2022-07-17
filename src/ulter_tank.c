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

//
// Created by Css on 12/21/2018.
//
#ifdef main
#undef main
#endif
SDL_Renderer* renderer;
SDL_Surface* screen;
SDL_Event events;
SDL_Event events2;
SDL_Event event;
int flag;
int mine_powerflag1;
int* run = &flag;
int menu_flag;
int putmine_flag2;
int putmine_flag1;
double tempmine_x;
double tempmine_y;
int mine_timer;
int begining_of_time;
int start_ticks;
int mine1_x, mine1_y, mine2_x, mine2_y, mine3_x, mine3_y, mine4_x, mine4_y;
int timer_flag;
int ran;
int main(){
    timer_flag = 1;
    int saved_walls1_x[44] = {0, 1, 1, 2, 2, 3, 4, 4, 5, 0, 3, 0, 4, 1, 5, 2, 4, 1, 3, 0, 6, 0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 1, 5, 4, 6, 3, 5, 2, 4, 1, 6, 6};
    int saved_walls1_y[44] = {0, 1, 3, 2, 4, 2, 2, 5, 4, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 0, 7, 7 ,2, 4, 3, 6, 3, 3, 6, 6, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7};
    int saved_walls2_x[72] = {0, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 8, 0, 4, 0, 3, 6, 1, 0, 5, 3, 5, 1, 4, 6, 2, 7, 1, 9, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 8, 9, 8, 1, 4, 9, 5, 3, 6, 4, 6, 2, 5, 8, 4, 8, 4, 9, 9};
    int saved_walls2_y[72] = {0, 5, 1, 4, 0, 4, 6, 3, 7, 1, 6, 2, 6, 8, 3, 8, 2, 6, 0, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 0, 9, 9, 7, 3, 5, 2, 5, 7, 4, 8, 2, 8, 4, 7, 9, 6, 9, 5, 8, 0, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9, 9};
    int saved_walls3_x[62] = {0, 2, 3, 3 ,4, 4, 5, 6, 6, 6, 7, 7, 8, 8, 0, 1, 5, 8, 1, 0, 3, 0, 4, 6, 1, 3, 8, 0, 2, 9, 0, 0, 2, 3, 3, 4, 4, 5, 6, 6, 6, 7, 7, 8, 8, 9, 3, 6, 9, 8, 2, 4, 3, 5, 8, 2, 6, 9, 1, 8, 9, 9};
    int saved_walls3_y[62] = {0, 5, 0, 3, 1, 4, 3, 0, 2, 4, 1, 3, 2, 4, 0, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 0, 7, 7, 6, 1, 4, 3, 5, 4, 1, 3, 5, 2, 4, 3, 5, 0, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7};
    srand(time(0));
    struct Tank* tank1 = malloc(sizeof (struct Tank));
    tank1 -> direction = rand() % 7;
    tank1 -> bullet_counter = 0;
    tank1 -> hurt = 0;
    tank1 -> score = 0;
    tank1 -> mine = 0;
    struct Tank* tank2 = malloc(sizeof(struct Tank));
    tank2 -> direction = rand() % 7;
    tank2 -> bullet_counter = 0;
    tank2 -> hurt = -9;
    tank2 -> score = -1;
    tank2 -> mine = 0;


    ran = rand() % 3;
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
    init_window();
    set_renderer();

    int counter1 = 0;
    int counter = 0;
    struct bullet* bullets1[40];
    for(counter = 0 ; counter < 40 ; counter++){
        bullets1[counter] = malloc(sizeof(struct bullet));
        tank1 -> bullets[counter] = bullets1[counter];
        bullets1[counter] -> x = tank1 -> x;
        bullets1[counter] -> y = tank1 -> y;
        bullets1[counter] -> flag = 0;
    }


    struct bullet* bullets2[40];
    for(counter = 0 ; counter < 40 ; counter++){
        bullets2[counter] = malloc(sizeof(struct bullet));
        tank2 -> bullets[counter] = bullets2[counter];
        bullets2[counter] -> x = tank2 -> x;
        bullets2[counter] -> y = tank2 -> y;
        bullets2[counter] -> flag = 0;
    }


    struct Wall* save_walls = malloc(sizeof(struct Wall));
     begining_of_time = SDL_GetTicks();
    char* time_buffer = malloc(sizeof(char) * 50);
    const double FPS = 50;
    int flag = 1;
    int* run = &flag;
    int max_bullet = 40;

    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // Mix_Music* background = Mix_LoadMUS("Dream Raid Full Version (Mock Up).mp3");
    // Mix_PlayMusic(background, -1);
    menu_flag =1;
    flag = 1;
    while (*run) {
        if (menu_flag) {
            show_menu(tank1, tank2);
        }
        if (timer_flag == 1) {
            start_ticks = SDL_GetTicks();
        }

        while (SDL_PollEvent(&events)) {

            if (events.type == SDL_QUIT) {
                *run = 0;
                break;
            } else if (events.type == SDL_KEYDOWN) {

                switch (ran) {
                    case 0 :
                        movetank2(events.key.keysym.sym, tank2, saved_walls1_x, saved_walls1_y, 22, tank1);
                        movetank(events.key.keysym.sym, tank1, saved_walls1_x, saved_walls1_y, 22);

                        break;
                    case 1 :
                        movetank2(events.key.keysym.sym, tank2, saved_walls2_x, saved_walls2_y, 36, tank1);
                        movetank(events.key.keysym.sym, tank1, saved_walls2_x, saved_walls2_y, 36);
                        break;
                    case 2 :
                        movetank2(events.key.keysym.sym, tank2, saved_walls3_x, saved_walls3_y, 31, tank1);
                        movetank(events.key.keysym.sym, tank1, saved_walls3_x, saved_walls3_y, 31);
                        break;
                }
            }


        }
        Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if (keystates[SDLK_w]) {
            //if (logic1(tank2, x, y, num, key)) {
            tank2->x += 5 * cos(tank2->direction);
            tank2->y -= 5 * sin(tank2->direction);
            //}
            draw_smoke(tank2);
        }

        if (keystates[SDLK_s]) {
            // if (logic1(tank2, x, y, num, key)) {
            tank2->x -= 5 * cos(tank2->direction);
            tank2->y += 5 * sin(tank2->direction);
            // }
            draw_smoke(tank2);
        }

        if (keystates[SDLK_d]) {
            tank2->direction -= 0.2;
        }

        if (keystates[SDLK_a]) {
            tank2->direction += 0.2;
        }
        if (keystates[SDLK_v]) {
            if (tank2->mine == 0 && tank2->bullet_counter <= 20) {
                fire1(tank2);
            } else if (tank2->mine == 1) {
                tank2->mine = 0;
                tempmine_x = tank2->x;
                tempmine_y = tank2->y;
                putmine_flag2 = 1;
            }
        }

        /*if (keystates[SDLK_ESCAPE]) {
            show_menu(tank1, tank2);
        }
        if (keystates[SDLK_UP]) {
            //if (logic(tank1, x, y, num, key)) {
            tank1->x += 5 * cos(tank1->direction);
            tank1->y -= 5 * sin(tank1->direction);
            //}
            draw_smoke(tank1);
        }
        if (keystates[SDLK_DOWN]) {
            //  if (logic(tank1, x, y, num, key)) {
            tank1->x -= 5 * cos(tank1->direction);
            tank1->y += 5 * sin(tank1->direction);
        //}
        draw_smoke(tank1);
        }
        if(keystates[SDLK_RIGHT]) {
            tank1->direction -= 0.2;
        }
        if(keystates[SDLK_LEFT]) {
            tank1->direction += 0.2;
        }
        if(keystates[SDLK_m]) {
            if (tank1->mine == 0 && tank1->bullet_counter <= 20) {
                fire(tank1);
            } else if (tank1->mine == 1) {
                mine_powerflag1 = 1;
                tank1->mine = 0;
                tempmine_x = tank1->x;
                tempmine_y = tank1->y;
                putmine_flag1 = 1;
            }
        }*/




        int i, j;
        for(i = 0 ; i < 40 ; i++){
            if(tank1 -> bullets[i] -> flag && tank1 -> bullets[i] -> timer <30){
                switch (ran){
                    case 0 :
                        move_bullet(bullets1[i], saved_walls1_x, saved_walls1_y, 22);
                        break;
                    case 1 :
                        move_bullet(bullets1[i], saved_walls2_x, saved_walls2_y, 36);
                        break;
                    case 2 :
                        move_bullet(bullets1[i], saved_walls3_x, saved_walls3_y, 31);
                        break;
                }
                tank1 -> bullets[i] -> timer++;
                if(1){
                    draw_bullet(bullets1[i] -> x, bullets1[i] -> y);

                }
            }
        }
        for( j = 0 ; j < 40 ; j++){
            if(tank2 -> bullets[j] -> flag && tank2 -> bullets[j] -> timer < 30 ){
             //   move_bullet1(bullets2[j], saved_walls1_x, saved_walls1_y);
                switch (ran){
                    case 0 :
                        move_bullet1(bullets2[j], saved_walls1_x, saved_walls1_y, 22);
                        break;
                    case 1 :
                        move_bullet1(bullets2[j], saved_walls2_x, saved_walls2_y, 36);
                        break;
                    case 2 :
                        move_bullet1(bullets2[j], saved_walls3_x, saved_walls3_y, 31);
                        break;
                }
                tank2 -> bullets[j] -> timer++;
                if(1){
                    draw_bullet1(bullets2[j] -> x, bullets2[j] -> y);

                }
            }
        }

        /*if(tank1 -> bullet_counter == 40 && tank2 -> bullet_counter == 40){
            show_menu(tank1, tank2);
        }*/
        if(tank2 -> bullet_counter == 40 && tank1 -> bullet_counter == 40){
            *run=0;
        }
        for( i = 0 ; i < 40 ; i++){
            tankscore(bullets1[i], bullets2[i], tank1, tank2, ran, start_ticks);
        }

        printscore(tank1, tank2);
        sprintf(time_buffer, "%s""%d s", "time:",(start_ticks - begining_of_time)/1000 );
        stringRGBA(renderer, 5, 5, time_buffer, 0, 0, 0, 255);
        if(putmine_flag2){
          //mine_timer = 0;
            draw_cmine(tempmine_x, tempmine_y, tank1, tank2);
        }
        if(putmine_flag1){
          //mine_timer = 0;
            draw_cmine(tempmine_x, tempmine_y, tank2, tank1);
        }
        show_mine(tank1, tank2);
        draw_tanks( tank1);
        draw_tanks2(tank2);
        read_map_array(save_walls, ran );
        renderer_present();
        draw_renderer();
        while (SDL_GetTicks() - start_ticks < 1000 / FPS){
            SDL_Delay(50);
        }

    }
    // Mix_FreeMusic(background);
    //  Mix_CloseAudio();

    destroy_window();

    return 0;

}

