/*
課題番号　：L23-12
内容　　　：healthオブジェクトに、５人分の検診構造体配列（要素数５）を格納して、身長は降順に、かつ
			身長が同じ場合には体重を昇順に並び替えて表示する。
			検診構造体のメンバは、名前と身長、体重。
			構造体配列はmain関数で初期化する。
			要素数はconst指定子を使って定義する。
			構造体配列のソート前とソート後の状態をhealthオブジェクトで表示する。
			表示は、オブジェクトで行う。
ファイル名：L23-B12.cpp
作成日　　：2015/11/26
作成者　　：BayaSea
*/

#include <iomanip>		//マニピュレータ用
#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//検診構造体の定義
struct Exam {
	string name;	//名前
	int tall;		//身長
	int weight;		//体重
};

const int MAX = 5;	//構造体配列要素数

//健康クラス定義
class Health {
	Exam exam[MAX];		//検診構造体配列
public:
	//検診設定　ex[]：検診構造体配列
	void setExam(Exam ex[])
	{
		for (int i = 0; i < MAX; i++)
		{
			exam[i] = ex[i];
		}
	}

	//検診ソート
	void sortExam()
	{
		Exam taihi;		//退避用構造体

		//ソートの2重ループ
		for (int i = 0; i < MAX - 1; i++)
		{
			for (int j = i + 1; j < MAX; j++)
			{
				//身長を降順に並び替え、身長が同じだった場合体重の昇順に並び替え
				if ((exam[i].tall < exam[j].tall) || 
					((exam[i].tall == exam[j].tall) && (exam[i].weight > exam[j].weight))) 
				{
					taihi = exam[i];
					exam[i] = exam[j];
					exam[j] = taihi;
				}
			}
		}
	}

	//検診表示
	void show()
	{
		for (int i = 0; i < MAX; i++){
			cout << "[" << i << "]" << setw(10) << left << exam[i].name << setw(4) << right << exam[i].tall << "cm " << setw(4) << exam[i].weight << "kg" << endl;
		}
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Health health;		//healthオブジェクト

	//検診構造体配列宣言
	Exam exam[MAX] = {
		{ "GUNMO", 160, 80 },
		{ "BERZEB",80, 30 },
		{ "HARY", 170, 70 },
		{ "TRINITY", 160, 50 },
		{ "ROBO", 170, 90 }
	};

	health.setExam(exam);		//検診設定メソッド呼び出し
	health.show(); 				//ソート前（検診表示）メソッド呼び出し
	cout << endl;				//見やすくする改行

	health.sortExam();			//ソートメソッド呼び出し
	health.show(); 				//ソート後（検診表示）メソッド呼び出し

	_getch();
	return 0;
}
