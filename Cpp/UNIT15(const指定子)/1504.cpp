/*----------------------------------------------------------------
 ���15-04	2016.10.6

 15CU0210 BayaSea
------------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//�X�܃N���X��`
class Shop {
	int num = 0;		//��
public:
	void setNum(int const sn){ num = sn; }
	int getNum()const{ return num; }
};
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop(create<Shop>());

	sh_shop->setNum(100);
	cout << "��=" << sh_shop->getNum() << endl;

	return 0;
}

