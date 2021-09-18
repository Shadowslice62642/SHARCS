#include <iostream>
#include <algorithm>
#include <cstring>

//TODO: write partial perm

uint64_t encode_perm(uint8_t pieces, uint8_t slots, uint8_t *cubie_p) {
    //preprocessing (create partial permutation array)
    uint8_t partial_perm[12];
    for (int i = 0; i < slots; i++){
        if(cubie_p[i] < pieces){
            partial_perm[cubie_p[i]] = i;
        }
    }
    //calculation (find coordinate)
    uint64_t coord_p = 0;
    int seen = 0;
    uint8_t temp = 0;
    for (int i = 0; i < pieces; i++) {
        temp = slots-partial_perm[i]-1;
        coord_p += partial_perm[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        coord_p *= slots-i-1; //partial factorial thingy
        seen += (1 << temp); //record new entry
        //std::cout << coord_p << std::endl;
    }
    coord_p /= slots-pieces; //correct for overmultiplication (12Px not 12P(x-1))
    return coord_p;
}

uint64_t encode_perm(uint8_t slots, uint8_t *cubie_p) {
    //calculation (find coordinate)
    uint64_t coord_p = 0;
    int seen = 0;
    uint8_t temp = 0;
    for (int i = 0; i < slots; i++) {
        temp = slots-cubie_p[i]-1;
        coord_p += cubie_p[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        coord_p *= slots-i-1; //partial factorial thingy
        seen += (1 << temp); //record new entry
        //std::cout << coord_ep << std::endl;
    }
    return coord_p;
}

uint64_t* encode_split_perm(uint8_t slots, uint8_t break_point, uint8_t *cubie_p){
    //calculation (find coordinates)
    uint64_t coord_p[2];
    int seen = 0;
    uint8_t temp = 0;
    for (int i = 0; i < slots; i++) {
        if (cubie_p[i] < break_point){
            temp = slots-cubie_p[i]-1;
            coord_p[0] += cubie_p[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        }
        else {
            temp = slots-cubie_p[i]-1;
            coord_p[1] += cubie_p[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        }
        coord_p[0] *= slots-i-1; //partial factorial thingy
        coord_p[1] *= slots-i-1; //partial factorial thingy
        seen += (1 << temp); //record new entry
        //std::cout << coord_ep << std::endl;
    }
    return coord_p;
}

uint64_t* encode_split_perm(uint8_t pieces, uint8_t slots, uint8_t break_point, uint8_t *cubie_p) {
    //preprocessing (create partial permutation array)
    uint8_t partial_perm[12];
    for (int i = 0; i < slots; i++){
        if(cubie_p[i] < pieces){
            partial_perm[cubie_p[i]] = i;
        }
    }
    //calculation (find coordinates)
    uint64_t coord_p[2];
    int seen = 0;
    uint8_t temp = 0;
    for (int i = 0; i < break_point; i++) {
        temp = slots-partial_perm[i]-1;
        coord_p[0] += partial_perm[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        coord_p[0] *= slots-i-1; //partial factorial thingy
        seen += (1 << temp); //record new entry
    }
    coord_p[0] /= slots-pieces; //correct for overmultiplication (12Px not 12P(x-1))
    for (int i = break_point; i < pieces; i++){
        temp = slots-partial_perm[i]-1;
        coord_p[0] += partial_perm[i]-__builtin_popcount(seen >> temp); //pieces-partial_perm[i]-1
        coord_p[0] *= slots-i-1; //partial factorial thingy
        seen += (1 << temp); //record new entry
    }
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

void testing() {
    uint8_t *cubie_ep = new uint8_t[12];
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
    std::cout << hello;
}

