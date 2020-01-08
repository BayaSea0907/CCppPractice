//Command�inormal�jAppendCommand
//Command01(normal).cpp�@�Ɂ@�����R�}���h��ǉ�����
//
//�����Z�b�g�̃\�[�X�R�[�h��ύX���Ȃ��Ă��A������ǉ����邱�Ƃ��ł���
//�܂��A�����̎������e��g�ݍ��킹�āA�V���Ȏ���������
//�V�����������e��execute���\�b�h�ɁA�����̎������e��execute���\�b�h���L�q����ƁA
//�V�����������e�����s���ꂽ�ہA�L�q�������Ɋ����̎������e�����s�����

//�y�ǉ������z
//�Z�x10%�̐H����100g�ɁA�H����1g�������Ă����A�O�a�H������������

//
//Command01AppendCommand(normal).cpp
//����
//�H������������
//���F90g
//�H���F10g
//�Z�x�F10%
//�H����1g�����������
//���F90g
//�H���F33g
//�Z�x�F26.8293%
//�H���������A����ɐH����1g�����������
//���F90g
//�H���F33g
//�Z�x�F26.8293%
//

#include <iostream>
#include <string>
#include <list>				//�ǉ������R�}���h�p�Ƃ���
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
	virtual void execute() = 0;									//�����̎��s
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
//�y�ǉ������z
//������H�����ɐH����1g�������ĖO�a�H������������
class MakeSaltWaterAddSaltCommand : public Command {
	list<Command*> lstCommand;							//�������X�g
public:
	//�������X�g�Ɏ����R�}���h��ǉ�
	void addCommand(Command* commandP){ lstCommand.push_back(commandP); }

	void execute()
	{
		list<Command*>::iterator lstCommand_itr = lstCommand.begin();

		//�o�^�ώ����R�}���h�̎��s
		while(lstCommand_itr != lstCommand.end())
		{
			(*lstCommand_itr)->execute();		//�����R�}���h�̎��s
			lstCommand_itr++;					//���̎����R�}���h
		}

		//�������ʂ̋L�^
		cout << "�H���������A����ɐH����1g�����������" << endl;
		beakerP->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//�������e�R�}���h�I�u�W�F�N�g�̐���
	Command* makeSaltWaterP = new MakeSaltWaterCommand;		//�H������������
	Command* addSaltP = new AddSaltCommand;					//�H����1g�����������

	//������H�����ɐH����1g�����������
	MakeSaltWaterAddSaltCommand* makeSaltWaterAddSaltP = new MakeSaltWaterAddSaltCommand;

	//�����Z�b�g�i�r�[�J�[�j�ɐH���������i��90g�A�H��10g�j
	Beaker* beakerP = new Beaker(90, 10);

	//�����Z�b�g���������e�R�}���h�I�u�W�F�N�g�ɃZ�b�g
	makeSaltWaterP->setBeaker(beakerP);
	addSaltP->setBeaker(beakerP);
	makeSaltWaterAddSaltP->setBeaker(beakerP);

	//�������X�g�̐ݒ�i�������e�R�}���h�I�u�W�F�N�g�̑g�ݍ��킹�j
	makeSaltWaterAddSaltP->addCommand(makeSaltWaterP);	//�H�������������R�}���h�ǉ�
	makeSaltWaterAddSaltP->addCommand(addSaltP);		//�H��1g������������R�}���h�̒ǉ�

	//����
	//�������X�g�ɓo�^���Ă���A�H�������������R�}���h�ƐH��1g������������R�}���h�����s�����
	makeSaltWaterAddSaltP->execute();

	delete makeSaltWaterP;
	delete addSaltP;
	delete makeSaltWaterAddSaltP;
	delete beakerP;

	return 0;
}
