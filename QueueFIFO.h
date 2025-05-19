#include <ostream>
#include <cassert>
#include <iostream>

#ifndef AB2CPP_QUEUE_H
#define AB2CPP_QUEUE_H
#endif //AB2CPP_QUEUE_H

template<typename T>

class QueueFIFO {
private:
    T *buffer;
    int capacity;
    int head;
    int tail;
    int count;
public:
    explicit QueueFIFO(int s) {
        assert(s > 0 && "size must be positive");
        try {
            buffer = new T[s];
        } catch (std::bad_alloc &e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            throw std::bad_alloc();
        }
        capacity = s;
        head = 0;
        tail = 0;
        count = 0;

    }


    ~QueueFIFO() {
        delete[] buffer;
    }

    bool isEmpty() {
        return count == 0;
    }


    void push(T x) {
        if (count == capacity) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[tail] = x;
        tail = (tail + 1) % capacity;
        count++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Buffer is empty");
        }
        T element = buffer[head];
        head = (head + 1) % capacity;
        count--;
        return element;
    }

    T peekElement() {
        assert(!isEmpty() && "QueueFIFO empty");
        return buffer[head];
    }

    int getSize() {
        return count;
    }

    void clear() {
        count = 0;
        head = 0;
        tail = 0;
        delete[] buffer;
        try {
            buffer = new T[capacity];
        } catch (std::bad_alloc &e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            throw std::bad_alloc();
        }
    }

    int getHead() const {
        return head;

    }

    int getTail() const {
        return tail;
    }


    class Iterator {
    private:
        const QueueFIFO<T> &queue;
        int remaining;
        int index;

    public:
        explicit Iterator(QueueFIFO<T> &queue) : queue(queue) {

            index = queue.head;
            remaining = queue.count;
        }

        void start() {
            index = queue.head;
            remaining = queue.count;
        }

        void next() {
            if (finish()) {
                throw std::out_of_range("no more elements to iterate");
            }

            index = (index+1) % queue.capacity;
            remaining--;
        }

        bool finish() const {
            return remaining <= 0;
        }

        T value() const {
            return *(queue.buffer+index);
        }
    };

    QueueFIFO<T>::Iterator getIterator() {
        return Iterator(*this);
    }

};

