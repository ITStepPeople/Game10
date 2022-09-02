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
	void setScaleSprite(const float& sizex, const float& sizey) { sprite.setScale(sizex, sizey); }
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
			sprite.move(0.17 * time, 0);
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
			sprite.move(-0.17 * time, 0);
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
			sprite.move(-0.35 * time, 0);
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
			sprite.move(0.35 * time, 0);
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
	float CurrentFrame2 = 0;
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
		 dy = -0.07;
	 }
 }
 void MoveRightOrLeft(const float& t, const float& time)
 {
	 int q = 115 * int(CurrentFrame2);
	 CurrentFrame2 += 0.009 * time;
	 x = 25, y = 90, x1 = 100, y1 = 65;
	 if (CurrentFrame2 > 5)CurrentFrame2 -= 5;
	 sprite.setTextureRect(IntRect(x + q, y, x1, y1));
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
	Text levelText;
	levelText.setFont(font);
	levelText.setOutlineThickness(2);

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
	SoundBuffer sound3;
	sound1.loadFromFile("resources\\myaukan-e-koshki--pod-gitaru.wav");
	sound2.loadFromFile("resources\\ball.wav");
	sound3.loadFromFile("resources\\draka.flac");
	Sound testsound;
	Sound mrr;
	Sound draka;
	testsound.setBuffer(sound1);
	testsound.play();
	testsound.setVolume(25);
	testsound.setLoop(true);
	mrr.setBuffer(sound2);
	mrr.setVolume(20);
	draka.setBuffer(sound3);
	draka.setVolume(15);

	Player A("resources\\Cat.png", "resources\\CatRev.png", 881,999, 279,201);
	ItemforGame I("resources\\YJuk9VS.png",290,0,95,110);
	I.setPositionSprite(rand() % (W / 3 + W / 3) + 100, -10);
	ItemforGame Dog("resources\\pngegg.png", 0, 90, 125, 65);
	Dog.setScaleSprite(2, 2);
	Dog.setPositionSprite(-250, 675);
	Dog.setOnGround(true);

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
		//endgame menu
		if (!Keep_playing)
		{
			textEND.setCharacterSize(40);
			textEND.setPosition(W / 3 + 20, H / 3 + 80);
			textEND.setFillColor(Color::Cyan);
			textEND.setString("  F1 - New game.\n\n        ESC - Exit.");
			if (Keyboard::isKeyPressed(Keyboard::F1))
			{
				Keep_playing = true;
				timefish1 = std::clock();
				lives = 18;
				score = 0;
				level = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		// CAT
		if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::A))
			A.Sit(time);
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift) && !Keyboard::isKeyPressed(Keyboard::A))
			{
				A.SprintRight(W, time);
				if (spriteFon.getPosition().x > -800)
				{
					spriteFon.move(-0.35 * time, 0);
					I.MoveRightOrLeft(-0.35 * time, time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift) && !Keyboard::isKeyPressed(Keyboard::D))
			{
				A.SprintLeft(W, time);
				if (spriteFon.getPosition().x < 0)
				{
					spriteFon.move(0.35 * time, 0);
					I.MoveRightOrLeft(0.35 * time, time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::LShift) && !Keyboard::isKeyPressed(Keyboard::D))
			{
				A.MoveLeft(W, time);
				if (spriteFon.getPosition().x < 0)
				{
					spriteFon.move(0.15 * time, 0);
					I.MoveRightOrLeft(0.15 * time, time);
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::LShift) && !Keyboard::isKeyPressed(Keyboard::A))
			{
				A.MoveRight(W, time);
				if (spriteFon.getPosition().x > -800)
				{
					spriteFon.move(-0.15 * time, 0);
					I.MoveRightOrLeft(-0.15 * time, time);
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
						if (score == 135 * level)
						{
							level++;
						}
						if (level > 1)
						{
							if (Dog.getPosition().y - 30 <= A.getPosition().y)
							{
								if (Dog.getPosition().x + 100 >= A.getPosition().x && Dog.getPosition().x <= A.getPosition().x + 200)// проверка на dog
								{
									lives--;
									Dog.setOnGround(true);
									Dog.setPositionSprite(-250, 650);
									draka.play();
								}
							}
							if (score % 50 == 0 && Dog.getOnGround())
							{
								Dog.setOnGround(false);
								Dog.setPositionSprite(-250, 650);
							}
							if(!Dog.getOnGround())
							{							
								Dog.MoveRightOrLeft(0.5 * time, time);			
							}
							if (Dog.getPosition().x >= W)
							{
								Dog.setOnGround(true);
								Dog.setPositionSprite(-250, 650);
							}
						}
						if (!I.getOnGround())
						{
							if (I.getPosition().x >= A.getPosition().x && I.getPosition().x <= A.getPosition().x + 200 && I.getPosition().y >= A.getPosition().y - 50 && I.getPosition().y <= A.getPosition().y) // проверка на поимку рыбки
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
						std::string str3 = "Round ";
						str3 += std::to_string(int(level));
						levelText.setPosition(W-W/8, 40);
						levelText.setCharacterSize(30);
						levelText.setFillColor(Color(255, 220, 0, 200));
						levelText.setString(str3);
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
		window.draw(levelText);
		window.draw(A.getSprite());
		if (timefish2 > 3000)
		window.draw(I.getSprite());
		if (Keep_playing)
		window.draw(text);
		if(!Keep_playing)
		{
			window.draw(textEND);
			window.draw(text2);
			window.draw(scoreEnd);
		}
		if(level > 1)
		window.draw(Dog.getSprite());
		window.display();
	}
	return 0;
}