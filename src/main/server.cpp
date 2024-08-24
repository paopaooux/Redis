#include "server.h"

#include "common.h"

int main() {
    redis::Server server{};
    server.join();

    return 0;
}