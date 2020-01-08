//**********************************************************
// �t�@�C����		:���1505.cpp
//**********************************************************
// �쐬��			:BayaSea
// �X�V��			:2016.11.10
//**********************************************************
#include <iostream>
#include <memory>
#include <string>
using namespace std;

//���i�N���X��`
class Goods {
protected:
	string name;		//���i��
public:
	Goods(string n = " ") :name(n){}
	virtual void show() const = 0;
};
///////////////////////////////////////////////////////////////////
//�������N���X��`
class Drink : public Goods {
	int num;	//�{��
public:
	Drink(string ds = "TEA", int dn = 100) :num(dn), Goods(ds) {};
	void show() const { cout << name << "=" << num << endl; }
};
///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Goods> sh_drink(create<Drink>());
	sh_drink->show();

	return 0;
}
