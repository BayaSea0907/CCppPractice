/*---------------------------------------------------------------
 ���15-02	2016.10.6

BayaSea
-----------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//�a���҃N���X��`
class Depo {
	int depo = 500;			//�a���c���i���~�j
public:
	int getDepo()const{ return depo; }	//�a���c���擾
};
///////////////////////////////////////////////////////////////////
//��s�N���X��`
class Bank {
public:
	//�a���c���\��
	void depoShow(shared_ptr<const Depo> const sh_depo)
	{
		cout << "��s����݂��a���c��=" << sh_depo->getDepo() << endl;
	}
};
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	//�a���҃|�C���^
	shared_ptr<const Depo> const sh_depo(create<Depo>());

	//��s�|�C���^
	shared_ptr<Bank> sh_bank(create<Bank>());

	sh_bank->depoShow(sh_depo);		//��s�N���X���\�b�h�Ăяo��

	return 0;
}


