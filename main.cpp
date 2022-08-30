#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace sf;

class Player
{
	int x, y, x1, y1;
	float CurrentFrame;
	float CurrentFrame2;
	Texture texture;
	Texture textureRev;
	Sprite sprite;
	bool sit;
	bool rightM;
	bool leftM;
	float dy = 0;
	bool onGround;
public:	
	Player(const std::string& n, const std::string& n2)
	{
		texture.loadFromFile(n);
		textureRev.loadFromFile(n2);
		CurrentFrame = 0;
		CurrentFrame2 = 0;
		x = 881, y = 999, x1 = 279, y1 = 201;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(x, y, x1, y1));
		sprite.setPosition(50, 625);
		sprite.setScale(0.7, 0.7);
		sit = true;
		rightM = false;
		leftM = false;
		onGround = true;
		texture.setSmooth(true);
		textureRev.setSmooth(true);
	}
	Sprite getSprite()const { return sprite; }
	void setOnGround(const bool &g) { this->onGround = g; }
	void Sit(const float &time)
	{
		if (rightM && sit)
		{
			x = 820, y = 0, x1 = 360, y1 = 199;
			int q = 199 * int(CurrentFrame);
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 6)
			{
				sit = false;
				CurrentFrame -= 6;
			}
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		}
		if (leftM && sit)
		{
			x = 760, y = 0, x1 = 370, y1 = 199;
			int q = 199 * int(CurrentFrame);
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 6)
			{
				sit = false;
				CurrentFrame -= 6;
			}
			sprite.setTexture(textureRev);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		}
	}
	void MoveRight(Sprite &spriteFon,const int &W,const float &time)
	{
		sprite.setTexture(texture);
		int q = 199 * int(CurrentFrame);
		CurrentFrame += 0.009 * time;
		x = 1183, y = 0, x1 = 436, y1 = 199;
		if (CurrentFrame > 12)CurrentFrame -= 12;
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x < W - 350)
			sprite.move(0.12 * time, 0);
		if (spriteFon.getPosition().x > -800)
			spriteFon.move(-0.10 * time, 0);
		sit = true;
		rightM = true;
		leftM = false;
	}
	void MoveLeft(Sprite& spriteFon, const int& W, const float& time)
	{
		sprite.setTexture(textureRev);
		int q = 199 * int(CurrentFrame);
		CurrentFrame += 0.009 * time;
		if (CurrentFrame > 12)CurrentFrame -= 12;
		x = 347, y = 0, x1 = 408, y1 = 199;
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x > 50)
			sprite.move(-0.12 * time, 0);
		if (spriteFon.getPosition().x < 0)
			spriteFon.move(0.10 * time, 0);
		sit = true;
		leftM = true;
		rightM = false;
	}
	void SprintLeft(Sprite& spriteFon, const int& W, const float& time)
	{
		x = 1550, y = 1410, x1 = 365, y1 = 199;
		int q = 199 * int(CurrentFrame2);
		CurrentFrame2 += 0.015 * time;
		if (CurrentFrame2 > 5)
			CurrentFrame2 -= 13;
		sprite.setTexture(textureRev);
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x > 50)
			sprite.move(-0.30 * time, 0);
		if (spriteFon.getPosition().x < 0)
			spriteFon.move(0.25 * time, 0);
		sit = true;
		rightM = false;
		leftM = true;
	}
	void SprintRight(Sprite& spriteFon, const int& W, const float& time)
	{
		x = 33, y = 1410, x1 = 365, y1 = 199;
		int q = 199 * int(CurrentFrame2);
		CurrentFrame2 += 0.015 * time;
		if (CurrentFrame2 > 5)
			CurrentFrame2 -= 13;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x < W - 350)
			sprite.move(0.30 * time, 0);
		if (spriteFon.getPosition().x > -800)
			spriteFon.move(-0.25 * time, 0);
		sit = true;
		rightM = true;
		leftM = false;
	}
	void Jump(const float& time)
	{
		if(!onGround)
		{
			if (leftM || !rightM)
			{
				x = 1550, y = 1410, x1 = 365, y1 = 199;
				int q = 199 * int(CurrentFrame2);
				CurrentFrame2 += 0.015 * time;
				if (CurrentFrame2 > 5)
					CurrentFrame2 -= 13;
				sprite.setTexture(textureRev);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			}
			else
			{
				x = 33, y = 1410, x1 = 365, y1 = 199;
				int q = 199 * int(CurrentFrame2);
				CurrentFrame2 += 0.015 * time;
				if (CurrentFrame2 > 5)
					CurrentFrame2 -= 13;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
			}
			
			sit = true;
		}
		
		if (sprite.getPosition().y >= 625)
		{
			onGround = true;
			dy = 0;
		}
		if(onGround && Keyboard::isKeyPressed(Keyboard::Space))
		{
			dy = -0.5;
		}
		if(!onGround)
		{
			dy += 0.001 * time;
		}
		sprite.move(0, dy);
	}
};

int main()
{
	int W = 1200, H = 800;
	RenderWindow window(VideoMode(W, H), "CAT!"/*,Style::Fullscreen*/);
	Clock clock;

	Texture textureFon;
	textureFon.loadFromFile("resources\\Fon.jpg");
	textureFon.setSmooth(true);

	Sprite spriteFon;
	spriteFon.setTexture(textureFon);
	spriteFon.setScale(0.3, 0.3);

	SoundBuffer sound1;
	sound1.loadFromFile("resources\\04. The Blinded Forest.flac");
	Sound testsound;
	testsound.setBuffer(sound1);
	testsound.play();
	testsound.setVolume(30);
	testsound.setLoop(true);

	Player A("resources\\Cat.png", "resources\\CatRev.png");
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				exit(0);
				window.close();
			}
		}
		if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
		{
			A.Sit(time);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift))
		{
			A.SprintRight(spriteFon, W, time);
		}
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift))
		{
			A.SprintLeft(spriteFon, W, time);
		}
		if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::LShift))
		{
			A.MoveLeft(spriteFon, W, time);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::LShift))
		{
			A.MoveRight(spriteFon, W, time);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			A.setOnGround(false);
			A.Jump(time);		
		}
		if (!Keyboard::isKeyPressed(Keyboard::Space))
		{
			A.Jump(time);
		}
		window.clear(Color::White);
		window.draw(spriteFon);
		window.draw(A.getSprite());
		window.display();
	}
	return 0;
}