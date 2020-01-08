//------------------------------------------------------------------------------
//�ۑ�1�@bitshift
// unsigned int�^��32bit�ϐ��̓��e��2�i���ŕ\������v���O���������B�������A
// �����Ƃ��āA�r�b�g�V�t�g���g����2�i����\������B�\�����邽�߂̒l�́A�L�[���͂���B
//
//	2016/5/2	BayaSea
//------------------------------------------------------------------------------

#include <iostream>

#define DATELENGTH 32
#define MYDEBUG 0

int main(int argc, const char * argv[]) {
	//�ϐ��錾
	unsigned int variable,tmp;
	int binary[DATELENGTH];
	int i;

	//�l�̃L�[����
	std::cout << "2�i�\������l >>";
#if MYDEBUG
	std::cin >> std::hex >> variable;
#else
	std::cin >> variable;
#endif

	std::cout << "BitLength " << sizeof(unsigned int) << std::endl;
	//2�i���ϊ��H

	for (i = 0; i < DATELENGTH; i++) {
		tmp = variable >> i;
		tmp = tmp << (DATELENGTH - 1);
		tmp ? (binary[i] = 1) : (binary[i] = 0);
	}

	//�\��
	for (i = DATELENGTH - 1; i >= 0; --i) {
		std::cout << binary[i];
		if ((i % 4) == 0) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}