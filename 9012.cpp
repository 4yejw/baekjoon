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
	if (Count == 0) {
		popmiss = 1;
	}
	else {
		Nptr DeleteNode = Top;
		Top->Next->Prev = Top->Prev;
		Top->Prev = Top->Next;
		Top = Top->Next;
		delete DeleteNode;
		Count--;
	}
}
bool StackClass::IsEmpty() {
	return Count == 0;
}

int main() {
	int N = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		StackClass S;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				S.Push(1);
			else 
				S.Pop();
		}

		if (S.IsEmpty() && S.popmiss == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}