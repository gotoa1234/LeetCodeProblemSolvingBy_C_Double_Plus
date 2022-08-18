#include "0205.Isomorphic_Strings.cpp"
using namespace Solution205;
using namespace std;


int main()
{

	Solution205::Isomorphic_Strings useClass;
	Solution205::Isomorphic_Strings::Isomorphic_Strings_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isIsomorphic(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData002();
	result = useClass.isIsomorphic(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData003();
	result = useClass.isIsomorphic(getTestModel.s, getTestModel.t);
	return 0;
}
