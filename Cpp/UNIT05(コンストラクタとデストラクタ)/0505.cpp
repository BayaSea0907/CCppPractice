/*------------------------------------------------
|���05-05	  BayaSea
--------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X
class Shop {
	int sales = 0;
public:
	Shop(int sal) : sales(sal) { cout << "�I�u�W�F�N�g����" << endl; }
	~Shop() { cout << "�I�u�W�F�N�g����" << endl; }

	int getSales() { return sales; }
};
///////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));

	cout << "���㍂=" << shopP->getSales() << endl;

	delete shopP;
	
	system("pause");
	return 0;
}
