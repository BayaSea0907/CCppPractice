/*
�ۑ�ԍ��@�FL16-1
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁA�q�[���[���g�ɃG�[���𑗂�i�\������j�B
�@�@�@�@�@�@�q�[���[�̖��O�͎����̖��O�Ƃ��A�G�[���́Awhile�����g���ăq�[���[��HP��0�ȉ��ɂȂ�܂ŕ\������B
�@�@�@�@�@�@1��G�[�����邲�Ƃ�HP��10������̂Ƃ���B
�t�@�C�����FL16-01.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name = "����";     //�q�[���[��("�����̖��O")
	int hp = 100;                  //HP(100)
public:
	//�G�[�����\�b�h
	void yell(){
		//�G�[���J�Ԃ�
		while(hp > 0){
			cout << name << "�t�@�C�g�I�I" << endl;

			hp -= 10;//HP�����炷

		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//�q�[���[�I�u�W�F�N�g�錾

	hero.yell();	//�G�[�����\�b�h�Ăяo��

	_getch();
	return 0;
}



