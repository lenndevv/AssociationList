#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

namespace association_list {

    class Structure {
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

        bool operator==(const Structure& other) const;
        bool operator!=(const Structure& other) const;

        class Error : public std::runtime_error {
        public:
            explicit Error(const std::string& message);
        };

    private:
        class Impl;
        Impl* impl;
    };
}
