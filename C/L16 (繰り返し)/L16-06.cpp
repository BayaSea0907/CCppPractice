/*
�ۑ�ԍ��@�FL16-6
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁA5��HP��100���Z����ۂɁA���Z�̉񐔂�\������B
�@�@�@�@�@�@���Z�̌J�Ԃ��ɂ́Afor�����g�����̂Ƃ���B
�@�@�@�@�@�@�������A���[�v�J�E���^��0����n�߂�B
�t�@�C�����FL16-06.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//�����[�v�J�E���^��4�ɂȂ�܂Łi4�����j�A�J��Ԃ��Ƃǂ��Ȃ�ł��傤���H
//A.�S�񕪏��������

//�����[�v�J�E���^��4�ɂȂ����Ƃ����i4�ȉ��j�A�J��Ԃ��Ƃǂ��Ȃ�ł��傤���H
//A.�T�񕪏��������

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	int hp = 0;    		//HP�i0�j
public:
	//HP���Z���\�b�h
	void addHp(){
		//���[�v�J�E���^��HP�̉��Z���T��J�Ԃ�
		//cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++){
			cout << "HP�����Z�@" << cnt+1 << "���" << endl;
			hp += 100;
		}
	}

	//HP�擾���\�b�h
	int getHp(){ return hp; }
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//�q�[���[�I�u�W�F�N�g�錾

	hero.addHp();		//HP���Z���\�b�h�̌Ăяo��

	cout << endl << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}



