/*
�ۑ�ԍ��@�FL14-5
���e�@�@�@�F��`daikei�I�u�W�F�N�g�ɏ�ӁA��ӁA�����idouble�^�j��ݒ肵����A�ʐς��v�Z����B
�@�@�@�@�@�@�������A��ӁA��ӁA�����̓��́A�ʐϕ\����main�֐��ōs���B
�@�@�@�@�@�@�܂��A�ʐόv�Z��daikei�I�u�W�F�N�g�̃��\�b�h�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-05.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//��`�N���X��`
class Daikei {

	double jouhen;		//���
	double teihen;		//���
	double takasa;		//����
	double area;		//�ʐ�

public:

	//��ӁE��ӁE�����ݒ�p���\�b�h
	void setVar(double sjouhen, double steihen, double stakasa)
	{
		jouhen = sjouhen;
		teihen = steihen;
		takasa = stakasa;
	}

	//�ʐόv�Z���\�b�h
	void calcArea()
	{
		area = (jouhen + teihen) * takasa / 2;
    }

	//�ʐώ擾���\�b�h
	double getArea()
	{ 
		return area;
	}
};


////////////////////////////////////////////////////////////////


int main()
{

	Daikei daikei;		//��`�I�u�W�F�N�g�錾
	double jouhen;		//��ӓ��͗p
	double teihen;		//��ӓ��͗p
	double takasa;		//�������͗p

	cout << "��Ӂ@��Ӂ@��������́i��@3.5 11.5 10.0�j>> ";
	cin >> jouhen >> teihen >> takasa;

	//��ӁE��ӁE�����ݒ�
	daikei.setVar(jouhen, teihen, takasa);

	daikei.calcArea();	//�ʐόv�Z

	//�ʐϕ\��
	cout << "�ʐ�=" << daikei.getArea() << endl;

	_getch();
	return 0;
}
