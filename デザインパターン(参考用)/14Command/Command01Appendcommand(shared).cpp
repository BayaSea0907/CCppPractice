//Command�ishared�jAppendCommand
//Command01(shared).cpp�@�Ɂ@�����R�}���h��ǉ�����
//
//�����Z�b�g�̃\�[�X�R�[�h��ύX���Ȃ��Ă��A������ǉ����邱�Ƃ��ł���
//�܂��A�����̎������e��g�ݍ��킹�āA�V���Ȏ���������
//�V�����������e��execute���\�b�h�ɁA�����̎������e��execute���\�b�h���L�q����ƁA
//�V�����������e�����s���ꂽ�ہA�L�q�������Ɋ����̎������e�����s�����

//�y�ǉ������z
//�Z�x10%�̐H����100g�ɁA�H����1g�������Ă����A�O�a�H������������

//
//Command01AppendCommand(shared).cpp
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
	shared_ptr<Beaker> sh_beaker;		//�����Z�b�g�I�u�W�F�N�g�i�r�[�J�[�j�Ǘ��|�C���^
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; }	//�r�[�J�[�̐ݒ�
	virtual void execute() = 0;													//�����̎��s
	virtual void addCommand(shared_ptr<Command> sh_command){}					//�ǉ��R�}���h�Ŏg�p
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
//�y�ǉ������z
//������H�����ɐH����1g�������ĖO�a�H������������
class MakeSaltWaterAddSaltCommand : public Command {
	list<shared_ptr<Command>> sh_lstCommand;					//�������X�g
public:
	//�������X�g�Ɏ����R�}���h��ǉ�
	void addCommand(shared_ptr<Command> sh_command){ sh_lstCommand.push_back(sh_command); }

	void execute()
	{
		list<shared_ptr<Command>>::iterator sh_lstCommand_itr = sh_lstCommand.begin();

		//�o�^�ώ����R�}���h�̎��s
		while(sh_lstCommand_itr != sh_lstCommand.end())
		{
			(*sh_lstCommand_itr)->execute();		//�����R�}���h�̎��s
			sh_lstCommand_itr++;					//���̎����R�}���h
		}

		//�������ʂ̋L�^
		cout << "�H���������A����ɐH����1g�����������" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//�������e�R�}���h�I�u�W�F�N�g�̐���
	shared_ptr<Command> sh_makeSaltWater(createObject<MakeSaltWaterCommand>());	//�H������������
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());				//�H����1g�����������

	//������H�����ɐH����1g�����������
	shared_ptr<Command> sh_makeSaltWaterAddSalt(createObject<MakeSaltWaterAddSaltCommand>());

	//�����Z�b�g�i�r�[�J�[�j�ɐH���������i��90g�A�H��10g�j
	shared_ptr<Beaker> sh_beaker(createObject<Beaker, double>(90, 10));

	//�����Z�b�g���������e�R�}���h�I�u�W�F�N�g�ɃZ�b�g
	sh_makeSaltWater->setBeaker(sh_beaker);
	sh_addSalt->setBeaker(sh_beaker);
	sh_makeSaltWaterAddSalt->setBeaker(sh_beaker);

	//�������X�g�̐ݒ�i�������e�R�}���h�I�u�W�F�N�g�̑g�ݍ��킹�j
	sh_makeSaltWaterAddSalt->addCommand(sh_makeSaltWater);	//�H�������������R�}���h�ǉ�
	sh_makeSaltWaterAddSalt->addCommand(sh_addSalt);		//�H��1g������������R�}���h�̒ǉ�

	//����
	//�������X�g�ɓo�^���Ă���A�H�������������R�}���h�ƐH��1g������������R�}���h�����s�����
	sh_makeSaltWaterAddSalt->execute();

	return 0;
}
