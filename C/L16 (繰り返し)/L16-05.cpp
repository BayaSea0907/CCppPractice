/*
�ۑ�ԍ��@�FL16-5
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁA5��HP��100���Z������AHP��\������B
�@�@�@�@�@�@�������Afor�����g�����̂Ƃ���B
�@�@�@�@�@�@�������Ahero�I�u�W�F�N�g��hp�́A�N���X��`��0�ŏ��������Ă������̂Ƃ���B
�t�@�C�����FL16-05.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	int hp = 0;			//HP�i0�j
public:
	//HP���Z���\�b�h
	void addHp(){
		//hp�̉��Z���T��J�Ԃ�
		//cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++){
			cout << "HP�����Z" << endl;

			hp += 100;		//100���Z
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


