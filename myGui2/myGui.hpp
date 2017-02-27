////////////////////////////////////////////////////////////////
/// myGui v 2.0 made by capi1500 free to use and publish
////////////////////////////////////////////////////////////////

#ifndef mGUImyGui

#define mGUImyGui

#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std::placeholders;

void none(){}

#include "Help/coord.hpp"
#include "Help/texturePack.hpp"
#include "Objects/object.hpp"
#include "Objects/button.hpp"
#include "Objects/checkBox.hpp"
#include "Objects/radioBox.hpp"
#include "Objects/textBox.hpp"

namespace mGUI{
	texturePack defaultTextures;	
	
	class myGui{
		private:
			std::map<std::string, objectType> types;
			std::map<std::string, Object*> objects;
			sf::Clock clock;
			sf::Time time;
		public:
			void handleEvents(sf::Event event, sf::RenderWindow* window){
				switch(event.type){
					case sf::Event::MouseButtonPressed:
						for(std::map<std::string, Object*>::iterator it = objects.begin(); it != objects.end(); it++){
							if(it->second->clicked(sf::Mouse::getPosition(*window))){
								it->second->click(time);
							}
						}
						return;
					default:
						return;
				}
			}
			
			void update(){
				time = clock.getElapsedTime();
				for(std::map<std::string, Object*>::iterator it = objects.begin(); it != objects.end(); it++){
					switch(types[it->first]){
						case objectType::Button:
							static_cast<Button*>(it->second)->checkTime(time);
							break;
						default:
							break;
					}
				}
			}
			
			void add(std::string name, objectType type){
				types[name] = type;
				switch(type){
					case objectType::Button:
						objects[name] = new Button();
						break;
					case objectType::CheckBox:
						objects[name] = new CheckBox();
						break;
					case objectType::RadioBox:
						objects[name] = new RadioBox();
						break;
					case objectType::TextBox:
						objects[name] = new TextBox();
						break;
					default:
						objects[name] = new Object();
						break;
				}
			}
			
			Object* operator[](std::string name){
				switch(types[name]){
					case objectType::Button:
						return static_cast<Button*>(objects[name]);
					case objectType::CheckBox:
						return static_cast<CheckBox*>(objects[name]);
					case objectType::RadioBox:
						return static_cast<RadioBox*>(objects[name]);
					case objectType::TextBox:
						return static_cast<TextBox*>(objects[name]);
					default:	
						return objects[name];
				}
			}
			
			texturePack* getTextures(){
				return &defaultTextures;
			}
			
			void draw(sf::RenderWindow* window, texturePack* textures){
				for(std::map<std::string, Object*>::iterator it = objects.begin(); it != objects.end(); it++){
					switch(it->second->getType()){
						case objectType::Button:
							static_cast<Button*>(it->second)->draw(window, textures);	
							break;
						case objectType::CheckBox:
							static_cast<CheckBox*>(it->second)->draw(window, textures);	
							break;
						case objectType::RadioBox:
							static_cast<RadioBox*>(it->second)->draw(window, textures);	
							break;
						case objectType::TextBox:
							static_cast<TextBox*>(it->second)->draw(window, textures);	
							break;
						default:
							static_cast<Object*>(it->second)->draw(window, textures);	
							break;
					}
				}
			}
			
			myGui(){
				clock.restart();
				//defaultTextures.load("texturePack/default/");
			}
	};
}

#endif
