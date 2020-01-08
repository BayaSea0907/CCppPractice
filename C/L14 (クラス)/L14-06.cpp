/*
課題番号　：L14-6
内容　　　：人manオブジェクトに身長と体重を設定した後、BMIを計算する。
　　　　　　ただし、身長と体重の入力、BMIの表示はmain関数で行う。
　　　　　　また、manオブジェクトで計算したBMIは、オブジェクトに格納しないでmain関数に戻すものとする。
ファイル名：L14-06.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□呼び出したメソッドで計算した値（BMI）をそのまま戻して、main関数で表示していることを確認しな
//　さい。
//確認しました。

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {

    double height;						//身長（ｍ）
    double weight;						//体重（㎏）

public:

    //身長・体重格納メソッド
    void setVar(double sheight, double sweight){

	    height = sheight;
	    weight = sweight;
    }

    //BMI取得メソッド
    double getBmi(){

		double bmi; 					//肥満度格納用

		bmi = weight / (height * height );
		return bmi;
    }

	/*計算結果を変数に格納することなく、そのまま直接戻すこともできる
    //BMI取得メソッド
        double getBmi(){
        return weight / (height * height);
    }
    */
};


//////////////////////////////////////////////////////


int main()
{
		
    Man man;											//人オブジェクト宣言
    double height;										//身長（ｍ）入力用
    double weight;										//体重（㎏）入力用

    cout << "身長を入力（例　175cmの場合　1.75）>> ";
    cin >> height;
    cout << "体重を入力（例　70.5kgの場合　70.5）>> ";
    cin >> weight;

	man.setVar(height,weight);							//身長・体重の設定

    cout << "ＢＭＩ=" << man.getBmi() << endl;			//BMI表示

    _getch();
    return 0;
}
