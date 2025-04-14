#include "association_list.hpp"
#include <iostream>

using namespace association_list;

int main() {
    Structure s;

    try {
        s.insert("apple", 10);
        s.insert("banana", 20);
        s.print();

        std::cout << "Value for 'apple': " << s.get("apple") << std::endl;

        s.remove("apple");

        Structure s2 = s;
        s2.insert("banana", 20);

        // lambda expression
        std::cout << "Structures equal? " << (s == s2 ? "Yes" : "No") << std::endl;

        // bandom pafetchinti istrinta rakta
        std::cout << s.get("apple") << std::endl;
    } catch (const Structure::Error& e) {
        std::cerr << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}
