/*
�ۑ�ԍ��@�FL26-Special1
���e�@�@�@�Fstropr�I�u�W�F�N�g��char�^�����z��i�ő啶�����P�O�j��n���āA�����񒆂̉p���������p
�@�@�@�@�@�@�啶���ɒu���������������\������B
�@�@�@�@�@�@main�֐��ŁA������͐錾�Ɠ�����"gameCU"�ŏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-S1.cpp
�쐬���@�@�F2016/1/18
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//���������A���|�C���^�ϐ����@�ɂ��Ă��A�z��𓯂��悤�ɑ���ł��邱�Ƃ��m�F���܂��傤�B
//A.�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 11;			//�z��v�f���̒�`
//�����񑀍�N���X��`
class StrOpr {
public:
	/**/
	//�p�������p�啶���ϊ��@s[]�F�����z��̃A�h���X
	void smallToBig(char s[]){
		for (int i = 0; s[i] != '\0'; i++){
			if ('a' <= s[i] && s[i] <= 'z'){
				s[i] -= ' ';
			}
		}
	}

	///////////////////////////////////////////////////////////////////
	/*
	//�|�C���^�Ŕz��̐擪�A�h���X���󂯎��֐�
	//�p�������p�啶���ϊ��@*p�F�����z��̃A�h���X
	void smallToBig(char* p)
	{
		for (int i = 0; *(p + i) != '\0'; i++){
			if ('a' <= *(p + i) && *(p + i) <= 'z'){
				*(p + i) -= ' ';
			}
		}
	}*/
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char str[MAX] = "gameCU";

	stropr.smallToBig(str);	//�p�������p�啶���ϊ����\�b�h�Ăяo��

	cout << str << endl;

	_getch();
	return 0;
}

