//
// Created by Css on 12/27/2018.
//

#ifndef PROJECT_LOGIC_H
#define PROJECT_LOGIC_H
int logic( struct Tank* tank, int x[], int y[], int n, SDL_Keycode key);
int logic1( struct Tank* tank2, int x[], int y[], int n, SDL_Keycode key);
int tankscore(struct bullet* bullet, struct bullet* bullet1, struct Tank* tank, struct Tank* tank1, int ran, int start_ticks);
int bullet_logic(struct bullet* bullet, int x[], int y[], int n);
#endif //PROJECT_LOGIC_H
