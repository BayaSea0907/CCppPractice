//Adapter�i�p���g�p�Fshared�|�C���^�g�p�j
//����N���X���񋟂��Ă���C���^�t�F�[�X���A�ʂ̃N���X �̃C���^�t�F�[�X�ɕϊ�����
//�����̃R�[�h���󂷂��ƂȂ������ւ����s���������A�ȑO�Ɏg���Ă����N���X�ƁA
//�V�����g���N���X�Ƃł́A�p�ӂ���Ă��郁�\�b�h���قȂ邩������Ȃ�
//���������Ƃ��ɁA�ԂɃA�_�v�^�����ݍ���ŁA�C���^�t�F�[�X��ϊ�����
//
//�Â�����OldDisposal�ł́u������init�v�u�v�Z�ƕ\��run�v�ŁA���v�Z�ƌ��ʂ�\��������̂ł�����
//���A�V��������NewDisposal�ł́A�v�Z�ƕ\���𕪂��A�u���������R���X�g���N�^�v�u�v�Zstart�v
//�u�\��stop�v�œ����������s�����̂ɂ���
//�V��������NewDisposal�𗘗p����main���ł́A�Â�����OldDisposal�̃��\�b�h���𗬗p������
//���̏ꍇ�AOldDisposal��NewDisposal�Ƃ̃��\�b�h���Ƃ̐��������Ƃ邽�߂�adapter�N���X���`���邱�ƂɂȂ�
//
//�y�v���Ӂz
//��ʂ̃|�C���^�ϐ��iIDisposal* disposalP�j���g�p�����ꍇ�A
//����interface�N���X��virtual�f�X�g���N�^���`���Ă��Ȃ��ƁAadapter�N���X�̃f�X�g���N�^��
//�Ăяo�����Ɏ��s���G���[�������N����
//��������ɂ́A�W����g���iadapter02(�W��shared).cpp���Q�Ɓj
//
//adapter01(�p��shared).cpp
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
	virtual ~IDisposal(){}		//��ʂ̃|�C���^���g���ꍇ�ɂ́A�K���K�v
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//adapter�N���X��`
class Adapter : private NewdDisposal, public IDisposal {
public:
	Adapter(){}
	void init(){}				//����interface�N���X�̃��\�b�h���������邽�߂ɕK�v
	void run(){ start(); }		//NewdDisposal��start���\�b�h���Ăяo��
	~Adapter(){ stop(); }		//NewdDisposal��stop���\�b�h���Ăяo��
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
//��ʂ̃|�C���^�ϐ����g�p�����ꍇ�A����interface�N���X��virtual�f�X�g���N�^���`���Ă��Ȃ���
//���s���G���[�������N����
	IDisposal* disposalP(new Adapter);		//adapter�I�u�W�F�N�g����

	disposalP->run();
	delete disposalP;
*/
	return 0;
}
