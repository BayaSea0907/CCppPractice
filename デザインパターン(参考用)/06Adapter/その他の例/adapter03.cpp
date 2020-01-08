//Adapter �p�^�[���i�Ϗ��𗘗p�j
//���Y�N���ǂ����Ă� Chairperson �C���^�t�F�[�X�������������Ȃ��ƌ����������ꍇ
//�̂��Ƃ��l���܂��傤�B���Ȃ��́A���Y�N�ƒ��̗ǂ��Ԏq����Ɋw����\�ɂȂ��Ă���
//�����Ƃɂ��܂����B
//�搶�̑_���́A�Ԏq���񂪁A Taro �N���X�� enjoyWithClassmate ���\�b�h�����܂�
//�Ăяo�����ƂŃN���X���܂Ƃ߂Ă����Ƃ������̂ł��B
//���̍ہA�w����\�͉Ԏq����Ȃ̂ŁA�Ԏq���� Chairperson �C���^�t�F�[�X����������
//���ƂɂȂ�܂��B
//adapter2.cpp

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
//�Ԏq�\�̓N���X��`�iinterface�̎����N���X�j
class Hanako : public Chairperson {
	Taro* taroP;
public:
	Hanako():taroP(new Taro){}
	void organizeClass()
	{
		taroP->enjoyWithAllClassmate();
	}
	~Hanako(){ delete taroP; }
};

//////////////////////////////////////////////////////
//�S�C�N���X��`
class Teacher {
	Chairperson* chairpersonP;		//���ۃN���X�|�C���^�iinterface�j
public:
	Teacher()
	{
		chairpersonP = new Hanako;		//�Ԏq����
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
