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
	void Push(int Item);
	void Pop();
	bool IsEmpty();
	int GetTop();
	bool popmiss;
private:
	Nptr Top;
	int Count;
};

StackClass::StackClass() {
	Top = NULL;
	Count = 0;
	popmiss = 0;
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
void StackClass::Pop() {
		Nptr DeleteNode = Top;
		Top->Next->Prev = Top->Prev;
		Top->Prev = Top->Next;
		Top = Top->Next;
		delete DeleteNode;
		Count--;
}
bool StackClass::IsEmpty() {
	return Count == 0;
}
int StackClass :: GetTop() {
	if (Count == 0)
		return 0;
	else
		return Top->Data;
}

int main() {
	string S;
	while(true) {
		getline(cin, S);
		StackClass Stack;
		if (S == ".")
			break;
		for (long unsigned int i = 0; i < S.length(); i++) {
			if (S[i] == '[')
				Stack.Push(1);
			else if (S[i] == '(')
				Stack.Push(2);
			else if (S[i] == ']') {
				if (Stack.GetTop() == 1)
					Stack.Pop();
				else
					Stack.popmiss = 1;
			}
			else if (S[i] == ')') {
				if (Stack.GetTop() == 2)
					Stack.Pop();
				else
					Stack.popmiss = 1;
			}
		}
		if (Stack.IsEmpty() && Stack.popmiss == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
}