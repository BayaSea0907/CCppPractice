//���O�V�|�O�S�y�v���O����A�z BayaSea
#include <iostream>
#include <string>				//�����񑀍�p�N���X
using namespace std;

//���Z�ƃN���X��`
class Finance {
	string name;				//��Ж�
	int loan;					//�ݏo���i���~�j
public:
	Finance(string fn = "", int fl = 0) :name(fn), loan(fl){}
	string getName(){ return name; }
	int getLoan(){ return loan; }
};
/////////////////////////////////////////////////////
//�����ƃN���X��`
class Production {
	string name;				//��Ж�
	string product;				//������
public:
	Production(string pn = "", string pr = "") :name(pn), product(pr){}
	string getName(){ return name; }
	string getProduct(){ return product; }
};
/////////////////////////////////////////////////////
int main()
{
	Finance* finP(new Finance("AIFL", 2000));
	Production* prodP(new Production("TADANO", "crane"));

	cout << finP->getName() << "=" << finP->getLoan() << endl;

	cout << prodP->getName() << "=" << prodP->getProduct() << endl;

	delete finP;
	delete prodP;
	return 0;
}
