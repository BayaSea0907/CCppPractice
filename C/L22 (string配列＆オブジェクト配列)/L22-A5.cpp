/*
�ۑ�ԍ��@�FL22-5
���e�@�@�@�F�R�l�̃q�[���[�����ꂽ�̂ŁA���ꂼ��̃q�[���[��hero�I�u�W�F�N�g�z��i�v�f���R�j�ň����B
�@�@�@�@�@�@���͂����R�l�̃q�[���[�����I�u�W�F�N�g�z��i�v�f���R�j�̊e�v�f�Ɋi�[���āA���ꂼ��̃q
�@�@�@�@�@�@�[���[����\������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL22-A5.cpp
�쐬���@�@�F2015/11/12
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name;		//�q�[���[��
public:
	//�q�[���[���ݒ�@str�F�q�[���[��
	void setName(string str)
	{
		name = str;
	}

	//�q�[���[���擾
	string getName()
	{
		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero[3];		//hero�I�u�W�F�N�g�z��
	string name;		//�q�[���[�����͗p

	//�q�[���[������
	for (int i = 0; i < 3; i++)
	{
		cout << "�q�[���[�������>> ";
		cin >> name;

		//�q�[���[���ݒ�
		hero[i].setName(name);
	}

	//�q�[���[���\��
	for (int i = 0; i < 3; i++)
	{
		cout << hero[i].getName() << endl;		//�q�[���[���擾
	}

	_getch();
	return 0;
}

