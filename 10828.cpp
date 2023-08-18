#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

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
	void Push(int Item); //1
	int Pop(); //2
	int GetTop(); //5
	bool IsEmpty(); //4
	int Size(); //3
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
bool StackClass::IsEmpty() {
	return Count == 0;
}
int StackClass::Size() {
	return Count;
}

int main() {
	int N = 0;
	scanf("%d", &N);
	StackClass S;

	for (int i = 0; i < N; i++) {
		string Option;
		cin >> Option;

		int PushValue = 0;
		if (Option == "push") {
			scanf("%d", &PushValue);
			S.Push(PushValue);
		}
		else if (Option == "pop")
			printf("%d\n", S.Pop());
		else if (Option == "size")
			printf("%d\n", S.Size());
		else if(Option == "empty")
			printf("%d\n", S.IsEmpty());
		else if(Option =="top")
			printf("%d\n", S.GetTop());
	}
}
