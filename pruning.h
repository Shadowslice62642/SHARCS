#pragma once
#include <iostream>
#include "coordMoves.h"
#include "solver.h"

//pls ignore jankiness; I just want a working pruning table for now and intend to actually implement multiple coordinates later.
void makePruningTable(Step step){
    uint64_t position_count1[5];
    int coord_count1[5];
    uint64_t position_count2[5];
    int coord_count2[5];
    uint64_t position_count3[5];
    int coord_count3[5];
    uint64_t position_count3[5];
    int coord_count3[5];
    uint64_t position_count4[5];
    int coord_count4[5];
    step.prune1 = makePermPrune(step.cp_moves, coord_count1, position_count1);
    step.prune2 = makePermPrune(step.ep_moves, coord_count2, position_count2);
    step.prune3 = makeOriPrune(step.co_moves, coord_count3, position_count3);
    step.prune4 = makeOriPrune(step.eo_moves, coord_count4, position_count4);
}

template <typename T> //look ma, templates!
char* makePermPrune(T move_table, int* coord_count, uint64_t* position_count){

}

template <typename T>
char* makePermPrune(T move_table, uint64_t* position_count){

}

template <typename T> //look ma, templates!
char* makeOriPrune(T move_table, int* coord_count, uint64_t* position_count){

}

template <typename T>
char* makeOriPrune(T move_table, uint64_t* position_count){

}