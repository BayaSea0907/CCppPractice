/*
�ۑ�ԍ��@�FL26-Special2
���e�@�@�@�Fstropr�I�u�W�F�N�g�ɂQ��char�^�����z��i�v�f���P�O�j��n���āA��Q�����̕�����
�@�@�@�@�@�@���P�����̕����z��ɃR�s�[������P�����̕������\������B
�@�@�@�@�@�@������̃R�s�[�͂P�������s���B
�@�@�@�@�@�@main�֐��ŁA��Q�����̕����z��͐錾�Ɠ�����"AllStar"�ŏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-S2.cpp
�쐬���@�@�F2016/1/18
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�����񑀍�N���X��`
class StrOpr {
public:
	//������R�s�[�@s1[]�F�����z��̐擪�A�h���X�As2[]�F�����z��̐擪�A�h���X
	void copyStr(char s1[], char s2[]){
		int i = 0;			//�Y���p

		for (; s2[i] != '\0'; i++){
			s1[i] = s2[i];
		}
		s1[i] = '\0';
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char org[10] = "AllStar";
	char trg[10];

	stropr.copyStr(trg, org);		//������R�s�[���\�b�h�Ăяo��

	cout << "trg=" << trg << endl;

	_getch();
	return 0;
}

