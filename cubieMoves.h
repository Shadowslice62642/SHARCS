#pragma once
#include <iostream>

//corners_p
    uint8_t* move_U_perm_c(uint8_t *corners_p){ // U
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[3];
        corners_p[3] = corners_p[2];
        corners_p[2] = corners_p[1];
        corners_p[1] = x;
        return corners_p;
    }

    uint8_t* move_L_perm_c(uint8_t *corners_p){ // L
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[1];
        corners_p[1] = corners_p[4];
        corners_p[4] = corners_p[5];
        corners_p[5] = x;
        return corners_p;
    }

    uint8_t* move_F_perm_c(uint8_t *corners_p){ // F
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[5];
        corners_p[5] = corners_p[6];
        corners_p[6] = corners_p[3];
        corners_p[3] = x;
        return corners_p;
    }

    uint8_t* move_R_perm_c(uint8_t *corners_p){ // R
        uint8_t x;
        x = corners_p[2];
        corners_p[2] = corners_p[3];
        corners_p[3] = corners_p[6];
        corners_p[6] = corners_p[7];
        corners_p[7] = x;
        return corners_p;
    }

    uint8_t* move_B_perm_c(uint8_t *corners_p){ // B
        uint8_t x;
        x = corners_p[1];
        corners_p[1] = corners_p[2];
        corners_p[2] = corners_p[7];
        corners_p[7] = corners_p[4];
        corners_p[4] = x;
        return corners_p;
    }

    uint8_t* move_D_perm_c(uint8_t *corners_p){ // D
        uint8_t x;
        x = corners_p[4];
        corners_p[4] = corners_p[7];
        corners_p[7] = corners_p[6];
        corners_p[6] = corners_p[5];
        corners_p[5] = x;
        return corners_p;
    }

//corners_o
    uint8_t* move_U_ori_c(uint8_t *corners_o){ // U
        uint8_t x;
        x = corners_o[0];
        corners_o[0] = corners_o[3];
        corners_o[3] = corners_o[2];
        corners_o[2] = corners_o[1];
        corners_o[1] = x;
        return corners_o;
    }

    uint8_t* move_L_ori_c(uint8_t *corners_o){ // L
        uint8_t x;
        x = corners_o[0];
        corners_o[0] = (corners_o[1]+1)%3;
        corners_o[1] = (corners_o[4]+2)%3;
        corners_o[4] = (corners_o[5]+1)%3;
        corners_o[5] = (x+2)%3;
        return corners_o;
    }

    uint8_t* move_F_ori_c(uint8_t *corners_o){ // F
        uint8_t x;
        x = corners_o[0];
        corners_o[0] = (corners_o[5]+2)%3;
        corners_o[5] = (corners_o[6]+1)%3;
        corners_o[6] = (corners_o[3]+2)%3;
        corners_o[3] = (x+1)%3;
        return corners_o;
    }

    uint8_t* move_R_ori_c(uint8_t *corners_o){ // R
        uint8_t x;
        x = corners_o[2];
        corners_o[2] = (corners_o[3]+1)%3;
        corners_o[3] = (corners_o[6]+2)%3;
        corners_o[6] = (corners_o[7]+1)%3;
        corners_o[7] = (x+2)%3;
        return corners_o;
    }

    uint8_t* move_B_ori_c(uint8_t *corners_o){ // B
        uint8_t x;
        x = corners_o[1];
        corners_o[1] = (corners_o[2]+1)%3;
        corners_o[2] = (corners_o[7]+2)%3;
        corners_o[7] = (corners_o[4]+1)%3;
        corners_o[4] = (x+2)%3;
        return corners_o;
    }

    uint8_t* move_D_ori_c(uint8_t *corners_o){ // D
        uint8_t x;
        x = corners_o[4];
        corners_o[4] = corners_o[7];
        corners_o[7] = corners_o[6];
        corners_o[6] = corners_o[5];
        corners_o[5] = x;
        return corners_o;
    }

