/*---------------------------------------------------
���15-01	2016.10.6

BayaSea
-----------------------------------------------------*/
#include <iostream>
using namespace std;

//�a���҃N���X��`
class Depo {
	int depo = 500;			//�a���c���i���~�j
public:
	int getDepo()const{ return depo; }		//�a���c���擾
};
///////////////////////////////////////////////////////////////////
//��s�N���X��`
class Bank {
public:
	//�a���c���\��
	void depoShow(const Depo* depoP)
	{
		cout << "��s����݂��a���c��=" << depoP->getDepo() << endl;
	}
};
///////////////////////////////////////////////////////////////////
int main()
{
	Depo* depoP(new Depo);		//�a���҃N���X�|�C���^
	Bank* bankP(new Bank);		//��s�N���X�|�C���^

	bankP->depoShow(depoP);		//��s�N���X���\�b�h�Ăяo��

	delete depoP;
	delete bankP;
	return 0;
}
