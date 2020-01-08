//proxy�ishared�F��{�I�ȍl�����j
//�����𑼂̃I�u�W�F�N�g�ɔC����i�㗝������j
//�㗝�𗧂Ă�{���̃N���X(RealPrint)���A�㗝����N���X(CProxyPrint)���A����interface�̌^(IPrint)�ɂ���
//����ɂ��A������v������main�֐����ł́A�{���̃N���X(RealPrint)�̃��\�b�h���Ăяo���̂̂Ɠ���������
//�㗝�N���X�̃��\�b�h���Ăяo���ĐU�镑�킹�邱�Ƃ��ł���
//
//�y���_�z
//�㗝�N���X���`����ƁA�{���ɏ������K�v�ɂȂ�܂ŁA�{���̃N���X�̐�����x�点�邱�Ƃ��ł���
//�������A�{���̃N���X�𐶐�����K�v���Ȃ���������Ȃ��ꍇ�ɂ́A�{���ɕK�v�ɂȂ�܂Ő�����x�点�邱�Ƃ��ł���
//proxy02(shared).cpp
//����
//ROBOT

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

/////////////////////////////////////////////////////////////////
//interface�N���X��`�i�{���Ƒ㗝�N���X����interface���ۃN���X�j
class IPrint
{
public:
	virtual void print(string str) = 0;
	virtual ~IPrint(){}
};

/////////////////////////////////////////////////////////////////
//�{���N���X��`
class RealPrint : public IPrint
{
public:
	//�B�㗝�I�u�W�F�N�g�̃��\�b�h����Ăяo����āA���߂ď��������
	void print(string str){ cout << str << endl; }
};

/////////////////////////////////////////////////////////////////
//�㗝�N���X��`�i�{���N���X��㗝����N���X�j
class CProxyPrint : public IPrint
{
	shared_ptr<IPrint> sh_realClass;		//�㗝����{���I�u�W�F�N�g�Ǘ��p�|�C���^
public:
	CProxyPrint():sh_realClass(NULL){}

	//�@�{���N���X�̑���ɌĂяo�����㗝�N���X�̃��\�b�h
	void print(string str)
	{
		//�܂��{���I�u�W�F�N�g����������Ă��Ȃ��ꍇ�A�{���I�u�W�F�N�g�𐶐�����
		if(sh_realClass == NULL)
		{
			sh_realClass = createObject<RealPrint>();		//�{���I�u�W�F�N�g����
		}

		//�A�����ŁA�{���I�u�W�F�N�g�̃��\�b�h�B���Ăяo��
		sh_realClass->print(str);
	}
};

/////////////////////////////////////////////////////////////////
int main()
{
	//�㗝�I�u�W�F�N�g����
	shared_ptr<IPrint> sh_iprint(createObject<CProxyPrint>());

	sh_iprint->print("ROBOT");				//�㗝�N���X�̃��\�b�h�Ăяo��

	return 0;
}
