/*-----------------------------------------------------------
|���04-02	 BayaSea
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int sales;			//���㍂�i���~�j
public:
	void setSales(){ sales = 100; }	//���㍂�ݒ�
	int getSales(){ return sales; }	//���㍂�擾
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->setSales();
	cout << "���㍂=" << shopP->getSales() << endl;

	delete shopP;
	system("pause");
	return 0;
}