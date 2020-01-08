//Observer�ishared�j
//�I�u�W�F�N�g�̏�ԕω����A�ώ@�ҁiobserver)�ɒʒm���ď�Ԃ̓��������
//
//�yMediator��Observer�ł͖ړI���Ⴄ�z
//Mediator�ł́A��Ԃ��ω�����ƕ����̃I�u�W�F�N�g�Ԃ̒���ҁiMediator�j�ֈ�U�ʒm���āA
//�ΏۂƂ���I�u�W�F�N�g�֒ʒm����
//�܂�AMediator�ł́A�e�I�u�W�F�N�g�����ړI�ɂ���肷�鑊��𒲒�҂݂̂ɂ���
//�����̌o�H�����炵�A�\�����������肳����

//Observer�́A���炩���ߓo�^���Ă������ώ@�҂֒ʒm����
//Observer�ł́A��Ԃ̕ω����A�֌W�̂��鑼�̃I�u�W�F�N�g�ɂ��ʒm���ď�Ԃɖ�����
//�����Ȃ��悤�ɓ�������邱�Ƃ�ړI�ɂ���

//�����ł́A�ȒP�ɁA�ώ@�Ώێ҂̐Ԃ���񂪋������Ƃ�����ԕω��ɑΉ����āA
//�ώ@�҂̐e�i��e�ƕ��e�j���Ή�������i�e���g�̏�Ԃ�ω�������j
//�ώ@�ҁiObserver�j�Ɗώ@�Ώێ҂́A���ꂼ�ꒊ�ۃN���X���p�������Ē�`����
//�ώ@�҂́A�ώ@�Ώێ҂����Ԃ��ω������ʒm���󂯎�郁�\�b�h���`����
//�ώ@�Ώێ҂́A���ׂĂ̊ώ@�҂�vector�ɓo�^����
//�����āA�ώ@�Ώێ҂̏�Ԃ��ω������Ȃ�΁A�ω��������Ƃ�vector�ɓo�^�����ώ@�҂֒ʒm����
//���ꂼ��̊ώ@�҂ւ̒ʒm�́A�ώ@�ґΏۂ̒��ۃN���X�ɒ�`���Ă����ƁA
//���ׂĂ̊ώ@�Ώێҋ��ʂ̒ʒm���@�Ƃ��ėp�ӂł���

//�ώ@�҂Ɗώ@�Ώێ҃N���X�̒�`�ʒu�ɂ͋C��t���邱��
//�ώ@��interface��`���p�������ώ@�҃N���X��`�́A�ώ@��interface�A�ώ@�Ώێ�interface�ȍ~��
//��`���Ȃ���΂Ȃ�Ȃ��i�ώ@��interface����ɒ�`����ƃR���p�C���G���[�ƂȂ�j

//�ώ@�҂֒ʒm���鎞�ɁA�ώ@�ΏێҎ��g�̃A�h���X�ithis�j��n�����Athis��shared�|�C���^�ł͂Ȃ��̂ŁA
//�ʏ�̃|�C���^�Ŏ���

//Observer02(shared).cpp
//����
//�I�M���[�@�I�M���[
//��e��TARO�����₹��
//���e��TARO�������ăI���I�����`

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std::tr1;
using namespace std;

class Child;

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Observer----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�ώ@��interface�N���X��`�i���ۃN���X�j
class Parent {
public:
	//�ώ@�Ώۂ���ω������ʒm���󂯎���āA�ώ@�Ҏ��g���X�V����
	virtual void takeCare(Child* childP) = 0;
};
//-------------------------------------------------------------------

//�ώ@�Ώ�-----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�ώ@�Ώ�interface�N���X��`�i���ۃN���X�j
class Child {
protected:
	vector<shared_ptr<Parent>> sh_vParents;		//�ώ@�ҁi�e�j�Ǘ�vector
public:
	//�ώ@�҂�ǉ�
	void addParent(shared_ptr<Parent> sh_parent){ sh_vParents.push_back(sh_parent); }

	//�ώ@�ҁi�e�j�֌����ʒm����
	//�i�ʒm���\�b�h�𒊏ۃN���X���Œ�`�����΁A�����̊ώ@�Ώێҋ��ʂŎg����j
	virtual void notifyParent()
	{
		for(int i = 0; i < (int)sh_vParents.size(); i++)
		{
			sh_vParents[i]->takeCare(this);
		}
	}

	virtual void cry() = 0;
	virtual string getName()const = 0;
};
//-------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Observer�ώ@�Ғ�`-------------------------------------------------
//��`�ʒu�́A�K���ώ@�Ώێ҃N���X��`�̌�ɂ���
//////////////////////////////////////////////////////////////////
//��e�N���X��`
class Mother : public Parent {
public:
	//�ʒm���󂯎��A���g���X�V����
	void takeCare(Child* childP)
	{
		cout << "��e��" << childP->getName() << "�����₹��" << endl;
	}
};
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//��e�N���X��`
class Father : public Parent {
public:
	//�ʒm���󂯎��A���g���X�V����
	void takeCare(Child* childP)
	{
		cout << "���e��" << childP->getName() << "�������ăI���I�����`" << endl;
	}
};
//-------------------------------------------------------------------

//�ώ@�ΏێҒ�`--------------------------------------------------
//�Ԃ����N���X��`
class Baby : public Child {
	string name;			//���O
public:
	Baby(string sname):name(sname){}

	//�i�ώ@�Ώہj�Ԃ���񎩐g���u�I�M���[�v�Ƌ�����Ԃɕω�����
	void cry()
	{
		cout << "�I�M���[�@�I�M���[" << endl;
		notifyParent();					//�ώ@�ҁi�e�j�֏�Ԃ��ω��������Ƃ�ʒm
	}

	string getName()const{ return name; }
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	//�ώ@�ҁi�e�j����
	shared_ptr<Parent> sh_mother(createObject<Mother>());
	shared_ptr<Parent> sh_father(createObject<Father>());

	//�ώ@�Ώہi�q�ǂ��j����
	shared_ptr<Child> sh_child(createObject<Baby, string>("TARO"));

	//�ώ@�Ώہi�q�ǂ��j�Ɋώ@�ҁi�e�j��o�^
	sh_child->addParent(sh_mother);
	sh_child->addParent(sh_father);

	sh_child->cry();		//�Ԃ���񂪋������i�ώ@�Ώۂ̏�Ԃ��ω������j

	return 0;
}