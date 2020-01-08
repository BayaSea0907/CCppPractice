//Bridge�ishared�j
//�N���X���@�\�Ǝ����ɕ�����ۂ̋��n�����s��
//Bridge���g�����Ƃɂ���āA�@�\������̊g�����s���₷���Ȃ�
//
//�Ⴆ�΁A�A�C�e���̊l����i�Ƃ��āA�����A���D�A�w���̂R��ނ�������̂Ƃ���
//���ꂪ���������ƂȂ�A�A�C�e���l��interface�N���XAcquire���p��������
//�����āA�l���҂ɂ́A���l�A�P�l�A���l�̂R�l������A���ꂼ��A�C�e�����l������
//�R�l�͓������@getItem���\�b�h�Ăяo���Ŋl��������̂Ƃ���
//���̍ہA�R�l�̊l���Ǝ����̊l����i�����т��邽�߂ɁA�R�l��Bridge�@interface�N���X���p�������Ē�`����
//����interce�N���X���A�@�\�����ƂȂ�
//���̂悤�Ɏ����Ƌ@�\�𕪗������邱�Ƃɂ���āA�ǉ����̊g�����e�ՂɂȂ�

//Bridge00(shared).cpp
//����
//�P�l�́@�������Ď�ɓ��ꂽ
//���l�́@���D���Ď�ɓ��ꂽ
//���l�́@�����Ď�ɓ��ꂽ

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
//------------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(createObject<Y>()));
}
//------------------------------------------------------------------

//�A�C�e���l���N���X------------------------------------------------
//////////////////////////////////////////////////////////////////
//�A�C�e���l��interface�N���X��`�i���ۃN���X�j
class Acquire {
public:
	virtual void getItem() = 0;
};

//�l����i�N���X--------------------------------------------------
//////////////////////////////////////////////////////////////////
//�����N���X��`
class Exchange : public Acquire {
public:
	void getItem(){ cout << "�������Ď�ɓ��ꂽ" << endl; }
};
//----------------------------------------------------------------
//���D�N���X��`
class Plunder : public Acquire {
public:
	void getItem(){ cout << "���D���Ď�ɓ��ꂽ" << endl; }
};
//------------------------------------------------------------------
//�w���N���X��`
class purchase : public Acquire {
public:
	void getItem(){ cout << "�����Ď�ɓ��ꂽ" << endl; }
};
//------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Bridge�@interface�N���X��`�i���ۃN���X�j
class Bridge {
protected:
	shared_ptr<Acquire> sh_Acquire;			//�l����i�I�u�W�F�N�g�Ǘ�
public:
	Bridge(shared_ptr<Acquire> sh_bacqire):sh_Acquire(sh_bacqire){}
	virtual void getItem()const = 0;
	virtual ~Bridge(){}
};

//////////////////////////////////////////////////////////////////
//���l�~���N���X��`
class Villain : public Bridge {
public:
	//�l����i��Bridge�ɓo�^
	Villain(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//�A�C�e���l��
	~Villain(){}
};
//--------------------------------------------------------------------
//�P�l�~���N���X��`
class Virtue : public Bridge {
public:
	//�l����i��Bridge�ɓo�^
	Virtue(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//�A�C�e���l��
	~Virtue(){}
};
//--------------------------------------------------------------------
//���l�~���N���X��`
class Dealer : public Bridge {
public:
	//�l����i��Bridge�ɓo�^
	Dealer(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//�A�C�e���l��
	~Dealer(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//�l����i�̐���
	shared_ptr<Bridge> sh_bridge1(createObject<Virtue, Exchange>());	//�P�l�͌���
	shared_ptr<Bridge> sh_bridge2(createObject<Villain, Plunder>());	//���l�͗��D
	shared_ptr<Bridge> sh_bridge3(createObject<Dealer, purchase>());	//���l�͍w��

	//�A�C�e���̊l��
	cout << "�P�l�́@";
	sh_bridge1->getItem();

	cout << "���l�́@";
	sh_bridge2->getItem();

	cout << "���l�́@";
	sh_bridge3->getItem();

	return 0;
}
