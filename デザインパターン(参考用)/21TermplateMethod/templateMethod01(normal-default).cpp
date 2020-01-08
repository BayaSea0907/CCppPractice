//templateMethod�iinterface�N���X�g�p�j
//�h���N���X�Ɉ�A�̏����菇���������郁�\�b�h���Ȃ��ꍇ�A���邢��
//�����̃f�t�H���g��������������ꍇ�ɂ́A
//interface�N���X�̉��z���\�b�h�Ƀf�t�H���g�������`�����肷��
//
//�����ł�
//interface�N���X�̑O����FrontProc�Ƀf�t�H���g�������`
//Concert�N���X�̑O����FrontProc�𖢒�`�Ƃ���
//
//templateMethod01(normal-default).cpp
//�O�����̃f�t�H���g����
//���������O������̏���
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
	virtual bool FrontProc()
	{
		cout << "�O�����̃f�t�H���g����" << endl;
		return true;
	}
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
/*
	//�O����
	bool FrontProc()
	{
		cout << "Concert �u����Ă�����Ⴂ�@�݂Ă�����Ⴂ�v" << endl;
		return false;
	}
*/
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
