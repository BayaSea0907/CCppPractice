/*------------------------------------------------------------
|���06-04	 BayaSea
| 2��chgSales���\�b�h���A�֐������̏��������g�������\�b�h�ɂ���B
--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int sales;				//���㍂�i���~�j
public:
	Shop(int sal = 0) :sales(sal){}
//    void chgSales(){ sales += 300; }
//    void chgSales(int num){ sales *= num; }

	void chgSales(int num = 0)
	{
		if (num <= 0)	sales += 300;
		else			sales *= num;

		//�O�����Z�q���g����
		//sales = (num <= 0) ? sales + 300 : sales * num;
	}
	int getSales(){ return sales; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));
	int num;                        //�������͗p

	cout << "�����̓���>> ";
	cin >> num;

	shopP->chgSales(num);

	cout << "���㍂=" << shopP->getSales() << endl;

	delete shopP;
	return 0;
}

