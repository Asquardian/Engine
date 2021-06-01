#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>

class Scene {
private:
	int FrameID;
public:
	Scene() {
		
	}
};

class Background {
private:
	sf::Sprite BackgroundSprite;
	sf::Texture BackgroundTexture;
	sf::Music BackgroundMusic;
	int CharId;
public:
	Background(std::string TextureFile) {
		BackgroundTexture.loadFromFile(TextureFile);
		BackgroundSprite.setTexture(BackgroundTexture);
	}
	Background(std::string TextureFile, std::string MusicFile) {
		BackgroundTexture.loadFromFile(TextureFile);
		BackgroundSprite.setTexture(BackgroundTexture);
		BackgroundMusic.openFromFile(MusicFile);
		BackgroundMusic.getLoop();
		BackgroundMusic.play();
	}
	void Update(sf::RenderWindow& window) {
		window.draw(BackgroundSprite);
	}
	void LoadNewbackground(std::string File) {
		BackgroundTexture.loadFromFile(File);
		BackgroundSprite.setTexture(BackgroundTexture);
	}
};