//simpleFactory�i���i�F�����Ԃ͐��i���A�H�i�͌��j
//�I�u�W�F�N�g�����֐��i�O���֐��j���g���āA���i�I�u�W�F�N�g�i�����ԁA���i�j�𐶐����Ă���
//���iinterface�N���X�͈�ʃN���X�i���z���\�b�h��`�j
//
/*
//���iinterface�N���X��`
class IProduct {
public:
	virtual ~IProduct(){}
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }

//    �������z���\�b�h�ł͒�`�ł��Ȃ�
//    ���R�F���ۃN���X�̏������z���\�b�h�́A���ۃN���X���h���N���X�Ŏ������Ȃ���΂Ȃ�Ȃ�����
//    �@�@�@�h��Car�N���X�Ŏ������Ă���̂́AgetName���\�b�h�̂�
//    �@�@�@�igetKosu���\�b�h�������ł��Ă��Ȃ����߁j
//    virtual string getName()const = 0;
//    virtual int getKosu()const = 0;

};
//�����ԃN���X��`
class Car : public IProduct {
public:
	string getName()const{ return name; }
};
//�H�i�N���X��`
class Foods : public IProduct {
public:
	int getKosu()const{ return kosu; }
};
*/
//simpleFactory00(normal).cpp
//����
//Audi
//COKE

#include <iostream>
#include <string>
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

/////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����֐�
//�����ŁA�h���N���X�I�u�W�F�N�g�𐶐����Ă���i�߂�l�́A��{�N���X�|�C���^�j
IProduct* createFactory(int id)
{
    switch(id)
    {
        case 1: return new Car("Audi");
        case 2: return new Foods(800);
       default: return NULL;
    }
}

/////////////////////////////////////////////////////////////////
int main()
{
	IProduct* carP;
	IProduct* foodsP;

	carP = createFactory(1);			//�����ԃI�u�W�F�N�g����
	cout << carP->getName() << endl;

	foodsP = createFactory(2);			//�H�i�I�u�W�F�N�g����
	cout << foodsP->getKosu() << endl;

	delete carP;
	delete foodsP;

	return 0;
}
