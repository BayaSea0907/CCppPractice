/*
�ۑ�ԍ��@�FL21-5
���e�@�@�@�FL21-4�����������āA�e�X�gtest�I�u�W�F�N�g�̔z��ɂT�����̓��_����͂�����A���v��\������B
�@�@�@�@�@�@���v�v�Z��test�I�u�W�F�N�g�̃��\�b�h�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@���_���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL21-05.cpp
�쐬���@�@�F2015/10/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];			//���_�z��
	int total = 0;		//���v�p�i0�j
public:
	//���_�ݒ胁�\�b�h�@n[]�F���_�z��
	void setTen(int n[])
	{
		//�z��v�f�ɓ��_��ݒ�@cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++)
		{
			ten[cnt] = n[cnt] ;
		}
	}

	//���_���v�v�Z���\�b�h
	void calcTotal()
	{
		//���v�̌v�Z�@cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++)
		{
			total += ten[cnt];
		}
	}

	//���v�擾���\�b�h
	int getTotal()
	{
		return total;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//�e�X�g�I�u�W�F�N�g�錾
	int ten[5];		//���_�z����͗p

	//�z��v�f�ɓ��_����́@cnt�F���[�v�J�E���^
	for (int cnt = 0; cnt < 5; cnt++)
	{
		cout << "���_�����>> ";
		cin >> ten[cnt];
	}

	test.setTen(ten);		//���_�ݒ胁�\�b�h�̌Ăяo��
	test.calcTotal();			//���_���v�v�Z���\�b�h�̌Ăяo��

	cout << "���v�_=" << test.getTotal() << endl;

	_getch();
	return 0;
}


