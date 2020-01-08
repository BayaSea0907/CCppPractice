//Memento�ishared�j
//Memento�I�u�W�F�N�g��shared�|�C���^�ŊǗ������āA�ǂ��ł������ł���悤�ɂ��Ă���
//�iMemento�N���X�̃R���X�g���N�^��public�����ɂ��Ă���j
//���̏ꍇ�A�R���X�g���N�^��private�ɂ���ƃI�u�W�F�N�g�����e���v���[�g�֐��Ő����ł��Ȃ��_�����ƂȂ�
//Singleton�p�^�[���ɂ��邱�Ƃ��l�����邪�AMemento�I�u�W�F�N�g��GameManager�N���X�ł����������Ȃ����Ƃ�
//�l����΁A�R���X�g���N�^��private�ɂ��āA�ʏ�̃|�C���^�ŊǗ����邾���ł悢�iMemento02(shared).cpp�j

//Memento01(shared-BAD).cpp
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
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

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

	friend class GameManager;	//GameManager������private�ȃ����o���A�N�Z�X�ł���
public:
	Memento(){}			//�R���X�g���N�^�i�ǂ��ł�Memento�I�u�W�F�N�g�𐶐��ł��Ă��܂���肠��j
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
	shared_ptr<Memento> createMemento()
	{
		//Momento�L�^�I�u�W�F�N�g�̐���
		shared_ptr<Memento> sh_memento(createObject<Memento>());

		sh_memento->setScore(score);
		sh_memento->setHighScore(highScore);
		cout << "�ۑ��F�X�R�A=" << sh_memento->getScore() 
			 << " �n�C�X�R�A=" << sh_memento->getHighScore() << endl;
		return sh_memento;
	}
	
	//��Ԃ̕���
	void setMemento(shared_ptr<const Memento> sh_memento)
	{
		score = sh_memento->getScore();
		highScore = sh_memento->getHighScore();
		cout << "�����F�X�R�A=" << sh_memento->getScore() 
			 << " �n�C�X�R�A=" << sh_memento->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<GameManager> sh_game(createObject<GameManager>());	//�Q�[���Ǘ��I�u�W�F�N�g
	shared_ptr<Memento> sh_memento = NULL;							//Memento�I�u�W�F�N�g

	srand((unsigned int)time(NULL));

	while(1)
	{
		sh_game->continueGame();		//�Q�[���i�s

		//���ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ�ۑ�
		if(sh_memento == NULL && rand() % 40 == 0)
		{
			sh_memento = sh_game->createMemento();		//�ۑ���
		}

		//�ۑ����œK���ȃ^�C�~���O�ŁA��Ԃ𕜌�
		if(sh_memento != NULL && rand() % 70 == 1)
		{
			sh_game->setMemento(sh_memento);	//��Ԃ𕜌�
			sh_memento = NULL;					//���ۑ���
		}

		//�I��
		if(sh_memento == NULL && rand() % 100 == 0)	break;
	}

	return 0;
}
