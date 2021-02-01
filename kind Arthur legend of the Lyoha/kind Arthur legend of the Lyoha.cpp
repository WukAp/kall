#include <SFML/Graphics.hpp>		
#include <iostream> 				
#include <conio.h> 				


using namespace sf;

RenderWindow window(VideoMode(640, 480), L"Рекурсия"); // создаем окно

// отрисовка круга
void circleDraw(int x, int y, int R) {
	
	CircleShape сircle(R);		//создание круга заданного радиуса
	сircle.setPosition(x, y);  
	сircle.setFillColor(Color(0, 0, 0, 0));	//цвет круга (прозрачный)
	сircle.setOutlineThickness(1.f);	//толщина окружности
	сircle.setOutlineColor(Color::Yellow);	//цвет окружности
	window.draw(сircle);		//вывод круга в буфер 
	
}

void recDraw(int x, int y, int R, int N) {
	 circleDraw(x, y, R); // отрисовка круга

	 // рекурсивный вызов при N>1
	 if (N > 1) {
		 R = (int)R / 2;
		recDraw(x+ R, y-R, R, N - 1);
		recDraw(x-R, y+R, R, N - 1);
		recDraw(x + R ,y+3*R, R, N - 1);
		recDraw(x+ 3 * R, y + R, R, N - 1);
	}
	
	
}

int main()
{
	int x,y,R,N;
	setlocale(LC_ALL, "Russian");

	//ввод данных
	puts("Введите координаты центра первой окружности:\n");
	std::cin >> x>>y;
	puts("Введите радиус круга в пикселях:\n");
	std::cin >> R;
	puts("Введите количество уровней рекурсии:\n");
	std::cin >> N;


	recDraw(x,y,R,N); // вызов рекурсивной отрисовки фигуры
	window.display();		//буфер отображается на экране
	_getch();
	return 0;
}
