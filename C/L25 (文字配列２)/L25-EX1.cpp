/*
�ۑ�ԍ��@�FL25-ExcellentSpecial1
���e�@�@�@�Fbook�I�u�W�F�N�g�ɓ��͂����^�C�g����string�^������Ɋi�[���āA�p���������p�啶���ɒu
�@�@�@�@�@�@�������^�C�g������\������B
�@�@�@�@�@�@�p����������p�啶���ւ̕ϊ��́A�v�Z�����g���܂��B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL25-EX1.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�{�N���X��`
class Book {
	string title;		//�^�C�g��
public:
	//�^�C�g���ݒ�@str�F�^�C�g��������
	void(setTitle(string str)) {
		title = str;
	}

	//�����ϊ�
	void chgLetter() {
		for (int i = 0; title[i] != '\0'; i++) {
			if (('a' <= title[i]) &&(title[i] <= 'z') ) {
				title[i] -= ' ';
			}
			else{
				title = "�p�������ł͂���܂���";
			}
		}
	}

	//�^�C�g���擾
	string getTitle() {
		return title;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Book book;
	string title;		//�^�C�g�����͗p
	string str;			//�^�C�g���擾�p

	cout << "�^�C�g������́i��@StaRLinE�j>> ";
	cin >> str;

	book.setTitle(str);		//�^�C�g���ݒ胁�\�b�h�̌Ăяo��
	book.chgLetter();		//�����ϊ����\�b�h�̌Ăяo��

	cout << book.getTitle() << endl;

	_getch();
	return 0;
}

