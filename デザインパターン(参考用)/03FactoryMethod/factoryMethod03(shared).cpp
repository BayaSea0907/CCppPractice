//factoryMethod�ishared�|�C���^�j
//���i�I�u�W�F�N�g�ƃI�u�W�F�N�g�����H��I�u�W�F�N�g��shared�|�C���^�ŊǗ�
//factoryMethod�̍l�������ȗ������邽�߂ɁA���i�I�u�W�F�N�g�̃C���X�^���X�ϐ���
//string�݂̂ɂ��Ă���
//
//factoryMethod�̍l�����͓���
//�y�d�v�|�C���g�z
//���i�I�u�W�F�N�g�̐����́A�H��interface�N���X��CreateObject���\�b�h��
//�Ăяo���Ȃ����萶���ł��Ȃ����Ƃ��|�C���g
//
//factoryMethod02(shared).cpp
//����
//Audi
//��s�͔j�Y���܂���

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
////////////////////////////////////////////////////////////

//���i�N���X++++++++++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////
//���iinterface�N���X��`�i���ۃN���X�j
class IProduct {
public:
	virtual string getName()const = 0;
	virtual ~IProduct(){}
};

////////////////////////////////////////////////////////////
//���i�i�����ԁj�N���X��`
class Car: public IProduct {
	string name;			//���i��
public:
	Car(string cname):name(cname){}
	string getName()const{ return name; }
	~Car(){}
};
//----------------------------------------------------------
//���i�i��s�j�N���X��`
class Bank: public IProduct {
public:
	Bank(){ cout << "��s�͔j�Y���܂���" << endl; }
	string getName()const{ return ""; }
	~Bank(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//���i�I�u�W�F�N�g�����i�H��j�N���X++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////
//�H��interface�N���X��`�i���ۃN���X�j
class IFactory
{
	//�A�h���N���X�̃��\�b�h�B���㏑������
	virtual shared_ptr<IProduct> create(string cname) = 0;
	virtual shared_ptr<IProduct> create() = 0;
public:
	//�@�������Ăяo���Ďn�܂�
	//�������z���\�b�h����āACFactory�Ŏ��ۂɐ�������
	shared_ptr<IProduct> CreateInstance(string cname)
	{
		return create(cname);		//�A���Ăяo��
	}

	shared_ptr<IProduct> CreateInstance()
	{
		return create();			//�A���Ăяo��
	}

	virtual ~IFactory(){}
};

////////////////////////////////////////////////////////////
//���i�I�u�W�F�N�g�����H��
class CFactory : public IFactory
{
protected:
	//�B�����ŁA���ۂɐ��i�I�u�W�F�N�g�𐶐�����
	shared_ptr<IProduct> create(string cname)
	{
		return createObject<Car>(cname);
	}

	shared_ptr<IProduct> create()
	{
		return createObject<Bank>();
	}
public:
	~CFactory(){}
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////
int main()
{
	//�H��I�u�W�F�N�g����
	shared_ptr<CFactory> sh_cfactory(createObject<CFactory>()); 

	//�������i�I�u�W�F�N�g�Ǘ��p
	shared_ptr<IProduct> sh_car;
	shared_ptr<IProduct> sh_bank;

	sh_car = sh_cfactory->CreateInstance("Audi");	//�����ԃI�u�W�F�N�g����
	cout << sh_car->getName() << endl;

	sh_bank = sh_cfactory->CreateInstance();		//��s�I�u�W�F�N�g����

	return 0;
}


