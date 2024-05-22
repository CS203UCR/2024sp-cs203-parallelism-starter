#include"join_reference.hpp"
#include"join_solution.hpp"
#include <vector>

#define ELEMENT_TYPE uint64_t

typedef std::tuple<int, int> Bench;

std::vector<Bench> benches = {
    std::make_tuple(600, 2),
    std::make_tuple(350, 25),
    std::make_tuple(120, 100),
};

extern "C"
void join_reference_c(order *orders, product *products, uint64_t o_records, uint64_t p_records, uint64_t brands, int64_t *result)
{
    {
        join_reference(orders, products, o_records, p_records, brands, result);
    }
}
FUNCTION(join, join_reference_c);


extern "C"
void join_solution_c(order *orders, product *products, uint64_t o_records, uint64_t p_records, uint64_t brands, int64_t *result)
{
    {
        join_solution(orders, products, o_records, p_records, brands, result);
    }
}
FUNCTION(join, join_solution_c);
