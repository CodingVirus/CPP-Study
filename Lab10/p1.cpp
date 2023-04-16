#include <iostream>
using namespace std;

class Element {
private:
    int value;
    Element* next;

public:
    Element(int val) :value(val), next(NULL) {};
    void setNext(Element* e) {
        next = e;
    }
    Element* getNext() {
        return next;
    }
    int getValue() {
        return value;
    }
};

class MyArray {
protected:
    Element* elements;
    int num;
    string type;

public:
    MyArray() :num(0), elements(NULL) {}
    virtual void add(int val) = 0;
    virtual void remove() = 0;
    int size() { return num; }
    void printData();
    ~MyArray() {
        delete[] elements;
    }

};

void MyArray::printData() {
    Element* cur = elements;
    cout << type << ": ";
    while (cur != NULL) {
        cout << cur->getValue() << " -> ";
        cur = cur->getNext();
    }
    cout << endl;
}

class MyStack : public MyArray {
public:
    MyStack() {
        type = "Stack";
    };
    void add(int val);
    void remove();
};

void MyStack::add(int val) {
    cout << "+ Insert into the stack : " << val << endl;
    Element* e = new Element(val);
    e->setNext(elements);
    elements = e;
    num++;
}

void MyStack::remove() {
    if (num > 0) {
        cout << "- Pop from the stack : " << elements->getValue() << endl;
        elements = elements->getNext();
        num--;
    }
}

class MyQueue : public MyArray {
private:
    Element* front;
    Element* back;

public:
    MyQueue() :front(NULL), back(NULL) {
        type = "Queue";
    }
    void add(int val);
    void remove();
};

void MyQueue::add(int val) {
    Element* e = new Element(val);
    if (front == NULL) {
        elements = back = e;
        front = elements;
    }
    else {
        Element* tmp = elements;
        e->setNext(tmp);
        elements = e;
        front = elements;
    }
    num++;
}

void MyQueue::remove() {
    if (num > 0) {
        Element* tmp = front;
        Element* tmp2 = back;
        while (tmp != 0)
        {
            if (tmp->getNext() == tmp2)
            {
                tmp->setNext(NULL);
                //cout << "- Pop from the Queue : " << back->getValue() << endl;
                back = tmp;
                delete tmp2;
                num--;
            }
            tmp = tmp->getNext();
        }
    }
}

int main() {
    MyArray** arrays = new MyArray * [2];

    MyStack stack;
    MyQueue queue;

    arrays[0] = &stack;
    arrays[1] = &queue;

    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        for (int j = 0; j < 2; j++) {
            arrays[j]->add(val);
        }
    }
    cout << "\n######Before remove elements######\n";
    for (int i = 0; i < 2; i++) {
        arrays[i]->printData();
    }
    cout << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            arrays[j]->remove();
        }
    }
    cout << "\n######After remove elements######\n";
    for (int i = 0; i < 2; i++) {
        arrays[i]->printData();
    }

    delete[] arrays;

    return 0;
}