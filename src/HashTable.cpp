#include "HashTable.h"

void HashTable::set(const std::string& key, const std::string& value) {
    table[key] = value;
}

std::string HashTable::get(const std::string& key) {
    if (table.find(key) != table.end()) {
        return table[key];
    }
    return "";
}

void HashTable::del(const std::string& key) {
    table.erase(key);
}