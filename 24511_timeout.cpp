//�ð��ʰ�
#include <iostream>
using namespace std;

//====================DEQUE ����=====================
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
	void AddLast(element Item);//���� �������� ��带 �����Ѵ�
	void AddFirst(element Item);//���� ù��°�� ��带 �����Ѵ�
	void Change(int num, int Item);//���� num��° ����� ���� Item���� �����Ѵ�
	element RemoveLast();//���� ������ ��带 �����ϰ� ���� ��ȯ�Ѵ�
	element RemoveFirst();//���� ù��° ��带 �����ϰ� ���� ��ȯ�Ѵ�
	bool IsEmpty();
	element GetFront();//���� ù��° ����� ���� ��ȯ�Ѵ�
	element GetRear();//���� ������ ����� ���� ��ȯ�Ѵ�
	element Retrieve(int num);//num��° ����� Data�� ��ȯ�Ѵ�
	element GetSize();//���� ũ�⸦ ��ȯ�Ѵ�
	void Show();//���� ��ü ����� Data�� ����Ѵ�
private:
	Nptr Head;//ù��° ��带 ����Ű�� ������
	Nptr Tail;//������ ��带 ����Ű�� ������
	int Count;//���� ũ��
};

//==================DEQUE �Լ� �ۼ�======================
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
void DoubleEndedQueue::Change(int num, int Item) {
	if (Count == 0)
		cout << "no value\n";
	else if (num<1 || num>GetSize())
		cout << "out of range\n";
	else {
		Nptr temp = Head;
		for (int i = 1; i < num; i++)
			temp = temp->Next;
		temp->Data = Item;
	}
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
element DoubleEndedQueue::Retrieve(int num) {
	if (Count == 0)
		return -1;
	else if (num<1 || num>GetSize())
		return -1;
	else {
		Nptr temp = Head;
		for (int i = 1; i < num; i++) {
			temp = temp->Next;
		}
		return temp->Data;
	}
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
void DoubleEndedQueue::Show() {
	cout << "DEQUE = [ ";
	Nptr temp = Head;
	while (temp != NULL) {
		cout << temp->Data << ' ';
		temp = temp->Next;
	}
	cout << "]\n";
}
//====================queuestack����=========================
class queuestack {
public:
	queuestack();
	~queuestack();
	void Insert_N();
	void Insert_A();
	void Insert_B();
	void Insert_M();
	void Insert_C();
	int Output(int x0);
	int N;
	DoubleEndedQueue A;
	DoubleEndedQueue B;
	int M;
	DoubleEndedQueue C;
	DoubleEndedQueue K;
};
//====================queuestack�Լ��ۼ�=========================
queuestack::queuestack() {
	Insert_N();
	Insert_A();
	Insert_B();
	Insert_M();
	Insert_C();
}
queuestack::~queuestack() {
}
void queuestack::Insert_N() {
	int n = 0;
	cin >> n;
	N = n;
}
void queuestack::Insert_A() {
	for (int i = 0; i <N; i++) {
		int temp;
		cin >> temp;
		A.AddLast(temp);
	}
}
void queuestack::Insert_B() {
	for (int i = 0; i <N; i++) {
		int temp;
		cin >> temp;
		B.AddLast(temp);
	}
}
void queuestack::Insert_M() {
	int m = 0;
	cin >> m;
	M = m;
}
void queuestack::Insert_C() {
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		C.AddLast(temp);
	}
}
int queuestack::Output(int x0) {
	int& key = x0;
	DoubleEndedQueue temp;
	for (int i = 1; i <= N; i++) {
		temp.AddFirst(B.Retrieve(i));
		if (A.Retrieve(i) == 0) {
			temp.AddLast(key);
			key = temp.RemoveFirst();
			B.Change(i, temp.RemoveFirst());
		}
		else {//A.Retrieve(i) ==1
			temp.AddLast(key);
			key = temp.RemoveLast();
			B.Change(i, temp.RemoveLast());
		}
	}
	return key;
}

//===========main=========
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	queuestack QS;

	for (int i = 0; i < QS.M; i++) {
		cout << QS.Output(QS.C.RemoveFirst()) << ' ';
	}
}