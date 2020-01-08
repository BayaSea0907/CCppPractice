//Command�inormal�j
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
//Command00(normal).cpp
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
using namespace std;

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
	Beaker* beakerP;		//�����Z�b�g�I�u�W�F�N�g�i�r�[�J�[�j�Ǘ��|�C���^
public:
	void setBeaker(Beaker* sbeakerP){ beakerP = sbeakerP; }		//�r�[�J�[�̐ݒ�
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
		while(beakerP->isMelted())
		{
			beakerP->addSalt(1);		//�H����1g�ǉ�
			beakerP->mix();				//����������
		}

		//�������ʂ̋L�^
		cout << "�H����1g�����������" << endl;
		beakerP->note();
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
		while (!beakerP->isMelted())
		{ 
			beakerP->addWater(10);		//����10g�ǉ�
			beakerP->mix();				//����������
		}

		//�������ʂ̋L�^
		cout << "����10g�����������" << endl;
		beakerP->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------------
//�H�������������R�}���h�N���X��`
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		beakerP->mix();		//����������

		//�������ʂ̋L�^
		cout << "�H������������" << endl;
		beakerP->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	//�������e�R�}���h�I�u�W�F�N�g�̐���
	Command* addSaltP = new AddSaltCommand;					//�H����1g�����������
	Command* addWaterP = new AddWaterCommand;				//����10g�����������
	Command* makeSaltWaterP = new MakeSaltWaterCommand;		//�H������������

	//�����Z�b�g�̐���
	Beaker* beakerP1 = new Beaker(100, 0);			//��100g�A�H��0g
	Beaker* beakerP2 = new Beaker(0, 10);			//��0g�A�H��10g
	Beaker* beakerP3 = new Beaker(90, 10);			//��90g�A�H��10g

	//�����Z�b�g���������e�R�}���h�I�u�W�F�N�g�ɃZ�b�g
	addSaltP->setBeaker(beakerP1);
	addWaterP->setBeaker(beakerP2);
	makeSaltWaterP->setBeaker(beakerP3);

	//����
	addSaltP->execute();			//�H����������������s
	cout << endl;
	addWaterP->execute();			//����������������s
	cout << endl;
	makeSaltWaterP->execute();		//10%�̐H����100g�����������s

	delete addSaltP;
	delete addWaterP;
	delete makeSaltWaterP;
	delete beakerP1;
	delete beakerP2;
	delete beakerP3;

	return 0;
}
