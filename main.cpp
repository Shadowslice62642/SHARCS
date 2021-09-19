#define dev 1
#include <iostream>
#include "coordMoves.h"
#include "solver.h"
#include "cubieMoves.h"

int main(){
    testing();
    make_move_tables(6, 6);
    return 0;
}