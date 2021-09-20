#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

//TODO: Add permutation decoder?

#define preprocessing(slots, pieces) \
    uint8_t partial_perm[12]; \
    for (int i = 0; i < slots; i++){\
        if(cubie_p[i] < pieces){ \
            partial_perm[cubie_p[i]] = i;\
        } \
    }\

#define coord_calc(iter_start, iter_end, coord_p) \
    for (int i = iter_start; i < iter_end; i++) {\
        temp = slots-partial_perm[i]-1;\
        coord_p += partial_perm[i]-__builtin_popcount(seen >> temp);\
        coord_p *= slots-i-1;\
        seen += (1 << temp);\
    }

    /*for (int i = 0; i < pieces; i++) {\
        temp = slots-partial_perm[i]-1;\
        coord_p += partial_perm[i]-__builtin_popcount(seen >> temp);\ //pieces-partial_perm[i]-1
        coord_p *= slots-i-1; \//partial factorial thingy
        seen += (1 << temp); \//record new entry
    }*/

uint64_t encode_perm(uint8_t pieces, uint8_t slots, uint8_t *cubie_p) {
    preprocessing(slots, pieces);
    uint64_t coord_p = 0;
    int seen = 0;
    uint64_t temp = 0;
    coord_calc(0, pieces, coord_p)
    coord_p /= slots-pieces; //correct for overmultiplication (12Px not 12P(x-1))
    return coord_p;
}

uint64_t encode_perm(uint8_t slots, uint8_t *cubie_p) {
    preprocessing(slots, slots)
    uint64_t coord_p = 0;
    int seen = 0;
    uint64_t temp = 0;
    coord_calc(slots, slots-1, coord_p)
    coord_p += cubie_p[slots-1]-__builtin_popcount(seen >> temp);
    return coord_p;
}

uint64_t encode_split_perm(uint8_t slots, uint8_t break_point, uint8_t *cubie_p){
    preprocessing(slots, slots)
    uint64_t temp_coord_p[2];
    int seen = 0;
    uint64_t temp = 0;
    coord_calc(0, break_point, temp_coord_p[0])
    uint64_t coord_p = (temp_coord_p[0] << 32);
    coord_calc(break_point, slots-1, temp_coord_p[1])
    temp_coord_p[1] += cubie_p[slots-1]-__builtin_popcount(seen >> temp);
    coord_p += temp_coord_p[1];
    return coord_p;
}

uint64_t encode_split_perm(uint8_t pieces, uint8_t slots, uint8_t break_point, uint8_t *cubie_p) {
    preprocessing(slots, pieces)
    uint64_t temp_coord_p[2];
    int seen = 0;
    uint64_t temp = 0;
    coord_calc(0, break_point, temp_coord_p[0])
    uint64_t coord_p = (temp_coord_p[0] << 32);
    coord_calc(break_point, pieces, temp_coord_p[1])
    temp_coord_p[1] /= slots-pieces; //correct for overmultiplication
    coord_p += temp_coord_p[1];
    return coord_p;
}

uint64_t encode_ori(uint8_t ori_count, uint8_t slots, uint8_t *cubie_o){
    uint64_t coord_o = 0;
    for (int i = 0; i < slots; i++){
        coord_o *= ori_count;
        coord_o += cubie_o[i];
    }
    return coord_o;
}

uint8_t* decode_ori(uint8_t ori_count, uint8_t slots, uint64_t coord_o){
    uint8_t* cubie_o = new uint8_t[slots];
    for(int i = 0; i < slots; i++){
        cubie_o[slots-i] = coord_o%ori_count;
        coord_o /= ori_count;
    }
    return cubie_o;
}

#if (dev == 1)
void testing() {
    uint8_t cubie_ep[12];
    uint8_t iteration = 6;
    uint64_t hello = 0;
    uint8_t *checked = new uint8_t[665280];
    memset(checked, 0, 665280);
    for (int i = 0; i < 12; i++){
        cubie_ep[i] = i;
    }
    for(uint64_t i = 0; i < 665280; i++){
        hello = encode_perm(6, 12, cubie_ep);
        /*std::cout << "iteration: " << i << " permutation: ";
        for (int j = 0; j < 12; j++) {
            std::cout << (int)cubie_ep[j] << " ";
        }
        std::cout << "coord: " << hello << std::endl;*/
        if (checked[hello] == 1){
            std::cout << i << " oops " << hello << " " << std::endl;
        }
        else {
            checked[hello] = 1;
        }
        for (int j = 0; j < 12; j++){
            if (cubie_ep[j] > 5){
                cubie_ep[j] = 12;
            }
        }
        std::next_permutation(&cubie_ep[0], &cubie_ep[12]);
        iteration = 6;
        for (int j = 0; j < 12; j++)
        if (cubie_ep[j] == 12){
            cubie_ep[j] = iteration;
            iteration++;
        }
    }
    hello = 0;
    for (uint64_t i = 0; i < 665280; i++){
        hello += checked[i];
    }
    //std::cout << hello;
}
#endif