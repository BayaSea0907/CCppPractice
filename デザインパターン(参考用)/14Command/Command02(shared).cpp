//Command�ishared�j
//Command00(shared)��Command01AppendCommand�������ЂƂɂ����v���O����
//
//�����Z�b�g�̃\�[�X�R�[�h��ύX���Ȃ��Ă��A������ǉ����邱�Ƃ��ł���
//�܂��A�����̎������e��g�ݍ��킹�āA�V���Ȏ���������
//�V�����������e��execute���\�b�h�ɁA�����̎������e��execute���\�b�h���L�q����ƁA
//�V�����������e�����s���ꂽ�ہA�L�q�������Ɋ����̎������e�����s�����

//�y�ǉ������z
//�Z�x10%�̐H����100g�ɁA�H����1g�������Ă����A�O�a�H������������
//�H�������������R�}���h�iMakeSaltWaterCommand�j�@�Ɓ@�H����1g������������R�}���h�iAddSaltCommand�j��
//�g�ݍ��킹�����s�R�}���h�N���X���`����
//
//Command02(shared).cpp
//����
//����1g�����������
//���F100g
//���F36g
//�Z�x�F26.4706%
//
//����10g�����������
//���F30g
//���F10g
//�Z�x�F25%
//
//
//���߂̑g�ݍ��킹
//������������
//���F90g
//���F10g
//�Z�x�F10%
//����1g�����������
//���F90g
//�H���F33g
//�Z�x�F26.8293%
//���������A����ɉ���1g�����������
//���F90g
//�H���F33g
//�Z�x�F26.8293%
//

#include <iostream>
#include <string>
#include <list>			//���ߑg�ݍ��킹�p�Ƃ���
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�------------------------------------
/////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//-----------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//-----------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//---------------------------------------------------------------

/////////////////////////////////////////////////////////////
//���߁i�����j�ΏۃN���X��`
class Beaker {
	double water;		//��
	double salt;		//��
	bool melted;		//���̗n��x�itrue�F���ׂėn�����Afalse�F�n���c�����j
public:
	Beaker(double bwater = 0.0, double bsalt = 0.0)
:water(bwater), salt(bsalt), melted(true)
	{
		mix();		//����������
	}

	void addSalt(double asalt){ salt += asalt; }		//���̒ǉ�
	void addWater(double awater){ water += awater; }		//���̒ǉ�

	//����������
	void mix()
	{
		//�n�������n���c�������̐ݒ�i�퉷�ł̖O�a�H�����̔Z�x�͖�26.4%�j
		if((salt / (salt + water)) * 100 < 26.4)
			melted = true;		//�n����
		else
			melted = false;		//�n���c����
	}

	double getSalt()const{ return salt; }
	double getWater()const{ return water; }
	bool isMelted()const{ return melted; }		//�n����Ԃ𒲂ׂ�

	//�������ʂ̋L�^
	void note()
	{
		cout << "���F" << water << "g" << endl; 
		cout << "���F" << salt << "g" << endl;
		cout << "�Z�x�F" << (salt / (water + salt)) * 100 << "%" << endl;
	}
};

//Command++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////
//����interface�N���X��`�i���ۃN���X�j
class Command {
protected:
	shared_ptr<Beaker> sh_beaker;	//���߁i�����j�Ώۃr�[�J�[�Ǘ�
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; } 

	virtual void execute() = 0;		//���߁i�����j�̎��s

	//���ߑg�ݍ��킹�Ŏg�p
	virtual void addCommand(shared_ptr<Command> sh_command){}
	virtual ~Command(){}
};

