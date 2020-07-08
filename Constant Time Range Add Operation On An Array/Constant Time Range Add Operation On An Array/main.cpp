#include <iostream>
#include <vector>


/*
Majority of code is found here https://www.geeksforgeeks.org/constant-time-range-add-operation-array/

I have added a print largest func to find largest value in the array.
*/


#if 1
// Utility method to add value val, to range [lo, hi] 
void add(std::vector<int>& arr, int N, int low, int high, int value)
{
	arr[low] += value;
	if (high != N - 1)
		arr[high + 1] -= value;

}

// Utility method to get actual array from operation array 
void updateArray(std::vector<int>& arr, int N)
{
	// convert array into prefix sum array 
	for (int i = 1; i < N; i++)
		arr[i] += arr[i - 1];
}
int printLargest(std::vector<int>& arr, int N)
{
	int large = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > large) {
			large = arr[i];
		}
	}
	return large;

}

// method to print final updated array 
void printArr(std::vector<int>& arr, int N)
{
	updateArray(arr, N);
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << printLargest(arr, N);
}


// Driver code to test above methods 
int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> arr(N);
	std::cout << "Array looks like this: ";

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
	}
	std::cout << "\n";
	std::vector<int> total;
	for(int i = 0; i < M; i++)
	{
		int A, B, K;
		std::cin >> A >> B >> K;
		add(arr, N, (A-1), (B-1), K);
	}
	printArr(arr, N);
	return 0;
}
#endif