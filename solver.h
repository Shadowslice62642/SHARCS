#include <iostream>
#include "coordMoves.h"

struct Step {
    uint32_t *ep_moves;
    uint16_t *cp_moves;
    uint16_t *eo_moves;
    uint16_t *co_moves;
    char *prune1;
    char *prune2;
    char *prune3;
    char *prune4;
};