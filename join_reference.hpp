
#include <cstdlib>
#include "archlab.h"
#include <unistd.h>
#include<cstdint>
#include"function_map.hpp"
#include "table_struct.h"

#ifndef join_REFERENCE_INCLUDED
#define join_REFERENCE_INCLUDED




//template<typename T>
void __attribute__((noinline)) join_reference(order *orders, product *products, uint64_t o_records, uint64_t p_records, uint64_t brands, int64_t *result) {

    uint64_t k = 0; 

    for(int32_t i = 0; i < o_records; i++) {
        k = orders[i].product_id;
        result[products[k].brand] += orders[i].quantity*products[k].price;
    }
    return;

}

#endif
