/*
�ۑ�ԍ��@�FL16-12
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�̃��\�b�h�ŁA0�`100�̓��_���T���͂��Ȃ���A
�@�@�@�@�@�@50�ȏ�̒l��50�����̓��_�����ꂼ�ꂢ���������̂������߂�B
�@�@�@�@�@�@0�`100�̓��_�͌��ɃJ�E���g���Ȃ��B
�@�@�@�@�@�@�������Awhile�����g�����̂Ƃ���B
�@�@�@�@�@�@���p�v���p�e�B�́A�N���X��`��0�ɏ���������B
�@�@�@�@�@�@�e���i50������50�ȏ�j�\���́Amain�֐��ōs���B
�t�@�C�����FL16-A12.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test{
	int under50 = 0;	//50�������p(0)
	int over50 = 0;		//50�ȏ���p(0)
public:
	//���_���́E�����胁�\�b�h
	void inpJudgeTen()
	{
		int ten;	//���_���͗p

		//���͂����l���ƂɂT�O�ȏ�̒l�ƂT�O�����̒l�̌������߂鏈�����T��J�Ԃ�
		int cnt = 0;	//���[�v�J�E���^

		while(cnt < 5)
		{
			cout << "���_����́i���_��0�`100�j>> ";
			cin >> ten;

			//�O�ȏ�P�O�O�ȉ��̓��͒l�̏ꍇ�̂݌������߁A���[�v�J�E���^�����Z����
			if(0 <= ten && ten <= 100)
			{
				//50�����̒l�̌������߂�
				if(ten < 50)
				{
					under50 += 1;
				}
				//50�ȏ�̒l�̌������߂�
				else
				{
					over50 += 1;
				}

				cnt++;		//���͂����l���A0�`100�̌��J�E���g
			}
		}
	}

	//50�������擾���\�b�h
	int getUnder50()
	{
		return under50;
	}

	//50�ȏ���擾���\�b�h
	int getOver50()
	{
		return over50;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;				//�e�X�g�I�u�W�F�N�g�錾

	test.inpJudgeTen();		//���_���́E�����胁�\�b�h

	cout << endl << "50�ȏ�=" << test.getOver50()
		<< " 50����=" << test.getUnder50() << endl;

	_getch();
	return 0;
}
