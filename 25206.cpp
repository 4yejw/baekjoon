#include <iostream>
#include <string>
using namespace std;

int main() {
	double Total = 0;//����x���������� ��
	double TimeTotal = 0;//���� ����

	for (int i = 0; i < 20; i++) {
		string name;//���� �̸�
		double time;//����
		double grade;//���� ����

		cin >> name;
		cin >> time;
		string strGrade;
		cin >> strGrade;
		if (strGrade == "A+")
			grade = 4.5;
		else if (strGrade == "A0")
			grade = 4.0;
		else if (strGrade == "B+")
			grade = 3.5;
		else if (strGrade == "B0")
			grade = 3.0;
		else if (strGrade == "C+")
			grade = 2.5;
		else if (strGrade == "C0")
			grade = 2.0;
		else if (strGrade == "D+")
			grade = 1.5;
		else if (strGrade == "D0")
			grade = 1.0;
		else if (strGrade == "F")
			grade = 0.0;
		else //P�� ��� Ȥ�� �ٸ���
			grade = -1.0;

		if (grade >= 0.0)
			TimeTotal += time;//������ ���� ���

		if(grade>=0.0)//����*���������� �� ���
			Total += time * grade;
	}
	cout.precision(7);//�Ҽ��� �ڸ� ����
	cout << Total / TimeTotal << endl;
}