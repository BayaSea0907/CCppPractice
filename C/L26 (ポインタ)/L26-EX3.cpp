/*
�ۑ�ԍ��@�FL26-ExtraSpecial3
���e�@�@�@�FL26-EX2���������āA�W���֐�strcat�֐����g���ă��[�r�[����A�����āA�������ʂ�\������B
�t�@�C�����FL26-EX3.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

//�m�F���邱�ƁF
//����������R�s�[����֐��́A���ɕW���֐��ŗp�ӂ���Ă��邱�Ƃ��m�F���Ȃ����B

#include <conio.h>
#include <iostream>
using namespace std;

//���[�r�[�N���X��`
class Movie {
	char name[13];		//���[�r�[��
public:
	//���[�r�[���ݒ�@str[]�F���[�r�[��
	void setName(char str[]){
		strcpy_s(name, 13, str);
	}
	//���[�r�[���A���@str[]�F�A��������
	void catName(char str[]){
		strcat_s(name, 13, str);
	}

	//���[�r�[���擾�@str[]�F���[�r�[���擾�p
	void getName(char str[]){
		strcpy_s(str, 13, name);
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	Movie movie;
	char name[3] = "CU";
	char str[11] = " vs ARASHI";
	char result[13];			//���[�r�[���擾�p

	movie.setName(name);		//���[�r�[���ݒ胁�\�b�h�̌Ăяo��
	movie.catName(str);	 		//���[�r�[���A�����\�b�h�̌Ăяo��
	movie.getName(result);		//���[�r�[���擾���\�b�h�̌Ăяo��

	cout << "�A��������=" << result << endl;

	_getch();
	return 0;
}
