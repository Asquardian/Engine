#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>
#include <thread>
#include "Function.h"

class Updateable {
public:
	virtual void Update() {

	}
};

class DialogWindow: public Updateable {
private:
	sf::Sprite DialogSprite;
	sf::Texture DialogTexture;
	sf::Text DialogCharacter;
	sf::Text DialogText;
	sf::Font DialogFont;
public:
	DialogWindow() {

	}
	DialogWindow(std::string File, std::string FontFile) {
		DialogTexture.loadFromFile(File);
		DialogSprite.setTexture(DialogTexture);
		DialogSprite.setPosition(150, 550);
		DialogFont.loadFromFile(FontFile);
		DialogText.setFont(DialogFont);
		DialogCharacter.setFont(DialogFont);
		DialogText.setCharacterSize(14);
		DialogCharacter.setCharacterSize(16);
		DialogCharacter.setPosition(160, 558);
		DialogText.setPosition(160, 578);
	}
	void SetSpeaker(std::wstring Text) {
		DialogCharacter.setString(Text);
	}
	void SetCharacter(std::wstring Text) { //Поставить текст
		DialogCharacter.setString(Text);
	}
	void SetText(std::wstring Text) { //Поставить текст
		DialogText.setString(Text);
	}
	void Update(sf::RenderWindow &window) {
		window.draw(DialogSprite);
		window.draw(DialogCharacter);
		window.draw(DialogText);
		window.display();
	}
};

class Background: public Updateable {
private:
	sf::Sprite BackgroundSprite;
	sf::Texture BackgroundTexture;
public:
	/*Background& operator=(const Background& other) {  VS Глюканула, видимо
		BackgroundSprite = other.BackgroundSprite;
		BackgroundTexture = other.BackgroundTexture;
	}*/
	Background() {

	}
	Background(std::string TextureFile) {
		BackgroundTexture.loadFromFile(TextureFile);
		BackgroundSprite.setTexture(BackgroundTexture);
	}
	void Update(sf::RenderWindow& window) {
		window.draw(BackgroundSprite);
	}
	void LoadNewbackground(std::string File) {
		BackgroundTexture.loadFromFile(File);
		BackgroundSprite.setTexture(BackgroundTexture);
	}
};

class Character: public Updateable {
private:
	sf::Sprite CharacterSprite;
	sf::Texture CharacterTexture;
	sf::Sound Speech;
	sf::SoundBuffer buffer;
	std::wstring CharName;
public:
	Character() {

	}
	Character(std::string TextureFile) {
		CharacterTexture.loadFromFile(TextureFile);
		CharacterSprite.setTexture(CharacterTexture);
	}
	void SetCharName(std::wstring name) {
		CharName = name;
	}
	std::wstring returnCharName() {
		return CharName;
	}
	void createNewCharacter() {
		std::cout << "Texture for character\n";
		std::string TextureFile; 
		std::cin >> TextureFile;
		CharacterTexture.loadFromFile(TextureFile);
		CharacterSprite.setTexture(CharacterTexture);
	}
	void LoadSpeech(std::string File) {
		buffer.loadFromFile(File);
		Speech.setBuffer(buffer);
	}
	void Speak() {
		Speech.play();
	}
	void Update(sf::RenderWindow& window) {
		window.draw(CharacterSprite);
	}
};

class Frame { //Хранит Весь Кадр
public:
	Character InfoChar;
	Background InfoBack;
	DialogWindow InfoDialog;
	Frame() {

	}
	void SetFrame(Character CharImport, Background BackImport, DialogWindow DialogImport) {
		InfoChar = CharImport;
		InfoBack = BackImport;
		InfoDialog = DialogImport;
	}
};