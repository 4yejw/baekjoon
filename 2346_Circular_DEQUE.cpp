#include <iostream> 
using namespace std;
typedef int element;

typedef struct nodeRecord {
	element Data;//num
	element Key;
	struct nodeRecord* Next;
	struct nodeRecord* Prev;
}node;
typedef node* Nptr;


class DoubleEndedQueue {
public:
	DoubleEndedQueue();
	~DoubleEndedQueue();
	void AddLast(element Item,element key);
	void AddFirst(element Item,element key);//Queue 
	element RemoveLast();//Queue
	element RemoveFirst();//stack
	bool IsEmpty();
	element GetFront();
	element GetRear();
	element GetSize();
	element GetFrontKey();
	element GetLastKey();
	void Show();
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
void DoubleEndedQueue::AddLast(element Item,element key) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Key = key;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Next = NewNode;
		NewNode->Prev = NewNode;
	}
	else {
		Head->Prev = NewNode;
		NewNode->Next = Tail->Next;
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = Tail->Next;
	}
	Count++;
}
void DoubleEndedQueue::AddFirst(element Item,element key) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Key = key;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Next = NewNode;
		NewNode->Prev = NewNode;
	}
	else {
		NewNode->Next = Tail->Next;
		Tail->Next = NewNode;
		NewNode->Prev = Head->Prev;
		Head->Prev = NewNode;
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
		Tail->Next = Head;
		Head->Prev = Tail;
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
		Head->Prev = Tail;
		Tail->Next = Head;
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
element DoubleEndedQueue::GetFrontKey() {
	if (Count == 0)
		return -1;
	else
		return Head->Key;
}
element DoubleEndedQueue::GetLastKey() {
	if (Count == 0)
		return -1;
	else
		return Tail->Key;
}
void DoubleEndedQueue::Show() {
	Nptr temp = Head;
	for (int i = 0; i < GetSize(); i++) {
		cout << temp->Data << ' ';
		temp = temp->Next;
	}
}
int main() {
	DoubleEndedQueue D;
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int paper = 0;
		cin >> paper;
		D.AddLast(i, paper);
	}
	for(int i=0;i<N;i++) {
		int range = D.GetFrontKey();
		if (range > 0) {
			cout << D.RemoveFirst() << ' ';
			for (int i = 0; i < range-1; i++) {
				int FrontKey = D.GetFrontKey();
				D.AddLast(D.RemoveFirst(), FrontKey);
			}	
		}
		else { //range < 0
			cout << D.RemoveFirst() << ' ';
			for (int i = 0; i < - range ; i++) {
				int LastKey = D.GetLastKey();
				D.AddFirst(D.RemoveLast(), LastKey);
			}
		}
	}
}
