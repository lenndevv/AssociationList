#include "association_list.hpp"
#include <cassert>
#include <fstream>

using namespace association_list;

int main() {
    std::ofstream out("test_association_list_output.txt");

    Structure s;
    s.insert("x", 1);
    assert(s.contains("x"));
    assert(s.get("x") == 1);

    s.insert("y", 2);
    assert(s.contains("y"));

    s.insert("x", 3);
    assert(s.get("x") == 3);

    s.remove("y");
    assert(!s.contains("y"));

    bool exceptionCaught = false;
    try {
        s.get("y");
    } catch (const Structure::Error& e) {
        exceptionCaught = true;
        out << "Exception caught: " << e.what() << "\n";
    }
    assert(exceptionCaught);

    Structure s2 = s;
    assert(s == s2);

    s2.insert("z", 99);
    assert(s != s2);

    s2.print();

    out << "All tests passed successfully.\n";
    out.close();

    return 0;
}
