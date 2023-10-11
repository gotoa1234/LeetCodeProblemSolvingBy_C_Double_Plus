#include "Easy\0605.Can_Place_Flowers.cpp"
using namespace Solution605;

int main()
{
	Solution605::Can_Place_Flowers useClass;
	Solution605::Can_Place_Flowers::Can_Place_Flowers_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.canPlaceFlowers(getTestModel.flowerbed, getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.canPlaceFlowers(getTestModel.flowerbed, getTestModel.n);
}