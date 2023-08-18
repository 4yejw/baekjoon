//요세푸스 문제 
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
	while (Count != 0)
		Pop();
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
void LinkedQueue::Push(int Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Count == 0)
		Front = NewNode;
	else
		Rear->Next = NewNode;
	Rear = NewNode;
	Count++;
}
int LinkedQueue::Pop() {
	if (Count == 0)
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
	if (Count == 0)
		return -1;
	else
		return Front->Data;
}
int LinkedQueue::GetRear() {
	if (Count == 0)
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

int main() {
	int N = 0, K = 0;
	cin >> N >> K;
	LinkedQueue Q;
	for (int i = 1; i <= N; i++)
		Q.Push(i);

	int i = 1;
	cout << '<';
	while (Q.GetSize()!=0) {
		if (Q.GetSize() == 1)
			cout << Q.Pop()<<'>';
		else if (i++ % K == 0)
			cout << Q.Pop() << ", ";
		else
			Q.Push(Q.Pop());
	}			                                    
}