/*
�ۑ�ԍ��@�FL25-DeluxeSpecial2
���e�@�@�@�Fdic�I�u�W�F�N�g�ɓ��͂����Q�̒P���string������Ɋi�[���āA���������̏����Ŕ�r����
�@�@�@�@�@�@�召�֌W��\������B
�@�@�@�@�@�@�ŏ��ɓ��͂����P�ꂪ�@!�@�ɂȂ�܂ŌJ�Ԃ��B
�@�@�@�@�@�@���͂����Q�̒P������������̏����Ŕ�r�����召�֌W�́A�P��̒����i�������j�ƕ����R�[
�@�@�@�@�@�@�h�̕��я��i�p�������͉p�啶�������傫���j���Ƃ��w���B
�@�@�@�@�@�@break�����g���Ă��悢�B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�@�@�@�@�@�@�������J�Ԃ��̂ŁA���́A�召��r�A���ʕ\���𖳌����[�v�Ő��䂵�āA�ŏ��ɓ��͂����P���
�@�@�@�@�@�@!�@����͂����Ƃ����[�v�𔲂���悤�ɂ���B
�t�@�C�����FL25-DX2.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//�����s��ȊO�ɁA��ɏグ��(1)�`(3)�̂��ׂĂ̗���m�F���Ȃ����B
//A.�m�F���܂����B

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�����N���X��`
class Dictionary {
	string words1;		//�P��p
	string words2;		//�P��p
	int flag;			//�召�֌W���ʗp�i�O�F�����@�P�Fwords1���傫���@
						//				�|�P�Fwords2���傫���j
public:
	//�P��ݒ�@w1�F�P��Aw2�F�P��
	void setWords(string w1, string w2) {
		words1 = w1;
		words2 = w2;
	}

	//�P�ꎫ������r
	void compWords() {
		if (words1 == words2) {
			flag = 0;
		}
		else if (words1 > words2) {
			flag = 1;
		}
		else {
			flag = -1;
		}
	}

	//��r���ʎ擾
	int getResult(){
		return flag ;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Dictionary dic;
	string words1;		//�P��P���͗p
	string words2;		//�P��Q���͗p
	int flag;			//�召�֌W���ʗp�i�O�F�����@�P�Fwords1���傫���@
	//									�|�P�Fwords2���傫���j

	while (1)
	{
		cout << "�P�����́F�I���� !>> ";
		cin >> words1;

		cout << "�P������>> ";
		cin >> words2;

		if (words1 == "!") {
			cout << "�������I�����܂�" << endl;
			break;
		}

		dic.setWords(words1, words2);	  //�P��ݒ胁�\�b�h�Ăяo��
		dic.compWords();			 //�P�ꎫ������r���\�b�h�Ăяo��

		flag = dic.getResult();		//��r���ʕ\�����\�b�h�Ăяo��

		switch (flag)
		{
			case -1: cout << words1 << " > " << words2 << endl << endl;
					 break;
			case  0: cout << words1 << " = " << words2 << endl << endl;
				 	 break;
			case  1: cout << words1 << " < " << words2 << endl << endl;
					 break;
		}
	}

	_getch();
	return 0;
}
