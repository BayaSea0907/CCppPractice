//Memento�inormal�j
//Memento �Ƃ́A�p��Łu�L�O�i�v�u�`���v���Ӗ�����P��
//Memento �p�^�[���Ƃ́A �C���X�^���X�̂���Ƃ��̏�Ԃ��X�i�b�v�V���b�g�Ƃ��ĕۑ����Ă������ƂŁA
//���̎��̃C���X�^���X�̏�Ԃ𕜌����邱�Ƃ��\�ɂ������
//�C���X�^���X�̏�Ԃ��A�v���O�������s���ɂǂ�ǂ�ω����邱�Ƃ��l�����܂��B
//��x�ω����Ă��܂����C���X�^���X���A�u�����O�̏�Ԃɖ߂������v�u���鎞�_�̏�Ԃɖ߂������v�Ȃǂ̗v����
//���ɔ���������̂ł��B ���̂悤�ȗv���ɃX�}�[�g�ɉ����邱�Ƃ��ł���̂��AMemento �p�^�[���ł��B
//Memento �p�^�[�����g���ƁA�C���X�^���X�̂��鎞�̏�Ԃ��A�ȒP�ɃX�i�b�v�V���b�g�Ƃ��Ďc�����Ƃ��ł��A
//����ɁA��������̕������\�ɂȂ�܂��B
//�C���X�^���X�S�Ă̏�Ԃ��o���Ă������߂ɁA clone ���쐬���邱�Ƃ�����܂����A
//Memento �p�^�[���ł́A�K�v�ȏ��݂̂�ێ����Ă����A�K�v�ȃf�[�^�݂̂𕜌��ł���


//�Ⴆ�΁A�Q�[���𒆒f���čĊJ�������A���f���̓��_��Ԃ���p������Ƃ���
//���_�L�^�N���X�Ƃ���Memento�N���X���`���A����Memento�N���X�ɂ̓Q�[���Ǘ��I�u�W�F�N�g���炵��
//�A�N�Z�X�ł��Ȃ��悤�ɂ���i�A�N�Z�X�ł��錠���́Afriend�ł���GameManager�N���X�̂݁j
//������Memento�N���X�ł́A�C���X�^���X�ϐ��i���_�j���A�N�Z�X���郁�\�b�h��R���X�g���N�^��
//private�ɂ��Ă����A���\�b�h��GameManager�N���X�������A�N�Z�X�ł���悤�ɂ���
//�v���O�����ł́A�����𔭐������ĕۑ��A�������s���A�m�F�̂��ߕۑ������^�C�~���O�œ��_��\�����Ă���

//Memento00(normal).cpp
//����
//�ۑ��F�X�R�A=280 �n�C�X�R�A=4060
//�����F�X�R�A=280 �n�C�X�R�A=4060
//
//�ۑ��F�X�R�A=450 �n�C�X�R�A=10350
//�����F�X�R�A=450 �n�C�X�R�A=10350
//
//�ۑ��F�X�R�A=630 �n�C�X�R�A=20160
//�����F�X�R�A=630 �n�C�X�R�A=20160
//
//�ۑ��F�X�R�A=1200 �n�C�X�R�A=72600
//�����F�X�R�A=1200 �n�C�X�R�A=72600
//
//�ۑ��F�X�R�A=1610 �n�C�X�R�A=130410
//�����F�X�R�A=1610 �n�C�X�R�A=130410

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//Memento----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//����̋L�^�N���X��`
class Memento {
	int score;				//���݂̃X�R�A
	int highScore;			//�n�C�X�R�A

	void setScore(int sscore){ score = sscore; }
	int  getScore()const{ return score; }
	void setHighScore(int shighScore){ highScore = shighScore; }
	int  getHighScore()const{ return highScore; }

	Memento(){}					//�R���X�g���N�^
	friend class GameManager;	//GameManager������private�ȃ����o���A�N�Z�X�ł���
public:
	~Memento(){}
};

//Memento�N���X���g���ď�Ԃ��L�^�������N���X��`--------------------
//////////////////////////////////////////////////////////////////
//�Q�[���Ǘ��N���X��`
class GameManager {
	int score;				//���݂̃X�R�A
	int highScore;			//�n�C�X�R�A
public:
	GameManager():score(0), highScore(0){}

	//�Q�[���i�s�i���_���Z�j
	void continueGame()
	{
		score += 10;
		highScore += score;
	}
	
	//��Ԃ̕ۑ�
	Memento* createMemento()
	{
		Memento* memP = new Memento();		//Momento�L�^�I�u�W�F�N�g�̐���

		memP->setScore(score);
		memP->setHighScore(highScore);
		cout << "�ۑ��F�X�R�A=" << memP->getScore() 
			 << " �n�C�X�R�A=" << memP->getHighScore() << endl;
		return memP;
	}
	
	//��Ԃ̕���
	void setMemento(const Memento* memP)
	{
		score = memP->getScore();
		highScore = memP->getHighScore();
		cout << "�����F�X�R�A=" << memP->getScore() 
			 << " �n�C�X�R�A=" << memP->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	GameManager* gameP = new GameManager;	//�Q�[���Ǘ��I�u�W�F�N�g�Ǘ��|�C���^
	Memento* memP = NULL;					//Memento�I�u�W�F�N�g�Ǘ��|�C���^

	srand((unsigned int)time(NULL));

	while(1)
	{
		gameP->continueGame();		//�Q�[���i�s

		//���ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ�ۑ�
		if(memP == NULL && rand() % 40 == 0)
		{
			memP = gameP->createMemento();		//�ۑ���
		}

		//�ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ𕜌�
		if(memP != NULL && rand() % 70 == 0)
		{
			gameP->setMemento(memP);	//��Ԃ𕜌�
			delete memP;				//��Ԃ𕜌������琶��Memento�I�u�W�F�N�g�����
			memP = NULL;				//���ۑ���
		}

		//�I��
		if(memP == NULL && rand() % 100 == 0)	break;
	}

	delete gameP;

	return 0;
}
