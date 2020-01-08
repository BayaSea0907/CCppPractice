//templateMethod�iinterface�N���X�g�p�j
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
//�����s�����邱�Ƃ��ł��闘�_������B
//
//interface�N���X�ɒ�`������A�����菇���\�b�h�ł́A���ꂼ��̔h���N���X�̃��\�b�h����
//false���Ԃ����ƁA���̎��_�ł��̏�����ł��؂点�邱�Ƃ��ł���B
//�t�ɁAtrue���Ԃ����ƁAinterface�̃��\�b�h�ł��̏����Ɋ֘A���鏈��������������
//���s�����邱�Ƃ��ł���B

//templateMethod01(normal).cpp
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
using namespace std;

//��A�̏����̗�����`�����N���X----------------------------------
///////////////////////////////////////////////////////////////////////
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
	void processFlowList(CProcBase* pflP)
	{
		//�O����
		if( pflP->FrontProc() )	//�A�̉��z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������O������̏���" << endl;
		}
		//�{����
		if( pflP->MainProc() )		//�A�̉��z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������{������̏���" << endl;
		}
		//�㏈��
		if( pflP->EndProc() )		//�A�̏������z���\�b�h���Ăяo��
		{
			//false���Ԃ��Ă����ꍇ
			cout << "���������㏈����̏���" << endl;
		}
	}
};
///////////////////////////////////////////////////////////////////////

//��A�̎��������N���X����---------------------------------------------
///////////////////////////////////////////////////////////////////////
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
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
int main()
{
	CProcBase* concertP(new Concert);
	CProcBase* gameP(new Game);

	//���ꂼ��̈�A�̏��������s����
	concertP->processFlowList(concertP);	//�R���T�[�g
	cout << endl;
	gameP->processFlowList(gameP);			//�Q�[��

	delete concertP;
	delete gameP;

	return 0;
}
