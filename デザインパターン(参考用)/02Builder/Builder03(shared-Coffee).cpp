//Builder�ishared�j
//�u�쐬�ߒ��v�����肷��Director�Ɓu�\���`���v�����肷��Builder�Ƃ�g�ݍ���āA
//�I�u�W�F�N�g�̐��������_��ɂ��A���̃I�u�W�F�N�g�́u�쐬�ߒ��v�����R���g���[������
//
//Coffee�i��������A�N���[������A�������N���[���ABlack�j�������̂Ƃ��āA
//���ꂼ���Coffee�N���X���ABuilder interface�N���X����h�������Ē�`����
//�����āA���ꂼ���Coffee�̍������쐬�ߒ�Director�N���X��ʂɒ�`����
//
//��肽��Coffee�I�u�W�F�N�g��Director�I�u�W�F�N�g�ɓn���ƁADirector�I�u�W�F�N�g��
//�쐬�ߒ��ɏ]����Coffee������Ă����
//
//���̂悤�ɑf�ނƂȂ�u�\���`���v�����肷��Builder�Ɓu�쐬�ߒ��v�����肷��Director
//��p�ӂ��邱�Ƃɂ���āA���p�҂͍�肽��Builder�I�u�W�F�N�g��Director�I�u�W�F�N�g��
//�n�������ŁA�f�ޓ��e��쐬�ߒ����ӎ����邱�ƂȂ��I�u�W�F�N�g�𐶐��ł���

//Builder03(shared-Coffee).cpp
//����
//�I�[�_�[��coffee�� Cream����
//�I�[�_�[��coffee�� Sugar����Cream����
//�I�[�_�[��coffee�� Black

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

//////////////////////////////////////////////////////////////////
//COFFEE�N���X��`
class Coffee {
	string coffee;
public:
	Coffee():coffee(""){}

	void addCoffee(string acoffee){ coffee += acoffee; }	//�ǉ�
	string getCoffee()const{ return coffee; }				//�擾
};

//�\���`��------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder�i�\���`���jinterface�N���X��`
class Builder {
public:
	virtual void addSugar() = 0;
	virtual void addCream() = 0;
	virtual void addBlack() = 0;
	virtual shared_ptr<Coffee> getResult()const = 0;
};

//////////////////////////////////////////////////////////////////
//��������Builder�N���X��`
class SugarCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffee�I�u�W�F�N�g�Ǘ�
public:
	SugarCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffee�I�u�W�F�N�g����

	void addSugar(){ sh_Coffee->addCoffee("Sugar����"); }		//�����ǉ�
	void addCream(){ sh_Coffee->addCoffee(""); }				//Cream�Ȃ�
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//���݂�Coffee�擾
};
//---------------------------------------------------------------
//�N���[������Builder�N���X��`
class CreamCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffee�I�u�W�F�N�g�Ǘ�
public:
	CreamCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffee�I�u�W�F�N�g����

	void addSugar(){ sh_Coffee->addCoffee(""); }				//�����Ȃ�
	void addCream(){ sh_Coffee->addCoffee("Cream����"); }		//�N���[���ǉ�
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//���݂�Coffee�擾
};
//---------------------------------------------------------------
//�~���N���N���[������Builder�N���X��`
class SugarCreamCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;									//Coffee�I�u�W�F�N�g�Ǘ�
public:
	SugarCreamCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffee�I�u�W�F�N�g����

	void addSugar(){ sh_Coffee->addCoffee("Sugar����"); }			//�����ǉ�
	void addCream(){ sh_Coffee->addCoffee("Cream����"); }			//�N���[���ǉ�
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }		//���݂�Coffee�擾
};
//---------------------------------------------------------------
//�u���b�NBuilder�N���X��`
class BlackCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffee�I�u�W�F�N�g�Ǘ�
public:
	BlackCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffee�I�u�W�F�N�g����

	void addSugar(){ sh_Coffee->addCoffee(""); }				//�����Ȃ�
	void addCream(){ sh_Coffee->addCoffee(""); }				//�N���[���Ȃ�
	void addBlack(){ sh_Coffee->addCoffee("Black"); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//���݂�Coffee�擾
};
//--------------------------------------------------------------------

//�쐬�ߒ�------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder�I�u�W�F�N�g�́i�쐬�ߒ��j�N���X��`
class Director {
	shared_ptr<Builder> sh_builder;		//���ۂɑ��삷�鐶��Builder�I�u�W�F�N�g�Ǘ�
public:
	Director(shared_ptr<Builder> sh_dbuilder):sh_builder(sh_dbuilder){}

	//����Builder�I�u�W�F�N�g�̍쐬�ߒ��������Ȃ�ׂ����\�b�h
	void constract()
	{
		sh_builder->addSugar();				//�����ǉ�
		sh_builder->addCream();				//Cream�ǉ�
		sh_builder->addBlack();				//Black�ǉ�
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Builder> sh_builder;

	//Coffee�I�u�W�F�N�g����---------------------------------------------------
	//-----------------------------------------------------------------
//	sh_builder = createObject<CreamCoffeeBuilder>();			//�N���[������
	//-----------------------------------------------------------------
//	sh_builder = createObject<SugarCreamCoffeeBuilder>();   	//�������N���[������
	//-----------------------------------------------------------------
	sh_builder = createObject<BlackCoffeeBuilder>();			//BlackCoffee
	//------------------------------------------------------------------------

	//CoffeeBuilder�I�u�W�F�N�g�̍쐬�ߒ��I�u�W�F�N�g����
	shared_ptr<Director> sh_direct(createObject<Director>(sh_builder));

	sh_direct->constract();										//coffee�����
	shared_ptr<Coffee> sh_coffee = sh_builder->getResult();		//�����coffee���擾

	cout << "�I�[�_�[��coffee�� " << sh_coffee->getCoffee() << endl;

	return 0;
}
