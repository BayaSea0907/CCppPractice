/*------------------------------------------------------
|���05-01	 BayaSea
|
| Q.�����ςł��B�s��������闝�R���q�ׂďC�����Ȃ����B
| A.sales������������Ă��Ȃ��̂ɁAaddSales�Ŕ���グ��ǉ����悤�Ƃ��Ă����B
--------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop{
	int sales;		//���㍂
public:
	Shop() : sales(0){}

	void initSales(int sal) { sales = 0; } 
	void addSales (int sal) { sales += sal; }
	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	//������Z
	shopP->addSales(100);
	cout << "����=" << shopP->getSales() << endl;

	delete shopP;

	system("pause");
	return 0;
}
