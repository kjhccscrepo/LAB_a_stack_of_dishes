#pragma once
#include <string>
const int maxSize = 20;
template <typename T>
class FrogStack {
public:
    T *stack_arr;
    T *top;
    T *start;
    int count;

    FrogStack() {
        stack_arr = new T[maxSize];
        top = stack_arr;
        start = stack_arr;
        count = 0;
    }

    bool is_empty() const {
        return (count == 0);
    }

    bool is_full() const {
        return (count == maxSize);
    }

    void clear() {
        stack_arr = new T[maxSize];
        top = stack_arr;
        start = stack_arr;
        count = 0;
    }

    void push(T element) {
        if (!is_full()) {
            *top = element;
            ++top;
            count++;
        }
        else {
            throw std::string("my Stack is full!");
        }
    }

    T pop() {
        if (!this->is_empty())
        {
            --top;
            count--;
            T poppedElement = *top;
            return poppedElement;
        }
        else
        {
            throw std::string("my Stack is empty!");
        }
    }

    T peek() {
        if (!is_empty())
        {
            --top;
            T poppedElement = *top;
            ++top;
            return poppedElement;
        }
        else
        {
            throw std::string("my Stack is empty (can't peek)!");
        }
    }

    int mySize() const {
        if (is_empty()) return 0;
        return count;
    }
};