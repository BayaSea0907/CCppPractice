/*
�ۑ�ԍ��@�FL24-8
���e�@�@�@�Fhero�I�u�W�F�N�g�ɁA�R�̃A�C�e�����i�ő�X�����j��v�f�Ƃ���char�^�Q���������z��i�R
�@�@�@�@�@�@�s�P�O��j���i�[���āA���ꂼ��̃A�C�e������\������B
�@�@�@�@�@�@main�֐��ŁA�Q���������z���錾�Ɠ����ɂR�̃A�C�e�����ŏ���������B
�@�@�@�@�@�@�I�u�W�F�N�g�łQ���������z��ɃA�C�e�������i�[����Ƃ��ƁA�\���̓A�C�e�����i������P�ʁj
�@�@�@�@�@�@�ōs���B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL24-08.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	char item[3][10];      //�A�C�e�����Q�����z��
public:
	//�A�C�e�����ݒ�@s[][10]�F�A�C�e���z��
	void setItem(char s[][10])
	{
		//�s�P�ʂŕ�������i�[����
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(item[i], 10, s[i]);
		}
	}

	//�A�C�e�����\��
	void show()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << item[i] << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	char str[3][10] = {
		"mant",
		"bigSword",
		"goldenAxe"
	};

	hero.setItem(str); 	//�A�C�e�����ݒ胁�\�b�h�Ăяo��
	hero.show();		//�A�C�e�����\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

