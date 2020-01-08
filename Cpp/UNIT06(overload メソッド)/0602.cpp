#include <iostream>
using namespace std;

int main() {
	cout << "問題06-02"																					<< endl;
	cout << " 問題06-01の関数引数の初期化を使ったコンストラクタを書き加えた場合、"						<< endl
		 << " ３つのコンストラクタを書き並べて定義できませんが、その理由を述べなさい。"					<< endl
		 << " また、コンストラクタ①と③、②と③をそれぞれ併記した場合には、どうなりますか？"			<< endl << endl
	 	 << "A.①と③"																					<< endl
		 << " Hero() と Hero(int sh = 0) が引数無しでも実行されるコンストラクタなので、"				<< endl
		 << " 引数を渡さないとエラーが起こる。"															<< endl << endl
		 << "A.②と③"																					<< endl
		 << " 引数が有る場合では、Hero(int ch) と Hero(int ch = 0) が実行されるので、"					<< endl
		 << " エラーが起こる。"																			<< endl << endl;
			
	system("pause");
	return 0;
}