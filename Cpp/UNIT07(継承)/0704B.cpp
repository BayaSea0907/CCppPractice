/*---------------------------------------------------
|���07-04�y�v���O����B�z	BayaSea
-----------------------------------------------------*/
#include <iostream>
#include <string>					//�����񑀍�p�N���X
using namespace std;

//��ЃN���X��`
class Company {
	string name;					//��Ж�
public:
	Company(string sn = ""):name(sn){}
	string getName() { return name; }
};
/////////////////////////////////////////////////////
//���Z�ƃN���X��`
class Finance : public Company {
	int loan;						//�ݏo���i���~�j
public:
	Finance(string fn = "", int sl = 0):loan(sl), Company(fn){}
	int getLoan() { return loan; }
};
/////////////////////////////////////////////////////
//�����ƃN���X��`
class Production : public Company {
	string product;					//������
public:
	Production(string pn = "", string pp = ""):product(pp), Company(pn){}
	string getProduct() { return product; }
};
/////////////////////////////////////////////////////
int main()
{
	Finance* finP(new Finance("AIFL", 2000));
	Production* prodP(new Production("TADANO", "crane"));

	cout << finP->getName()  << "�ݏo��=" << finP->getLoan()     << endl;
	cout << prodP->getName() << "������=" << prodP->getProduct() << endl;

	delete finP;
	delete prodP;
	return 0;
}