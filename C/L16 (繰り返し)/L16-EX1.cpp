/*
�ۑ�ԍ��@�FL16-ExtraSpecial1
���e�@�@�@�F���]reverse�I�u�W�F�N�g�ɐݒ肵�����̐����l�̌��𔽓]���������l��\������B
�@�@�@�@�@�@���]��reverse�I�u�W�F�N�g�̃��\�b�h�ōs���A���]�������l�͂����ǃI�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@�����l���͂Ɣ��]���l�\����main�֐��ōs���B
�t�@�C�����FL16-EX1.cpp
�쐬���@�@�F2015/10/15
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//���]�N���X��`
class Reverse {
	int suti;		//���͐��l�p
	int rev = 0;	//���]��p�i0�j
public:
	//���l�ݒ胁�\�b�h
	void setSuti(int ssuti)
	{
		suti = ssuti;
	}

	//���l���]���\�b�h
	void reverseSuti()
	{
		//���l�𔽓]����
		do
		{
			//���ɔ��]�ݒ肵���l�̌����P���ɂ��炷�i�P����10�{�l�j
			rev *= 10;

			//���]�ݒ肵���l�̈�̈ʂɁA�܂����]���Ă��Ȃ����͒l�̍ŏ�ʌ��̒l��ݒ�
			rev +=(suti % 10);

			//�܂����]���Ă��Ȃ��l�����߂�
			suti /= 10;


		}while(0 < suti);
	}

	//���]���l�擾���\�b�h
	int getRev()
	{
		return rev;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Reverse reverse;	//���]�I�u�W�F�N�g�錾
	int suti;		//���͗p

	cout << "���̐����l�����>> ";
	cin >> suti;
	reverse.setSuti(suti);	//���l���̓��\�b�h�̌Ăяo��

	reverse.reverseSuti();	//���l���]���\�b�h�̌Ăяo��
	cout << "���]�����l=" << reverse.getRev() << endl;

	_getch();
	return 0;
}
