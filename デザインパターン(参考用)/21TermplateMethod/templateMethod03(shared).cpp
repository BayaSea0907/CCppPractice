//templateMethod�ishared�|�C���^�j
//�����̗��ꎩ�͓̂��������A���̋�̓I�Ȓ��g�̎������قȂ�ꍇ�Ɏg��
//�Ⴆ�΁A�u�O�����v�u�{�����v�u�㏈���v�ɕ�������Ƃ��A
//�����̗�����P�̘g�g�݁i���e���v���[�g�j�Ƃ���interface�N���X�Ƃ��Ē�`����B
//�����āAinterface�N���X���p�������h���N���X�ɂ����āA��̓I�Ɏ������鏈����
//��`����B
//
//�p�������h���N���X�Ɂu�����v���鏈�����Ȃ��ꍇ��A�f�t�H���g�̏���������ꍇ�́A
//interface�N���X�̉��z���\�b�h���������z���\�b�h�Œ�`���Ȃ�
//
//����templateMethod�p�^�[�����g���ƁA
//main�֐��ł́A���ꂼ��̐����I�u�W�F�N�g�̋�̓I�ȏ������e�͈�؂킩���Ă��Ȃ����A
//���ꂼ��̐����I�u�W�F�N�g�́AtemplateMethod�p�^�[���N���XCProcBase�ɒ�`�����A
//�����̗���̏��Ԓʂ�ɏ�������Ă��邱�Ƃ��킩��B
//�܂�A��̓I�ȏ����菇���ӎ������邱�ƂȂ��A��`���������菇�ŏ�����
//���s�����邱�Ƃ��ł��闘�_������B
//
//interface�N���X�ɒ�`������A�����菇���\�b�h�ł́A���ꂼ��̔h���N���X�̃��\�b�h����
//false���Ԃ����ƁA���̎��_�ł��̏�����ł��؂点�邱�Ƃ��ł���B
//�t�ɁAtrue���Ԃ����ƁAinterface�̃��\�b�h�ł��̏����Ɋ֘A���鏈��������������
//���s�����邱�Ƃ��ł���B

//templateMethod03(shared).cpp
//Concert �u����Ă�����Ⴂ�@�݂Ă�����Ⴂ�v
//Concert �u�Ձv
//���������O������̏���
//Concert �u���肪�Ƃ��v
//���������㏈����̏���

//Game opennning
//���������O������̏���
//Game playing
//���������{������̏���
//Game closing
//���������㏈����̏���

#include <iostream>
#include <memory>
using namespace std::tr1;
using namespace std;

//��A�̏����̗�����`�����N���X----------------------------------
//////////////////////////////////////////////////////////////////
//templateMmethod�@interface�N���X��`
//���ׂĂ̏������A�h���N���X�Łu�����v�����
class CProcBase
{
	//�A�h���N���X�̎������\�b�h�B�ŏ㏑�������i���������j
	virtual bool FrontProc(){ return true; }
	virtual bool MainProc(){ return true; }
	virtual bool EndProc(){ return true; }
public:
	//�@�����ɒ�`���������̏��ԂɁA���z���\�b�h���Ăяo��
	void processFlowList(shared_ptr<CProcBase> sh_pfl)
	{
		//�O����
		if( sh_pfl->FrontProc() )	//�A�̉��z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������O������̏���" << endl;
		}
		//�{����
		if( sh_pfl->MainProc() )		//�A�̉��z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������{������̏���" << endl;
		}
		//�㏈��
		if( sh_pfl->EndProc() )		//�A�̏������z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������㏈����̏���" << endl;
		}
	}
};
//////////////////////////////////////////////////////////////////

//��A�̎��������N���X����------------------------------------------
//////////////////////////////////////////////////////////////////
//�R���T�[�g�����N���X��`
class Concert : public CProcBase {
	//�O����
	bool FrontProc()
	{
		cout << "Concert �u����Ă�����Ⴂ�@�݂Ă�����Ⴂ�v" << endl;
		return false;
	}
	//�{����
	bool MainProc()
	{
		cout << "Concert �u�Ձv" << endl;
		return true;
	}
	//�㏈��
	bool EndProc()
	{
		cout << "Concert �u���肪�Ƃ��v" << endl;
		return true;
	}
};
//------------------------------------------------------------------
//Game�����N���X��`
class Game : public CProcBase {
	//�O����
	bool FrontProc()
	{
		cout << "Game opennning" << endl;
		return true;
	}
	//�{����
	bool MainProc()
	{
		cout << "Game playing" << endl;
		return true;
	}
	//�㏈��
	bool EndProc()
	{
		cout << "Game closing" << endl;
		return true;
	}
};
//----------------------------------------------------------------

//shared�|�C���^�p�I�u�W�F�N�g����--------------------------------
//////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����e���v���[�g�֐�
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}

//////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<CProcBase> sh_concert;
	shared_ptr<CProcBase> sh_game;

	sh_concert = createObject<Concert>();		//�R���T�[�g�I�u�W�F�N�g����
	sh_game = createObject<Game>();				//�Q�[���I�u�W�F�N�g����

	//���ꂼ��̈�A�̏��������s����
	sh_concert->processFlowList(sh_concert);	//�R���T�[�g
	cout << endl;
	sh_game->processFlowList(sh_game);			//�Q�[��

	return 0;
}
