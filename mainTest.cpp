#include <iostream>
#include "RingBuffer.hpp"

int main() {
    try {
        RingBuffer<int> rb(3); // capacity = 3
        std::cout << rb << "\n"; // must be empty

        // push_back test
        rb.push_back(10);
        rb.push_back(20);
        rb.push_back(30);
        std::cout << "After push_back 10,20,30:\n" << rb << "\n";

        // resize test
        rb.push_back(40);
        std::cout << "After push_back 40 (resize triggered):\n" << rb << "\n";

        // push_front test
        rb.push_front(5);
        std::cout << "After push_front 5:\n" << rb << "\n";

        // pop_front test
        rb.pop_front();
        std::cout << "After pop_front:\n" << rb << "\n";

        // pop_back test
        rb.pop_back();
        std::cout << "After pop_back:\n" << rb << "\n";

        // front / back test
        std::cout << "Front element: " << rb.front() << "\n";
        std::cout << "Back element: " << rb.back() << "\n";

        // size / empty test
        std::cout << "Size = " << rb.size() << ", Empty? " << std::boolalpha << rb.empty() << "\n";

        rb.pop_back();
        rb.pop_back();
        rb.pop_back();
        std::cout << "Size = " << rb.size() << ", Empty? " << std::boolalpha << rb.empty() << "\n";
        rb.pop_back();

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
    }
}
