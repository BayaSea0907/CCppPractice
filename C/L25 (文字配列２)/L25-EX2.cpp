/*
�ۑ�ԍ��@�FL25-ExtraSpecial2
���e�@�@�@�Fbook�I�u�W�F�N�g�ɓ��͂����^�C�g����string������Ɋi�[���āA�p�����݂̂̃^�C�g���ɕ�
�@�@�@�@�@�@������B�����āA�����ē��͂���������istring������j�����������p�����݂̂̃^�C�g����\
�@�@�@�@�@�@������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL25-EX2.cpp
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
	string pack;		//�p���݂̂̕�����p
public:
	//�^�C�g���ݒ�@str�F�^�C�g��������
	void setTitle(string str) {
		pack = str;
	}

	//�p����쐬
	void packAlpha() {
		for (int i = 0; pack[i] != '\0'; i++) 
		{
			if (('a' <= pack[i] && pack[i] <= 'z') 
			   || ('A' <= pack[i] && pack[i] <= 'Z'))
			{
				title += pack[i];
			}
		}
	}

	//�p���^�C�g�������@str�F�����^�C�g��
	void addPack(string str) {
		pack = title + ' ' + str;
	}

	//�p���^�C�g���擾
	string getPack() {
		return pack;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Book book;
	string str;			//�^�C�g���A�����^�C�g�����͗p

	cout << "�^�C�g������́i��@S*12ta[rT6r++e?k+=�j>> ";
	cin >> str;
	book.setTitle(str);		//�^�C�g���ݒ胁�\�b�h�̌Ăяo��

	book.packAlpha();		  //�p����쐬���\�b�h�̌Ăяo��

	cout << "�����^�C�g������́i��@Milky Way�j>> ";
	cin >> str;
	book.addPack(str);		//�p���^�C�g���������\�b�h�̌Ăяo��

	cout << book.getPack() << endl;
	_getch();
	return 0;
}
