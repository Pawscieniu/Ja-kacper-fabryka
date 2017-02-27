#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "myGui.hpp"
#include "Help/typedef.hpp"

using namespace std;

RenderWindow win;
myGui gui;
Color winColor(200, 200, 200);

void fun(){
	if(gui("cGroup")->allChecked() and gui("rGroup")->indexChecked(static_cast<RadioBox*>(gui["ra2"])->getId()))
		win.setTitle("CLICKED & CHECKED!!!");
	else if(gui("rGroup")->indexChecked(static_cast<RadioBox*>(gui["ra2"])->getId()))
		win.setTitle("CHECKED!!!");
	else if(gui("cGroup")->allChecked())
		win.setTitle("CLIKED!!!");
	else
		win.setTitle("gui tests");
}

void click(){
	winColor = Color(255, 0, 0);
}

void endClick(){
	winColor = Color(200, 200, 200);
}

int main(){
	win.create(VideoMode(500, 500), "gui tests");
	gui("cGroup")->manage = fun;
	gui("rGroup")->manage = fun;
	gui.add("button", objectType::Button);
	gui.add("ch2", objectType::CheckBox);
	gui.add("ra1", objectType::RadioBox);
	gui.add("ra2", objectType::RadioBox);
	gui.add("ch1", objectType::CheckBox);
	gui["button"]->setPosition(Vector2f(100, 100));
	gui["button"]->setSize(Vector2f(100, 100));
	gui["button"]->onClick = click;
	gui["ch1"]->setPosition(Vector2f(200, 200));
	gui["ch1"]->setSize(Vector2f(100, 100));
	gui["ch2"]->setPosition(Vector2f(200, 300));
	gui["ch2"]->setSize(Vector2f(100, 100));
	gui["ra1"]->setPosition(Vector2f(300, 200));
	gui["ra1"]->setSize(Vector2f(100, 100));
	gui["ra2"]->setPosition(Vector2f(300, 300));
	gui["ra2"]->setSize(Vector2f(100, 100));
	static_cast<Button*>(gui["button"])->afterClick = endClick;
	static_cast<CheckBox*>(gui["ch1"])->setGroup(gui("cGroup"));
	static_cast<CheckBox*>(gui["ch2"])->setGroup(gui("cGroup"));
	static_cast<RadioBox*>(gui["ra1"])->setGroup(gui("rGroup"));
	static_cast<RadioBox*>(gui["ra2"])->setGroup(gui("rGroup"));
	while(win.isOpen()){
		Event event;
		while(win.pollEvent(event)){
			gui.handleEvents(event, &win);
			switch(event.type){
				case Event::Closed:
					win.close();
					break;
				default:
					break;
			}
		}
		gui.update();
		win.clear(winColor);
		gui.draw(&win);
		win.display();
	}
}
