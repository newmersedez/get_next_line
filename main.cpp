#include <iostream>

using namespace std;

class Shape
{
	public:
		int	cord_x = 123;
		int	cord_y = 145;
	
	public:
		virtual ~Shape() {};
		
		virtual Shape *clone() const = 0;
};

class Circle : public Shape
{
	private:
		int	radius;
	
	public:
	Circle(int a) : radius(a) {}
	Circle(const Circle &cr) : radius(cr.radius) {}
	~Circle() = default;

	Shape	*clone() const override
	{
		return new  Circle(*this);
	}
};

int main()
{
	Shape	*cr1 = new Circle(1);
	Shape	*cr2 = cr1->clone();
	Shape	*cr3 = new Circle(*(static_cast<Circle *>(cr1)));

	cout << "cr2 = " << cr2->cord_x << " " << cr2->cord_y << "\n";
	cout << "cr3 = " << cr3->cord_x << " " << cr3->cord_y << "\n";
	return (0);
}
