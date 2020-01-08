//Strategy（normal）
//ある処理のアルゴリズムを一塊の戦略単位オブジェクトとして考え、必要に応じて戦略単位で交換する
//アルゴリズムをif文などで分岐させる代わりに、戦略単位オブジェクトで交換するので
//交換や他の戦略の追加が簡単に行える

//【プログラム】バブルソート戦略、クイックソート戦略のいずれかを戦略オブジェクトとして選択する
//共通戦略interfaceを定義し、派生クラスとしてそれぞれの戦略クラスを定義する
//そのほかに、選択した戦略オブジェクトを管理するクラス（SortOperation）を定義する
//そして、このSortOperationオブジェクトで管理している選択した戦略オブジェクトのソート処理を行う
//戦略オブジェクト単位でアルゴリズムを切り替えられるので、柔軟でメンテナンスしやすい設計となる
//
//Strategy00(normal).cpp
//結果
//バブルソート
//クイックソート

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Strategy定義----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//ソート戦略interfaceクラス定義（抽象クラス定義）
class ISortStrategy {
public:
	virtual void sort(vector<int> vIntData) = 0;
};

//////////////////////////////////////////////////////////////////
//バブルソートクラス定義
class BubbleSortStrategy : public ISortStrategy {
public:
	void sort(vector<int> vIntData)
	{
		cout << "バブルソート" << endl;
	}
};
//----------------------------------------------------------------
//クイックソートクラス定義
class QuickSortStrategy : public ISortStrategy {
public:
	void sort(vector<int> vIntData)
	{
		cout << "クイックソート" << endl;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//ソート操作クラス定義
class SortOperation {
	ISortStrategy* sortStrategyP;	//選択実行するソート戦略オブジェクト管理ポインタ
	vector<int> vIntData;			//データ配列
public:
	SortOperation(ISortStrategy* ssortStrategyP):sortStrategyP(ssortStrategyP){}

	void setData(int data){ vIntData.push_back(data); }
	void sort(){ sortStrategyP->sort(vIntData); }

	~SortOperation()
	{
		vIntData.clear();		//vectorデータの消去
		delete sortStrategyP;	//戦略オブジェクトの解放
	}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	SortOperation* sort1P = new SortOperation(new BubbleSortStrategy());
	SortOperation* sort2P = new SortOperation(new QuickSortStrategy());

	//バブルソート戦略
	sort1P->setData(200);
	sort1P->setData(100);
	sort1P->setData(150);
	sort1P->sort();

	//クイックソート戦略
	sort2P->setData(400);
	sort2P->setData(300);
	sort2P->setData(200);
	sort2P->sort();

	delete sort1P;
	delete sort2P;

	return 0;
}
