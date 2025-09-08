template <typename T>
RingBuffer<T>::RingBuffer(long capacity) 
{
    if (capacity < 0) throw std::invalid_argument("RingBuffer capacity must be non-negative");
    m_capacity = capacity;
    
    if (capacity > 0) {
        m_data = std::make_unique<T[]>(m_capacity);
    }
}

template <typename T>
void RingBuffer<T>::push_back(T val)
{
    if (this->m_size == this->m_capacity) resize();

    m_data[m_tail] = val;
    m_tail = next(m_tail);

    ++this->m_size;
}

template <typename T>
void RingBuffer<T>::pop_front()
{
    if (empty()) throw std::out_of_range("The RingBuffer is empty");

    m_head = next(m_head);
    --this->m_size;
}

template <typename T>
void  RingBuffer<T>::push_front(T val)
{
    if (m_size == m_capacity) resize();

    m_head = prev(m_head);
    m_data[m_head] = val;

    ++this->m_size;
}

template <typename T>
void RingBuffer<T>::pop_back()
{
    if (empty()) throw std::out_of_range("The RingBuffer is empty.");

    m_tail = prev(m_tail);
    --m_size;
}

template <typename T>
T& RingBuffer<T>::front()
{
    return m_data[m_head];
}

template<typename T>
const T& RingBuffer<T>::front() const
{
    return m_data[m_head];
}

template<typename T>
T& RingBuffer<T>::back()
{
    return m_data[prev(m_tail)];
}

template <typename T>
const T& RingBuffer<T>::back() const
{
    return m_data[prev(m_tail)];
}

template <typename T>
std::size_t RingBuffer<T>::size() const
{
    return m_size;
}

template <typename T>
bool RingBuffer<T>::empty() const 
{
    return m_size == 0;
}

template<typename U>
std::ostream& operator<< (std::ostream& os, const RingBuffer<U>& rb)
{
    if (rb.empty()) return os << "RingBuffer is empty";

    os <<  "The elements of the RingBuffer: ";
    
    std::size_t idx{rb.m_head};

    for (std::size_t i{}; i < rb.m_size; ++i) {
        os << rb.m_data[idx]  << " ";
        idx = rb.next(idx);
    }
    os << "\n";

    return os;
}

//utility functions

template <typename T>
std::size_t RingBuffer<T>::prev(std::size_t idx) const
{
    if (m_capacity == 0) throw std::out_of_range("Cannot push to RingBuffer with zero capacity");
    return (idx - 1 + m_capacity) % m_capacity;
}

template <typename T>
std::size_t RingBuffer<T>::next(std::size_t idx) const
{
    if (m_capacity == 0) throw std::out_of_range("Cannot push to RingBuffer with zero capacity");
    return (idx + 1) % m_capacity;
} 

template <typename T>
void RingBuffer<T>::resize() {
    std::size_t newCapacity = m_capacity == 0 ? 1 : m_capacity * 2;

    std::unique_ptr<T[]> newBuffer = std::make_unique<T[]>(newCapacity);

    std::size_t idx{ m_head };
    for (std::size_t i{}; i < m_size; ++i) {
        newBuffer[i] = m_data[idx];
        idx = next(idx);
    }

    std::swap(m_data, newBuffer);
    m_capacity = newCapacity;
    m_head = 0;
    m_tail = m_size;
}