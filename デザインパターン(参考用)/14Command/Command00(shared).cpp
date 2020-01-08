//Command�ishared�j
//���߂��̂��̂����\�b�h�ɒ�`���āA���߃I�u�W�F�N�g�Ƃ��Đ�������
//���߃I�u�W�F�N�g�̎��s�́A��`�������\�b�h���Ăяo��
//�܂�A���߂����s���������ΏۃI�u�W�F�N�g�ɁA�����ꂩ�̖��߃I�u�W�F�N�g��n���΁A
//�ΏۃI�u�W�F�N�g�́A�n���ꂽ���߃I�u�W�F�N�g�ɒ�`����Ă��閽�߂ǂ���Ɏ��s�����
//
//�قȂ���e�̖��߂ł����Ă��A�������O�̃��\�b�h���Ăяo���Ď��s���������̂�
//����interface�N���X�Ƃ���Command�N���X���`���A��̓I�Ȗ��߃N���X��h���N���X�Ƃ��Ē�`����
//�����āA���̔h���N���X�I�u�W�F�N�g�i���߃I�u�W�F�N�g�j�̃��\�b�h���Ăяo���Ď��s����

//�ЂƂЂƂ̈قȂ閽�߂ɑΉ��������߃I�u�W�F�N�g������̂ŁA���߃I�u�W�F�N�g��g�ݍ��킹��
//�g�����Ƃ��ł���

//��j�O�a�H������������
//�P�j��100g�ɐH����1g���������ꍇ�A�H���͉�g�n���邩�H
//�菇
//1.�r�[�J�[�ɐ���100g�����
//2.�r�[�J�[�ɐH����1g�����
//3.����������
//4.���S�ɗn����΁A2�ɖ߂�
//5.�H�����n���c������A���̂Ƃ��̐��ʁA�H���ʁA�Z�x���L�^����

//�Q�j�H��10g�ɐ���10g���������ꍇ�A���͉�g�K�v���H
//�菇
//1.�r�[�J�[�ɐH����10g�����
//2.�r�[�J�[�ɐ���10g�����
//3.����������
//4.���S�ɗn���Ȃ���΁A2�ɖ߂�
//5.�H�������S�ɗn������A���̂Ƃ��̐��ʁA�H���ʁA�Z�x���L�^����

//�O�a�H��������邽�߂ɕK�v�ȃ��\�b�h�������Z�b�gBeaker�N���X�Ƃ��Ē�`����

//�������e�i�菇�j�̒���interface�N���X���p���������ꂼ��̔h���N���X�ɁA��̓I�ȓ��e�i�菇�j���`����
//���߃I�u�W�F�N�g�Ƃ��Đ�������
//�����āA�����Z�b�g�ɁA�������e�i�菇�j��n���Ď������s��

//
//Command00(shared).cpp
//����
//�H����1g�����������
//���F100g
//�H���F36g
//�Z�x�F26.4706%
//
//����10g�����������
//���F30g
//�H���F10g
//�Z�x�F25%
//
//
//�H������������
//���F90g
//�H���F10g
//�Z�x�F10%

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//�����Z�b�g�N���X��`
class Beaker {
	double water;		//��
	double salt;		//�H��
	bool melted;		//�H���̗n��x�itrue�F���ׂėn�����Afalse�F�n���c�����j
public:
	Beaker(double bwater = 0.0, double bsalt = 0.0):water(bwater), salt(bsalt), melted(true)
	{
		mix();		//����������
	}

	void addSalt(double asalt){ salt += asalt; }		//�H���̒ǉ�
	void addWater(double awater){ water += awater; }	//���̒ǉ�

	//�n�t������������
	void mix()
	{
		//�n�������n���c�������̐ݒ�i�퉷�ł̖O�a�H�����̔Z�x�͖�26.4%�j
		if((salt / (salt + water)) * 100 < 26.4)	melted = true;		//�n����
		else										melted = false;		//�n���c����
	}

	double getSalt()const{ return salt; }
	double getWater()const{ return water; }
	bool isMelted()const{ return melted; }		//�n����Ԃ𒲂ׂ�

	//�������ʂ̋L�^
	void note()
	{
		cout << "���F" << water << "g" << endl; 
		cout << "�H���F" << salt << "g" << endl;
		cout << "�Z�x�F" << (salt / (water + salt)) * 100 << "%" << endl;
	}
};

//Command----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�������e�R�}���hinterface�N���X��`�i���ۃN���X�j
class Command {
protected:
	shared_ptr<Beaker> sh_beaker;	//�����Z�b�g�I�u�W�F�N�g�i�r�[�J�[�j�Ǘ�
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; }	//�r�[�J�[�̐ݒ�
	virtual void execute() = 0;									//�v�����e�̎��s
	virtual ~Command(){}
};

//Command�I�u�W�F�N�g�N���X�i���ۂ̎������e�N���X�j-----------------
//////////////////////////////////////////////////////////////////
//�H����1g�������ĖO�a�H�������������R�}���h�N���X��`
class AddSaltCommand : public Command {
public:
	void execute()
	{
		//���S�ɗn���Ă���Ԃ͐H����������
		while(sh_beaker->isMelted())
		{
			sh_beaker->addSalt(1);		//�H����1g�ǉ�
			sh_beaker->mix();				//����������
		}

		//�������ʂ̋L�^
		cout << "�H����1g�����������" << endl;
		sh_beaker->note();
	}
	~AddSaltCommand(){}
};
//-------------------------------------------------------------------
//����10g�������ĖO�a�H�������������R�}���h�N���X��`
class AddWaterCommand : public Command {
public:
	void execute()
	{ 
		//�n���c���Ă���Ԃ͐���������
		while (!sh_beaker->isMelted())
		{ 
			sh_beaker->addWater(10);		//����10g�ǉ�
			sh_beaker->mix();				//����������
		}

		//�������ʂ̋L�^
		cout << "����10g�����������" << endl;
		sh_beaker->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------------
//�H�������������R�}���h�N���X��`
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		sh_beaker->mix();		//����������

		//�������ʂ̋L�^
		cout << "�H������������" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	//�������e�R�}���h�I�u�W�F�N�g�̐���
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());		//�H����1g�����������
	shared_ptr<Command> sh_addWater(createObject<AddWaterCommand>());	//����10g�����������
	shared_ptr<Command> sh_makeSaltWater(createObject<MakeSaltWaterCommand>());		//�H������������

	//�����Z�b�g�̐���
	shared_ptr<Beaker> sh_beaker1(createObject<Beaker, double>(100, 0));	//��100g�A�H��0g
	shared_ptr<Beaker> sh_beaker2(createObject<Beaker, double>(0, 10));		//��0g�A�H��10g
	shared_ptr<Beaker> sh_beaker3(createObject<Beaker, double>(90, 10));	//��90g�A�H��10g

	//�����Z�b�g���������e�R�}���h�I�u�W�F�N�g�ɃZ�b�g
	sh_addSalt->setBeaker(sh_beaker1);
	sh_addWater->setBeaker(sh_beaker2);
	sh_makeSaltWater->setBeaker(sh_beaker3);

	//����
	sh_addSalt->execute();			//�H����������������s
	cout << endl;
	sh_addWater->execute();			//����������������s
	cout << endl;
	sh_makeSaltWater->execute();		//10%�̐H����100g�����������s

	return 0;
}