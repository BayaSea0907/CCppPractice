/*-------------------------------------------------------
|���03-02	 BayaSea
---------------------------------------------------------*/
#include <iostream>
using namespace std;

//���i�\���̒�`
struct Goods {
	int num;        //��
	int tanka;      //�P���i�~�j
};
////////////////////////////////////////////////////////////////
//�X�܃N���X��`
class Shop {
	Goods goods;			//���i�\���̕ϐ��錾
public:
	//���P���ݒ�@sg�F���Ast�F�P��
	void setGoods(int sg, int st)
	{
		goods.num   = sg;
		goods.tanka = st;
	}
	int getNum()  { return goods.num; }		//���擾
	int getTanka(){ return goods.tanka; }	//�Z�̎擾
};
////////////////////////////////////////////////////////////////
int main()
{
	//�|�C���^�錾�Ɠ����̃A���P�[�V����
	Shop* shop(new Shop);

	//���i100�j�A�P���i50�~�j�̐ݒ�
	shop->setGoods(100, 50);

	//���i���̕\��
	cout << "���i="  << shop->getNum()
		 << " �P��=" <<	shop->getTanka() << endl;

	//�A���P�[�V�����̈�̉��
	delete shop;

	system("pause");
	return 0;
}
