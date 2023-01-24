/*
В этом задании вы усложните иерархию классов для усложнённой предметной области.
У вас появляется информация о длине сторон и углах ваших фигур,
а также несколько более конкретных фигур.Теперь в треугольнике вы должны
хранить информацию о длине всех его трёх сторон(a, b, c) и значениях
его трёх углов(A, B, C).В четырёхугольнике вы храните информацию о длине
его четырёх сторон(a, b, c, d) и значениях его четырёх углов(A, B, C, D).
Также у вас появляются более конкретные фигуры :

прямоугольный треугольник(угол C всегда равен 90);
равнобедренный треугольник(стороны a и c равны, углы A и C равны);
равносторонний треугольник(все стороны равны, все углы равны 60);
прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
квадрат(все стороны равны, все углы равны 90);
параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
ромб(все стороны равны, углы A, C и B, D попарно равны).
Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов,
но извне вы не должны быть способны изменить длины сторон и углы.

Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям.
Например, нельзя создать квадрат с разными углами.Геометрические соотношения проверять
не нужно.Например, сумма углов в треугольнике может быть не равна 180.
Задача: спроектировать и реализовать классы, описывающие предметную область.
Продемонстрируйте их работу : создайте по одному экземпляру каждой фигуры
и выведите на экран информацию о длинах её сторон и величине её углов.
Значения используйте произвольные.
Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова
базовых конструкторов.

Для вывода информации о фигуре создайте функцию print_info, которая будет
принимать в качестве аргумента указатель на базовый класс фигуры.
*/


#include <iostream>
#include <string>


/*
***************************************************************
***************************************************************
*/
// базовый класс треугольника
class Triangle
{
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	Triangle();
	void get_name();
	void get_sides();
	void get_angle();
protected:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
	std::string name;
};
Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	name = "Triangle:";
}
Triangle::Triangle()
{
	a = b = c = A = B = C = 0;
}
void Triangle::get_name()
{
	std::cout << name << "\n";
}
void Triangle::get_sides()
{
	std::cout << "Sides: " << "a = " << a << ", " << "b = " << b << ", " << "c = " << c << "\n";
}
void Triangle::get_angle()
{
	std::cout << "Angle: " << "A = " << A << ", " << "B = " << B << ", " << "C = " << C << "\n";
}

// Прямоугольный треугольник
class RTriagnle : public Triangle
{
public:
	RTriagnle(int a, int b, int c, int A, int B);
};
RTriagnle::RTriagnle(int a, int b, int c, int A, int B)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	C = 90;
	name = "Right triangle:";
}

// равнобедренный треугольник
class IStriangle : public Triangle
{
public:
	IStriangle(int a, int b, int A, int B);
};
IStriangle::IStriangle(int a, int b, int A, int B)
{
	this->a = a;
	this->c = a;
	this->b = b;
	this->A = A;
	this->C = A;
	this->B = B;
	name = "Isosceles triangle:";
}

//равносторенний треугольник
class EQtriangle : public Triangle
{
public:
	EQtriangle(int a);
};
EQtriangle::EQtriangle(int a)
{
	this->a = this->b = this->c = a;
	A = 60;
	B = 60;
	C = 60;
	name = "Equilateral triangle:";
}


/*
***************************************************************
***************************************************************
*/
// базовый класс четырехугольника
class Quadrilateral
{
public:
	Quadrilateral();
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
	void get_name();
	void get_sides();
	void get_angle();
protected:
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;
	std::string name;
};
Quadrilateral::Quadrilateral()
{
	a = b = c = d = A = B = C = D = 0;
}
Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	name = "Quadrilateral:";
}
void Quadrilateral::get_name()
{
	std::cout << name << "\n";
}
void Quadrilateral::get_sides()
{
	std::cout << "Sides: " << "a = " << a << ", " << "b = " << b << ", " << "c = "
		<< c << ", " << "d = " << d << "\n";
}
void Quadrilateral::get_angle()
{
	std::cout << "Angle: " << "A = " << A << ", " << "B = " << B << ", " << "C = "
		<< C << ", " << "D = " << D << "\n";
}

// Параллелограмм
class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int A, int B);
};
Parallelogram::Parallelogram(int a, int b, int A, int B)
{
	this->a = this->c = a;
	this->b = this->d = b;
	this->A = this->C = A;
	this->B = this->D = B;
	name = "Parallelogram:";
}

// Прямоугольник 
class Rectangle : public Parallelogram
{
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90)
	{
		name = "Rectangle:";
	}
};

// Ромб
class Rhomb : public Parallelogram
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		name = "Rhomb:";
	}
};

// Квадрат
class Square : public Rectangle
{
public:
	Square(int a) : Rectangle(a, a)
	{
		name = "Square:";
	}
};


Triangle triangle(10, 20, 30, 50, 60, 70);
RTriagnle Rtriangle(10, 20, 30, 50, 60);
IStriangle Istriangle(10, 20, 50, 60);
EQtriangle Eqtriangle(30);

Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
Parallelogram parallelogram(20, 30, 30, 40);
Rectangle rectangle(10, 20);
Rhomb rhomb(30,		30, 40);
Square square(20);

int main()
{
	triangle.get_name();
	triangle.get_sides();
	triangle.get_angle();
	std::cout << "\n";

	Rtriangle.get_name();
	Rtriangle.get_sides();
	Rtriangle.get_angle();
	std::cout << "\n";

	Istriangle.get_name();
	Istriangle.get_sides();
	Istriangle.get_angle();
	std::cout << "\n";

	Eqtriangle.get_name();
	Eqtriangle.get_sides();
	Eqtriangle.get_angle();
	std::cout << "\n";

	quadrilateral.get_name();
	quadrilateral.get_sides();
	quadrilateral.get_angle();
	std::cout << "\n";

	parallelogram.get_name();
	parallelogram.get_sides();
	parallelogram.get_angle();
	std::cout << "\n";

	rectangle.get_name();
	rectangle.get_sides();
	rectangle.get_angle();
	std::cout << "\n";

	rhomb.get_name();
	rhomb.get_sides();
	rhomb.get_angle();
	std::cout << "\n";

	square.get_name();
	square.get_sides();
	square.get_angle();

	return 0;
}

