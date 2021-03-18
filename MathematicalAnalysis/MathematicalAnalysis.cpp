#include <iostream>
#include <vector>
#include <algorithm>>
#include <assert.h>

void BelongsTo();
void ContainedIn();

int main()
{
	BelongsTo();
	ContainedIn();
}

void BelongsTo()
{
	std::vector<int> A = { 1, 2, 3 };
	int a1 = 2, a2 = 4;

	struct Contains
	{
		const int a;
		Contains(int _a) : a(_a) {}

		bool operator()(int _a) const { return this->a == _a; }
	};

	bool a1BelongsToA = std::any_of(A.cbegin(), A.cend(), Contains(a1));
	bool a2BelongsToA = std::any_of(A.cbegin(), A.cend(), Contains(a2));

	assert(a1BelongsToA);
	assert(!a2BelongsToA);
}

void ContainedIn()
{
	std::vector<int> A = { 1, 2, 3 };
	std::vector<int> B = { 1, 2 };

	struct Contains
	{
		const int a;
		Contains(int _a) : a(_a) {}

		bool operator()(int _a) const { return this->a == _a; }
	};

	bool BisContainedInA = std::all_of(B.cbegin(), B.cend(), [A](int b) {
		return std::any_of(A.cbegin(), A.cend(), Contains(b)); });

	bool AisContainedInB = std::all_of(A.cbegin(), A.cend(), [B](int a) {
		return std::any_of(B.cbegin(), B.cend(), Contains(a)); });

	assert(BisContainedInA);
	assert(!AisContainedInB);
}