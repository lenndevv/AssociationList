#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

namespace association_list {

    class StructureImpl;

    class Structure {
    private:
        StructureImpl* impl;

    public:
        Structure();
        Structure(const Structure& other);
        Structure& operator=(const Structure& other);
        ~Structure();

        void insert(const std::string& key, int value);
        bool contains(const std::string& key) const;
        int get(const std::string& key) const;
        void remove(const std::string& key);
        void print() const;

        class Error : public std::runtime_error {
        public:
            Error(const std::string& message) : std::runtime_error(message) {}
        };
    };
}
