/*
�ۑ�ԍ��@�FL16-7
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁA5��HP��100���Z����ۂɁA���Z�̉񐔂�\������B
�@�@�@�@�@�@���Z�̌J�Ԃ��ɂ́Awhile�����g�����̂Ƃ���B
�@�@�@�@�@�@�������A���[�v�J�E���^��0����n�߂�B
�t�@�C�����FL16-07.cpp
�쐬���@�@�F2010/10/01
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//�����[�v�J�E���^���P���₷�v�Z�������Ȃ���΂ǂ��Ȃ�ł��傤���H
//A.�i���ƌJ��Ԃ�

//���J��Ԃ��������Awhile(���[�v�J�E���^ < 0)�@�Ə�����������ǂ��Ȃ�ł��傤���H
//A. hp=0�ƕ\�������B�J��Ԃ��������s���Ȃ�����

#include <conio.h>
#include <iostream>
using namespace std;
//�q�[���[�N���X��`
class Hero {
	int hp = 0;			//HP�i0�j
public:
	//HP���Z���\�b�h
	void addHp(){
		int cnt;		//���[�v�J�E���^

		//���[�v�J�E���^��HP�̉��Z���T��J�Ԃ�
		cnt = 0;

		while(cnt < 5){
			cout << "HP�����Z�@" << cnt+1 << "���" << endl;
			hp += 100;

			cnt++;		 //���[�v�J�E���^���P���₷

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

	cout << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}


