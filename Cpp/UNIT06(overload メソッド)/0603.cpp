/*------------------------------------------------------------
|���06-03	BayaSea
| Q.������5����͂�����A���ʂ͂ǂ��Ȃ�ł��傤���H
|
| A.�����L���chgSales���\�b�h���Ăяo���ꂽ
--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int sales;			//���㍂�i���~�j
public:
	Shop(int sal = 0) :sales(sal){}

	void chgSales(){ sales += 300; }
	void chgSales(int num){ sales *= num; }

	int getSales(){ return sales; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));
	int num;		//�������͗p

	cout << "�����̓���>> ";
	cin >> num;

	if (num <= 0)	shopP->chgSales();
	else			shopP->chgSales(num);

	cout << "���㍂=" << shopP->getSales() << endl;

	delete shopP;
	return 0;
}


