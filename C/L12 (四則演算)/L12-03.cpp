/*
�ۑ�ԍ��@�FL12-3
���e�@�@�@�F�����l200����͂��āA�����100�𑫂����l��\������B
�@�@�@�@�@�@�������A�l����͂����ϐ������������Ȃ����̂Ƃ���B
�t�@�C�����FL12-03.cpp
�쐬���@�@�F2015/04/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num;			//�����l�i�[�p
	int wa;				//���v�p

	cout << "�����l����́i��@200�j>> ";

	//�����l�̓���
	cin >> num;

	//���v�v�Z�i�ϐ�num�̒l��100�𑫂������v��ϐ�wa�ɑ���j
	wa = num + 100;

	//���v�l���i�[�����ϐ�wa�̒l��\��
	cout << "100�𑫂�������=" << wa << endl;

	//���v�v�Z���ʂ�\���i�ϐ�wa���g��Ȃ��j
	cout << "100�𑫂�������=" << num + 100 << endl;

	_getch();
	return 0;
}
