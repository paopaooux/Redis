#pragma once

// C header files
#include <errno.h> // global errno var

// C header files of syscall
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>

// C header files of net syscall
#include <arpa/inet.h>
#include <sys/socket.h>

#include <netinet/ip.h>

// C++ header files
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>

// custom header files
#include "panic.h"
#include "util.h"

const size_t k_max_msg = 4096;