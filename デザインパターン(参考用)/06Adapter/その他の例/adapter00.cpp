//adapter1.cpp
//Taro �N���X�� Chairperson �C���^�t�F�[�X�̃C���^�t�F�[�X�̈Ⴂ�𖄂߂�悤��
//NewTaro �N���X����������B

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
//new���Y�\�̓N���X��`�iinterface�̎����N���X�j
class NewTaro : public Taro, public Chairperson {
public:
	void organizeClass()
	{
		enjoyWithAllClassmate();
	}
};

//////////////////////////////////////////////////////
//�S�C�N���X��`
class Teacher {
	Chairperson* chairpersonP;		//���ۃN���X�|�C���^�iinterface�j
public:
	Teacher()
	{
		chairpersonP = new NewTaro;		//new���Y����
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
