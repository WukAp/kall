#include <SFML/Graphics.hpp>			//для графических фигур
#include <iostream> 				// для cin
#include <conio.h> 				// для _getch
#include <windows.h>				// для SetConsoleCP()

int main()
{
	int CircleR;
	SetConsoleCP(1251);			// разрешить русский текст в потоке ввода
	SetConsoleOutputCP(1251);		// разрешить русский текст в потоке вывода
	puts("Введите радиус круга в пикселях (1-100):");
	std::cin >> CircleR;
	sf::RenderWindow window(sf::VideoMode(640, 480), L"Простые фигуры"); // создаем окно 640х480

	//рисование точки (одного пикселя):
	sf::VertexArray point(sf::Points, 1 /*количество точек*/);	//создаем массив из 1 точки 
	point[0].position = sf::Vector2f(100, 100);	//позиция точки: X,Y
	point[0].color = sf::Color::Red;	//цвет точки

	//рисование линии:
	sf::VertexArray line(sf::Lines, 2 /*количество точек*/);	//создаем массив из двух точек

	line[0].position = sf::Vector2f(10, 10);	//позиция начала линии: X,Y
	line[1].position = sf::Vector2f(90, 90);	//позиция конца линии: X,Y
	line[0].color = sf::Color::White;		//цвет начала линии
	line[1].color = sf::Color::White;		//цвет конца линии 

	//рисование круга
	sf::CircleShape сircle(CircleR);		//создаем круг заданного радиуса
	сircle.setPosition(110, 110);		//позиция верхнего левого угла фигуры 
						//(описывающего фигуру прямоугольника)
	сircle.setFillColor(sf::Color::Yellow);	//цвет круга

	window.clear();			//очистка окна
	window.draw(point);		//вывод точки в буфер
	window.draw(line);		//вывод линии в буфер
	window.draw(сircle);		//вывод круга в буфер 

	window.display();		//буфер отображается на экране
	_getch();			//ожидание нажатия клавиши в текстовом окне
	return 0;
	//jopa1
}
