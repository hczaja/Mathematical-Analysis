#include "Introduction.h"

int main()
{
	std::vector<int> A = { 1, 2, 3 };
	std::vector<int> B = { 1, 2 };

	int a1 = 2;
	int a2 = 4;

	std::cout << "a1 belongs to A: " << BelongsTo(a1, A) << std::endl;
	std::cout << "a2 belongs to A: " << BelongsTo(a2, A) << std::endl;
	std::cout << "B is contained in A: " << IsContainedIn(B, A) << std::endl;
	std::cout << "A is contained in B: " << IsContainedIn(A, B) << std::endl;
}