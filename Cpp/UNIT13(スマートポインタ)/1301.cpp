/*-----------------------------------------------------------------
|���13-01	 BayaSea
 ------------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//�X�܃N���X��`
class Shop {
	int sales;			//���㍂�i���~�j
public:
	Shop(int sal = 0) :sales(sal){}
	int getSales(){ return sales; }
};
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X, class Y>
shared_ptr<X> create(Y n){ return shared_ptr<X>(new X(n)); }
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�̏���\������O���֐�
//���e�Fshared�|�C���^�ŎQ�Ƃ��Ă��鐶���I�u�W�F�N�g�����L�Ǘ�����
//�����Fshared_ptr<Shop> sh_shop�@�����I�u�W�F�N�g��shared�|�C���^
void Hyouzi(shared_ptr<Shop> sh_shop)
{
	cout << "���㍂=" << sh_shop->getSales() << endl;
}
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop(create<Shop>(777));		//shared�|�C���^�錾

	Hyouzi(sh_shop);	//shared�|�C���^���֐��ɓn��

	cout << "�l�n���Ŏ󂯂��֐��𔲂��Ă����㍂="
		<< sh_shop->getSales() << endl;

	system("pause");
	return 0;
}
