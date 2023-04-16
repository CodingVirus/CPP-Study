#include <iostream>
#include <string>

using namespace std;


class Node {
	friend class List;
public:
	Node() {
		data = 0;
		next = NULL;
	};
	Node(int i) {
		data = i;
		next = NULL;
	}
private:
	Node* next;
	int data;
};

class List {
private:
	Node* head;
public:
	List() {
		head = NULL;
	};
	List(Node* insertNode) {
		head = NULL;
		insert(insertNode);
	};
	void insert(Node* insertNode) {
		if (head == NULL) {
			head = insertNode;
		}
		else {
			Node* current = head;
			Node* beforeCurrent = NULL;
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				current = ptr;
			}
			current->next = insertNode;
		}
	}
	void del(int delNum) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
		}
		else {
			Node* current = head;
			Node* beforeCurrent = NULL;
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				beforeCurrent = current;
				current = ptr;
				if (current->data == delNum) {
					if (beforeCurrent == head && current == head) {
						head = current->next;
					}
					else {
						beforeCurrent->next = current->next;
					}
					delete current;
					return;
				}
			}
			cout << delNum << " cannot find in List" << endl;
		}
		return;
	}
	void printList() {
		if (head == NULL) {
			cout << "List is Empty" << endl;
		}
		else {
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				cout << ptr->data << " ";
			}
		}
	}
};


template <typename T>
class myData {
private:
	T x;
public:
	List* linkedList = new List();
	myData() {};
	myData(T index, int row, int col, int count) {
		Node* inputNode = new Node(index);
		linkedList->insert(inputNode);
		linkedList->printList();
		if (count % col == 0) {
			cout << endl;
		}
	}
};


/*
template <>
class myData<string> {
private:

public:
	List* linkedList = new List();
	myData() {};
	myData(string index) {
		Node* inputNode = new Node(index);
		linkedList->insert(inputNode);
		linkedList->printList();
	}
};
*/

int main() {

	//myData<int> myData(5);
	int count = 0;
	int count1 = 0;
	cout << "\nm1 Matrix:" << endl;
	for (int i = 0; i < 12; i++) {
		count++;
		myData<int> myData1(i, 3, 4, count);
	}

	cout << "\n\nm2 Matrix:" << endl;
	for (int i = 0; i < 12; i++) {
		count1++;
		myData<int> myData1(i+3, 4, 3, count1);
	}

	return 0;
}





