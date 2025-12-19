#include "kv_store.h"

KeyValueStore::KeyValueStore(size_t capacity)
    : cache_(capacity) {}

void KeyValueStore::set(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    cache_.put(key, value);
}

std::optional<std::string> KeyValueStore::get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    return cache_.get(key);
}

void KeyValueStore::remove(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    cache_.erase(key);
}
