/*
�ۑ�ԍ��@�FL16-9
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�̃��\�b�h�ŁA���_���R����͂��Ȃ��瑍���_�����߂�B
�@�@�@�@�@�@�������Afor�����g�����̂Ƃ���B
�@�@�@�@�@�@�����_�́A�v���p�e�B�ŗp�ӂ��Ă����A�N���X��`��0�ɏ��������Ă����B
�@�@�@�@�@�@���͂��链�_��0�ȏ�Ƃ��A���l���ǂ����̔��ʂ͍s��Ȃ����̂Ƃ���B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL16-09.cpp
�쐬���@�@�F2015/10/01BayaSea15CU0210���їT��
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test{
	int total = 0;									//�����_(0)
public:
	//���_���́E�����_�ݒ胁�\�b�h
	void inpAddTen()
	{
		int ten;									//���_���͗p

		//���_���͂Ƒ����_�v�Z���R��J�Ԃ�
		for(int cnt = 0; cnt < 3; cnt++)
		{
			cout << "�_������́i��@100�j>> ";
			cin >> ten;

			total += ten;							//�����_�v�Z
		}
	}

	//�����_�擾���\�b�h
	int getTotal()
	{
		return total;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;			//�e�X�g�I�u�W�F�N�g�錾

	test.inpAddTen();	//���_���͂Ƒ����_�ݒ胁�\�b�h�Ăяo��

	cout << endl << "total=" << test.getTotal() << endl;

	_getch();
	return 0;
}

