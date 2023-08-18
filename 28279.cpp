#include <iostream>
using namespace std;

typedef int element;

typedef struct nodeRecord {
	element Data;
	struct nodeRecord* Next;
	struct nodeRecord* Prev;
}node;

typedef node* Nptr;

class DoubleEndedQueue {
public:
	DoubleEndedQueue();
	~DoubleEndedQueue();
	void AddLast(element Item);//2
	void AddFirst(element Item);//1
	element RemoveLast();//4
	element RemoveFirst();//3
	bool IsEmpty();//6
	element GetFront();//7
	element GetRear();//8
	element GetSize();//5
private:
	Nptr Head;
	Nptr Tail;
	int Count;
};

DoubleEndedQueue::DoubleEndedQueue() {
	Head = NULL;
	Tail = NULL;
	Count = 0;
}
DoubleEndedQueue::~DoubleEndedQueue() {
	while (Count != 0)
		RemoveFirst();
}
void DoubleEndedQueue::AddLast(element Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Prev = NULL;
	}
	else {
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = NewNode;
	}
	Count++;
}
void DoubleEndedQueue::AddFirst(element Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Prev = NULL;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Next = NULL;
	}
	else {
		Head->Prev = NewNode;
		NewNode->Next = Head;
		Head = NewNode;
	}
	Count++;
}
element DoubleEndedQueue::RemoveLast() {
	if (Count == 0)
		return -1;
	else if (Count == 1) {
		int value = Tail->Data;
		Nptr RemoveNode = Tail;
		Tail = NULL;
		Head = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
	else {
		int value = Tail->Data;
		Nptr RemoveNode = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
}
element DoubleEndedQueue::RemoveFirst() {
	if (Count == 0)
		return -1;
	else if (Count == 1) {
		int value = Head->Data;
		Nptr RemoveNode = Head;
		Tail = NULL;
		Head = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
	else {
		int value = Head->Data;
		Nptr RemoveNode = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
}
bool DoubleEndedQueue::IsEmpty() {
	return Count == 0;
}
element DoubleEndedQueue::GetFront() {
	if (Count == 0)
		return -1;
	else
		return Head->Data;
}
element DoubleEndedQueue::GetRear() {
	if (Count == 0)
		return -1;
	else
		return Tail->Data;
}
element DoubleEndedQueue::GetSize() {
	return Count;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N = 0;
	cin >> N;
	DoubleEndedQueue D;
	for (int i = 0; i < N; i++) {
		int option = 0;
		cin >> option;
		if (option == 1) {
			int AddValue = 0;
			cin >> AddValue;
			D.AddFirst(AddValue);
		}
		else if (option == 2) {
			int AddValue = 0;
			cin >> AddValue;
			D.AddLast(AddValue);
		}
		else if (option == 3)
			cout << D.RemoveFirst() << '\n';
		else if (option == 4)
			cout << D.RemoveLast() << '\n';
		else if (option == 5)
			cout << D.GetSize() << '\n';
		else if (option == 6)
			cout << D.IsEmpty() << '\n';
		else if (option == 7)
			cout << D.GetFront() << '\n';
		else if (option == 8)
			cout << D.GetRear() << '\n';
	}
}