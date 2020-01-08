//Decorator�inormal�j
//�����̃N���X�ɑ΂���ǉ��@�\���A���̃N���X���g�ɒǉ������ɁA
//����t����iDecorate����j���o�i�R�A�ƂȂ���̂ɂ��Ԃ��Ă����C���[�W�j�Ŏ�������B
//��j�����̏����̑O��ɐV���ȏ�����t�������邱�Ƃ��ł���

//��ԏ�ʂɁA����ƂȂ�N���X�ƁA�����鑤�̃N���X�̋���interface�N���X���`����
//����N���X�ɍ��A�����Ă���Ώہi�����鑤�̃I�u�W�F�N�g�j���L��������
//
//�y�v���O�������e�z
//������Ɂ{�L���̏��������
//��������镶����StrDisplay�N���X�Ə���gBorder�N���X�Ƃ̋���interface�@Display�N���X���`����
//����gBorder�N���X���p�������{�L������PlusBorder�N���X���`����
//���������\��������͏���ginterface�N���X�Ő��䂵�Ȃ���A�\������g�N���X�̃��\�b�h��
//�ҏW����
//
//Decorator00(normal).cpp
//����
//+++ game Playing +++

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//������\������interface�N���X��`�i���ۃN���X��`�j
class Display {
public:
	Display(){}

	virtual int getRowCount()const = 0;			//�\���s���擾
	virtual string getText(int row)const = 0;	//�\��������擾

	//������\��
	void Print()
	{
		for(int i = 0; i < getRowCount(); i++)
			cout << getText(i) << endl;
	}

	virtual ~Display(){}
};

//Decorator��`----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//����ginterface�N���X��`
class Border : public Display {
	Display* displayP;				//����g�����镶����Ǘ��p�|�C���^
protected:
	Border(Display* bdisplayP):displayP(bdisplayP){}
	const Display* getDisplay()const{ return displayP; }
	virtual ~Border(){ delete displayP; }
};
//----------------------------------------------------------------
//+�L������g�N���X��`
class PlusBorder : public Border {
public:
	PlusBorder(Display* displayP):Border(displayP){}

	//�s���擾
	virtual int getRowCount()const
	{
		return getDisplay()->getRowCount();
	}

	//+�L������g��t����������擾
	virtual string getText(int row)const
	{
		string text("+++ " + getDisplay()->getText(row) + " +++");
		return text;
	}
	virtual ~PlusBorder(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//�\��������N���X��`
class StrDisplay : public Display {
	string dispStr;						//�\��������
public:
	StrDisplay(const string& sstr):dispStr(sstr){}

	virtual int getRowCount()const{ return 1; }				//�\���s���i�P�s�Œ�j�擾
	virtual string getText(int row)const{ return dispStr; }	//�\��������擾

	virtual ~StrDisplay(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	//����g�t���̕�����\��
	Display* displayP = new PlusBorder(new StrDisplay("game Playing"));

	displayP->Print();

	delete displayP;

	return 0;
}
