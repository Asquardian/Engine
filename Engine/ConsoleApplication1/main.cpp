#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <Windows.h>
#include "Function.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Engine");
	while (window.isOpen()) {
		CreateScene(window);
	}
}
