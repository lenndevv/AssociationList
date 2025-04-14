#include "association_list.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace association_list;

int main() {
    std::ofstream out("test_association_list_output.txt");

    Structure s;

    // basic insert/get/contains
    s.insert("x", 1);
    assert(s.contains("x"));
    assert(s.get("x") == 1);

    // overwrite value test
    s.insert("x", 42);
    assert(s.get("x") == 42);
    out << "Overwrite test passed\n";

    // inserting multiple keys
    s.insert("a", 10);
    s.insert("b", 20);
    s.insert("c", 30);
    assert(s.contains("a") && s.contains("b") && s.contains("c"));

    // remove existing key
    s.remove("a");
    assert(!s.contains("a"));

    // removing non-existent key
    bool removeFail = false;
    try {
        s.remove("nonexistent");
    } catch (const Structure::Error& e) {
        removeFail = true;
        out << "Exception (remove non-existent): " << e.what() << "\n";
    }
    assert(removeFail);

    // get from empty structure
    Structure empty;
    bool emptyFail = false;
    try {
        empty.get("nothing");
    } catch (const Structure::Error& e) {
        emptyFail = true;
        out << "Exception (get from empty): " << e.what() << "\n";
    }
    assert(emptyFail);

    // deep copy and assignment
    Structure s2 = s;
    assert(s == s2);

    Structure s3;
    s3 = s;
    assert(s == s3);

    s3.insert("z", 999);
    assert(s != s3);

    // print test
    out << "Print output:\n";
    s.print();

    // edge case
    Structure many;
    for (int i = 0; i < 1000; ++i) {
        many.insert("key" + std::to_string(i), i);
    }
    assert(many.contains("key999"));
    assert(many.get("key0") == 0);
    out << "Large insert test passed\n";

    out << "All tests completed successfully.\n";
    out.close();

    return 0;
}
