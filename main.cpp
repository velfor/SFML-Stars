#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(600, 600), "SFML Stars");
	Clock clock;
	// ������ ���������������
	const int size = 150;
	RectangleShape* stars = new RectangleShape[size];
	
	
	while (clock.getElapsedTime().asMilliseconds() < 5000)
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		for (int i = 0; i < size; i++) {
			//��������� ���������� ������ �����-��������������
			float x = rand() % 600;
			float y = rand() % 600;

			//������� ������������� ������ 450 � �������� 1
			RectangleShape star(Vector2f(1.f, 1.f));
			//���������� � ������
			star.move(x, y);
			//������������ �� ������ ����
			star.rotate((float)(atan2(y - 300, x - 300) * 180 / 3.1416f));
			//���������� � ������
			stars[i] = star;
			window.draw(stars[i]);
		}
		window.display();

		while (clock.getElapsedTime().asMilliseconds() < 1000) {}

		for (int i = 0; i < size; i++) {
			float len = rand() % 200 + 10;
			stars[i].setSize(Vector2f(len, 1.f));
		}
		// ��������� ����
		window.clear();
		//������ ������ �����
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