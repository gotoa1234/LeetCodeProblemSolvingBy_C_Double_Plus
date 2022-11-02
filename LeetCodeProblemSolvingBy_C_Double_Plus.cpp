#include "0048.Rotate_Image.cpp"
using namespace Solution48;
using namespace std;

int main()
{

	Solution48::Rotate_Image useClass;
	Solution48::Rotate_Image::Rotate_Image_Model getTestModel = useClass.GetTestData001();
	useClass.rotate(getTestModel.matrix);
	getTestModel = useClass.GetTestData002();
	useClass.rotate(getTestModel.matrix);
	return 0;
}