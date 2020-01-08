//Command�ishared-hero�j
//
//Hero�̃A�N�V�����𖽗߂ŗ^���čs�킹��

//Command03(shared-hero).cpp
//����
//�W�����v
//
//����
//�W�����v

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
//--------------------------------------------------------------------
/////////////////////////////////////////////////////////////
//���ߑΏۃN���X��`
class Hero {
public:
	void run(){ cout << "����" << endl; }
	void jump(){ cout << "�W�����v" << endl; }
};

//Command++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////
//����interface�N���X��`�i���ۃN���X�j
class Command {
protected:
	shared_ptr<Hero> sh_hero;		//���ߑΏۊǗ�
public:
	void setHero(shared_ptr<Hero> sh_shero){ sh_hero = sh_shero; }

	virtual void execute() = 0;		//���߂̎��s
	virtual void addCommand(shared_ptr<Command> sh_command) = 0;
	virtual ~Command(){}
};

//���߃N���X---------------------------------------------------
/////////////////////////////////////////////////////////////
//����N���X��`
class Run : public Command {
public:
	void execute(){ sh_hero->run(); }
	void addCommand(shared_ptr<Command> sh_command){}
	~Run(){}
};
//------------------------------------------------------------
//�W�����v�N���X��`
class Jump : public Command {
public:
	void execute(){ sh_hero->jump(); }
	void addCommand(shared_ptr<Command> sh_command){}
	~Jump(){}
};
//-----------------------------------------------------------
//�y���߂̑g�ݍ��킹�p�z�����ăW�����v�N���X��`
class RunJump : public Command {
	list<shared_ptr<Command>> sh_lstCommand;		//���߃��X�g
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
	}
	~RunJump(){}
};

//////////////////////////////////////////////////////////////////
int main()
{
	//���߃I�u�W�F�N�g�̐���---------------------------------------
	shared_ptr<Command> sh_run(createObject<Run>());			//���閽��
	shared_ptr<Command> sh_jump(createObject<Jump>());			//�W�����v����
	shared_ptr<Command> sh_runJump(createObject<RunJump>());	//�����ăW�����v����

	//���ߑΏۃI�u�W�F�N�g�̐���-----------------------------------
	shared_ptr<Hero> sh_hero(createObject<Hero>());

	//����
	sh_jump->setHero(sh_hero);	//���߃I�u�W�F�N�g�ɖ��ߑΏۃI�u�W�F�N�g��o�^
	sh_jump->execute();			//���ߎ��s
	cout << endl;

	sh_runJump->setHero(sh_hero);

	//�����ăW�����v
	sh_runJump->addCommand(sh_run);		//���߃��X�g�֓o�^
	sh_runJump->addCommand(sh_jump);

	sh_runJump->execute();			//���ߎ��s

	return 0;
}

