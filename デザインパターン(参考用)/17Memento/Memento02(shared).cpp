//Memento�ishared�j
//�I�u�W�F�N�g�̂���Ƃ��̏�Ԃ��X�i�b�v�V���b�g�Ƃ��ĕۑ����Ă������ƂŁA
//���̎��̏�Ԃ𕜌����邱�Ƃ��\�ɂ������
//�I�u�W�F�N�g�̏�Ԃ��A�v���O�������s���ɂǂ�ǂ�ω����Ă���ꍇ�A
//�I�u�W�F�N�g���u�����O�̏�Ԃɖ߂������v�u���鎞�_�̏�Ԃɖ߂������v�ȂǂɑΉ�����
//clone�p�^�[���A�I�u�W�F�N�g�̑S�Ă̏�Ԃ��o���Ă����Ă��悢���A�K�v�ȏ��݂̂�ێ����āA
//�K�v�ȃf�[�^�݂̂𕜌�����̂�Memento�p�^�[�����g����

//�Ⴆ�΁A�Q�[���𒆒f���čĊJ�������A���f���̓��_��Ԃ���p������ꍇ�ɁAMementop�^�[�����g����
//���̏ꍇ�A���_�L�^�N���X�Ƃ���Memento�N���X���`���āA����Memento�N���X�ɂ̓Q�[���Ǘ��I�u�W�F�N�g����
//�����A�N�Z�X�ł��Ȃ��悤�ɂ��Ă����i�A�N�Z�X�ł��錠���́Afriend�ł���GameManager�N���X�̂݁j
//������Memento�N���X�ł́A�C���X�^���X�ϐ��i���_�j���A�N�Z�X���郁�\�b�h��R���X�g���N�^��
//private�ɂ��Ă����A���\�b�h��GameManager�N���X�������A�N�Z�X�ł���悤�ɂ���
//���̃v���O�����ł́A�����𔭐������ĕۑ��A�������s���A�m�F�̂��ߕۑ������^�C�~���O�œ��_��\�����Ă���

//Memento�I�u�W�F�N�g�́AGameManager�N���X�݂̂Ő�������̂ŁA�ʏ�̃|�C���^�ŊǗ����Ă���
//Memento�I�u�W�F�N�g��shared�|�C���^�ŊǗ������Ă��悢���A���̏ꍇ�A�R���X�g���N�^��private�ɂ����
//�I�u�W�F�N�g�����e���v���[�g�֐��Ő����ł��Ȃ�
//Singleton�p�^�[���ɂ��邱�Ƃ��l�����邪�AMemento�I�u�W�F�N�g��GameManager�N���X�ł����������Ȃ����Ƃ�
//�l����΁A�R���X�g���N�^��private�ɂ��āA�ʏ�̃|�C���^�ŊǗ����邾���ł悢

//Memento02(shared).cpp
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

//Memento----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//����̋L�^�N���X��`
class Memento {
	int score;				//���݂̃X�R�A
	int highScore;			//�n�C�X�R�A

	void setScore(int sscore){ score = sscore; }
	int getScore()const{ return score; }
	void setHighScore(int shighScore){ highScore = shighScore; }
	int getHighScore()const{ return highScore; }

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
		//Momento�L�^�I�u�W�F�N�g�̐���
		Memento* mementoP = new Memento;

		mementoP->setScore(score);
		mementoP->setHighScore(highScore);
		cout << "�ۑ��F�X�R�A=" << mementoP->getScore() 
			 << " �n�C�X�R�A=" << mementoP->getHighScore() << endl;
		return mementoP;
	}
	
	//��Ԃ̕���
	void setMemento(const Memento* mementoP)
	{
		score = mementoP->getScore();
		highScore = mementoP->getHighScore();
		cout << "�����F�X�R�A=" << mementoP->getScore() 
			 << " �n�C�X�R�A=" << mementoP->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<GameManager> sh_game(createObject<GameManager>());	//�Q�[���Ǘ��I�u�W�F�N�g
	Memento* mementoP = NULL;										//Memento�I�u�W�F�N�g�Ǘ��|�C���^

	srand((unsigned int)time(NULL));

	while(1)
	{
		sh_game->continueGame();		//�Q�[���i�s

		//���ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ�ۑ�
		if(mementoP == NULL && rand() % 40 == 0)
		{
			mementoP = sh_game->createMemento();		//�ۑ���
		}

		//�ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ𕜌�
		if(mementoP != NULL && rand() % 70 == 0)
		{
			sh_game->setMemento(mementoP);	//��Ԃ𕜌�
			delete mementoP;				//��Ԃ𕜌������琶��Memento�I�u�W�F�N�g�����
			mementoP = NULL;				//���ۑ���
		}

		//�I��
		if(mementoP == NULL && rand() % 100 == 0)	break;
	}

	return 0;
}
