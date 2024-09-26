#include "deque.h"
#include <stdexcept>

Deque::Deque() {
    capacity = 1000;
    data = new int[capacity];
    front = -1;
    back = 0;
    size = 0;
}

Deque::~Deque() {
    remove_all();
}

void Deque::push_front(int value) {
    if (size == capacity) {
        throw std::overflow_error("Wow, you filled up the whole deque!");
    }
    if (is_empty()) {
        front = back = 0;
    } else {
        front = (front - 1 + capacity) % capacity;
    }
    data[front] = value;
    size++;
}

void Deque::push_back(int value) {
    if (size == capacity) {
        throw std::overflow_error("Wow, you filled up the whole deque!");
    }
    if (is_empty()) {
        front = back = 0;
    } else {
        back = (back + 1) % capacity;
    }
    data[back] = value;
    size++;
}

int Deque::pop_front() {
    if (is_empty()) {
        throw std::underflow_error("Deque has no items in it.");
    }
    int value = data[front];
    if (front == back) {
        front = -1;
        back = 0;
    } else {
        front = (front + 1) % capacity;
    }
    size--;
    return value;
}

int Deque::pop_back() {
    if (is_empty()) {
        throw std::underflow_error("Deque has no items in it.");
    }
    int value = data[back];
    if (front == back) {
        front = -1;
        back = 0;
    } else {
        back = (back - 1 + capacity) % capacity;
    }
    size--;
    return value;
}

int Deque::peak_front() const {
    if (is_empty()) {
        throw std::underflow_error("Deque has no items in it.");
    }
    return data[front];
}

int Deque::peak_back() const {
    if (is_empty()) {
        throw std::underflow_error("Deque has no items in it.");
    }
    return data[back];
}

void Deque::remove_all() {
    delete[] data;
    data = new int[capacity];
    front = -1;
    back = 0;
    size = 0;
}

bool Deque::is_empty() const {
    return size == 0;
}
