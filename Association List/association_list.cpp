#include "association_list.hpp"
#include <vector>
#include <utility>

namespace association_list {

    class Structure::Impl {
    public:
        std::vector<std::pair<std::string, int>> data;

        Impl() = default;
        Impl(const Impl& other) : data(other.data) {}

        void insert(const std::string& key, int value) {
            for (auto& pair : data) {
                if (pair.first == key) {
                    pair.second = value;
                    return;
                }
            }
            data.emplace_back(key, value);
        }

        bool contains(const std::string& key) const {
            for (const auto& pair : data) {
                if (pair.first == key) return true;
            }
            return false;
        }

        int get(const std::string& key) const {
            for (const auto& pair : data) {
                if (pair.first == key) return pair.second;
            }
            throw Structure::Error("Key not found: " + key);
        }

        void remove(const std::string& key) {
            for (auto it = data.begin(); it != data.end(); ++it) {
                if (it->first == key) {
                    data.erase(it);
                    return;
                }
            }
            throw Structure::Error("Cannot remove. Key not found: " + key);
        }

        bool equals(const Impl& other) const {
            return data == other.data;
        }
    };

    Structure::Error::Error(const std::string& message)
        : std::runtime_error(message) {}

    Structure::Structure() : impl(new Impl()) {}
    Structure::Structure(const Structure& other)
        : impl(new Impl(*other.impl)) {}

    Structure& Structure::operator=(const Structure& other) {
        if (this != &other) {
            delete impl;
            impl = new Impl(*other.impl);
        }
        return *this;
    }

    Structure::~Structure() {
        delete impl;
    }

    void Structure::insert(const std::string& key, int value) {
        impl->insert(key, value);
    }

    bool Structure::contains(const std::string& key) const {
        return impl->contains(key);
    }

    int Structure::get(const std::string& key) const {
        return impl->get(key);
    }

    void Structure::remove(const std::string& key) {
        impl->remove(key);
    }

    void Structure::print() const {
        std::cout << "Structure contents:\n";
        for (const std::string& key : {"a", "b", "c", "d", "x", "y", "z", "apple", "banana"}) {
            if (contains(key)) {
                std::cout << key << " => " << get(key) << "\n";
            }
        }
    }

    bool Structure::operator==(const Structure& other) const {
        return impl->equals(*other.impl);
    }

    bool Structure::operator!=(const Structure& other) const {
        return !(*this == other);
    }
}
