/*
�ۑ�ԍ��@�FL26-9
���e�@�@�@�Fhero�I�u�W�F�N�g�̃A�h���X���|�C���^�Ɋi�[���āA�|�C���^���g���ăI�u�W�F�N�g�̃q�[���[
�@�@�@�@�@�@��"BERG"��\������B
�@�@�@�@�@�@�q�[���[���́A�N���X��`�ŏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-09.cpp
�쐬���@�@�F2016/1/14
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name = "BERG";		//�A�C�e����
public:
	//�q�[���[���擾
	string getName(){
		return name;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	Hero* p;		//hero�I�u�W�F�N�g�ւ̃|�C���^

	p =	&hero; 		//hero�I�u�W�F�N�g�̃A�h���X���|�C���^�֊i�[

	cout << p->getName() << endl; 	//�|�C���^���g���ăq�[���[����\��

	_getch();
	return 0;
}



