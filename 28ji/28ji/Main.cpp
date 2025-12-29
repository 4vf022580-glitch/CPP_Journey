#include <iostream>
#include <string>

class Entity
{
public:
    std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    // 构造函数：使用初始化列表给 m_Name 赋值
    Player(const std::string& name)
        : m_Name(name) {
    }

    // 子类虽然重写了这个函数，但父类没允许（没写virtual），所以没用
    std::string GetName() { return m_Name; }
};

int main()
{
    // 1. 正常的父类对象
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl; // 输出: Entity

    // 2. 正常的子类对象
    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl; // 输出: Cherno

    // 3. 【陷阱】父类指针指向子类对象
    Entity* entity = p;
    // 因为 Entity::GetName 不是虚函数，编译器只看 entity 的类型(Entity*)
    std::cout << entity->GetName() << std::endl; 

    std::cin.get();
}