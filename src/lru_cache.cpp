#include "lru_cache.h"

LRUCache::LRUCache(size_t capacity) : capacity_(capacity) {}

void LRUCache::promote(const std::string& key) {
    auto& entry = entries_.at(key);
    lru_.erase(entry.second);
    lru_.push_front(key);
    entry.second = lru_.begin();
}

void LRUCache::put(const std::string& key, const std::string& value) {
    if (entries_.count(key)) {
        entries_[key].first = value;
        promote(key);
        return;
    }

    if (entries_.size() >= capacity_) {
        const auto& evicted = lru_.back();
        entries_.erase(evicted);
        lru_.pop_back();
    }

    lru_.push_front(key);
    entries_[key] = {value, lru_.begin()};
}

std::optional<std::string> LRUCache::get(const std::string& key) {
    if (!entries_.count(key)) {
        return std::nullopt;
    }
    promote(key);
    return entries_[key].first;
}

void LRUCache::erase(const std::string& key) {
    if (!entries_.count(key)) return;
    lru_.erase(entries_[key].second);
    entries_.erase(key);
}
