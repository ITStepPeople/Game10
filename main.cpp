#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "map.h"
using namespace sf;

class Basic
{
protected:
	int x, y, x1, y1;
	float CurrentFrame;
	Texture texture;
	Sprite sprite;
	float dy;
	bool onGround;
public:
	Basic() 
	{
		CurrentFrame = 0;
		dy = 0;
		onGround = true;
	};

	Sprite getSprite()const { return sprite; }
	bool getOnGround()const { return onGround; }
	void setOnGround(const bool& g) { this->onGround = g; }
	void setPositionSprite(const float& X, const float& Y) { sprite.setPosition(X, Y); }
	void SetXY_X1_Y1(const int& x, const int& y, const int& x1, const int& y1)
	{
		this->x = x;
		this->y = y;
		this->x1 = x1;
		this->y1 = y1;
	}

};
class Player :virtual public Basic
{
	float CurrentFrame2;
	Texture textureRev;
	bool sit;
	bool rightM;
	bool leftM;
public:	
	Player(const std::string& n, const std::string& n2, const int& X, const int& Y, const int& X1, const int& Y1)
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
			spriteFon.move(-0.12 * time, 0);
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
			spriteFon.move(0.12 * time, 0);
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
			spriteFon.move(0.28 * time, 0);
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
			spriteFon.move(-0.28 * time, 0);
		sit = true;
		rightM = true;
		leftM = false;
	}
	void Jump(const float& time)
	{
		if(!onGround && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
		{
			if (leftM || !rightM)
			{
				x = 1550, y = 1020, x1 = 365, y1 = 199;
				int q = 199 * int(CurrentFrame2);
				CurrentFrame2 += 0.010 * time;
				if (CurrentFrame2 > 7)
					CurrentFrame2 -= 10;
				sprite.setTexture(textureRev);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
				leftM = true;
			}
			else
			{
				x = 33, y = 1020, x1 = 365, y1 = 199;
				int q = 199 * int(CurrentFrame2);
				CurrentFrame2 += 0.010 * time;
				if (CurrentFrame2 > 7)
					CurrentFrame2 -= 10;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(x, y + q, x1, y1));
				rightM = true;
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

class ItemforGame: virtual public Basic
{
	
public:
 ItemforGame(const std::string& n, const int& X, const int& Y, const int& X1, const int& Y1)
	{
	texture.loadFromFile(n);
	texture.setSmooth(true);
	x = X, y = Y, x1 = X1, y1 = Y1;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, x1, y1));
	onGround = false;
	CurrentFrame = 0;
	dy = -0.05;
	}

 void MoveDown(const float& time,const int&stop)
 {
	 std::cout << sprite.getPosition().y<<std::endl;	 
	 if (sprite.getPosition().y >= stop)
	 {
		 onGround = true;
		 dy = -0.05;
	 }
	 if (!onGround)
	 {
		 if (sprite.getPosition().y < stop / 3)
		 {
			 float t = rand() % 100 + 1;
			 std::cout << "t: " << t << std::endl;
			 dy += t / 100000.0 * time;
			 sprite.move(0, dy);
		 }
		 else
			 sprite.move(0, dy);
	 }
	 
 }
};
int main()
{
	srand(time(0));
	int W = 1200, H = 800;
	RenderWindow window(VideoMode(W, H), "CAT!"/*,Style::Fullscreen*/);
	Clock clock;

	Image map_i;
	map_i.loadFromFile("resources\\test1.png");
	Texture map;
	map.loadFromImage(map_i);
	Sprite s_map;
	s_map.setTexture(map);

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

	Player A("resources\\Cat.png", "resources\\CatRev.png", 881,999, 279,201);
	ItemforGame I("resources\\YJuk9VS.png",0,0,90,110);
	I.setPositionSprite(rand() % 500 + 200, 0);
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
			A.Sit(time);
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift))
			A.SprintRight(spriteFon, W, time);
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift))
			A.SprintLeft(spriteFon, W, time);
		if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::LShift))
			A.MoveLeft(spriteFon, W, time);
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::LShift))
			A.MoveRight(spriteFon, W, time);
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			A.setOnGround(false);
			A.Jump(time);
		}
		if (!Keyboard::isKeyPressed(Keyboard::Space))
			A.Jump(time);
		if (!I.getOnGround())
		{
			I.MoveDown(time, 800);
		}
		else
		{
			I.setOnGround(false);
			I.setPositionSprite(rand() % W/2 + 100, 0);
		}

		window.clear(Color::White);
		/*for (int i = 0; i < H_MAP; i++)
		{
			for (int u = 0; u < W_MAP; u++)
			{
				if (Tilemap[i][u] == ' ')s_map.setTextureRect(IntRect(0, 0, 254, 254));
				if (Tilemap[i][u] == '0')s_map.setTextureRect(IntRect(0, 256, 244, 254));
				if (Tilemap[i][u] == 's')s_map.setTextureRect(IntRect(254, 0, 254, 254));
				s_map.setPosition(u * 220, i * 220);
				window.draw(s_map);
			}
		}*/
		window.draw(spriteFon);
		window.draw(A.getSprite());
		window.draw(I.getSprite());
		window.display();
	}
	return 0;
}