/*
�ۑ�ԍ��@�FL21-ExtraSpecial2
���e�@�@�@�Fregi�I�u�W�F�N�g�ɁA���͂������z���i�[���āA����Ɩ�����\������B
�@�@�@�@�@�@���z������z��̋���Ŋ���Ȃ�����햇�������߂ẮA����ɑΉ����閇���z��Ɋi�[����B
�@�@�@�@�@�@�����5���A������2���ŕ\������B
�@�@�@�@�@�@�\�߁A�N���X��`�ŋ���z�������ŁA�����Ė����z���0�ŏ���������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL21-EX2.cpp
�쐬���@�@�F2015/12/03
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//���W�X�^�[�N���X��`
class Regi {
	int kinsyu[9];		//����p
	int maisu[9];		//�����p
public:
	//����A�����z��ɏ����l�ݒ�
	void initProperty()
	{
		kinsyu[0] = 10000;
		kinsyu[1] = 5000;
		kinsyu[2] = 1000;
		kinsyu[3] = 500;
		kinsyu[4] = 100;
		kinsyu[5] = 50;
		kinsyu[6] = 10;
		kinsyu[7] = 5;
		kinsyu[8] = 1;

		//�����p�z��̏�����
		for (int i = 0; i < 9; i++){
			maisu[i] = 0;
		}
	}
	//���햇���v�Z�@kingaku�F���z
	void calcMaisu(int kingaku)
	{
		//���������߂�
		for (int i = 0; kingaku != 0; i++)
		{
			//���͂������z�������葽���ꍇ�̂ݏ������s��
			//���������z����͂��鎖�������ꍇ�́@if������
			//if (kingaku >= kinsyu[i]) {}

			maisu[i] = kingaku / kinsyu[i];		//���������߂�
			kingaku %= kinsyu[i];			//�c��̋��z�����߂�
		}
	}

	//���햇���\��
	void showMaisu(){
		for (int i = 0; i < 9; i++)
		{
			cout << setw(5) << kinsyu[i] << "�~"
				 << setw(2) << maisu[i] << "��" << endl;
		}
	}
};
////////////////////////////////////////////////////////////


int main()
{
	Regi regi;			//���W�X�^�[�I�u�W�F�N�g�錾
	int kingaku;		//���z���͗p

	regi.initProperty();		//���햇���z�񏉊������\�b�h�̌Ăяo��

	cout << "���z�����>> ";
	cin >> kingaku;

	regi.calcMaisu(kingaku);	//���햇���v�Z���\�b�h�̌Ăяo��
	regi.showMaisu();			//���햇���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}



