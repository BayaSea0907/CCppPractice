//���O�U�|�O�T BayaSea
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//�����ăQ�[���N���X
class Game
{
	int PC;			//�����ăi���o�[
public:
	//�R���X�g���N�^
	Game()
	{
		srand((unsigned)time(NULL));
		PC = rand() % 10;
	}
	/*
	//�����āiPC�ΐ�p�j
	void hit()
	{
		if(PC == (rand() % 10))		cout << "������" << endl;
		else						cout << "�͂���" << endl;
	}
	//�����āi�v���C���[�ΐ�p�j
	void hit(int play)
	{
		if(play == PC)				cout << "������" << endl;
		else						cout << "�͂���" << endl;
	}
	*/
	//---------------------------------------------------------------
	//�`�������W���F�����āiplay:0�`9�@�v���C���[�ΐ�A0�`9�ȊO�@PC�ΐ�p�����j
	void hit(int play = (rand() % 10))
	{
		//PC�ΐ�A�v���[���[�ΐ틤��
		if(play == PC)				cout << "������" << endl;
		else						cout << "�͂���" << endl;
	}
	//---------------------------------------------------------------
};
int main()
{
	Game* gameP(new Game);
	int select;          //�ΐ�P�[�X�I��p�i�P�F��PC�A�P�ȊO�F�΃v���C���[�j
	int play;            //�v���C���[���͒l�p

	cout << "PC�ΐ�(1)�@or�@PC�΃v���C���[�ΐ�(2)>> ";
	cin >> select;

	switch (select)
	{
	case 1:
		gameP->hit();
		break;
	default:
		do
		{
			cout << "�v���C���[�l�̓��́i�O�`�X�j>> ";
			cin >> play;

			if (play >= 0 && play <= 9)    break;

			cout << "�͈͊O�ł��@�ē��͂��ĉ�����" << endl;
		} while (1);

		gameP->hit(play);
		break;
	}

	delete gameP;
	return 0;
}
