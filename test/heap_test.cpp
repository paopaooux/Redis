#include <iostream>

#include "common.h"
#include "heap.h"
#include "rand.h"

const int N = 10000;
size_t a[N];

redis::Heap heap;

int main() {
    for (unsigned long& i : a) {
        heap.push(g_rand_int(0, N << 2), &i);
    }
    heap.check();
    std::cout << "heap struct \033[92mpass!\033[0m\n";

    return 0;
}