#pragma once

#include <unordered_map>
#include <list>
#include <string>
#include <optional>

class LRUCache {
public:
    explicit LRUCache(size_t capacity);

    void put(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key);
    void erase(const std::string& key);

private:
    using ListIt = std::list<std::string>::iterator;

    size_t capacity_;
    std::list<std::string> lru_;
    std::unordered_map<
        std::string,
        std::pair<std::string, ListIt>
    > entries_;

    void promote(const std::string& key);
};
