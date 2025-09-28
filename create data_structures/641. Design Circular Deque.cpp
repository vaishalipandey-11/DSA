#include <bits/stdc++.h>
using namespace std;    

class MyCircularDeque {
public:
    int n;
    int count = 0;
    vector<int> deq;
    int front;
    int rear;
    MyCircularDeque(int k) {
        n = k;
        deq = vector<int>(n, 0);
        front = 0;
        rear = n - 1;
    }
    

    bool insertFront(int value) {
        if (isFull())  return false;
         front = (front - 1 + n) % n;
        deq[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())  return false;
        rear = (rear + 1) % n;
        deq[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())  return false;
        deq[front] = 0;
        front = (front + 1) % n;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        deq[rear] = 0;
        rear = (rear - 1 + n) % n;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return deq[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return deq[rear];
    }

    bool isEmpty() {
        if (count == 0)
            return true;
        return false;
    }

    bool isFull() {
        if (count == n)
            return true;
        return false;
    }
};

