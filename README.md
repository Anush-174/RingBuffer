# RingBuffer (Circular Buffer) Implementation in C++

A simple **ring buffer** implementation in C++ using templates and smart pointers.  
Supports both `push_back` / `push_front` and `pop_back` / `pop_front` operations, along with dynamic resizing.

---

## 📂 Project Structure

```
.
├── RingBuffer.hpp   # Class declaration
├── RingBuffer.cpp   # Template implementation
└── mainTest.cpp     # Example usage and tests
```

---

## ⚙️ Features
- Template-based implementation (`RingBuffer<T>`).
- Supports:
  - `push_back` / `pop_back`
  - `push_front` / `pop_front`
- Provides access to:
  - `front()` / `back()`
  - `size()` / `empty()`
- Automatic dynamic resizing when the buffer is full.
- Exception safety (throws `std::out_of_range` and `std::invalid_argument` where appropriate).
- Overloaded `operator<<` for easy printing.

---

## 🔧 Build & Run

Use any modern C++ compiler (C++17 or later). Example with `g++`:

```bash
g++ -std=c++17 -o ringbuffer mainTest.cpp
./ringbuffer
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
