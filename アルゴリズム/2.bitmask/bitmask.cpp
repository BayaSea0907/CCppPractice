/*------------------------------------------------------------------------
|�ۑ�2 bitmask
| unsigned int�^��32bit�ϐ��̓��e��2�i���ŕ\������v���O���������B
| �������A�����Ƃ��āA�}�X�N�f�[�^���g���r�b�g���Z��2�i����\������B
|
|	2016/5/16	BayaSea
--------------------------------------------------------------------------*/
#include <iostream>

#define DATELENGTH 32

using namespace std;

int main()
{
	unsigned int maskDate;
	unsigned int souceDate = 1;
	unsigned int variable;

	cout << "0�`4, 294, 967, 295�܂ł̒l����͂��Ă������� >> ";
	cin >> variable;

	//2�i���\��
	for (int i = 0; i < DATELENGTH; i++) {
		maskDate = souceDate << (DATELENGTH - (i + 1));

		(variable & maskDate) ? cout << 1 : cout << 0;

		if ((i + 1) % 4 == 0)	cout << " ";
	}

	system("pause");
	return 0;
}