/*
�ۑ�ԍ��@�FL25-Special1
���e�@�@�@�F�������琔�l�֕ϊ�����strToDec�I�u�W�F�N�g�ɓ��͂���������i�����݂̂̕�����F�ő啶��
�@�@�@�@�@�@���P�O�j��char�^�����z��Ɋi�[���āA�P�O�i�����ɕϊ����ĕ\������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�@�@�@�@�@�@�Ⴆ�΁A������Ƃ���12345����͂����ꍇ�A�\������P�O�i������12345�i�ꖜ���O�S�l�\
�@�@�@�@�@�@�܁j�ƂȂ�B
�t�@�C�����FL25-S1.cpp
�쐬���@�@�F2015/1/4
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�������琔�l�֕ϊ�����N���X��`
class StrToDec {
	char str[11];		//���͐�����p
	int num = 0;		//�����l�ϊ��p
public:
	//������ݒ�@s[]�F������
	void setStr(char s[]) {
		strcpy_s(str, 11, s);
	}

	//�����񂩂琔�l�ւ̕ϊ�
	void chgStrToDec() {
		for (int i = 0; str[i] != '\0'; i++) 
		{
			//str��10�{���Č������炵�Ȃ���i�[
			num = (num * 10) + (int)(str[i] - '0');	
		}
	}

	//�ϊ��㐔�l�擾
	int getNum() {
		return num;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	StrToDec strToDec;		//�������琔�l�֕ϊ��I�u�W�F�N�g�錾
	char str[11];			//��������͗p

	cout << "����������>> ";
	cin >> str;
	
	strToDec.setStr(str);		//������ݒ胁�\�b�h�̌Ăяo��

	strToDec.chgStrToDec();		//�����񂩂琔�l�ւ̕ϊ����\�b�h�̌Ăяo��
	cout << "�ϊ���������=" << strToDec.getNum() << endl;

	_getch();
	return 0;
}


