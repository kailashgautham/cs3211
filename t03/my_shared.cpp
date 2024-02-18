#include <thread>
#include <memory>
#include <cstdint>

template <typename T>
struct SharedPtr
{
private:
  std::atomic<size_t>* m_count;
    T* m_ptr;

    // TODO: add additional fields

public:
    SharedPtr(T* ptr) : m_count(new atomic<size_t>(1)), m_ptr(ptr)
    {

    }

    SharedPtr(const SharedPtr& other) : m_count(other.m_count), m_ptr(other.m_ptr)
    {
        // TODO: synchronise this
        m_count->fetch_add(1);
    }

    ~SharedPtr()
    {
      size_t old_count = m_count->fetch_sub(1);
      if (old_count == 1) {
        delete m_ptr;
        delete m_count;
      }
    }

    T* get() { return m_ptr; }

    const T* get() const { 
      return m_ptr; 
    };
