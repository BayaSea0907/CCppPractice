/*
�ۑ�ԍ��@�FL16-Special2
���e�@�@�@�F�������[�v���g���āA�O�����͂����܂œ��͂����l�̐�Βl��\������B
�@�@�@�@�@�@���l���͂Ɛ�Βl�\���̌J�Ԃ�����iwhile���j�́Amain�֐��ōs���B
�@�@�@�@�@�@�������A���͂����l��0�̏ꍇ�ɂ́Abreak�����g���Ė������[�v�𔲂��Ă��悢�B
�t�@�C�����FL16-S2.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//��Βl�Ή��N���X��`
class Abs {
public:
	//��Βl�擾���\�b�h
	int getAbs(int n)
	{
		//��Βl�����̒l�����ׂ�
		if (n < 0)
		{	
			n *= -1;			//��Βl�����̒l�������ꍇ�A�����ɖ߂�
		}			
		return n;				//��Βl�������������ꍇ�A���̂܂ܕԂ�
	}	
};
////////////////////////////////////////////////////////////
int main()
{
	Abs abs;					//��Βl�Ή��I�u�W�F�N�g�錾
	int num;					//���͗p
		
	//�������[�v
	while(1)
	{
		cout << "�����l�̓��́i�I���@0�j>> ";
		cin >> num;

		//���͐��l���O�̏ꍇ�A�����I�Ƀ��[�v�𔲂���
		if (num == 0)
		{
			cout << endl << "���[�v�𔲂��܂�..." << endl;
			break;
		}
		cout << "��Βl=" << abs.getAbs(num) << endl;		//��Βl�\�����\�b�h�̌Ăяo��
	}

	_getch();
	return 0;
}


