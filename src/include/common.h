#pragma once

// C header files
#include <errno.h> // global errno var

// C header files of syscall
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <netinet/ip.h>

// C++ header files
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// panic func
void err(const char* msg) {
    std::perror(msg);
    std::abort();
}

void msg(const char* msg) {
    std::perror(msg);
}

// global constant
const size_t k_max_msg = 4096;

// #define DEBUG

// custom header files
#include "debug.h"
#include "util.h"