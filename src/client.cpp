#include "client.h"

#include "common.h"

int main() {
    redis::Client client{};
    std::vector<std::string> cmds1 = {"set", "k", "v"};
    client.send(cmds1);
    client.receive();
    std::vector<std::string> cmds2 = {"get", "k"};
    client.send(cmds2);
    client.receive();
    return 0;
}