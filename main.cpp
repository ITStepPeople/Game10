#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1200, 800), "SFML Works!"/*,Style::Fullscreen*/);

	float CurrentFrame = 0;
	float CurrentFrame2 = 0;
	int x, y, x1, y1;
	x = 881, y = 999, x1 = 279, y1 = 201;

	Texture textureFon;
	Texture texture;
	Texture textureRev;
	Sprite spriteFon;
	Sprite sprite;
	texture.loadFromFile("resources\\Cat.png");
	textureRev.loadFromFile("resources\\CatRev.png");
	textureFon.loadFromFile("resources\\Fon.jpg");

	spriteFon.setTexture(textureFon);
	spriteFon.setScale(0.3, 0.3);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, x1, y1));
	sprite.setPosition(50, 625);//x,y
	sprite.setScale(0.7, 0.7);

	SoundBuffer sound1;
	sound1.loadFromFile("resources\\04. The Blinded Forest.flac");
	Sound testsound;
	testsound.setBuffer(sound1);
	testsound.play();
	testsound.setVolume(30);

	Clock clock;
	bool sit = true;
	bool rightM = false;
	bool leftM = false;
	while (window.isOpen())
	{
		std::cout << "x: " << x << std::endl;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				exit(0);
				window.close();
			}
		}
		if (!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left) && sit == true)
		{
			if (rightM == true)
			{
				x = 820, y = 0, x1 = 360, y1 = 199;
				int q = 199 * int(CurrentFrame);
				CurrentFrame += 0.007 * time;
				if (CurrentFrame > 6)
				{
					sit = false;
					CurrentFrame -= 6;
				}
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			}
			if (leftM == true)
			{
				x = 760, y = 0, x1 = 370, y1 = 199;
				int q = 199 * int(CurrentFrame);
				CurrentFrame += 0.007 * time;
				if (CurrentFrame > 6)
				{
					sit = false;
					CurrentFrame -= 6;
				}
				sprite.setTexture(textureRev);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::Right))
		{
			x = 33, y = 1410, x1 = 365, y1 = 199;
			int q = 199 * int(CurrentFrame2);
			CurrentFrame2 += 0.015 * time;
			if (CurrentFrame2 > 5)
				CurrentFrame2 -= 13;
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			sprite.move(0.30 * time, 0);
			spriteFon.move(-0.10 * time, 0);
			sit = true;
			rightM = true;
			leftM = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::Left))
		{
			x = 1550, y = 1410, x1 = 365, y1 = 199;
			int q = 199 * int(CurrentFrame2);
			CurrentFrame2 += 0.015 * time;
			if (CurrentFrame2 > 5)
				CurrentFrame2 -= 13;
			sprite.setTexture(textureRev);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			/*if(sprite.getPosition() < )*/
			sprite.move(-0.30 * time, 0);
			spriteFon.move(0.10 * time, 0);
			sit = true;
			rightM = false;
			leftM = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::LShift))
		{
			sprite.setTexture(textureRev);
			int q;
			q = 199 * int(CurrentFrame);
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 12)CurrentFrame -= 12;
			x = 347, y = 0, x1 = 408, y1 = 199;
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			sprite.move(-0.20 * time, 0);
			spriteFon.move(0.05 * time, 0);
			sit = true;
			leftM = true;
			rightM = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::LShift))
		{
			sprite.setTexture(texture);
			int q = 199 * int(CurrentFrame);
			CurrentFrame += 0.009 * time;
			x = 1183, y = 0, x1 = 436, y1 = 199;
			if (CurrentFrame > 12)CurrentFrame -= 12;
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			sprite.move(0.20 * time, 0);
			spriteFon.move(-0.05 * time, 0);
			sit = true;
			rightM = true;
			leftM = false;
		}
		window.clear(Color::White);
		window.draw(spriteFon);
		window.draw(sprite);
		window.display();
	}
	return 0;
}