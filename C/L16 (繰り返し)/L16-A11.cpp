/*
�ۑ�ԍ��@�FL16-11
���e�@�@�@�F��maru�I�u�W�F�N�g�̃��\�b�h�ŁA�Q�d���[�v���g���ĉ��ɂT��A�c�ɂR�s�́h���h��\������B
�t�@�C�����FL16-A11.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�ۃN���X��`
class Maru {
public:
    //���\�����\�b�h
    void showMaru()
	{
		//�c�i�s�j�����̐���@gyo�F�c�i�s�j�p���[�v�J�E���^
		for(int gyo = 0; gyo < 3; gyo++)
		{
			//�P�s����̉��i��j�����̐���@retu�F���i��j�p���[�v�J�E���^
			for(int retu = 0; retu < 5; retu++)
			{
				cout << "��";
			}
				
			cout << endl;		//�s���i�P�s�̏I���j�̉��s
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Maru maru;			//�ۃI�u�W�F�N�g�錾

	maru.showMaru();	//�ە\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}
