#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(600, 600), "SFML Stars");
	Clock clock;
	// массив прямоугольников
	const int size = 150;
	RectangleShape* stars = new RectangleShape[size];
	
	
	while (clock.getElapsedTime().asMilliseconds() < 5000)
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		for (int i = 0; i < size; i++) {
			//вычисляем координаты начала линии-прямоугольника
			float x = rand() % 600;
			float y = rand() % 600;

			//создаем прямоугольник длиной 450 и толщиной 1
			RectangleShape star(Vector2f(1.f, 1.f));
			//перемещаем в начало
			star.move(x, y);
			//поворачиваем на нужный угол
			star.rotate((float)(atan2(y - 300, x - 300) * 180 / 3.1416f));
			//записываем в массив
			stars[i] = star;
			window.draw(stars[i]);
		}
		window.display();

		while (clock.getElapsedTime().asMilliseconds() < 1000) {}

		for (int i = 0; i < size; i++) {
			float len = rand() % 200 + 10;
			stars[i].setSize(Vector2f(len, 1.f));
		}
		// Отрисовка окна
		window.clear();
		//рисуем массив линий
		for (int i = 0; i < size; i++) {
			float dx = 0.1 * cos(atan2(stars[i].getPosition().y - 300, stars[i].getPosition().x - 300));
			float dy =0.1 * sin(atan2(stars[i].getPosition().y - 300, stars[i].getPosition().x - 300));
			stars[i].move(dx, dy);
			window.draw(stars[i]);
		}
		window.display();
	}
	return 0;
}