//State�ishared�j
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
//State02(shared).cpp
//����
//�����F�����Ђ�
//�������I�F����
//���͂悤�I�F�}�t���[

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
//--------------------------------------------------------------------

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
	shared_ptr<State> sh_state;			//���
public:
	void changeState(shared_ptr<State> sh_sstate){ sh_state = sh_sstate; }	//��ԕύX

	string morningGreet(){ return sh_state->morningGreet(); }					//���̂�������
	string getProtectionForCold(){ return sh_state->getProtectionForCold(); }	//�h���΍�
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<StateHero> sh_hero(createObject<StateHero>());
	shared_ptr<State> sh_state;

	//�@������
	sh_state = createObject<BadMoodState>();
	sh_hero->changeState(sh_state);			//�q�[���[�ɏ�Ԃ�o�^
	cout << sh_hero->morningGreet() << "�F" << sh_hero->getProtectionForCold() << endl;
	
	//�@���悢
	sh_state.reset();
	sh_state = createObject<OrdinaryState>();
	sh_hero->changeState(sh_state);			//�q�[���[�ɏ�Ԃ�o�^
	cout << sh_hero->morningGreet() << "�F" << sh_hero->getProtectionForCold() << endl;
	
	//���ɂ�����
	sh_state.reset();
	sh_state = createObject<FallingLoveState>();
	sh_hero->changeState(sh_state);			//�q�[���[�ɏ�Ԃ�o�^
	cout << sh_hero->morningGreet() << "�F" << sh_hero->getProtectionForCold() << endl;

	return 0;
}