//edges_p
    uint8_t* move_U_perm(uint8_t *edges_p){ // U
        uint8_t x;
        x = edges_p[0];
        edges_p[0] = edges_p[3];
        edges_p[3] = edges_p[2];
        edges_p[2] = edges_p[1];
        edges_p[1] = x;
        return edges_p;
    }

    uint8_t* move_L_perm(uint8_t *edges_p){ // L
        uint8_t x;
        x = edges_p[1];
        edges_p[1] = edges_p[4];
        edges_p[4] = edges_p[9];
        edges_p[9] = edges_p[5];
        edges_p[5] = x;
        return edges_p;
    }

    uint8_t* move_F_perm(uint8_t *edges_p){ // F
        uint8_t x;
        x = edges_p[0];
        edges_p[0] = edges_p[5];
        edges_p[5] = edges_p[10];
        edges_p[10] = edges_p[6];
        edges_p[6] = x;
        return edges_p;
    }

    uint8_t* move_R_perm(uint8_t *edges_p){ // R
        uint8_t x;
        x = edges_p[3];
        edges_p[3] = edges_p[6];
        edges_p[6] = edges_p[11];
        edges_p[11] = edges_p[7];
        edges_p[7] = x;
        return edges_p;
    }

    uint8_t* move_B_perm(uint8_t *edges_p){ // B
        uint8_t x;
        x = edges_p[2];
        edges_p[2] = edges_p[7];
        edges_p[7] = edges_p[8];
        edges_p[8] = edges_p[4];
        edges_p[4] = x;
        return edges_p;
    }

    uint8_t* move_D_perm(uint8_t *edges_p){ // D
        uint8_t x;
        x = edges_p[8];
        edges_p[8] = edges_p[11];
        edges_p[11] = edges_p[10];
        edges_p[10] = edges_p[9];
        edges_p[9] = x;
        return edges_p;
    }

    uint8_t* move_M_perm(uint8_t *edges_p){ // M
        uint8_t x;
        x = edges_p[0];
        edges_p[0] = edges_p[10];
        edges_p[10] = edges_p[8];
        edges_p[8] = edges_p[2];
        edges_p[2] = x;
        return edges_p;
    }

    uint8_t* move_S_perm(uint8_t *edges_p){ // S
        uint8_t x;
        x = edges_p[1];
        edges_p[1] = edges_p[9];
        edges_p[9] = edges_p[11];
        edges_p[11] = edges_p[3];
        edges_p[3] = x;
        return edges_p;
    }

    uint8_t* move_E_perm(uint8_t *edges_p){ // E
        uint8_t x;
        x = edges_p[4];
        edges_p[4] = edges_p[5];
        edges_p[5] = edges_p[6];
        edges_p[6] = edges_p[7];
        edges_p[7] = x;
        return edges_p;
    }

//edges_o
    uint8_t* move_U_ori(uint8_t *edges_o){ // U
        uint8_t x;
        x = edges_o[0];
        edges_o[0] = edges_o[3];
        edges_o[3] = edges_o[2];
        edges_o[2] = edges_o[1];
        edges_o[1] = x;
        return edges_o;
    }

    uint8_t* move_L_ori(uint8_t *edges_o){ // L
        uint8_t x;
        x = edges_o[1];
        edges_o[1] = edges_o[4];
        edges_o[4] = edges_o[9];
        edges_o[9] = edges_o[5];
        edges_o[5] = x;
        return edges_o;
    }

    uint8_t* move_F_ori(uint8_t *edges_o){ // F
        uint8_t x;
        x = edges_o[0];
        edges_o[0] = (edges_o[5]+1)%2;
        edges_o[5] = (edges_o[10]+1)%2;
        edges_o[10] = (edges_o[6]+1)%2;
        edges_o[6] = (x+1)%2;
        return edges_o;
    }

    uint8_t* move_R_ori(uint8_t *edges_o){ // R
        uint8_t x;
        x = edges_o[3];
        edges_o[3] = edges_o[6];
        edges_o[6] = edges_o[11];
        edges_o[11] = edges_o[7];
        edges_o[7] = x;
        return edges_o;
    }

    uint8_t* move_B_ori(uint8_t *edges_o){ // B
        uint8_t x;
        x = edges_o[2];
        edges_o[2] = (edges_o[7]+1)%2;
        edges_o[7] = (edges_o[8]+1)%2;
        edges_o[8] = (edges_o[4]+1)%2;
        edges_o[4] = (x+1)%2;
        return edges_o;
    }

    uint8_t* move_D_ori(uint8_t *edges_o){ // D
        uint8_t x;
        x = edges_o[8];
        edges_o[8] = edges_o[11];
        edges_o[11] = edges_o[10];
        edges_o[10] = edges_o[9];
        edges_o[9] = x;
        return edges_o;
    }

    uint8_t* move_M_ori(uint8_t *edges_o){ // M
        uint8_t x;
        x = edges_o[0];
        edges_o[0] = (edges_o[10]+1)%2;
        edges_o[10] = (edges_o[8]+1)%2;
        edges_o[8] = (edges_o[2]+1)%2;
        edges_o[2] = (x+1)%2;
        return edges_o;
    }

    uint8_t* move_S_ori(uint8_t *edges_o){ // S
        uint8_t x;
        x = edges_o[1];
        edges_o[1] = (edges_o[9]+1)%2;
        edges_o[9] = (edges_o[11]+1)%2;
        edges_o[11] = (edges_o[3]+1)%2;
        edges_o[3] = (x+1)%2;
        return edges_o;
    }

    uint8_t* move_E_ori(uint8_t *edges_o){ // E
        uint8_t x;
        x = edges_o[4];
        edges_o[4] = (edges_o[5]+1)%2;
        edges_o[5] = (edges_o[6]+1)%2;
        edges_o[6] = (edges_o[7]+1)%2;
        edges_o[7] = (x+1)%2;
        return edges_o;
    }

