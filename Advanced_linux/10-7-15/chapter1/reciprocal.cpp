#include <cassert>
#include "reciprocal.hpp"
double reciprocal (int num) {
        assert (num != 0);
        return 1.0/num;
}