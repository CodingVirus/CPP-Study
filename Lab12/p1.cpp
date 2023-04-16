#include <iostream>
#include <time.h>
using namespace std;

class Student {
public:
    int id;
    string name;
    double subject;

    Student(int sId, string sName, double s) :id(sId), name(sName), subject(s) {}

    void operator=(Student val) {
        id = val.id;
        name = val.name;
        subject = val.subject;
    }
    ~Student() {
    };

};
ostream& operator<<(ostream& os, const Student& val)
{
    os << val.name << " " << val.id << " " << val.subject << endl;
    return os;
}

class MySort {
public:
    virtual bool operator()(double v1, double v2)const = 0;
};

class NonIncreasing : public MySort {
public:
    bool operator()(double s1, double s2)const {
        if (s1 < s2) return true;
        else return false;
    }
};

class NonDecreasing : public MySort {
public:
    bool operator()(double s1, double s2)const {
        if (s1 > s2) return true;
        else return false;
    }
};

template <typename T>
class Vector {
    class Node {
    private:
        T value;
        Node* next;

    public:
        Node(T val, Node* next) :value(val), next(next) {}
        friend class Vector;
    };

private:
    int mLen;
    Node* mNodes;

    MySort* sortingMethods[2];

public:
    Vector() :mLen(0), mNodes(NULL) {
        sortingMethods[0] = new NonIncreasing();
        sortingMethods[1] = new NonDecreasing();
    }

    void add(T val) {
        Node* v = new Node(val, NULL);
        if (mNodes == NULL) {
            mNodes = v;
        }
        else {
            Node* cur = mNodes;
            while (cur->next != NULL) cur = cur->next;
            cur->next = v;
        }
        mLen++;
    }

    void remove(int i) {
        Node* cur = mNodes;
        for (int j = 0; j < i - 1; j++)
            cur = cur->next;
        //cout << cur ->value << endl;
        Node* nex = cur->next;
        cur->next = nex->next;
        //cout << nex -> value << endl;
        mLen--;
        delete nex;

    }

    int size() const { return mLen; }

    void printVector() const {
        if (mLen > 0) {
            Node* node = mNodes;
            while (node != NULL) {
                cout << node->value.name << ", " <<
                    node->value.id << ", " <<
                    node->value.subject << endl;
                node = node->next;
            }
            cout << endl;
        }
    }

    ~Vector() {
        if (mLen > 0) {
            while (mNodes != NULL) {
                Node* v = mNodes;
                mNodes = mNodes->next;
                delete v;
            }
        }
    }

    T& operator[](int i) {
        return get(i)->value;
    }

    Node* get(int i) {
        Node* cur = mNodes;
        for (int j = 0; j < i; j++) {
            cur = cur->next;
        }
        //cur->next = cur->next->next;
        return cur;
    }

    void set(int i, T value) {
        Node* cur = mNodes;
        for (int j = 0; j < i; j++) {
            cur = cur->next;
        }
        cout << cur->value << endl;
        cur->value = value;;
    }

    void swap(int i, int j) {
        Node* cur1 = mNodes;
        Node* cur2 = mNodes;
        for (int k = 0; k < i; k++) {
            cur1 = cur1->next;
        }
        for (int k = 0; k < j; k++) {
            cur2 = cur2->next;
        }
        T tmp = cur1->value;
        cur1->value = cur2->value;
        cur2->value = tmp;
    }

    void sort(int op) {
        for (int i = 0; i < mLen; i++) {
            for (int j = 0; j < mLen - (i + 1); j++)
            {
                if ((*sortingMethods[op - 1])(get(j)->value.subject, get(j + 1)->value.subject)) {
                    swap(j, j + 1);
                }
            }
        }
    }
};


int main() {

    Vector<Student> vector;


    int baseID = 20200000;
    string names[7] = { "Albert", "John", "Jenny", "Henry", "Lucy", "Peter", "Maria" };
    srand(time(NULL));
    Student* Albert = new Student(baseID, names[0], rand() % (100 - 70 + 1) + 70);
    Student* John = new Student(baseID + 1, names[1], rand() % (100 - 70 + 1) + 70);
    Student* Jenny = new Student(baseID + 2, names[2], rand() % (100 - 70 + 1) + 70);
    Student* Henry = new Student(baseID + 3, names[3], rand() % (100 - 70 + 1) + 70);
    Student* Lucy = new Student(baseID + 4, names[4], rand() % (100 - 70 + 1) + 70);
    Student* Peter = new Student(baseID + 5, names[5], 100);
    Student* Maria = new Student(baseID + 6, names[6], rand() % (100 - 70 + 1) + 70);
    vector.add(*Albert);
    vector.add(*John);
    vector.add(*Jenny);
    vector.add(*Henry);
    vector.add(*Lucy);
    vector.add(*Peter);
    vector.add(*Maria);

    // 객체들을 출력
    vector.printVector();
    // 3번 인덱스의 객체를 출력
    cout << vector[3] << endl;

    //1번과 2번 인덱스 교환
    vector.swap(1, 2);
    vector.remove(5);

    vector.printVector();

    Student* piano = new Student(201900001, "piano", 100);
    // 1번 Index의 학생을 새로운 학생인 piano 대체함.
    vector.set(0, *piano);

    vector.printVector();


    int op;
    cout << "Here are sorting options [1: nonincreasing, 2: nondecreasing]" << endl;
    cin >> op;

    vector.sort(op);

    vector.printVector();
    cout << vector[0].name << endl;

}