//centers
    uint8_t* move_x(uint8_t centers[4]){
        uint8_t x = centers[0];
        centers[0] = centers[2];
        centers[2] = centers[3];
        centers[3] = centers[1];
        centers[1] = x;
        return centers;
    }

    uint8_t* move_y(uint8_t centers[4]){
        uint8_t x = centers[0];
        centers[0] = centers[3];
        centers[3] = centers[2];
        centers[2] = centers[1];
        centers[1] = x;
        return centers;
    }

    uint8_t* move_z(uint8_t centers[4]){
        uint8_t x = centers[0];
        centers[0] = centers[2];
        centers[2] = centers[1];
        centers[1] = centers[3];
        centers[3] = x;
        return centers;
    }

//full moves
/*    uint8_t* move_U(){ // U#
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[3];
        corners_p[3] = corners_p[2];
        corners_p[2] = corners_p[1];
        corners_p[1] = x;
        x = corners_o[0];
        corners_o[0] = corners_o[3];
        corners_o[3] = corners_o[2];
        corners_o[2] = corners_o[1];
        corners_o[1] = x;
        x = edges_p[0];
        edges_p[0] = edges_p[3];
        edges_p[3] = edges_p[2];
        edges_p[2] = edges_p[1];
        edges_p[1] = x;
        x = edges_o[0];
        edges_o[0] = edges_o[3];
        edges_o[3] = edges_o[2];
        edges_o[2] = edges_o[1];
        edges_o[1] = x;
    }

    uint8_t* move_L(){ // L
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[1];
        corners_p[1] = corners_p[4];
        corners_p[4] = corners_p[5];
        corners_p[5] = x;
        x = corners_o[0];
        corners_o[0] = (corners_o[1]+1)%3;
        corners_o[1] = (corners_o[4]+2)%3;
        corners_o[4] = (corners_o[5]+1)%3;
        corners_o[5] = (x+2)%3;
        x = edges_p[1];
        edges_p[1] = edges_p[4];
        edges_p[4] = edges_p[9];
        edges_p[9] = edges_p[5];
        edges_p[5] = x;
        x = edges_o[1];
        edges_o[1] = edges_o[4];
        edges_o[4] = edges_o[9];
        edges_o[9] = edges_o[5];
        edges_o[5] = x;
    }

    uint8_t* move_F(){ // F
        uint8_t x;
        x = corners_p[0];
        corners_p[0] = corners_p[5];
        corners_p[5] = corners_p[6];
        corners_p[6] = corners_p[3];
        corners_p[3] = x;
        x = corners_o[0];
        corners_o[0] = (corners_o[5]+2)%3;
        corners_o[5] = (corners_o[6]+1)%3;
        corners_o[6] = (corners_o[3]+2)%3;
        corners_o[3] = (x+1)%3;
        x = edges_p[0];
        edges_p[0] = edges_p[5];
        edges_p[5] = edges_p[10];
        edges_p[10] = edges_p[6];
        edges_p[6] = x;
        x = edges_o[0];
        edges_o[0] = (edges_o[5]+1)%2;
        edges_o[5] = (edges_o[10]+1)%2;
        edges_o[10] = (edges_o[6]+1)%2;
        edges_o[6] = (x+1)%2;
    }

    uint8_t* move_R(){ // R
        uint8_t x;
        x = corners_p[2];
        corners_p[2] = corners_p[3];
        corners_p[3] = corners_p[6];
        corners_p[6] = corners_p[7];
        corners_p[7] = x;
        x = corners_o[2];
        corners_o[2] = (corners_o[3]+1)%3;
        corners_o[3] = (corners_o[6]+2)%3;
        corners_o[6] = (corners_o[7]+1)%3;
        corners_o[7] = (x+2)%3;
        x = edges_p[3];
        edges_p[3] = edges_p[6];
        edges_p[6] = edges_p[11];
        edges_p[11] = edges_p[7];
        edges_p[7] = x;
        x = edges_o[3];
        edges_o[3] = edges_o[6];
        edges_o[6] = edges_o[11];
        edges_o[11] = edges_o[7];
        edges_o[7] = x;
    }

    uint8_t* move_B(){ // B
        uint8_t x;
        x = corners_p[1];
        corners_p[1] = corners_p[2];
        corners_p[2] = corners_p[7];
        corners_p[7] = corners_p[4];
        corners_p[4] = x;
        x = corners_o[1];
        corners_o[1] = (corners_o[2]+1)%3;
        corners_o[2] = (corners_o[7]+2)%3;
        corners_o[7] = (corners_o[4]+1)%3;
        corners_o[4] = (x+2)%3;
        x = edges_p[2];
        edges_p[2] = edges_p[7];
        edges_p[7] = edges_p[8];
        edges_p[8] = edges_p[4];
        edges_p[4] = x;
        x = edges_o[2];
        edges_o[2] = (edges_o[7]+1)%2;
        edges_o[7] = (edges_o[8]+1)%2;
        edges_o[8] = (edges_o[4]+1)%2;
        edges_o[4] = (x+1)%2;
    }

    uint8_t* move_D(){ // D
        uint8_t x;
        x = corners_p[4];
        corners_p[4] = corners_p[7];
        corners_p[7] = corners_p[6];
        corners_p[6] = corners_p[5];
        corners_p[5] = x;
        x = corners_o[4];
        corners_o[4] = corners_o[7];
        corners_o[7] = corners_o[6];
        corners_o[6] = corners_o[5];
        corners_o[5] = x;
        x = edges_p[8];
        edges_p[8] = edges_p[11];
        edges_p[11] = edges_p[10];
        edges_p[10] = edges_p[9];
        edges_p[9] = x;
        x = edges_o[8];
        edges_o[8] = edges_o[11];
        edges_o[11] = edges_o[10];
        edges_o[10] = edges_o[9];
        edges_o[9] = x;
    }

    uint8_t* move_M(){ // M
        uint8_t x;
        x = edges_p[0];
        edges_p[0] = edges_p[10];
        edges_p[10] = edges_p[8];
        edges_p[8] = edges_p[2];
        edges_p[2] = x;
        x = edges_o[0];
        edges_o[0] = (edges_o[10]+1)%2;
        edges_o[10] = (edges_o[8]+1)%2;
        edges_o[8] = (edges_o[2]+1)%2;
        edges_o[2] = (x+1)%2;
        x = centres_p[0];
        centres_p[0] = centres_p[1];
        centres_p[1] = centres_p[5];
        centres_p[5] = centres_p[3];
        centres_p[3] = x;
    }

    uint8_t* move_S(){ // S
        uint8_t x;
        x = edges_p[1];
        edges_p[1] = edges_p[9];
        edges_p[9] = edges_p[11];
        edges_p[11] = edges_p[3];
        edges_p[3] = x;
        x = edges_o[1];
        edges_o[1] = (edges_o[9]+1)%2;
        edges_o[9] = (edges_o[11]+1)%2;
        edges_o[11] = (edges_o[3]+1)%2;
        edges_o[3] = (x+1)%2;
        x = centres_p[0];
        centres_p[0] = centres_p[4];
        centres_p[4] = centres_p[5];
        centres_p[5] = centres_p[2];
        centres_p[2] = x;
    }

    uint8_t* move_E(){ // E
        uint8_t x;
        x = edges_p[4];
        edges_p[4] = edges_p[5];
        edges_p[5] = edges_p[6];
        edges_p[6] = edges_p[7];
        edges_p[7] = x;
        x = edges_o[4];
        edges_o[4] = (edges_o[5]+1)%2;
        edges_o[5] = (edges_o[6]+1)%2;
        edges_o[6] = (edges_o[7]+1)%2;
        edges_o[7] = (x+1)%2;
        x = centres_p[1];
        centres_p[1] = centres_p[2];
        centres_p[2] = centres_p[3];
        centres_p[3] = centres_p[4];
        centres_p[4] = x;
    }
    */