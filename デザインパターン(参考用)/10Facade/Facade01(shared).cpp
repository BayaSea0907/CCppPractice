//Facade(shared)
//�N���X�̗��p�҂��A���̏������e��m��Ȃ��Ă��A���A�I�u�W�F�N�g�𐶐����Ȃ��Ă�
//�����P�̑����ƂȂ郁�\�b�h���Ăяo�������ŏ����������ꍇ�Ɏg��
//���p�҂ɁA���G�ȏ������e���ӎ������Ȃ����Ƃ�ړI�ŗ��p����
//
//Facade01(shared).cpp
//����
//314.159

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//�ʐόv�Z�N���X��`
class CalcArea {
	int radius;			//���a
public:
	CalcArea():radius(10){ calcHyouzi(); }
	void calcHyouzi(){ cout << radius * radius * 3.141592 << endl; }
	~CalcArea(){}
};

//-------------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Facade�N���X��`
class Facade {
public:
	static void run()
	{
		shared_ptr<CalcArea> sh_calc(createObject<CalcArea>());
	}
};
//-------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//�ʐόv�Z�������ӎ����Ȃ����A�I�u�W�F�N�g���������Ȃ��ŏ�������
	Facade::run();

/*
	//��������Facade�I�u�W�F�N�g�𐶐����Ă���
	shared_ptr<Facade> sh_facade(createObject<Facade>());
	sh_facade->run();

	//�ʐόv�Z�������ӎ����ăI�u�W�F�N�g�������Ă���
	shared_ptr<CalcArea> sh_calcArea(createObject<CalcArea>());
*/

	return 0;
}
