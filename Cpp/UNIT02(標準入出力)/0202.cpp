//���O�Q�|�O�Q		BayaSea
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int num;		//��
public:
	//������
	void inp() { 
		cout << "������� >>";
		cin >> num;
	}

	//���擾
	int getNum() { return num; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop shop; 		//�I�u�W�F�N�g�錾

	shop.inp();									//�����̓��\�b�h�Ăяo��
	cout << "��=" << shop.getNum() << endl;	//���擾���\�b�h�Ăяo��

	system("pause");
	return 0;
}
