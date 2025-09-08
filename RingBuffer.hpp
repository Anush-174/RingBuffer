#pragma once

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>


template <typename T>
class RingBuffer {
public:

    RingBuffer(long capacity);

    void push_back(T val);
    void pop_front();
    
    void push_front(T val);
    void pop_back();

    T& front();
    const T& front( ) const;
    T& back();
    const T& back() const;

    std::size_t size() const;
    bool empty() const;

    template <typename U>
    friend std::ostream& operator<< (std::ostream& os, const RingBuffer<U>& rb);

private:
    void resize();
    std::size_t prev(std::size_t index) const;
    std::size_t next(std::size_t index) const;

private:    
    std::size_t m_size{};
    std::size_t m_capacity{};
    std::size_t m_head{}; // read start
    std::size_t m_tail{}; // write start

    std::unique_ptr<T[]> m_data;
};

#include "RingBuffer.cpp"