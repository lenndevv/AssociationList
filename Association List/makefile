CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: demo test

demo: demo.cpp association_list.cpp
	$(CXX) $(CXXFLAGS) demo.cpp association_list.cpp -o demo

test: test.cpp association_list.cpp
	$(CXX) $(CXXFLAGS) test.cpp association_list.cpp -o test
	./test

run: demo
	./demo

clean:
	rm -f demo test test_association_list_output.txt
