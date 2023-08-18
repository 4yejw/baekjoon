/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct nodeRecord {
	int Data;
	struct nodeRecord* Next;
}node;

typedef node* Nptr;

class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	void Push(int Item); //push
	int Pop(); //pop
	int GetFront(); //front
	int GetRear(); //back
	int GetSize(); //size
	bool IsEmpty(); //empty
	void Init();
private:
	Nptr Front;
	Nptr Rear;
	int Count;
};

LinkedQueue::LinkedQueue() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
LinkedQueue::~LinkedQueue() {
	Init();
}
void LinkedQueue::Push(int Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (IsEmpty())
		Front = NewNode;
	else
		Rear->Next = NewNode;
	Rear = NewNode;
	Count++;
}
int LinkedQueue::Pop() {
	if (IsEmpty())
		return -1;
	else {
		Nptr DequeueNode = Front;
		int value = GetFront();
		Front = Front->Next;
		delete DequeueNode;
		Count--;
		return value;
	}
}
int LinkedQueue::GetFront() {
	if (IsEmpty())
		return -1;
	else
		return Front->Data;
}
int LinkedQueue::GetRear() {
	if (IsEmpty())
		return -1;
	else
		return Rear->Data;
}
int LinkedQueue::GetSize() {
	return Count;
}
bool LinkedQueue::IsEmpty() {
	return Count == 0;
}
void LinkedQueue::Init() {
	while (!IsEmpty())
		Pop();
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

int main() {
	int N = 0;
	scanf("%d", &N);
	LinkedQueue Q;

	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		if (S == "push") {
			int value = 0;
			scanf("%d", &value);
			Q.Push(value);
		}
		else if (S == "pop")
			cout << Q.Pop() << endl;
		else if (S == "size")
			cout << Q.GetSize() << endl;
		else if (S == "empty")
			cout << Q.IsEmpty() << endl;
		else if (S == "front")
			cout << Q.GetFront() << endl;
		else if (S == "back")
			cout << Q.GetRear() << endl;
	}
}
*/ 