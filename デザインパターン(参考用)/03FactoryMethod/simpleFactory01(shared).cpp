//simpleFactory�i���i�F�����Ԃ͐��i���A�H�i�͌��j
//shared�|�C���^�p�I�u�W�F�N�g�����֐��i�O���֐��j���g���āA���i�I�u�W�F�N�g�i�����ԁA���i�j�𐶐����Ă���
//���iinterface�N���X�͈�ʃN���X�i���z���\�b�h��`�j
//simpleFactory01(shared).cpp
//����
//Audi
//COKE

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

/////////////////////////////////////////////////////////////////
//���iinterface�N���X��`
class IProduct {
public:
	virtual ~IProduct(){}
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }
};

/////////////////////////////////////////////////////////////////
//�����ԃN���X��`
class Car : public IProduct {
	string name;			//�Ԏ햼
public:
	Car(string cname):name(cname){}
	~Car(){}
	string getName()const{ return name; }
};

/////////////////////////////////////////////////////////////////
//�H�i�N���X��`
class Foods : public IProduct {
	int kosu;				//��
public:
	Foods(int fkosu):kosu(fkosu){}
	~Foods(){}
	int getKosu()const{ return kosu; }
};

//shared�|�C���^�p�I�u�W�F�N�g����---------------------------------
/////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
/////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����֐�
//�h���N���X�I�u�W�F�N�g�𐶐�����i�߂�l�́A��{�N���X�^��shared�|�C���^�j
shared_ptr<IProduct> createFactory(int id)
{
    switch(id)
    {
        case 1: return createObject<Car, string>("Audi");
        case 2: return createObject<Foods, int>(800);
       default: return NULL;
    }
}
//-----------------------------------------------------------------
/////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IProduct> sh_carP;
	shared_ptr<IProduct> sh_foodsP;

	sh_carP = createFactory(1);				//�����ԃI�u�W�F�N�g����
	cout << sh_carP->getName() << endl;

	sh_foodsP = createFactory(2);			//�H�i�I�u�W�F�N�g����
	cout << sh_foodsP->getKosu() << endl;
	return 0;
}
