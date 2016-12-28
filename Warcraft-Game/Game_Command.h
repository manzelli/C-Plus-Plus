// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Game_Commands (defined in Game_Command.cpp)

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>
#include "Model.h"
#include "Input_Handling.h"

using namespace std;

void move(Model*, int, double, double, View&);
void work(Model*, int, int, int, View&);
void stop(Model*, int, View&);
void go(Model*, View&);
void run(Model*, View&);
void quit(Model*);
void list_them(Model*);
void attack(Model*, int, int, View&);
void makenew(Model*, char, int, double, double, View&);

// Exception handling
int get_int();
double get_double();
char get_char();

#endif