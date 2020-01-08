/*------------------------------------------------------------
|���14-03		 BayaSea
--------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//���\�b�h�̃I�[�o�[���[�h�͈����̌^�ƌ��Ŕ��f�����̂ŁA
//�^������int�^�������̂Ńo�O���o���B

//���i�N���X��`
class Goods {
	int cost;			//��p�i�~�j
public:
	Goods() :cost(100){}
	void chgCost(int ccost){ cost += ccost; }
	void chgCost(int* ccost){ cost -= *ccost; }
	int getCost(){ return cost; }
};
///////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Goods> sh_goods(create<Goods>());
	int cost = 50;

	sh_goods->chgCost(cost);
	cout << "��p=" << sh_goods->getCost() << endl;

	return 0;
}
