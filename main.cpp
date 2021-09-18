#include <iostream>
#include <chrono>
#include "coordMoves.h"

int main(){
    void (*fcnPtr)();
    fcnPtr = &testing;
    auto t1 = std::chrono::high_resolution_clock::now();
    //fcnPtr();
    make_move_tables(6, 6);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
    std::cout << std::endl << "took: " << duration.count() << " microseconds" << std::endl;
    return 0;
}