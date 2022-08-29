#include <vector>
#include <unordered_map>
#include "299.Bulls_and_Cows.cpp"
#include <string>
using namespace Solution299;
//string getHint(string secret, string guess) {
//
//	vector<int> secretArray(10, 0), guessArray(10, 0);
//	int aCount = 0, bCount = 0;
//
//	for (int index = 0; index < secret.size(); ++index) 
//	{
//		if (secret[index] == guess[index]) {
//			aCount++;
//		}
//		else {
//			secretArray[secret[index] - '0']++;
//			guessArray[guess[index] - '0']++;
//	    }
//    }
//
//	for (int index = 0; index < 10; ++index) {
//		bCount += min(secretArray[index], guessArray[index]);
//	}
//
//	return to_string(aCount) + "A" + to_string(bCount) + "B";
//}

int main()
{
	//string secret = "112344", guess = "011146";
	//string result = getHint(secret, guess);
	Solution299::Bulls_and_Cows useClass;
	Solution299::Bulls_and_Cows::Bulls_and_Cows_Model getTestModel = useClass.GetTestData001();
	string result = useClass.getHint(getTestModel.secret, getTestModel.guess);

	getTestModel = useClass.GetTestData002();
	result = useClass.getHint(getTestModel.secret, getTestModel.guess);
	return 0;
}
