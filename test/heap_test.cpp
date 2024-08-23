#include <iostream>

#include "common.h"
#include "heap.h"
#include "rand.h"

const int N = 10000;
size_t a[N];

redis::Heap heap;

int main() {
    for (int i = 0; i < N; ++i)
        heap.push(g_rand_int(0, N << 2), &a[i]);
    heap.check();
    std::cout << "heap struct \033[92mpass!\033[0m\n";

    // TODO: 和heap关联的变量是正确的嘛?

    return 0;
}