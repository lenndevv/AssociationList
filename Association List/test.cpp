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

    s.remove("x");
    assert(!s.contains("x"));

    bool exceptionCaught = false;
    try {
        s.get("x");
    } catch (const Structure::Error& e) {
        exceptionCaught = true;
        out << "Exception caught: " << e.what() << "\n";
    }
    assert(exceptionCaught);

    out << "All tests passed successfully.\n";
    out.close();

    return 0;
}
