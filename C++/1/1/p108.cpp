#include<iostream>
using namespace std;
int main()
{
	int dan;

	while(1){
		cout << "���� ������ �̿��� ������ ��� ���α׷��Դϴ�." << endl;
		cout << "0�� �Է� �ϸ� ���� �մϴ�." << endl;
		cout << "����� ���� �Է� �ϼ��� : ";

		cin >> dan;

		if (dan == 0){
			cout << "������ ����� ���� �մϴ�" << endl;
			break;
		}

		if (dan<0 || dan>19)
		{
			cout << "1�ܺ���19�ܱ����� �ٽ� �Է����ּ���"<<endl;
			continue;
		}

		cout << dan << "�� ��� �մϴ�." << endl;

		for (int i = 1; i <= 9; i++){
			cout << "         " << dan << "* " << i << "= "
			<< (dan*i) << endl;
		}
	}
	return 0;
}