/*----------------------------------------------------------------
|���06-01	 BayaSea
------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//Hero�N���X��`
class Hero {
	int hp;			
public:
	
	/* 
	Hero() :hp(50){ cout << "HP=" << hp << "�Ő���" << endl; }			//�@�R���X�g���N�^
	Hero(int ch) :hp(ch){ cout << "HP=" << hp << "�Ő���" << endl; }	//�A�R���X�g���N�^�ich�FHP�j
	*/

	//�R���X�g���N�^�B�@���06-01�̉𓚗�
	Hero(int ch = 50) : hp(ch){
		cout << "HP=" << hp << "�Ő���" << endl;
	}

	//�x��
	void rest(){ cout << "��x�� ��x��" << endl; }
	void rest(int rh){ hp += rh; }		//�irhp�FHP�����ʁj

	int getHp(){ return hp; }		//HP�擾

	~Hero(){ cout << "�I�u�W�F�N�g����" << endl << endl; }
};
/////////////////////////////////////////////////////////////////
int main()
{
	Hero* heroP(new Hero);		//�I�u�W�F�N�g�̃A���P�[�V����

	heroP->rest();			//�x���i�f�t�H���g�j���\�b�h�Ăяo��
	cout << "HP=" << heroP->getHp() << endl;

	delete heroP;			//�A���P�[�V�����̈���
//---------------------------------------------------------------
	heroP = new Hero(200);		//HP200�ŃA���P�[�V����

	heroP->rest(100);		//�x���iHP�����w��j���\�b�h�Ăяo��
	cout << "HP=" << heroP->getHp() << endl;

	delete heroP;			//�A���P�[�V�����̈���
	return 0;
}



