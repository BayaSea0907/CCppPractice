//Adapter�i��܎g�p�Fshared�|�C���^�g�p�j
//�V��������Newdisposal�N���X���p������Adapter�I�u�W�F�N�g�Ɉ�ʂ̃|�C���^�ϐ��iIDisposal* disposalP�j��
//�g�p�����ꍇ�A����interface�N���X��virtual�f�X�g���N�^���`���Ă��Ȃ��ƁAadapter�N���X�̃f�X�g���N�^��
//�Ăяo�����Ɏ��s���G���[�������N����
//��������ɂ́Aadapter�N���X��Newdisposal�I�u�W�F�N�g���W�񂷂�
//�W��ɂ����ꍇ�A����interface�N���X��virtual�f�X�g���N�^���`���Ă��Ȃ��Ă����s���G���[�͂����Ȃ�
//�������ANewdisposal�̃f�X�g���N�^�͎��s����Ȃ�
//adapter02(�W��shared).cpp
//����
//NewdDisposal:start
//NewdDisposal:stop
//10000

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//�����N���X----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�Â������N���X��`
class OldDisposal {
	int x;
public:
	OldDisposal(){}
	void init(){ x = 100; }					//������
	void run(){ cout << x * x << endl; }	//���v�Z���ʕ\��
	~OldDisposal(){}
};
//----------------------------------------------------------------
//�V���������N���X��`
class NewdDisposal {
	int x;
public:
	NewdDisposal():x(100){}						//������
	//���v�Z
	void start()
	{
		cout << "NewdDisposal:start" << endl;
		x *= x;
	}
	//�v�Z���ʕ\��
	void stop()
	{
		cout << "NewdDisposal:stop" << endl;
		cout << x << endl;
	}
	virtual ~NewdDisposal(){}
};
//--------------------------------------------------------------------

//�Â������N���X����V�����N���X�Ƃ̐��������Ƃ邽�߂�interface�N���X���`����
///////////////////////////////////////////////////////////////////
//����interface�N���X��`�i����interface�N���X�j
//�Â������N���X�ɑΉ�����interface�N���X
class IDisposal {
public:
	virtual void init() = 0;
	virtual void run() = 0;
//	virtual ~IDisposal(){}		//��ʂ̃|�C���^���g���ꍇ�ɂ́A��`���Ă��Ȃ��Ă����s���G���[�͂����Ȃ�
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//adapter�N���X��`
class Adapter : public IDisposal {
	shared_ptr<NewdDisposal> sh_newDisposal;	//NewdDisposal���W��
public:
	Adapter():sh_newDisposal(new NewdDisposal){}
	void init(){}				//����interface�N���X�̃��\�b�h���������邽�߂ɕK�v
	void run(){ sh_newDisposal->start(); }		//NewdDisposal��start���\�b�h���Ăяo��
	~Adapter(){ sh_newDisposal->stop(); }		//NewdDisposal��stop���\�b�h���Ăяo��
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IDisposal> sh_disposal;
	
	sh_disposal = createObject<Adapter>();		//adapter�I�u�W�F�N�g����

	sh_disposal->run();

/*
//��ʂ̃|�C���^�ϐ����g�p�����ꍇ�A����interface�N���X��virtual�f�X�g���N�^���`���Ă��Ȃ��Ă�
//���s���G���[�͂����Ȃ�
//�������ANewdisposal�̃f�X�g���N�^�͎��s����Ȃ�
	IDisposal* disposalP(new Adapter);		//adapter�I�u�W�F�N�g����

	disposalP->run();
	delete disposalP;
*/

	return 0;
}
