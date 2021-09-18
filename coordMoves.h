#include <iostream>
#include <stdio.h>
#include "cubieMoves.h"
#include "encoding.h"

//cubie move vectors
//automate assignment?
uint8_t* (*edge_perm[18])(uint8_t[12]);
uint8_t* (*edge_ori[18])(uint8_t[12]);
uint8_t* (*corner_perm[18])(uint8_t[8], int);
uint8_t* (*corner_ori[18])(uint8_t[8], int);

//move tables
//convert to malloc?
uint32_t *ep_table = new uint32_t[3991680];
uint16_t *eo_table = new uint16_t[12288];
uint16_t *cp_table = new uint16_t[241920];
uint16_t *co_table = new uint16_t[13122];

void make_ep_table(uint8_t* (*edge_perm[18])(uint8_t[12])) {
    uint8_t edges_p[12];
    uint8_t edges_p_2[12];
    uint64_t temp = 0;
    int iteration = 6;
    for (int i = 0; i < 12; i++){
        edges_p[i] = i;
    }
    for(uint64_t i = 0; i < 665280; i++){
        std::copy(&edges_p[0], &edges_p[12], &edges_p_2[0]);
        temp = 6*encode_perm(6, 12, edges_p);
        for(int j = 0; j < 6; j++){
            std::copy(&edges_p_2[0], &edges_p_2[12], &edges_p[0]);
            ep_table[temp+j] = encode_perm(6, 12, edge_perm[j](edges_p));
        }
        for (int j = 0; j < 12; j++){
            if (edges_p[j] > 5){
                edges_p[j] = 12;
            }
        }
        std::next_permutation(&edges_p[0], &edges_p[12]);
        iteration = 6;
        for (int j = 0; j < 12; j++)
        if (edges_p[j] == 12){
            edges_p[j] = iteration;
            iteration++;
        }
    }
    FILE *f;
    f = fopen("ep_moves.table", "wb");
    fwrite(ep_table, 4, 3991680, f);
}

void make_cp_table(uint8_t* (*corner_perm[18])(uint8_t[8], int)) {
    uint8_t corners_p[8];
    uint8_t corners_p_2[8];
    uint64_t temp = 0;
    for (int i = 0; i < 8; i++){
        corners_p[i] = i;
    }
    for(uint64_t i = 0; i < 40320; i++){
        std::copy(&corners_p[0], &corners_p[8], &corners_p_2[0]);
        temp = 6*encode_perm(8, corners_p);
        for(int j = 0; j < 6; j++){
            std::copy(&corners_p_2[0], &corners_p_2[8], &corners_p[0]);
            cp_table[temp+j] = encode_perm(8, corner_perm[j](corners_p, 1));
        }
        std::next_permutation(&corners_p[0], &corners_p[8]);
    }
    FILE *f;
    f = fopen("cp_moves.table", "wb");
    fwrite(cp_table, 2, 241920, f);
}

void make_eo_table(uint8_t* (*edge_ori[18])(uint8_t[12])) {
    uint8_t *edges_o = new uint8_t[12];
    uint8_t *edges_o_2 = new uint8_t[12];
    for(uint64_t i = 0; i < 12; i++){
        edges_o = decode_ori(2, 12, i);
        std::copy(&edges_o[0], &edges_o[12], &edges_o_2[0]);
        for(int j = 0; j < 6; j++){
            std::copy(&edges_o_2[0], &edges_o_2[12], &edges_o[0]);
            eo_table[6*i] = encode_ori(2, 12, edge_ori[j](edges_o));
        }
    }
    delete edges_o;
    delete edges_o_2;
    FILE *f;
    f = fopen("eo_moves.table", "wb");
    fwrite(eo_table, 2, 12288, f);
}

void make_co_table(uint8_t* (*corner_ori[18])(uint8_t[8], int)) {
    uint8_t *corners_o = new uint8_t[8];
    uint8_t *corners_o_2 = new uint8_t[8];
    for(uint64_t i = 0; i < 12; i++){
        std::copy(&corners_o[0], &corners_o[12], &corners_o_2[0]);
        corners_o = decode_ori(3, 8, i);
        for(int j = 0; j < 6; j++){
            std::copy(&corners_o_2[0], &corners_o_2[12], &corners_o[0]);
            co_table[6*i] = encode_ori(3, 8, corner_ori[j](corners_o, 1));
        }
    }
    delete corners_o;
    delete corners_o_2;
    FILE *f;
    f = fopen("co_moves.table", "wb");
    fwrite(co_table, 2, 13122, f);
}

void make_move_tables(){
    edge_perm[0] = &move_U_perm;
    edge_perm[1] = &move_D_perm;
    edge_perm[2] = &move_R_perm;
    edge_perm[3] = &move_L_perm;
    edge_perm[4] = &move_F_perm;
    edge_perm[5] = &move_B_perm;
    corner_ori[0] = &move_U_ori;
    corner_ori[1] = &move_D_ori;
    corner_ori[2] = &move_R_ori;
    corner_ori[3] = &move_L_ori;
    corner_ori[4] = &move_F_ori;
    corner_ori[5] = &move_B_ori;
    edge_ori[0] = &move_U_ori;
    edge_ori[1] = &move_D_ori;
    edge_ori[2] = &move_R_ori;
    edge_ori[3] = &move_L_ori;
    edge_ori[4] = &move_F_ori;
    edge_ori[5] = &move_B_ori;
    corner_perm[0] = &move_U_perm;
    corner_perm[1] = &move_D_perm;
    corner_perm[2] = &move_R_perm;
    corner_perm[3] = &move_L_perm;
    corner_perm[4] = &move_F_perm;
    corner_perm[5] = &move_B_perm;
    FILE *f;
    f = fopen("ep_moves.table", "rb");
    if (f == NULL){
        std::cout << "Generating edge permutations..." << std::endl;
        make_ep_table(edge_perm);
    }
    else {
        std::cout << "Reading edge permutations from file..." << std::endl;
        fread(ep_table, 4, 3991680, f);
    }
    f = fopen("cp_moves.table", "rb");
    if (f == NULL){
        std::cout << "Generating corner permutations..." << std::endl;
        make_cp_table(corner_perm);
    }
    else {
        std::cout << "Reading corner permutations from file..." << std::endl;
        fread(cp_table, 2, 241920, f);
    }
    f = fopen("eo_moves.table", "rb");
    if (f == NULL){
        std::cout << "Generating edge orientations..." << std::endl;
        make_eo_table(edge_ori);
    }
    else {
        std::cout << "Reading edge orientations from file..." << std::endl;
        fread(eo_table, 2, 112288, f);
    }
    f = fopen("co_moves.table", "rb");
    if (f == NULL){
        std::cout << "Generating corner orientations..." << std::endl;
        make_co_table(corner_ori);
    }
    else {
        std::cout << "Reading corner orientations from file..." << std::endl;
        fread(co_table, 2, 13122, f);
    }
}