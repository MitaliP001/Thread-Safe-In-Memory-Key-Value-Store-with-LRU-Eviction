#pragma once

#include "lru_cache.h"
#include <mutex>

class KeyValueStore {
public:
    explicit KeyValueStore(size_t capacity);

    void set(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key);
    void remove(const std::string& key);

private:
    LRUCache cache_;
    std::mutex mutex_;
};
