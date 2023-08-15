//LinkedList Stack
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

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
	while (Count!=0)
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
	if (Count==0) {
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

	//명령의 수 N만큼 반복 
	for (int i = 0; i < N; i++) {
		int Option = 0;
		scanf("%d", &Option);

		int PushValue = 0;

		switch (Option) {

		case 1://정수 X를 스택에 넣는다 1<=X<=100,000 
			scanf("%d", &PushValue);
			S.Push(PushValue);
			break;

		case 2://스택에 정수가 있다면 맨 위의 값을 빼고 출력한다 없다면 -1
			printf("%d\n", S.Pop());
			break;

		case 3://스택에 들어있는 정수의 개수 출력
			printf("%d\n", S.Size());
			break;

		case 4://스택이 비어있으면 1 아니면 0을 출력
			printf("%d\n", S.IsEmpty());
			break;

		case 5://스택에 정수가 있다면 정수를 출력 없다면 -1
			printf("%d\n", S.GetTop());
			break;

		default: //1~5가 아닌것을 입력했을 때
			return 0;
		}
	}
}