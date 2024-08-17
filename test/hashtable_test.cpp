#include "common.h"
#include "interpret.h"

int main() {
    redis::interpreter::set("key1", "val1");
    redis::interpreter::set("key2", "val2");

    auto get1 = redis::interpreter::get("key1");
    if (get1.has_value())
        std::cout << "get 1 -> " << get1.value() << "\n";
    else
        std::cout << "get 1 get none\n";

    auto get3 = redis::interpreter::get("key3");
    if (get3.has_value())
        std::cout << "get 3 -> " << get3.value() << "\n";
    else
        std::cout << "get 3 get none\n";

    redis::interpreter::del("key2");
    auto get2 = redis::interpreter::get("key2");
    if (get2.has_value())
        std::cout << "get 2 -> " << get2.value() << "\n";
    else
        std::cout << "get 2 get none\n";

    redis::interpreter::set("key1", "val2");
    get1 = redis::interpreter::get("key1");
    if (get1.has_value())
        std::cout << "修改后 get 1 -> " << get1.value() << "\n";
    else
        std::cout << "修改后 get 1 get none\n";

    redis::interpreter::set("k1", "v1");
    redis::interpreter::set("k1", "v1_");
    redis::interpreter::set("k2", "v2");
    redis::interpreter::set("k3", "v3");

    redis::Bytes buf;
    buf.appendNumber(redis::interpreter::m_map.size(), 4);
    redis::interpreter::scan(buf);

    auto num = buf.getNumber<size_t>(4);
    for (int i = 0; i < num; ++i) {
        (void)buf.getNumber<char>(1);
        auto len = buf.getNumber<std::size_t>(4);
        auto s = buf.getStringView(len);
        std::cout << "key: \"" << s << "\"\n";
    }

    return 0;
}