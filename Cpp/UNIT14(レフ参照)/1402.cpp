/*---------------------------------------------------------
|���14-02		 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//�����N���X��`
class Swap {
public:
	//�l�̌����isn1�F�l�Asn2�F�l�j
	void swap(int& sn1, int& sn2)
	{
		std::swap(sn1, sn2);
	}
};
///////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Swap> sh_swap(create<Swap>());
	int num1 = 100, num2 = 200;

	sh_swap->swap(num1, num2);
	cout << "num1=" << num1 << " num2=" << num2 << endl;

	return 0;
}
