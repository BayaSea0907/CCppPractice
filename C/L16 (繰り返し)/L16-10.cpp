/*
�ۑ�ԍ��@�FL16-10
���e�@�@�@�FL16-9�����������āAwhile�����g���đ����_�����߂�B
�t�@�C�����FL16-10.cpp
�쐬���@�@�F2015/10/01BayaSea15CU0210���їT��
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test{
	int total = 0;//�����_(0)
public:
	//���_���́E�����_�ݒ胁�\�b�h
	void inpAddTen()
	{
		int ten;		//���_���͗p

		//���_���͂Ƒ����_�v�Z���R��J�Ԃ�
		int cnt = 0; 	//���[�v�J�E���^

		while(cnt < 3)
		{
			cout << "�_������́i��@100�j>> ";
			cin >> ten;

			total += ten;	//�����_�v�Z
			
			cnt++;			//���[�v�J�E���^�ɉ��Z
		}
	}

	//�����_�擾���\�b�h
	int getTotal()
	{
		return total;		//�����_��Ԃ�
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//�e�X�g�I�u�W�F�N�g�錾

	test.inpAddTen();	//���_���͂Ƒ����_�ݒ胁�\�b�h�Ăяo��

	cout << "total=" << test.getTotal() << endl;

	_getch();
	return 0;
}

