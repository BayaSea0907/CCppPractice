/*-----------------------------------------------------------------------------------------
|���05-03	BayaSea
|
| Q.�v���p�e�Bsales�����������邽�߂�initSales���\�b�h���A�N�Z�X���Ă��܂����A
|   ��낵������܂���B�Ȃ��ł��傤���H���R���q�ׂȂ����B�܂��A������i�Q�ʂ�j���q�ׂȂ����B
| 
|A.initSales���Ăяo���O��addSales���Ăяo�����Ƃ�����ƁAsales���s��̂܂܏��������Ă��܂��ꍇ������B
|   ������1:Shop�N���X�̃R���X�g���N�^�ł��炩���ߏ����������Ă����B
|   ������2:�v���p�e�B��錾�Ɠ����ɏ����������Ă����B
| -----------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
  //int sales = 0;
	int sales;
public:
	//Shop() : sales(0){}
	void initSales(){ sales = 0; }	
	void addSales(int sal){ sales += sal; }

	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->initSales();
	shopP->addSales(100);

	delete shopP;

	system("pause");
	return 0;
}
