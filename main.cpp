#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
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
	Vector2f getPosition()const { return sprite.getPosition(); }
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
	float CurrentFrame3;
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
		CurrentFrame3 = 0;
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
			int q = 199 * int(CurrentFrame3);
			CurrentFrame3 += 0.010 * time;
			if (CurrentFrame3 > 6)
			{
				sit = false;
				CurrentFrame3 -= 6;
			}
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		}
		if (leftM && sit)
		{
			x = 760, y = 0, x1 = 370, y1 = 199;
			int q = 199 * int(CurrentFrame3);
			CurrentFrame3 += 0.010 * time;
			if (CurrentFrame3 > 6)
			{
				sit = false;
				CurrentFrame3 -= 6;
			}
			sprite.setTexture(textureRev);
			sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		}
	}
	void MoveRight(const int &W,const float &time)
	{
		sprite.setTexture(texture);
		int q = 199 * int(CurrentFrame);
		CurrentFrame += 0.009 * time;
		x = 1183, y = 0, x1 = 436, y1 = 199;
		if (CurrentFrame > 12)CurrentFrame -= 12;
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x < W - 350)
			sprite.move(0.15 * time, 0);
		sit = true;
		rightM = true;
		leftM = false;
	}
	void MoveLeft(const int& W, const float& time)
	{
		sprite.setTexture(textureRev);
		int q = 199 * int(CurrentFrame);
		CurrentFrame += 0.009 * time;
		if (CurrentFrame > 12)CurrentFrame -= 12;
		x = 347, y = 0, x1 = 408, y1 = 199;
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x > 50)
			sprite.move(-0.15 * time, 0);
		sit = true;
		leftM = true;
		rightM = false;
	}
	void SprintLeft(const int& W, const float& time)
	{
		x = 1550, y = 1410, x1 = 365, y1 = 199;
		int q = 199 * int(CurrentFrame2);
		CurrentFrame2 += 0.015 * time;
		if (CurrentFrame2 > 5)
			CurrentFrame2 -= 13;
		sprite.setTexture(textureRev);
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x > 50)
			sprite.move(-0.32 * time, 0);
		sit = true;
		rightM = false;
		leftM = true;
	}
	void SprintRight(const int& W, const float& time)
	{
		x = 33, y = 1410, x1 = 365, y1 = 199;
		int q = 199 * int(CurrentFrame2);
		CurrentFrame2 += 0.015 * time;
		if (CurrentFrame2 > 5)
			CurrentFrame2 -= 13;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(x, y + q, x1, y1));
		if (sprite.getPosition().x < W - 350)
			sprite.move(0.32 * time, 0);
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
			dy = -1.0 * time;
		}
		if(!onGround)
		{
			dy += 0.021 * time;
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
	 if (sprite.getPosition().y >= stop)
	 {
		 onGround = true;
		 dy = -0.07;
	 }	
	 if (!onGround)
	 {
		 int q = 95 * int(CurrentFrame);
		 CurrentFrame += 0.009 * time;
		 x = 290, y = 0, x1 = 95, y1 = 110;
		 if (CurrentFrame > 3)CurrentFrame -= 3;
		 sprite.setTextureRect(IntRect(x + q, y, x1, y1));
		 if (sprite.getPosition().y < stop / 3)
		 {
			 float t = rand() % 10+1;
			 dy += t / 1000.0 * time;
			 sprite.move(0, dy);
		 }
		 else		 
			 sprite.move(0, dy);
	 }
	 else
	 {
		 onGround = true;
		 dy = -0.07;
	 }
 }
 void MoveLeft(const float& t)
 {
	 sprite.move(t, 0);
 }
 void MoveRight(const float& t)
 {
	 sprite.move(t, 0);
 }
};

