//factoryMethod
//���i�I�u�W�F�N�g���A�H��I�u�W�F�N�g�Ő�������
//simleFactory�i�I�u�W�F�N�g�����O���֐��j�Ő�������̂ł͂Ȃ��A
//�I�u�W�F�N�g�����I�u�W�F�N�g�Ő�������
//���i���A�H��ō����C���[�W�ǂ���̗��ꂪ�ł��Ă���
//
//�y�d�v�|�C���g�z
//���i�I�u�W�F�N�g�����́A�H��interface�N���X��CreateInstance���\�b�h��
//�Ăяo���Ȃ����萶���ł��Ȃ����Ƃ��|�C���g
//
/*
//�I�u�W�F�N�g�����N���X------------------------------------
//�H��interface�N���X��`
class IFactory
{
	//�A�h���N���X�̃��\�b�h�B�ŏ㏑������
	virtual IProduct* create(string cname) = 0;
public:
	//�@���̃��\�b�h���Ăяo���Ďn�܂�
	IProduct* CreateInstance(string cname)
	{
		return create(cname);	//�A�̉��z���\�b�h���Ăяo��
	}
};
////////////////////////////////////////////////////////
class CFactory : public IFactory
{
protected:
	//�B�����ŁA�悤�₭���ۂɐ��i�I�u�W�F�N�g�𐶐�����
	IProduct* create(string cname){ return new Product(cname); }
};
//--------------------------------------------------------------------
*/
//
//factoryMethod00(normal).cpp
//����
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////
//���iinterface�N���X��`
class IProduct {
public:
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }
	virtual ~IProduct(){}
};

//////////////////////////////////////////////////////////
//���i�N���X��`
class Car : public IProduct {
	string name;		//���i��
public:
	Car(string pname):name(pname){}
	string getName()const{ return name; }
	~Car(){}
};

//////////////////////////////////////////////////////////
//�H�i�N���X��`
class Foods : public IProduct {
	int kosu;			//��
public:
	Foods(int fkosu):kosu(fkosu){}
	int getKosu()const{ return kosu; }
	~Foods(){}
};

//�I�u�W�F�N�g�����N���X------------------------------------
//////////////////////////////////////////////////////////
//�H��interface�N���X��`
class IFactory
{
	virtual IProduct* create(string cname) = 0;
	virtual IProduct* create(int ckosu) = 0;
public:
	//���i�I�u�W�F�N�g����
	//�������z���\�b�h����āA�h���N���XCFactory�Ŏ��ۂɐ�������
	//cname�F���i���@ckosu�F��
	IProduct* CreateInstance(string cname){ return create(cname); }
	IProduct* CreateInstance(int ckosu){ return create(ckosu); }

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//���i�𐶐�����H��N���X��`
//�����Ő��i�h���N���X�I�u�W�F�N�g�𐶐�����i�߂�l�́A��{�N���X�|�C���^�j
class CFactory : public IFactory
{
protected:
	//�����ŁA���ۂɐ��i�I�u�W�F�N�g�𐶐�
	//cname�F���i���@ckosu�F��
	IProduct* create(string cname){ return new Car(cname); }
	IProduct* create(int ckosu){ return new Foods(ckosu); }
public:
	~CFactory(){}
};
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////
int main()
{
	CFactory* cFactoryP = new CFactory();		//�I�u�W�F�N�g�����H�ꐶ��
	IProduct* carP;
	IProduct* foodsP;

	//�H��I�u�W�F�N�g�Ő��i�I�u�W�F�N�g�𐶐�
	carP = cFactoryP->CreateInstance("Audi");		//�����ԃI�u�W�F�N�g����
	cout << carP->getName() << endl;

	foodsP = cFactoryP->CreateInstance(800);		//�H�i�I�u�W�F�N�g����
	cout << foodsP->getKosu() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP;

	return 0;
}
