/*
�ۑ�ԍ��@�FL16-8
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁA5��HP��100���Z����ۂɁA���Z�̉񐔂�\������B
�@�@�@�@�@�@���Z�̌J�Ԃ��ɂ́Ado�`while�����g�����̂Ƃ���B
�@�@�@�@�@�@�������A���[�v�J�E���^��0����n�߂���̂Ƃ���B
�t�@�C�����FL16-08.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//�����[�v�J�E���^���P���₷�v�Z�������Ȃ���΂ǂ��Ȃ�ł��傤���H
//A.�������[�v����Bwhile�̏����������Ɛ^�Ȃ̂�

//���J��Ԃ��������Awhile(���[�v�J�E���^ < 0)�@�Ə�����������ǂ��Ȃ�ł��傤���H
//A.���[�v���Ȃ��B0�����̊ԌJ��Ԃ��Ȃ̂ŁB

//L16-7�Ƃ̈Ⴂ���m�F���܂��傤�B
//���܂���

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {	
	int hp = 0;				//HP�i0�j

public:
	//HP���Z���\�b�h
	void addHp(){
		int cnt = 0;		//���[�v�J�E���^

		//���[�v�J�E���^��HP�̉��Z���T��J�Ԃ�
		do
		{
			cout << "HP�����Z�@" << cnt+1 << "���" << endl;
			hp += 100;

			cnt++;			//���[�v�J�E���^���P���₷

		}while(cnt < 5);
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


