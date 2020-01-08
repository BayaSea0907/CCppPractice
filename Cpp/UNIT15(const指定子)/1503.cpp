/*---------------------------------------------------------------
 ���15-02	2016.10.6

 BayaSea
-----------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

const double PAI = 3.141592653;

//�~�N���X��`
class Circle {
	int hankei = 10;		//���a�i�p�j
public:
	//�~�ʌv�Z
	double calcArc(const int& angle)
	{
		return hankei * (angle * PAI / 180);
	}
	int getHankei()const{ return hankei; }    //���a�擾
};
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Circle> sh_circle(create<Circle>());
	int angle;				//�p�x���͗p

	cout << "�p�x�̓���>> ";
	cin >> angle;

	cout << "�p�x=" << angle << " �~��=" << sh_circle->calcArc(angle) << endl;

	return 0;
}
