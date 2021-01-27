#include <SFML/Graphics.hpp>			//для графических фигур
#include <iostream> 				// для cin
#include <conio.h> 				// для _getch
using namespace sf;
int main()
{
	int CircleR;
	setlocale(LC_ALL, "Russian");
	puts("Введите радиус круга в пикселях (1-100):");
	std::cin >> CircleR;
	RenderWindow window(VideoMode(640, 480), L"Простые фигуры"); // создаем окно 640х480

	//рисование точки (одного пикселя):
	VertexArray point(Points, 1 /*количество точек*/);	//создаем массив из 1 точки 
	point[0].position = Vector2f(100, 100);	//позиция точки: X,Y
	point[0].color = Color::Red;	//цвет точки

	//рисование линии:
	VertexArray line(Lines, 2 /*количество точек*/);	//создаем массив из двух точек

	line[0].position = Vector2f(10, 10);	//позиция начала линии: X,Y
	line[1].position = Vector2f(90, 90);	//позиция конца линии: X,Y
	line[0].color = Color::White;		//цвет начала линии
	line[1].color = Color::White;		//цвет конца линии 

	//рисование круга
	CircleShape сircle(CircleR);		//создаем круг заданного радиуса
	сircle.setPosition(110, 110);		//позиция верхнего левого угла фигуры 
						//(описывающего фигуру прямоугольника)
	сircle.setFillColor(Color::Yellow);	//цвет круга

	window.clear();			//очистка окна
	window.draw(point);		//вывод точки в буфер
	window.draw(line);		//вывод линии в буфер
	window.draw(сircle);		//вывод круга в буфер 

	window.display();		//буфер отображается на экране
	return 0;
}
