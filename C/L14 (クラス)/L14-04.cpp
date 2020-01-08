/*
課題番号　：L14-4
内容　　　：円circleオブジェクトに半径（double型）を設定した後、直径と面積を計算する。
　　　　　　ただし、半径の入力、直径と面積の表示はmain関数で行う。
　　　　　　また、直径と面積はcircleオブジェクトのそれぞれのメソッドで計算して、
　　　　　　いちどインスタンス変数（オブジェクトに格納）に格納するものとする。
　　　　　　円周率は3.1415926
ファイル名：L14-04.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

//実行時に確認すること：
//□cicleオブジェクトの計算メソッドを呼び出すことによって、circleオブジェクトが計算しいることを
//　確認しなさい。
//A.確認しました。クラスCircleの計算メソッドの中の数値を変えると、答えが変わった。

//□circleオブジェクトが戻してくれた直径と面積を表示していることを確認しなさい。
//A.確認しました。計算メソッドの中で求めた値をインスタンス変数に格納して、取得メソッドでインスタンス変数をリターンして表示している。

#include <conio.h>
#include <iostream>
using namespace std;

//円クラス定義
class Circle {

    double radius;		//半径
    double diameter; 	//直径
    double area; 		//面積

public:

    //半径設定メソッド　sradius：半径受取り用
    void setRadius(double sradius){
	    radius = sradius;
    }

    //直径計算メソッド
    void calcDiameter(){
        diameter = radius * 2;
    }

    //面積計算メソッド
    void calcArea(){
        area = radius * radius * 3.1415926;
    }

    //直径取得メソッド
    double getDiameter(){
		return diameter;
    }

    //面積取得メソッド
    double getArea(){
        return area;
    }
};
//////////////////////////////////////////////////////
int main()
{
    Circle circle;				//円オブジェクト宣言
    double radius;				//入力用

    cout << "半径を実数値で入力（例　10.5）>> ";
    cin >> radius;

	circle.setRadius(radius);	//半径設定
    circle.calcDiameter();	    //直径計算
 
	circle.calcArea();			//面積計算

	cout << "直径=" << circle.getDiameter() << " 面積=" << circle.getArea() << endl;

    _getch();
    return 0;
}
