#include "kv_store.h"
#include <iostream>

int main() {
    KeyValueStore store(3);

    store.set("a", "1");
    store.set("b", "2");
    store.set("c", "3");

    std::cout << *store.get("a") << "\n";

    store.set("d", "4");

    if (!store.get("b")) {
        std::cout << "b evicted\n";
    }

    return 0;
}
