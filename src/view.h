//
// Created by Css on 12/21/2018.
//

#ifndef PROJECT_VIEW_H
#define PROJECT_VIEW_H

#include <SDL_keycode.h>
#include "struct.h"

void init_window();
void destroy_window();
void set_renderer();
void draw_renderer();
void renderer_present();
//int handleEvents(/*double* snake_x, double* snake_y*/);
void draw_tanks( struct Tank* tank);
void draw_tanks2( struct Tank* tank);
void draw_bullet(double bullet_x, double bullet_y);
void draw_bullet1(double bullet_x, double bullet_y);
void draw_walls(struct Wall* walls);
void read_map_array(struct Wall* saved_Walls, int  random_num1);
void printscore(struct Tank* tank1, struct Tank* tank2);
void draw_bmine(double mine_x, double mine_y);
void draw_cmine(double mine_x, double mine_y, struct Tank* tank, struct Tank* tankp);
void mine_power(int mine_x, int mine_y, struct Tank* tank1, struct Tank* tank2);
void show_mine(struct Tank* tank1, struct Tank* tank2);
void draw_smoke(struct Tank* tank);
#endif //PROJECT_VIEW_H
