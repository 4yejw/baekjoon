#include <iostream>
#include <string>
using namespace std;

int main() {
	double Total = 0;//학점x과목평점의 합
	double TimeTotal = 0;//학점 총합

	for (int i = 0; i < 20; i++) {
		string name;//과목 이름
		double time;//학점
		double grade;//과목 평점

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
		else //P인 경우 혹은 다른것
			grade = -1.0;

		if (grade >= 0.0)
			TimeTotal += time;//학점의 총합 계산

		if(grade>=0.0)//학점*과목평접의 합 계산
			Total += time * grade;
	}
	cout.precision(7);//소수점 자리 제한
	cout << Total / TimeTotal << endl;
}