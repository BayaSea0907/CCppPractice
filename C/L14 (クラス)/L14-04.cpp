/*
�ۑ�ԍ��@�FL14-4
���e�@�@�@�F�~circle�I�u�W�F�N�g�ɔ��a�idouble�^�j��ݒ肵����A���a�Ɩʐς��v�Z����B
�@�@�@�@�@�@�������A���a�̓��́A���a�Ɩʐς̕\����main�֐��ōs���B
�@�@�@�@�@�@�܂��A���a�Ɩʐς�circle�I�u�W�F�N�g�̂��ꂼ��̃��\�b�h�Ōv�Z���āA
�@�@�@�@�@�@�����ǃC���X�^���X�ϐ��i�I�u�W�F�N�g�Ɋi�[�j�Ɋi�[������̂Ƃ���B
�@�@�@�@�@�@�~������3.1415926
�t�@�C�����FL14-04.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��cicle�I�u�W�F�N�g�̌v�Z���\�b�h���Ăяo�����Ƃɂ���āAcircle�I�u�W�F�N�g���v�Z�����邱�Ƃ�
//�@�m�F���Ȃ����B
//A.�m�F���܂����B�N���XCircle�̌v�Z���\�b�h�̒��̐��l��ς���ƁA�������ς�����B

//��circle�I�u�W�F�N�g���߂��Ă��ꂽ���a�Ɩʐς�\�����Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B�v�Z���\�b�h�̒��ŋ��߂��l���C���X�^���X�ϐ��Ɋi�[���āA�擾���\�b�h�ŃC���X�^���X�ϐ������^�[�����ĕ\�����Ă���B

#include <conio.h>
#include <iostream>
using namespace std;

//�~�N���X��`
class Circle {

    double radius;		//���a
    double diameter; 	//���a
    double area; 		//�ʐ�

public:

    //���a�ݒ胁�\�b�h�@sradius�F���a����p
    void setRadius(double sradius){
	    radius = sradius;
    }

    //���a�v�Z���\�b�h
    void calcDiameter(){
        diameter = radius * 2;
    }

    //�ʐόv�Z���\�b�h
    void calcArea(){
        area = radius * radius * 3.1415926;
    }

    //���a�擾���\�b�h
    double getDiameter(){
		return diameter;
    }

    //�ʐώ擾���\�b�h
    double getArea(){
        return area;
    }
};
//////////////////////////////////////////////////////
int main()
{
    Circle circle;				//�~�I�u�W�F�N�g�錾
    double radius;				//���͗p

    cout << "���a�������l�œ��́i��@10.5�j>> ";
    cin >> radius;

	circle.setRadius(radius);	//���a�ݒ�
    circle.calcDiameter();	    //���a�v�Z
 
	circle.calcArea();			//�ʐόv�Z

	cout << "���a=" << circle.getDiameter() << " �ʐ�=" << circle.getArea() << endl;

    _getch();
    return 0;
}
