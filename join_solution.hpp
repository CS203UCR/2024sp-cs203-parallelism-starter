#ifndef join_SOLUTION_INCLUDED
#define join_SOLUTION_INCLUDED
#include <cstdlib>
#include "archlab.h"
#include <unistd.h>
#include<cstdint>
#include"function_map.hpp"
#include "table_struct.h"
#include <omp.h>
#include <atomic>

typedef struct p_order_t {
    uint64_t brand;
    uint64_t subtotal;
}  p_order;
#define NUM_OF_THREADS 4
#define TILE_SIZE 64
//template<typename T>
void __attribute__((noinline)) join_solution(order *orders, product *products, uint64_t o_records, uint64_t p_records, uint64_t brands, int64_t *result) {

    uint64_t k = 0;

    for(int32_t i = 0; i < o_records; i++) {
        k = orders[i].product_id;
        {
            result[products[k].brand] += orders[i].quantity*products[k].price;
        }
    }

    return;
}

#endif