//���߃N���X---------------------------------------------------
/////////////////////////////////////////////////////////////
//����1g�������ĖO�a�H���������N���X��`
class AddSaltCommand : public Command {
public:
	void execute()
	{
		//���S�ɗn���Ă���Ԃ͉���������
		while(sh_beaker->isMelted())
		{
			sh_beaker->addSalt(1);	//����1g�ǉ�
			sh_beaker->mix();		//����������
		}

		//�������ʂ̋L�^
		cout << "����1g�����������" << endl;
		sh_beaker->note();
	}
	~AddSaltCommand(){}
};
//-----------------------------------------------------------
//����10g�������ĖO�a�H���������N���X��`
class AddWaterCommand : public Command {
public:
	void execute()
	{ 
		//�n���c���Ă���Ԃ͐���������
		while (!sh_beaker->isMelted())
		{ 
			sh_beaker->addWater(10);	//����10g�ǉ�
			sh_beaker->mix();		//����������
		}

		//�������ʂ̋L�^
		cout << "����10g�����������" << endl;
		sh_beaker->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------
//���������N���X��`
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		sh_beaker->mix();		//����������

		//�������ʂ̋L�^
		cout << "������������" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------
//�y���߂̑g�ݍ��킹�p�z����������ɉ���1g�������ĖO�a�H���������N���X��`
class MakeSaltWaterAddSaltCommand : public Command {
	list<shared_ptr<Command>> sh_lstCommand;		//���߁i�����j���X�g
public:
	//���߁i�����j���X�g�ɖ��߂�ǉ�
	void addCommand(shared_ptr<Command> sh_command)
{ sh_lstCommand.push_back(sh_command); }

	void execute()
	{
		list<shared_ptr<Command>>::iterator
 sh_lstCommand_itr = sh_lstCommand.begin();

		//�o�^�ϖ��߁i�����j�̎��s
		while(sh_lstCommand_itr != sh_lstCommand.end())
		{
			(*sh_lstCommand_itr)->execute();	//���߃I�u�W�F�N�g�̎��s
			sh_lstCommand_itr++;			//���̖���
		}

		//�������ʂ̋L�^
		cout << "���������A����ɉ���1g�����������" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//���߃I�u�W�F�N�g�̐���---------------------------------------
	//����1g�������閽��
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());

	//����10g�������閽��
	shared_ptr<Command> sh_addWater(createObject<AddWaterCommand>()); 

	//��������閽��
	shared_ptr<Command> sh_makeSaltWater
(createObject<MakeSaltWaterCommand>());	

	//���ߑΏۃI�u�W�F�N�g�i������ԁj�̐���--------------------------
	//��100g�A��0g
	shared_ptr<Beaker> sh_beaker1(createObject<Beaker, double>(100, 0));

	//��0g�A��10g	
shared_ptr<Beaker> sh_beaker2(createObject<Beaker, double>(0, 10));

	//----------------------------------------------------------
	//���߃I�u�W�F�N�g�ɖ��ߑΏۃI�u�W�F�N�g��o�^
	sh_addSalt->setBeaker(sh_beaker1);
	sh_addWater->setBeaker(sh_beaker2);

	//----------------------------------------------------------
	//���ߎ��s
	sh_addSalt->execute();		//����������
	cout << endl;
	sh_addWater->execute();		//����������
	cout << endl;

	//----------------------------------------------------------
	cout << endl << "���߂̑g�ݍ��킹" << endl;

	//����������ɉ���1g�������閽��-----------
	shared_ptr<Command> sh_makeSaltWaterAddSalt
(createObject<MakeSaltWaterAddSaltCommand>());

	//��90g�A��10g--------------------------
	shared_ptr<Beaker> sh_beaker3(createObject<Beaker, double>(90, 10));

	//���߂̑g�ݍ��킹�p--------------------------------------
	sh_makeSaltWater->setBeaker(sh_beaker3);
	sh_addSalt->setBeaker(sh_beaker3);
	sh_makeSaltWaterAddSalt->setBeaker(sh_beaker3);

	//���߂̑g�ݍ��킹�i���ߓo�^�j
	sh_makeSaltWaterAddSalt->addCommand(sh_makeSaltWater); 	//���������
	sh_makeSaltWaterAddSalt->addCommand(sh_addSalt); 	//��1g��������

	sh_makeSaltWaterAddSalt->execute();	//���ߎ��s�i�o�^�ϖ��߂̎��s�j


	return 0;
}

