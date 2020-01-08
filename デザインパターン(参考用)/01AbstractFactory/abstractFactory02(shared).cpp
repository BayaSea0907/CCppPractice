//AbstractFactory�ishared�|�C���^�g�p�j
//�I�u�W�F�N�g�������A�����H��ƂȂ�֐��ōs��
//���i�ƂȂ�N���X�̐������A�\�[�X�R�[�h�̒��ɎU�݂��Ȃ��Ȃ邽�߁A�ύX���e�ՂɂȂ�
//�܂��A�����̍ۂɁA���̏������s�킹�邱�Ƃ��e�ՂɂȂ�i���̃��\�b�h���Ăяo���ď������邱�Ƃ��\�j
//
//�y�d�v�|�C���g�z
//�����u�^�C���v�ł����Ă��Ⴂ�����邪�A���̈Ⴂ�́A���i���쐬����H��̈Ⴂ�ɂ���Đ��܂��ƍl����̂ŁA
//���i�̓����I�ȈႢ���A�O������C�ɂ�����K�v���Ȃ��Ȃ�
//��x�I�u�W�F�N�g�����H�������Ă��܂��΁A��͑S�Ă̑��삪�C���^�t�F�[�X�N���X�o�R�ōs����_�����_
//���ʓI�ɂǂ�ȕ��i������悤�Ƃ��A�������삪�ł���
//�܂��A�P�̍H��ō쐬����镔�i�̃Z�b�g�́A��ɓ������̂Ȃ̂ŁA�����̕��i����ɐ������g�ݍ��킹�Ő����ł���
//
//�y���_�z
//���i��������ƁA�قƂ�ǑS�Ẳӏ��Œǉ���Ƃ��K�v�ɂȂ��Ă��܂�
//�ォ�畔�i��ǉ����邱�Ƃ͗e�Ղł͂Ȃ�
//abstractFactory02(shared).cpp
//����
//�����H��`�ō�����Ԃ̕��i�� �X���b�N�^�C���i���[�V���O�p�j�ƃn�C�I�N
//�����H��a�ō�����Ԃ̕��i�� �X�^�b�h���X�^�C���i����n�p�j�Ƃk�o�K�X

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//------------------------------------------------------------------

//���i�N���X��`++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�^�C��------------------------------------------------------------
//�^�C��interface�N���X��`�i���ۃN���X�j
class ITire
{
public:
	virtual string getTire()const = 0;
	virtual ~ITire(){}
};
//----------------------------------------------------------------
//�X���b�N�^�C���N���X��`
class Tire1 : public ITire
{
	string tire;
public:
	Tire1():tire("�X���b�N�^�C���i���[�V���O�p�j"){}
	string getTire()const{ return tire; }
};
//----------------------------------------------------------------
//�X�^�b�h���X�^�C���N���X��`
class Tire2 : public ITire
{
	string tire;
public:
	Tire2():tire("�X�^�b�h���X�^�C���i����n�p�j"){}
	string getTire()const{ return tire; }
};
//-----------------------------------------------------------------

//�R���N���X---------------------------------------------------------
//�R��interface�N���X��`�i���ۃN���X�j
class IFuel
{
public:
	virtual string getFuel()const = 0;
	virtual ~IFuel(){}
};
//-----------------------------------------------------------------
//�n�C�I�N�N���X��`
class Fuel1 : public IFuel
{
	string fuel;
public:
	Fuel1():fuel("�n�C�I�N"){}
	string getFuel()const{ return fuel; }
};
//-----------------------------------------------------------------
//�k�o�K�X�N���X��`
class Fuel2 : public IFuel
{
	string fuel;
public:
	Fuel2():fuel("�k�o�K�X"){}
	string getFuel()const{ return fuel; }
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//�I�u�W�F�N�g�����H��N���X��`+++++++++++++++++++++++++++++++++++++++
//�����H��interface�N���X��`�i���ۃN���X�j
class IFactory {
public:
	virtual shared_ptr<ITire> CreateTire() = 0;
	virtual shared_ptr<IFuel> CreateFuel() = 0;
	virtual ~IFactory(){}
};
//-----------------------------------------------------------------
//�����H��`�N���X��`�i���i�F�X���b�N�^�C���ƃn�C�I�N�j
class FactoryA : public IFactory{
public:
	//�X���b�N�^�C������
	shared_ptr<ITire> CreateTire(){ return createObject<Tire1>(); }

	//�n�C�I�N����
	shared_ptr<IFuel> CreateFuel(){ return createObject<Fuel1>(); }
};
//----------------------------------------------------------------
//�����H��a�N���X��`�i���i�F�X�^�b�h���X�^�C���Ƃk�o�K�X�j
class FactoryB : public IFactory{
public:
	//�X�^�b�h���X�^�C������
	shared_ptr<ITire> CreateTire(){ return createObject<Tire2>(); }

	//�k�o�K�X����
	shared_ptr<IFuel> CreateFuel(){ return createObject<Fuel2>(); } 
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IFactory> sh_factory;				//�����H��Ǘ��p

	sh_factory = createObject<FactoryA>();			//�����H��`����

	cout << "�����H��`�ō�����Ԃ̕��i�� "
		 << sh_factory->CreateTire()->getTire() << "��"
		 << sh_factory->CreateFuel()->getFuel() << endl;

	sh_factory = createObject<FactoryB>();			//�����H��a����

	cout << "�����H��a�ō�����Ԃ̕��i�� "
		 << sh_factory->CreateTire()->getTire() << "��"
		 << sh_factory->CreateFuel()->getFuel() << endl;

	return 0;
}
