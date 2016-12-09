// For this challenge you will be determining the smallest combination of coins for a given output
// have the function CoinDeterminer(num) take the input, which will be an integer ranging from 1 to 250, and return an integer output that will specify the least number of coins, that when added, equal the input integer. Coins are based on a system as follows: there are coins representing the integers 1, 5, 7, 9, and 11. So for example: if num is 16, then the output should be 2 because you can achieve the number 16 with the coins 9 and 7. If num is 25, then the output should be 3 because you can achieve 25 with either 11, 9, and 5 coins or with 9, 9, and 7 coins. 

#include <iostream>
#include <string>
using namespace std;

const int coins[] = { 1, 5, 7, 9, 11 }; // Constant int array representing the list of coin values
int CoinDeterminer(int num) {
	int index;
	// Check if num is one of the coin values
	for (int x = 0; x < 5; x++)
	{
		if (num == coins[x])
		{
			return 1;
		}
	}

	int total = 0;
	int temp = num;
	int count = 0;
	while (total != num)
	{
		// Analyzing the range of the coin value based on the difference
		// Example if number is 200, is best to use high coin value such as 11
		// On the other hand if number is 8 is best to start at 7.
		if (temp <= 4)
		{
			index = 0;
		}
		else if (temp <= 6)
		{
			index = 1;
		}
		else if (temp <= 12)
		{
			index = 2;
		}
		else if (temp <= 16)
		{
			index = 3;
		}
		else
		{
			index = 4;
		}

		// Begin adding up the combinations
		// It will start with the closet highest number to the target 
		// From there it will either stay the same or decrease
		count++;
		total += coins[index];
		temp = num - total;

		// Check if the difference is one of the coin values
		for (int y = 0; y < 5; y++)
		{
			if (temp == coins[y])
			{
				return count + 1;
			}
		}
	}
}

int main() {

	// keep this function call here
	cout << CoinDeterminer(6) << endl; // 2
	cout << CoinDeterminer(16) << endl; // 2
	cout << CoinDeterminer(25) << endl; // 3
	cout << CoinDeterminer(26) << endl; // 4
	cout << CoinDeterminer(5) << endl; // 1
	cout << CoinDeterminer(40) << endl; // 4
	cout << CoinDeterminer(4) << endl; // 4
	cout << CoinDeterminer(14) << endl; // 2
	return 0;

}