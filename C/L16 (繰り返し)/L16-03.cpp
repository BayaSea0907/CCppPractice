/*
�ۑ�ԍ��@�FL16-3
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�̃��\�b�h�ŁAwhile�����g���ăq�[���[���hX-men�h���V�s�\������B
�t�@�C�����FL16-03.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������ĉ��s�\�����ꂽ�����m�F���邱�ƁF
//�����[�v�J�E���^��7�ɂȂ�܂ł̏������A7�Ɠ������i�@���[�v�J�E���^�@==�@7�@�j�Ƃ�����ǂ��Ȃ��
//�@���傤���H
//A.�����\������Ȃ��Bcnt��7�̊ԌJ��Ԃ��ƂȂ��Ă��邩��


#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name = "Xmen";		//�q�[���[��("X-men")
public:
	//���O�\�����\�b�h
	void showName(){
		int cnt;        //cnt�F���[�v�J�E���^

		cnt = 0;        //���O�����i���[�v�̊J�n�l�ݒ�j

		//���O�̕\�����V��J�Ԃ�
		while(cnt < 7){
			cout << name << endl;
			
			cnt++;		//�㏈���i���[�v�J�E���g�A�b�v�j
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//�q�[���[�I�u�W�F�N�g�錾

	hero.showName();	//���O�\�����\�b�h�Ăяo��

	_getch();
	return 0;
}


