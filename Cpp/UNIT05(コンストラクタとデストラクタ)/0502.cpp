/*--------------------------------------------------------------------------------------
|���05-02	 BayaSea
|
| Q.���̂悤�ȃI�u�W�F�N�g�𐶐������ꍇ�A�ǂ��Ȃ�ł��傤���H���̏ꍇ�ɂ͏C�����Ȃ����B
|   �������A�֐������̏������͎g��Ȃ����̂Ƃ��܂��B
| A.�R���X�g���N�^�Ɉ�����n���Ȃ��Ƃ����Ȃ��̂ɁAshopXP�ł͓n���Ă��Ȃ������B
---------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int sales;
public:
	Shop():sales(0){}
	Shop(int sal):sales(sal){}

	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopXP(new Shop);	
	Shop* shopSP(new Shop(300));

	cout << "shopXP=" << shopXP->getSales() << endl;
	cout << "shopSP=" << shopSP->getSales() << endl;

	delete shopXP;
	delete shopSP;

	system("pause");
	return 0;
}