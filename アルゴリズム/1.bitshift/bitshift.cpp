//------------------------------------------------------------------------------
//課題1　bitshift
// unsigned int型の32bit変数の内容を2進数で表示するプログラムを作る。ただし、
// 条件として、ビットシフトを使って2進数を表示する。表示するための値は、キー入力する。
//
//	2016/5/2	BayaSea
//------------------------------------------------------------------------------

#include <iostream>

#define DATELENGTH 32
#define MYDEBUG 0

int main(int argc, const char * argv[]) {
	//変数宣言
	unsigned int variable,tmp;
	int binary[DATELENGTH];
	int i;

	//値のキー入力
	std::cout << "2進表示する値 >>";
#if MYDEBUG
	std::cin >> std::hex >> variable;
#else
	std::cin >> variable;
#endif

	std::cout << "BitLength " << sizeof(unsigned int) << std::endl;
	//2進数変換？

	for (i = 0; i < DATELENGTH; i++) {
		tmp = variable >> i;
		tmp = tmp << (DATELENGTH - 1);
		tmp ? (binary[i] = 1) : (binary[i] = 0);
	}

	//表示
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