//c++에서 가장 많이 사용하는 형태!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
//public: //이거 안쓰면 기본이 private
	//얘는 한번 해주면 다음 꺼 나올 때까지 다 public...........

	char szName[10]; //이름
	short nNo; //번호
	double a;

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();

	Student(){
		nNo = 0;
		szName[0] = 0;
		cout << "기본 생성자" << endl;
	}
	Student(int nNo, char* pName){
		cout << "매개변수 2개 생성자" << endl;
		this->nNo = nNo; 
		strcpy(szName, pName);
	}
	~Student(){
		cout << nNo<<"소멸자" << endl;
	}
};

struct StudentExtend : public Student{ //최대 접근 범위 자바는 안됨 (protected 도 안됨 자기 아들쪽에서만 쓰니까)
	int nKor;
	int nEng;
	int nMat; 

	StudentExtend(){
		cout << "아들생성자" << endl;
	}
};

void Student::SetStudent(int nNo, char* pName){
	//nNo = nNo;
	//이름이 같으면 매개변수로(가까운 놈) 인식해서 매개변수에 매개변수 넣은 것
	//그러니까 쓰레기 값이 나오지
	this->nNo = nNo; //자바와 다르게 -> 인 이유는 컴파일러가 아까 *pThis 대신에 *this로 받아줌
	//내가 *this를 넣으면 오히려 에러가 나니까 쓰기만 해라
	strcpy(szName, pName);
}
void Student::PrintStudent(){
	cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
}

int main(){
	int no;
	char name[20];
	Student student; //기본생성자 호출하는 방법	
	Student *st3 = new Student(3, "강아지");
	StudentExtend se;
	Student st1(5, "송");
	Student *st2 = new Student(); //동적으로 생성하는 법
	cout<<sizeof(student)<<endl;
	delete st2;
	delete st3;
	
	student.PrintStudent();
	st1.PrintStudent();

	cout << "학생 번호 입력 : ";
	cin >> no;

	cout << "학생 이름 입력 : ";
	cin >> name;

	student.SetStudent(no, name);
	student.PrintStudent();

	
	//se.nNo = 10;
	//cout << se.nNo << endl; //student를 바꾼 게 아니라 studentextend를 바꾼 거
	//지금 접근제어자 바꿔서 에러

	/*se.SetStudent(20, "망아지");
	se.PrintStudent(); //함수까지 상속을 받았다*/

	return 0;
}