/*
�ۑ�ԍ��@�FL26-SuperDeluxe1
���e�@�@�@�Fvalopr�I�u�W�F�N�g��int�^�̈���Q�Ƃ���|�C���^�̃A�h���X��n���āAint�^�̈�ɒl��
�@�@�@�@�@�@���͂��ĕ\������B
�@�@�@�@�@�@���͂̓I�u�W�F�N�g�ōs���A�\����main�֐��ōs���B
�t�@�C�����FL26-SD1.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l����N���X��`
class ValOpr {
public:
	//���́@**p�Fint�^�̈���Q�Ƃ���|�C���^�̃A�h���X
	void input(int** p){
		cout << "���������>> " ;
		cin >> **p;
	}
};
//////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	int num;			//���͒l�i�[�p
	int* p;

	p = &num;			//num�̃A�h���X���|�C���^p�ɑ��

	valopr.input(&p);		//�|�C���^p�̃A�h���X��n��

	cout << "num=" << *p << endl;

	_getch();
	return 0;
}


