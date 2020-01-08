//**********************************************************
// �t�@�C����		:���1803.cpp
//**********************************************************
// �쐬��			:BayaSea
// �쐬��			:2016.11.10
//**********************************************************
// Q.�ǂ��Ȃ�܂����H
//
// A.DAISON��PLAZA�̊ԂɁAEMION��3�}�����āA
//	 ���[�v��sh_vShop�̍ŏ�����Ō�܂ł̗v�f��\�������B
//	 �\���̍ۂɁA*sh_vShopItr�Ƃ���Ă����̂ŁAsh_vShop�̃|�C���^�����L���Ă���炵���B
//**********************************************************
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

//�X�܃N���X��`
class Shop {
	string name;                    //�X��
public:
	Shop(string sn = "") :name(sn){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
///////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop[2] =
	{
		create<Shop>("DAISO"),
		create<Shop>("PLAZA")
	};

	shared_ptr<Shop> sh_appendShop(create<Shop>("EMION"));

	vector<shared_ptr<Shop>> sh_vShop;
	vector<shared_ptr<Shop>>::iterator sh_vShopItr;

	for (size_t i = 0; i < 2; i++)    sh_vShop.push_back(sh_shop[i]);

	sh_vShopItr = sh_vShop.begin();

	sh_vShop.insert(sh_vShopItr + 1, 3, sh_appendShop);    //�v�f��}��

	for (sh_vShopItr = sh_vShop.begin();
		sh_vShopItr != sh_vShop.end(); sh_vShopItr++)
	{
		cout << (*sh_vShopItr)->getName() << endl;
	}

	return 0;
}