int main()
{
	srand(time(0));
	int W = 1200, H = 800;
	RenderWindow window(VideoMode(W, H), "CAT!"/*,Style::Fullscreen*/);
	window.setFramerateLimit(144);
	Clock clock;
	Font font;
	font.loadFromFile("resources\\sansation.ttf");
	Text text;
	text.setFont(font);
	text.setOutlineThickness(2);
	Text text2;
	text2.setFont(font);
	text2.setOutlineThickness(2);
	Text textEND;
	textEND.setFont(font);
	textEND.setOutlineThickness(2);
	Text scoreEnd;
	scoreEnd.setFont(font);
	scoreEnd.setOutlineThickness(2);
	Text ScoreinGame;
	ScoreinGame.setFont(font);
	ScoreinGame.setOutlineThickness(2);

	Texture textureFon;
	textureFon.loadFromFile("resources\\Fon.jpg");
	textureFon.setSmooth(true);
	Texture Heart;
	Heart.loadFromFile("resources\\serdce1.png");
	Heart.setSmooth(true);
	Texture endgame;
	endgame.loadFromFile("resources\\endgame.png");
	endgame.setSmooth(true);
	

	Sprite spriteFon;
	spriteFon.setTexture(textureFon);
	spriteFon.setScale(0.3, 0.3);
	Sprite Heart_s;
	Heart_s.setTexture(Heart);
	Heart_s.setScale(0.05, 0.05);
	Heart_s.setPosition(19, 0);
	Sprite EndgameSprite;
	EndgameSprite.setTexture(endgame);

	SoundBuffer sound1;
	SoundBuffer sound2;
	sound1.loadFromFile("resources\\04. The Blinded Forest.flac");
	sound2.loadFromFile("resources\\mrr1.flac");
	Sound testsound;
	Sound mrr;
	testsound.setBuffer(sound1);
	testsound.play();
	testsound.setVolume(30);
	testsound.setLoop(true);
	mrr.setBuffer(sound2);
	mrr.setVolume(50);

	Player A("resources\\Cat.png", "resources\\CatRev.png", 881,999, 279,201);
	ItemforGame I("resources\\YJuk9VS.png",290,0,95,110);
	I.setPositionSprite(rand() % (W / 3 + W / 3) + 100, -10);
	/*ItemforGame Dog("resources\\pngegg.png", 0, 90, 125, 65);
	Dog.setPositionSprite(500, 565);*/

	bool Keep_playing = true;
	int lives = 18;
	int score = 0;
	float level = 1;
	float timefish1 = std::clock();
	float timefish2;
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

		if (!Keep_playing) //endgame menu
		{
			textEND.setCharacterSize(40);
			textEND.setPosition(W / 3 + 20, H / 3 + 80);
			textEND.setFillColor(Color::Cyan);
			textEND.setString("Space - New game.\n\n        ESC - Exit.");
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				Keep_playing = true;
				timefish1 = std::clock();
				lives = 9;
				score = 0;
				level = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		// CAT
		if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
			A.Sit(time);
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift))
			{
				A.SprintRight(W, time);
				if (spriteFon.getPosition().x > -800)
				{
					spriteFon.move(-0.30 * time, 0);
					I.MoveRight(-0.30 * time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift))
			{
				A.SprintLeft(W, time);
				if (spriteFon.getPosition().x < 0)
				{
					spriteFon.move(0.30 * time, 0);
					I.MoveLeft(0.30 * time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::LShift))
			{
				A.MoveLeft(W, time);
				if (spriteFon.getPosition().x < 0)
				{
					spriteFon.move(0.12 * time, 0);
					I.MoveLeft(0.12 * time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::LShift))
			{
				A.MoveRight(W, time);
				if (spriteFon.getPosition().x > -800)
				{
					spriteFon.move(-0.12 * time, 0);
					I.MoveRight(-0.12 * time);
				}
			}
		if (!Keyboard::isKeyPressed(Keyboard::Space))
			A.Jump(time);
		timefish2 = std::clock() - timefish1;
		if (timefish2 > 300)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				A.setOnGround(false);
				A.Jump(time);
			}
		}
		// Fish
		if (Keep_playing)
			{
				timefish2 = std::clock() - timefish1;
				if (timefish2 > 3000) //start delay
				{
					if (lives > 0)
					{
						if (score == 225 * level)
						{
							level++;
						}
						if (!I.getOnGround())
						{
							if (I.getPosition().x >= A.getPosition().x && I.getPosition().x <= A.getPosition().x + 200 && I.getPosition().y >= A.getPosition().y - 50) // проверка на поимку рыбки
							{
								I.setOnGround(true);
								score += 15;
								mrr.play();
							}
							I.MoveDown(time+5*level, 800);
							if (I.getPosition().y >= 800)
								lives--;
						}
						else
						{
							I.setOnGround(false);
							I.setPositionSprite(rand() % (W / 3 + W / 3) + 100, -10);
						}
						char str[4];
						_itoa(lives / 2, str, 10);
						text.setPosition(45, 10);
						text.setCharacterSize(45);
						text.setFillColor(Color::White);
						text.setString(str);
						char str2[10];
						_itoa(score, str2, 10);
						ScoreinGame.setPosition(W - W/10, 0);
						ScoreinGame.setCharacterSize(45);
						ScoreinGame.setFillColor(Color(255, 220, 0, 200));
						ScoreinGame.setString(str2);
					}
					else
					{
						char str[20];
						EndgameSprite.setScale(0.3, 0.3);
						EndgameSprite.setPosition(W / 4, H / 5);
						EndgameSprite.setTextureRect(IntRect(1065, 1370, 1935, 1430));

						text2.setCharacterSize(90);
						text2.setPosition(W / 3 - 35, H / 3 - 40);
						text2.setFillColor(Color(255, 0, 0, 200));
						text2.setString("Game Over");
						
						scoreEnd.setCharacterSize(70);
						scoreEnd.setPosition(W / 2 - 43, H / 5 - 10);
						scoreEnd.setFillColor(Color(255, 220, 0, 200));
						scoreEnd.setString(_itoa(score,str,10));
						Keep_playing = false;
					}
				}
				else
				{    //starting timer
					char str[4];
					_itoa(4 - timefish2 / 1000, str, 10);
					text.setPosition(W / 2 - 30, H / 3 - 40);
					text.setCharacterSize(120);
					text.setFillColor(Color(255, 255, 0, 200));
					text.setString(str);
				}
			}


		window.clear(Color::White);
		window.draw(spriteFon);
		if (lives <= 0)
			window.draw(EndgameSprite);
		window.draw(Heart_s);
		window.draw(ScoreinGame);
		window.draw(A.getSprite());
		window.draw(I.getSprite());
		if (Keep_playing)
		window.draw(text);
		if(!Keep_playing)
		{
			window.draw(textEND);
			window.draw(text2);
			window.draw(scoreEnd);
		}
		
		/*window.draw(Dog.getSprite());*/
		window.display();
	}
	return 0;
}