#include <cstdio>
struct Component
{
	public:
		void Update();
		void Tick();
		void Draw();
};

void Component::Update()
{
	printf("what is up");
}

void Component::Draw()
{

}
