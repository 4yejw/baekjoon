#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct nodeRecord {
	int Data;
	struct nodeRecord* Next;
	struct nodeRecord* Prev;
}Node;
typedef Node* Nptr;

class StackClass {
public:
	StackClass();
	~StackClass();
	void Push(int Item);
	int Pop(); 
	int GetTop();
private:
	Nptr Top;
	int Count;
};

StackClass::StackClass() {
	Top = NULL;
	Count = 0;
}
StackClass::~StackClass() {
	while (Count != 0)
		Pop();
}
void StackClass::Push(int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	if (Count == 0) {
		NewNode->Next = NewNode;
		NewNode->Prev = NewNode;
	}
	else {
		NewNode->Next = Top;
		NewNode->Prev = Top->Prev;
		Top->Prev->Next = NewNode;
		Top->Prev = NewNode;
	}
	Top = NewNode;
	Count++;
}
int StackClass::Pop() {
	if (Count == 0) {
		return -1;
	}
	else {
		Nptr DeleteNode = Top;
		int DeleteValue = DeleteNode->Data;
		Top->Next->Prev = Top->Prev;
		Top->Prev = Top->Next;
		Top = Top->Next;
		delete DeleteNode;
		Count--;
		return DeleteValue;
	}
}
int StackClass::GetTop() {
	if (Count == 0)
		return -1;
	else
		return Top->Data;
}

int main() {
	int K = 0;
	scanf("%d", &K);
	StackClass S;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		int N = 0;
		scanf("%d", &N);
		if (N == 0) {
			sum -= S.GetTop();
			S.Pop();
		}
		else {
			sum += N;
			S.Push(N);
		}
	}
	printf("%d", sum);
}