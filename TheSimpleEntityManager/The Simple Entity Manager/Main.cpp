#include <iostream>
#include <string>

class Entity
{
protected:
	float x;
	float y;

public:
	Entity(float x, float y)
		: x(x), y(y)
	{
	}

	virtual ~Entity()
	{
	}

	void Move(float xa, float ya)
	{
		x += xa;
		y += ya;
	}

	virtual std::string GetName() const = 0;
};

class Player : public Entity
{
public:
	Player(float x, float y)
		:Entity(x, y)
	{
	}

	std::string GetName() const override
	{
		return "Player";
	}
};

class Enemy : public Entity
{
public:
	Enemy(float x, float y)
		:Entity(x, y)
	{
	}

	std::string GetName() const override
	{
		return "Enemy";
	}
};

void PrintEntityName(const Entity& entity)
{
	std::string name = entity.GetName();
	std::cout << name << std::endl;
}

int main()
{
	Player* player = new Player(0.0f, 0.0f);
	Enemy* enemy = new Enemy(0.0f, 0.0f);
	PrintEntityName(*player);
	PrintEntityName(*enemy);
	delete player;
	delete enemy;
	std::cin.get();
}