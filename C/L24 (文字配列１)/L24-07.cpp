/*
�ۑ�ԍ��@�FL24-7
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[��"BERG"��char�^�����z��i�v�f���P�O�j�Ɋi�[���āA������
�@�@�@�@�@�@�P�����ƕ����z��̓Y���ʒu����͂���B
�@�@�@�@�@�@�����āA���͂����P�����Ɠ��͂����Y���ʒu�̕����Ƃ�u���������q�[���[����\������B
�@�@�@�@�@�@���͂���Y���ʒu�͂O�`�R�B�O�`�R�ȊO�̓Y���ʒu����͂����ꍇ�̃G���[�����͍l���Ȃ��B
�@�@�@�@�@�@���͂�main�֐��ōs���A�\���̓I�u�W�F�N�g�łP�̕�����Ƃ��čs���B
�t�@�C�����FL24-07.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	char name[10];		//�q�[���[���i�[�p�����z��
public:
	//�q�[���[���ݒ�
	void setName(){
		strcpy_s(name, 10, "BERG");
	}

	//�P�����u���@c�F�u�������@id�F�u���Y��
	void chgChar(char c, int id){
		name[id] = c;
	}

	//�q�[���[���\��
	void show(){
		cout << name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	char c; 	//�P�������͗p 
	int id; 	//�u���Y�����͗p 

	hero.setName();		//�q�[���[���ݒ胁�\�b�h�Ăяo��

	cout << "�u���P�����ƒu���Y���i0�`3)�����(��: H 2) >> ";
	cin >> c >> id;

	hero.chgChar(c, id);	//�P�����u�����\�b�h�Ăяo��
	hero.show();			//�q�[���[���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

