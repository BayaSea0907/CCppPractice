/*--------------------------------------------------
|���03-05		BayaSea
----------------------------------------------------*/
#include <iostream>
using namespace std;

//�s���{���N���X��`
class Tokyo{
	int population = 13228912;
	double area = 2188.67;
public:
	//�l�����x�v�Z�擾
	int getCalcPopulationDensity() {
		return (int)((double) population / area);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Tokyo* tokyoP(new Tokyo);

	cout << "�l�����x="
	     << tokyoP->getCalcPopulationDensity() << endl;

	delete tokyoP;

	system("pause");
	return 0;
}
