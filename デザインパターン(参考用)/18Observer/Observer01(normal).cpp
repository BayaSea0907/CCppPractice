//Observer�inormal�j
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

//Observer01(normal).cpp
//����
//�I�M���[�@�I�M���[
//��e��TARO�����₹��
//���e��TARO�������ăI���I�����`

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Child;

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
	vector<Parent*> vParents;		//�ώ@�ҁi�e�j�Ǘ�vector
public:
	//�ώ@�҂�ǉ�
	void addParent(Parent* parentP){ vParents.push_back(parentP); }

	//�ώ@�ҁi�e�j�֌����ʒm����
	//�i�ʒm���\�b�h�𒊏ۃN���X���Œ�`�����΁A�����̊ώ@�Ώێҋ��ʂŎg����j
	virtual void notifyParent()
	{
		for(int i = 0; i < (int)vParents.size(); i++)
		{
			vParents[i]->takeCare(this);
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
	Parent* motherP = new Mother;
	Parent* fatherP = new Father;

	//�ώ@�Ώہi�q�ǂ��j����
	Child* childP = new Baby("TARO");

	//�ώ@�Ώہi�q�ǂ��j�Ɋώ@�ҁi�e�j��o�^
	childP->addParent(motherP);
	childP->addParent(fatherP);

	childP->cry();		//�Ԃ���񂪋������i�ώ@�Ώۂ̏�Ԃ��ω������j

	delete motherP;
	delete fatherP;
	delete childP;

	return 0;
}