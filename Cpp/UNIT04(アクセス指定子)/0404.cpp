/*--------------------------------------------------------------
| ���04-04	  BayaSea
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int discount;		//�������i�i�~�j

	//�������i�v�Z�ipr�F���i�j�������Q�O��
	void calcDiscount(int pr){ discount = (int)(pr * 0.8); }
public:
	void receivePrice(int pr) { calcDiscount(pr); }		//���i�󂯎��
	int getDiscount(){ return discount; }				//�������i�擾
};
////////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->receivePrice(1000);		//���i���胁�\�b�h�Ăяo��

	//�������i�擾���\�b�h�Ăяo��
	cout << "�������i=" << shopP->getDiscount() << endl;

	delete shopP;
	system("pause");
	return 0;
}
