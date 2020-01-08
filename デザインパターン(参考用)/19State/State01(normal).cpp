//State�inormal�j
//�u��ԁv���N���X�Ƃ��ĕ\�����āA��Ԃ̕ω��ɉ����ĐU�镑�����ς��悤�ɂ���
//�Ⴆ�΁A�u�@���̂�����ԁv�u�@����������ԁv��2�̏�Ԃɉ������U�������ς��

//State�p�^�[���̍\���́AStrategy�p�^�[���Ǝ��Ă��邪�A�ړI���قȂ�
//Strategy�p�^�[���́A�A���S���Y���̐؂�ւ����s���̂ŁA��{�I�ɂ��ꂼ��̐헪�N���X�̏����͓����B
//�헪�N���X�̐؂�ւ��͂���قǕp�ɂɍs��Ȃ�
//State�p�^�[���́A���́u��ԁv�ɉ����ĐU�镑�����قȂ�

//�q�[���[�̏�ԁi�@�������A�@���悢�A�������j�ɉ����āA���̈��A�A�h���΍��؂�ւ���
//���interface�N���X���p�������e��ԃN���X���`���A��ԑΏۃI�u�W�F�N�g�ɍ��̏�Ԃ�o�^����
//�U����
//
//State01(normal).cpp
//����
//�����F�����Ђ�
//�������I�F����
//���͂悤�I�F�}�t���[

#include <iostream>
#include <string>
using namespace std;

//Sate��`----------------------------------------------------------
/////////////////////////////////////////////////////////////////
//���interface�N���X��`
class State {
public:
	virtual string morningGreet() = 0;				//���̂��������`
	virtual string getProtectionForCold() = 0;		//�h���΍���`
};

//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//�@��������ԃN���X��`
class BadMoodState : public State {
public:
	string morningGreet(){ return "����"; }					//���̈��A�i�Ԃ�����ڂ��j
	string getProtectionForCold(){ return "�����Ђ�"; }		//�h���΍�
};
//---------------------------------------------------------------
//�@���ǂ���ԁi������j�N���X��`
class OrdinaryState : public State {
public:
	string morningGreet(){ return "�������I"; }			//���̈��A�i�j�炵���j
	string getProtectionForCold(){ return "����"; }		//�h���΍�
};
//---------------------------------------------------------------
//�����Ă����ԃN���X��`
class FallingLoveState : public State {
public:
	string morningGreet(){ return "���͂悤�I"; }			//���̈��A�i���̎q�炵���j
	string getProtectionForCold(){ return "�}�t���["; }		//�h���΍�
};
//--------------------------------------------------------------------

//��ԑΏۃN���X-------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�q�[���[��ԃN���X��`
class StateHero {
	State* stateP;			//���
public:
	void changeState(State* sstateP){ stateP = sstateP; }			//��ԕύX

	string morningGreet(){ return stateP->morningGreet(); }					//���̂�������
	string getProtectionForCold(){ return stateP->getProtectionForCold(); }	//�h���΍�
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	StateHero* heroP = new StateHero;
	State* stateP;

	//�@������
	stateP = new BadMoodState();
	heroP->changeState(stateP);			//�q�[���[�ɏ�Ԃ�o�^
	cout << heroP->morningGreet() << "�F" << heroP->getProtectionForCold() << endl;
	
	//�@���悢
	delete stateP;
	stateP = new OrdinaryState();
	heroP->changeState(stateP);			//�q�[���[�ɏ�Ԃ�o�^
	cout << heroP->morningGreet() << "�F" << heroP->getProtectionForCold() << endl;
	
	//���ɂ�����
	delete stateP;
	stateP = new FallingLoveState();
	heroP->changeState(stateP);			//�q�[���[�ɏ�Ԃ�o�^
	cout << heroP->morningGreet() << "�F" << heroP->getProtectionForCold() << endl;
	
	delete stateP;
	delete heroP;

	return 0;
}
