# RingBuffer (Circular Buffer) Implementation in C++

A simple **ring buffer** implementation in C++ using templates and smart pointers.  
Supports both `push_back` / `push_front` and `pop_back` / `pop_front` operations, along with dynamic resizing.

---


## ⚙️ Features
- Template-based implementation (`RingBuffer<T>`).
- Unlike traditional fixed-size ring buffers, it can grow to accommodate more elements.
- Automatic dynamic resizing when the buffer is full.
- Exception safety (throws `std::out_of_range` and `std::invalid_argument` where appropriate).
- Overloaded `operator<<` for easy printing.
- Operations and their time complexity:
  ---
 * push_back(T val): Add element to the end, O(1) amortized (O(n) when resizing)
 * push_front(T val): Add element to the front, O(1) amortized (O(n) when resizing)
 * pop_back(): Remove element from the end, O(1)
 * pop_front(): Remove element from the front, O(1)
 * front(): Access first element, O(1)
 * back(): Access last element, O(1)
 * size(): Return number of elements, O(1)
 * empty(): Check if buffer is empty, O(1)


---

## 🔧 Build & Run

Use any modern C++ compiler (C++17 or later). Example with `g++`:

```bash
g++ -std=c++17 -o ringbuffer mainTest.cpp
./ringbuffer
```
---

## 📂 Project Structure

```
.
├── RingBuffer.hpp   # Class declaration
├── RingBuffer.cpp   # Template implementation
└── mainTest.cpp     # Example usage and tests
```

---

## 📚 Notes
- The project separates **declaration (`.hpp`)** and **implementation (`.cpp`)**.  
- Since this is a template class, both files are included via `#include "RingBuffer.cpp"` at the end of the header.
- To use `RingBuffer` in your own project:
  ```cpp
  #include "RingBuffer.hpp"

  RingBuffer<int> rb(5);
  rb.push_back(42);
  std::cout << rb.front() << std::endl;
  ```

---

## 🧑‍💻 Author
Implemented as a learning exercise for data structures in modern C++.
