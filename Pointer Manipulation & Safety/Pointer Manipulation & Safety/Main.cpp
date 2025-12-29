#include <iostream>

void TakeDamage(int* pHealth, int* pScore, int damage)
{
	if (pHealth == nullptr || pScore == nullptr)
		return;

	*pHealth -= damage;
	if (*pHealth <= 0)
	{
		*pHealth = 0;
		*pScore -= 50;
		if (*pScore < 0)
		{
			*pScore = 0;
			return;
		}
	}
}

int main()
{
	int health = 100;
	int score = 100;
	TakeDamage(&health, &score, 20);
	std::cout << "Health:" << health << "  Score:" << score << std::endl;
	TakeDamage(&health, &score, 90);
	std::cout << "Health:" << health << "  Score:" << score << std::endl;
	TakeDamage(nullptr, &score, 90);
	std::cout << "Tried nullptr call" << std::endl;
	std::cin.get();
}