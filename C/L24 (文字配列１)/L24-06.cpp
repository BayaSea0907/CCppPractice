/*
�ۑ�ԍ��@�FL24-6
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[��"BERG"��char�^�����z��i�v�f���P�O�j�Ɋi�[���āA�q�[��
�@�@�@�@�@�@�[����\������B
�@�@�@�@�@�@main�֐���char�^�����z���錾�Ɠ����ɏ����������q�[���[��"BERG"���A�P�̕������
�@�@�@�@�@�@���ăI�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@�I�u�W�F�N�g����q�[���[�����擾���āAmain�֐��łP�̕�����Ƃ��ĕ\������B
�t�@�C�����FL24-06.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//��char�^�����z���錾�Ɠ����ɏ���������Ƃ��A�v�f���������Ȃ��Ă��������ł��邱�Ƃ��m�F���Ȃ����B
//�@    char name[] = "BERG";
//A.�m�F���܂����B

//���q�[���[��"BERG"���P�������i�[���ď������ł��邱�Ƃ��m�F���Ȃ����B
//      char name[10] = {'B', 'E', 'R', 'G', '\0'};
//A.�m�F���܂����B

//���q�[���[����"DORONJOBOY"�i�P�O�����j�ɒu��������ƁA�\�����ꂽ��A���s���G���[�ɂȂ邱�Ƃ��m
//�@�F���Ȃ����B�istack around the variable �ehero�f was corrupted.�j


#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	char name[10];		//�q�[���[���i�[�p�����z��
public:
	//�q�[���[���ݒ�@str[]�F�q�[���[���i�[�p�����z��
	void setName(char str[]){
		strcpy_s(name, 10, str);
	}
	//�q�[���[���擾�@str[]�F�q�[���[���擾�p�����z��@size�Fstr�z��̗v�f��
	void getName(char str[], int size){
		strcpy_s(str, size, name);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	//�P�̕�����P�ʂŊi�[���ď����������ꍇ 
	char name[] = "BERG";

	//�������т̕�������P�����P�ʂŊi�[���ď����������ꍇ
	//char name[10] = {'B', 'E', 'R', 'G', '\0'}; 

	char str[10];				//�q�[���[���擾�p

	hero.setName(name);		//�q�[���[���ݒ胁�\�b�h�Ăяo��

	//�q�[���[���擾���\�b�h�Ăяo��
	hero.getName(str, 10);		//�v�f���w��ɒ萔�l�g�p

	//hero.getName(str, sizeof(str)); 	//sizeof�֐��g�p

	cout << str << endl;		 //�P�̕�����Ƃ��ĕ\��

	_getch();
	return 0;
}
