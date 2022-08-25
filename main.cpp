#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1200,800), "SFML Works!"/*,Style::Fullscreen*/);
	//ddd
	Sprite spriteFon;
	Texture textureFon;
	textureFon.loadFromFile("resources\\Fon.jpg");
	spriteFon.setTexture(textureFon);

	spriteFon.setScale(0.3, 0.3);

	window.draw(spriteFon);
	window.display();
	Texture texture;
	Texture textureRev;
	texture.loadFromFile("resources\\Cat2.png");
	textureRev.loadFromFile("resources\\Cat2Rev.png");
	Sprite sprite;
	/*Sprite spriteRev;*/
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(881, 999, 279, 201));//x,y,x,y
	sprite.setPosition(50, 25);//x,y

	//spriteRev.setTexture(textureRev);
	//spriteRev.setTextureRect(IntRect(881, 999, 279, 201));//x,y,x,y
	//spriteRev.setPosition(50, 25);//x,y
	Clock clock;

	float CurrentFrame = 0;//хранит текущий кадр

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		/*time = time / 800;*/
		std::cout << time<< "\n";
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				
				window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			sprite.setTexture(textureRev);
			sprite.move(-0.1*time, 0);
			sprite.setTextureRect(IntRect(347, 1007, 367, 170));
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			sprite.setTexture(texture);
			sprite.move(0.1 * time, 0);
			sprite.setTextureRect(IntRect(1227, 1020, 367, 170));
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			sprite.move(0,-0.1 * time); //x,y
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.move(0, 0.1 * time);
		}

		window.clear(Color::White);
		window.draw(spriteFon);
		window.draw(sprite);

		window.display();
	}

	return 0;
}