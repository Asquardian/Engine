#include <SFML/Graphics.hpp>
#include <iostream>
#include <codecvt>
#include <locale>
#include <string>
#include <locale>
#include <Windows.h>
#include "Scene.h"

std::wstring createText() {
	std::wstring str;
	std::getline(std::wcin, str);
	return str;
}

void createChar(Character &CharBID) {
	CharBID.createNewCharacter();
	std::wstring str;
	if ((std::wcin >> str).get())
		CharBID.SetCharName(str);
}

double CreateScene(sf::RenderWindow& window) {
	std::wcin.imbue(std::locale("rus_rus.866"));
	Frame scene[100];
	std::wstring *str;
	str = new std::wstring [100] ;
	int FrameInt = 0;
	bool delay = false;
	Background back("back.png");
	Character *charByID;
	charByID = new Character[10];
	int charID = 0;
	createChar(charByID[0]);
	DialogWindow dialog("border.png", "FontC.TTF");
	//setlocale(LC_CTYPE, "");
	bool anim = true;
	scene[FrameInt].SetFrame(charByID[0], back, dialog);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) { //Window close
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (anim) {
			str[FrameInt] = createText();
			dialog.SetSpeaker(charByID[charID].returnCharName());
			dialog.SetText(str[FrameInt]);
			anim = false;
			back.Update(window);
			charByID[charID].Update(window);
			dialog.Update(window);
		}
		if (!delay && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			delay = true;
			FrameInt++;
		}
		else delay = false;
		if (!delay && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			delay = true;
			charID++;
			charByID[charID].createNewCharacter();
			anim = true;
		}
		else delay = false;
	}
	return 0;
}