#include "association_list.hpp"
#include <iostream>

using namespace association_list;
using namespace std;

int main() {
    Structure s;

    try {
        s.insert("Apple", 10);
        s.insert("Banana", 20);
        s.print();

        cout << "Value for 'Apple': " << s.get("Apple") << endl;

        s.remove("Apple");
        s.print();

        // Metamas exception'as
        cout << s.get("Apple") << endl;
    } catch (const Structure::Error& e) {
        cerr << "Caught error: " << e.what() << endl;
    }

    return 0;
}
