/*
�ۑ�ԍ��@�FL16-DeluxeSpecial2
���e�@�@�@�F�J�����_�[calendar�I�u�W�F�N�g�ŁA2015�N�W���̃J�����_�[��\������B
�@�@�@�@�@�@�����͂S���ŕ\������B
�@�@�@�@�@�@�A���Abreak�����g���Ă��悢�B
�@�@�@�@�@�@�܂��A���̂悤�ȗj���p�񋓌^���`����ƁA���Ȃ�ėp�I�Ȃ��̂ƂȂ�B
�t�@�C�����FL16-DX2.cpp
�쐬���@�@�F2015/11/22
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//�j���p�񋓌^
enum YOUBI
{
	Sun,
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat
};

//�J�����_�[�N���X��`
class Calendar {
    int maxDay = 31;	    //�W���ő�����i31���j
    int day = 1;	        //���t�i�����͂P���j
    YOUBI youbi = Sat;	    //�W�����߃J�����_�[�J�n�j���i�y�j���ݒ�j
			                //�iSat�̒l�𕡐���g�p���Ă��邽��youbi�ϐ��Ɋi�[�j
public:
    //�J�����_�[�\�����\�b�h
    void showCalendar()
	{
        int week;		//�T��

		week								//�������T���邩�����߂�

		cout << "  ��  ��  ��  ��  ��  ��  �y" << endl;

	    //�T����@i�F�T����p���[�v�J�E���^
		for(                        )
		{
			int j;		//�j������p���[�v�J�E���^

		    //��P�T�̌����߂܂ł̐���
			if(                 )
			{
		        //�����܂ł̋󔒕\���ƌ����i��P�T�j�̃J�����_�[�J�n�j���擾
		        for(                       )
				{
		                cout << setw(4) << ' ';
		        }
		    }
		    //��Q�T�̃J�����_�[�J�n�j���擾
			else
			{
				     = Sun;      //�J�����_�[�J�n�j���i���j���j�ݒ�
		    }

			//�T�P�ʂ̓��t�\��
			for(    ;          ;      )
			{
				//�����܂ł̓��t�\��
				if(                  )
				{
					cout << setw(4) << day;
		  			
		 		}
				else
				{
		 		 	
		 		}
			}
		 	cout << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Calendar calendar;			//�J�����_�[�I�u�W�F�N�g�錾

	calendar.showCalendar();	//�J�����_�[�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}
