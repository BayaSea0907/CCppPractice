/*
�ۑ�ԍ��@�FL26-ExtraSpecial2
���e�@�@�@�F���[�r�[�^�C�g����ύX�������B
�@�@�@�@�@�@movie�I�u�W�F�N�g�Ƀ^�C�g����"CU"���i�[���āA���߂ăI�u�W�F�N�g�ɕ�����" vs ARASHI"
�@�@�@�@�@�@��n���B�����āA" vs ARASHI"��A�������^�C�g����\������B
�@�@�@�@�@�@�A�������^�C�g�����́A�I�u�W�F�N�g�ɂ����Ǌi�[����B
�@�@�@�@�@�@main�֐��ŁA�^�C�g������char�^�����z��i�v�f���R�j�A�A���������char�^�����z��i�v
�@�@�@�@�@�@�f���P�P�j�ɐ錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-EX2.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

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

		int len;			//������̏I�[�̓Y�����i�[�p

		//name�z��̏I�������߂�
		for (len = 0; name[len] != '\0'; len++);

		//����
		for (int i = 0; str[i] != '\0'; i++, len++){
			name[len] = str[i];
		}
		
		name[len] = '\0';		//������̏I���Ƀk���������i�[
	}

	//���[�r�[���擾�@str[]�F���[�r�[���擾�p
	void getName(char str[]){
		strcpy_s(str, 13, name);
	}
};
//////////////////////////////////////////////////////////////////
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
