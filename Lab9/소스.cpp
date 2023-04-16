#include <iostream>
using namespace std;

class IntElement {
private:
    int value;
    IntElement* next;
public:
    IntElement(int val) :value(val), next(NULL) {}
    int& getValue() {
        return value;
    }
    IntElement* getNext() {
        return next;
    }
    void setNext(IntElement* element) {
        next = element;
    }
};

class IntSet {
private:
    IntElement* mElements;
    int mSize;
public:
    IntSet() :mSize(0), mElements(NULL) {};
    IntSet(int* arr, int n);
    ~IntSet() {}
    bool find(int val);
    int size();
    IntElement* getElements();
    
    void insert(int val);
    void remove(int val);
    void clear();
    friend ostream& operator<<(ostream&, const IntSet&);
    IntSet& operator++();
    IntSet& operator--(int);
    IntSet operator+(const IntSet& p1) const;
    IntSet operator-(const IntSet& p1) const;
};

IntSet IntSet::operator+(const IntSet& p) const {
    IntElement* cur = mElements;
    while (cur != NULL) {
        cur->getValue() + p.mElements->getValue();
        cur = cur->getNext();
    }
    return *this;
}

IntSet IntSet::operator-(const IntSet& p) const {
    IntElement* cur = mElements;
    while (cur!= NULL) {
        cur->getValue() - p.mElements->getValue();
        cur = cur->getNext();
    }
    return *this;
}

IntSet& IntSet::operator++() {
    IntElement* cur = mElements;
    while (cur != NULL) {
        ++cur->getValue();
        cur = cur->getNext();
    }
    return *this;
}

IntSet& IntSet::operator--(int) {
    IntElement* cur = mElements;
    while (cur != NULL) {
        cur->getValue()--;
        cur = cur->getNext();
    }
    return *this;
}

int IntSet::size() {
    return mSize;
}

void IntSet::remove(int val) {

}

void IntSet::clear() {

}

IntSet::IntSet(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        insert(num);
    }
}

bool IntSet::find(int val) {
    IntElement* cur = mElements;
    while (cur != NULL) {
        if (cur->getValue() == val) {
            break;
            return false;
        }
    }
}

ostream& operator<<(ostream& os, const IntSet& set) {
    IntElement* cur = set.mElements;
    while (cur != NULL) {
        cout << cur->getValue() << " ";
        cur = cur->getNext();
    }
    cout << endl;
    return os;
}

void IntSet::insert(int val) {
    IntElement* newElement = new IntElement(val);
    IntElement* cur = mElements;
    IntElement* pre = mElements;

    

    while (cur != NULL && cur->getValue() < val) {
        
        if (cur != mElements) {
            pre = pre->getNext();
        }
        cur = cur->getNext();
    }

    if (cur == mElements) {
        newElement->setNext(mElements);
        mElements = newElement;
    }
    else {
        if (cur == NULL) {
            pre->setNext(newElement);
        }
        else {
            pre->setNext(newElement);
            newElement->setNext(cur);
        }
    }
    

    mSize++;
    return;
}


int main()
{
    int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr2[5] = {5, 3, 1, 2, 5};
    int arr3[3] = {1,2,3};
    int arr4[3] = {3,2,1};


    IntSet set1(arr1, 10);
    IntSet set2(arr2, 5);
    IntSet set3(arr3, 3);
    IntSet set4(arr4, 3);

    set1.insert(10);
    set1.insert(11);
    set1.insert(1);


    cout << "elements in set : " << set1 << endl;
    cout << "elements in set2 : " << set2 << endl;
    cout << "Set3: " << set3 << endl;
    cout << "Set3: " << set4 << endl;

    ++set1;
    ++set2;
    cout << "elements in set : " << set1 << endl;
    cout << "elements in set2 : " << set2 << endl;

    set1--;
    set2--;
    cout << "elements in set : " << set1 << endl;
    cout << "elements in set2 : " << set2 << endl;

    cout << "set1: " << set1 + set2 << endl;
    cout << "size : " << set1.size() << endl;

    cout << "set1: " << set1 - set2 << endl;
    cout << "size : " << set1.size() << endl;

    cout << "size : " << set1.size() << endl;

    cout << "elements in set : " << set1 << endl;
    cout << "elements in set2 : " << set2 << endl;
    set1.insert(1);
    set1.insert(2);

    cout << "size : " << set1.size() << endl;

    cout << "elements in set : " << set1 << endl;
    cout << "elements in set2 : " << set2 << endl;

    /*
    if (set3 == set4)
        cout << "set3 and set4 are same" << endl;
    else
    {
        cout << "set3 and set4 are not same" << endl;
    }

    cout << "elements in set : " << set1 * set2 << endl;
    */
}