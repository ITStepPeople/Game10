#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1200, 800), "SFML Works!"/*,Style::Fullscreen*/);
	Sprite spriteFon;
	Texture textureFon;
	textureFon.loadFromFile("resources\\Fon.jpg");
	spriteFon.setTexture(textureFon);

	spriteFon.setScale(0.3, 0.3);

	window.draw(spriteFon);
	window.display();
	Texture texture;
	Texture textureRev;
	texture.loadFromFile("resources\\Cat.png");
	textureRev.loadFromFile("resources\\CatRev.png");
	Sprite sprite;

	int x, y, x1, y1;
	x = 881, y = 999, x1 = 279, y1 = 201;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, x1, y1));//x,y,x,y
	sprite.setPosition(50, 625);//x,y
	sprite.setScale(0.7, 0.7);

	//spriteRev.setTexture(textureRev);
	//spriteRev.setTextureRect(IntRect(881, 999, 279, 201));//x,y,x,y
	//spriteRev.setPosition(50, 25);//x,y
	float CurrentFrame = 0;//хранит текущий кадр

	Clock clock;


	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		/*std::cout << time<< "\n";*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			sprite.setTexture(textureRev);
			int q;
			q = 199 * int(CurrentFrame);
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 12)CurrentFrame -= 12;
			x = 347, y = 0, x1 = 408, y1 = 199;
			sprite.setTextureRect(IntRect(x, y + q, x1, y1/**int(CurrentFrame)*/));
			std::cout << sprite.getRotation() << "\n";
			sprite.move(-0.20 * time, 0);
			spriteFon.move(0.05 * time, 0);
			/*sprite.setTexture(textureRev);
			sprite.move(-0.1*time, 0);
			sprite.setTextureRect(IntRect(347, 1007, 367, 170));*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			sprite.setTexture(texture);
			int q;
			q = 199 * int(CurrentFrame);
			CurrentFrame += 0.009 * time;
			x = 1183, y = 0, x1 = 436, y1 = 199;
			if (CurrentFrame > 12)CurrentFrame -= 12;
			sprite.setTextureRect(IntRect(x, y + q, x1, y1/**int(CurrentFrame)*/));
			sprite.move(0.20 * time, 0);
			spriteFon.move(-0.05 * time, 0);


			/*sprite.setTextureRect(IntRect(1183, 7, 436, 183));*/
			/*sprite.setTexture(texture);
			sprite.move(0.1 * time, 0);
			sprite.setTextureRect(IntRect(1183, 7, 436, 183));*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			int q;
			q = 199 * int(CurrentFrame);
			x = 825, y = 200, x1 = 355, y1 = 199;
			sprite.setTexture(texture);
			if (CurrentFrame > 6)CurrentFrame -= 6;
			sprite.setTextureRect(IntRect(x, y + q, x1, y1/**int(CurrentFrame)*/));
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.setTexture(texture);
			//sprite.move(0, 0.1/* * time*/);
			sprite.setTextureRect(IntRect(881, 999, 279, 201));
			sprite.setRotation(-25);
		}
		if (!Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.setRotation(0);
		}
		if ((!Keyboard::isKeyPressed(Keyboard::Right)) && (!Keyboard::isKeyPressed(Keyboard::Left)))
		{
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(881, 999, 279, 201));
		}
		window.clear(Color::White);
		window.draw(spriteFon);
		window.draw(sprite);


		window.display();
	}

	return 0;
}