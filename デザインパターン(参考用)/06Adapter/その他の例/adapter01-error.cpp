//Adapter �p�^�[��
//���Ȃ��̃N���X�݂͂�Ȃ΂�΂�ŁA�܂������܂Ƃ܂肪����܂���B
//���Ȃ��́A�w����\�����߂�K�v������Ɗ����A���Y�N�Ɋw����\��C���悤�Ǝv���܂����B
//�y�R���p�C���G���[�ɂȂ�z
//Chairperson �C���^�t�F�[�X���������Ă��Ȃ� Taro �N���X��
//Chairperson �I�u�W�F�N�g�Ƃ��ė��p���悤�Ƃ��Ă��ł��Ȃ�
//adapter0.cpp

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////
//���Y�\�̓N���X��`
class Taro{
public:
	void enjoyWithAllClassmate()
	{
		cout << "�݂�ȂŊy����" << endl;
	}
};

//////////////////////////////////////////////////////
//�w����\�N���X��`�i���ۃN���X�Finterface�j
class Chairperson{
public:
	virtual void organizeClass() = 0;
};

//////////////////////////////////////////////////////
//�S�C�N���X��`
class Teacher {
	Chairperson* chairpersonP;		//���ۃN���X�|�C���^�iinterface�j
public:
	Teacher()
	{
		chairpersonP = new Taro;		//���Y�����i�G���[�j
		chairpersonP->organizeClass();
	}
	~Teacher(){ delete chairpersonP; }
};

//////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new Teacher);

	delete teacherP;

	return 0;
}
