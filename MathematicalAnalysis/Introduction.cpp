#include "Introduction.h"

bool BelongsTo(int a, std::vector<int> A)
{
	struct Contains
	{
		const int a;
		Contains(int _a) : a(_a) {}

		bool operator()(int _a) const { return this->a == _a; }
	};

	bool aBelongsToA = std::any_of(A.cbegin(), A.cend(), Contains(a));
	return aBelongsToA;
}

bool IsContainedIn(std::vector<int> A, std::vector<int> B)
{
	struct Contains
	{
		const int a;
		Contains(int _a) : a(_a) {}

		bool operator()(int _a) const { return this->a == _a; }
	};

	bool AisContainedInB = std::all_of(A.cbegin(), A.cend(), [B](int a) {
		return std::any_of(B.cbegin(), B.cend(), Contains(a)); });

	return AisContainedInB;
}