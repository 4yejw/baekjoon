#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	int Pop();
	int GetTop();
	int Size();
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
int StackClass::Size() {
	return Count;
}

int main() {
	bool Nice = 1;
	int N = 0;//학생들의 수
	scanf("%d", &N);
	StackClass S;
	int key = 1;//번호표 순서

	for (int i = 0; i < N; i++) {
		int k = 0;//줄서있는 학생 번호표
		scanf("%d", &k);

		while (S.Size() != 0 && S.GetTop() == key) {
			S.Pop();
			key++;
		}

		if (k == key) //순서대로 이면
			key++;
		else { //순서가 아니면
			if (S.Size() != 0 && S.GetTop() < k)//Sad가 되는 경우 
				Nice = 0;
			S.Push(k);//스택에 push
		}
	}
	if (Nice)
		printf("Nice\n");
	else
		printf("Sad\n");
}