#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "myGui.hpp"

using namespace std;

int main(){
	sf::RenderWindow win(sf::VideoMode(500, 500), "gui tests");
	mGUI::myGui gui;
	mGUI::defaultTextures.load("texturePack/default/");
	gui.add("button", mGUI::objectType::Button);
	gui["button"]->setPosition(sf::Vector2f(100, 100));
	gui["button"]->setSize(sf::Vector2f(100, 100));
	gui.add("object", mGUI::objectType::CheckBox);
	gui["object"]->setPosition(sf::Vector2f(200, 200));
	gui["object"]->setSize(sf::Vector2f(100, 100));
	while(win.isOpen()){
		sf::Event event;
		while(win.pollEvent(event)){
			gui.handleEvents(event, &win);
			switch(event.type){
				case sf::Event::Closed:
					win.close();
					break;
				default:
					break;
			}
		}
		gui.update();
		win.clear();
		gui.draw(&win, &(mGUI::defaultTextures));
		win.display();
	}
}
