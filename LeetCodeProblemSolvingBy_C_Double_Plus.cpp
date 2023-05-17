#include "Easy/0190.Reverse_Bits.cpp"
using namespace Solution190;
using namespace std;

int main()
{
	Solution190::Reverse_Bits useClass;
	Solution190::Reverse_Bits::Reverse_Bits_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.reverseBits(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.reverseBits(getTestModel.n);
	return 0;
}