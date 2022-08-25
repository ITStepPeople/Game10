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
	texture.loadFromFile("resources\\Cat.png");
	textureRev.loadFromFile("resources\\CatRev.png");
	Sprite sprite;
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(881, 999, 279, 201));//x,y,x,y
	sprite.setPosition(50, 575);//x,y
	
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
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			sprite.setTexture(textureRev);
			int q;
			q = 199 * int(CurrentFrame);
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 12)CurrentFrame -= 12;

			sprite.setTextureRect(IntRect(347, 0 + q, 408, 199/**int(CurrentFrame)*/));
			std::cout << sprite.getRotation() << "\n";
			sprite.move(-0.15 * time, 0);
			/*sprite.setTexture(textureRev);
			sprite.move(-0.1*time, 0);
			sprite.setTextureRect(IntRect(347, 1007, 367, 170));*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			sprite.setTexture(texture);
			int q;
			q = 199 * int(CurrentFrame);
			CurrentFrame += 0.005 * time;

			if (CurrentFrame > 12)CurrentFrame -= 12;
			
				sprite.setTextureRect(IntRect(1183 , 0+q, 436, 199/**int(CurrentFrame)*/));
				sprite.move(0.15 * time, 0);
				
			
			/*sprite.setTextureRect(IntRect(1183, 7, 436, 183));*/
			/*sprite.setTexture(texture);
			sprite.move(0.1 * time, 0);
			sprite.setTextureRect(IntRect(1183, 7, 436, 183));*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{


			/*sprite.setTexture()*/
			//sprite.move(0,-0.1/* * time*/); //x,y
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.setTexture(texture);
			//sprite.move(0, 0.1/* * time*/);
			sprite.setTextureRect(IntRect(881, 999, 279, 201));
		}
		/*if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left)))
		{
			
			sprite2.setTexture(textureRev);
			
			sprite2.setTextureRect(IntRect(1550, 1630, 408, 199));
			sprite2.setRotation(52);
			sprite2.move(-0.15 * time, 0);
			
			
		}*/
		window.clear(Color::White);
		window.draw(spriteFon);
		window.draw(sprite);
	

		window.display();
	}

	return 0;
}