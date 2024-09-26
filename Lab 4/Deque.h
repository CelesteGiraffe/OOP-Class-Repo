#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int* data;
    int front;
    int back;
    int size;
    int capacity;

public:
    Deque();

    ~Deque();

    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int peak_front() const;
    int peak_back() const;
    void remove_all();

    bool is_empty() const;
};

#endif
