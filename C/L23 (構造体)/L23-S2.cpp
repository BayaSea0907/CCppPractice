/*
�ۑ�ԍ��@�FL23-Special2
�� �e�@�@�@�F��ero�I�u�W�F�N�g�Ƀq�[���[�����i�[���āA�q�[���[���ƊO���ϐ��Ő錾�����A�C�e���\��
�@�@�@�@�@�@�@�̂̃����o��\������B
�@�@�@�@�@�@�@�q�[���[���i�����̖��O�j�́A�N���X��`�ŏ���������B
�@�@�@�@�@�@�@�A�C�e���\���̂́A�O���ϐ��Ƃ��Đ錾���āA�錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�@�\���́A�I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-S2.cpp
�쐬���@�@�F2015/11/21
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�A�C�e���\���̒�`�E�錾�Ɠ����̏�����
struct Item {
	string name;	//�A�C�e����
	int power;		//�\��
} ITM = {			//�O���[�o���\���̕ϐ��̐錾�Ə�����
	"mant",
	50
};
////////////////////////////////////////////////////////////////
//�q�[���[�N���X��`
class Hero {
	string name = "BERG";	//�q�[���[��
public:
	//�\��
	void show(){
		cout << name << endl << ITM.name << " " << ITM.power << endl;
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();	//�\�����\�b�h�Ăяo��

	_getch();
	return 0;
}



