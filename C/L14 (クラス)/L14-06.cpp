/*
�ۑ�ԍ��@�FL14-6
���e�@�@�@�F�lman�I�u�W�F�N�g�ɐg���Ƒ̏d��ݒ肵����ABMI���v�Z����B
�@�@�@�@�@�@�������A�g���Ƒ̏d�̓��́ABMI�̕\����main�֐��ōs���B
�@�@�@�@�@�@�܂��Aman�I�u�W�F�N�g�Ōv�Z����BMI�́A�I�u�W�F�N�g�Ɋi�[���Ȃ���main�֐��ɖ߂����̂Ƃ���B
�t�@�C�����FL14-06.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//���Ăяo�������\�b�h�Ōv�Z�����l�iBMI�j�����̂܂ܖ߂��āAmain�֐��ŕ\�����Ă��邱�Ƃ��m�F����
//�@�����B
//�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {

    double height;						//�g���i���j
    double weight;						//�̏d�i�s�j

public:

    //�g���E�̏d�i�[���\�b�h
    void setVar(double sheight, double sweight){

	    height = sheight;
	    weight = sweight;
    }

    //BMI�擾���\�b�h
    double getBmi(){

		double bmi; 					//�얞�x�i�[�p

		bmi = weight / (height * height );
		return bmi;
    }

	/*�v�Z���ʂ�ϐ��Ɋi�[���邱�ƂȂ��A���̂܂ܒ��ږ߂����Ƃ��ł���
    //BMI�擾���\�b�h
        double getBmi(){
        return weight / (height * height);
    }
    */
};


//////////////////////////////////////////////////////


int main()
{
		
    Man man;											//�l�I�u�W�F�N�g�錾
    double height;										//�g���i���j���͗p
    double weight;										//�̏d�i�s�j���͗p

    cout << "�g������́i��@175cm�̏ꍇ�@1.75�j>> ";
    cin >> height;
    cout << "�̏d����́i��@70.5kg�̏ꍇ�@70.5�j>> ";
    cin >> weight;

	man.setVar(height,weight);							//�g���E�̏d�̐ݒ�

    cout << "�a�l�h=" << man.getBmi() << endl;			//BMI�\��

    _getch();
    return 0;
}
