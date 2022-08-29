#include <vector>
#include <unordered_map>
#include "0424.Longest_Repeating_Character_Replacement.cpp"
#include <string>
using namespace Solution424;
string getHint(string secret, string guess) {
	unordered_map<char, int> hashMap;
	for (int index = 0; index < secret.size(); index++)
	{
		hashMap[secret[index]]++;
	}

	int countA = 0;
	int countB = 0;
	for (int index = 0; index < guess.size(); index++)
	{
		if (hashMap.find(guess[index]) != hashMap.end())
		{
			//相同+A
			if (guess[index] == secret[index])
			{
				countA++;
				if (hashMap[guess[index]] > 0)
					hashMap[guess[index]]--;
				else
					countB--;
			}
			else//不相同+B
			{
				if (hashMap[guess[index]] > 0)
				{
					countB++;
					int a= hashMap[guess[index]];
					hashMap[guess[index]]--;
					int b = hashMap[guess[index]];
				}
			}
		}
	}
	return to_string(countA) + "A" + to_string(countB) + "B";
}

int main()
{
	string secret = "112344", guess = "011146";
	string result = getHint(secret, guess);
	/*std::string res;
	std::array<int, 10> fs{}, fg{};
	int b = 0, c = 0, n = secret.size();

	for (int i = 0; i < n; ++i) {
		if (secret[i] == guess[i]) {
			++b;
		}
		else {
			++fs[secret[i] - '0'];
			++fg[guess[i] - '0'];
		}
	}

	for (int i = 0; i < 10; ++i) {
		c += std::min(fs[i], fg[i]);
	}

	res += std::to_string(b);
	res.push_back('A');
	res += std::to_string(c);
	res.push_back('B');

	return res;*/
}
