#ifndef mGUIobject

#define mGUIobject

namespace mGUI{
	enum class objectType{
		Object,			// 0
		Button,			// 1
		CheckBox,		// 2
		RadioBox,		// 3
		TextBox			// 4
	};

	class Object : public sf::RectangleShape{
		protected:
			objectType type;
			bool Clicked;
		public:
			bool clicked(mGUI::Coord coord){
				return (coord.x > this->getPosition().x) and (coord.y > this->getPosition().y) and (coord.x < this->getPosition().x + this->getSize().x) and (coord.y < this->getPosition().y + this->getSize().y);
			}
			
			virtual void click(sf::Time time){
				onClick();
			}
			
			objectType getType(){
				return type;
			}
			
			bool ifClicked(){
				return Clicked;
			}
			
			std::function<void()> onClick;
			
			void draw(sf::RenderWindow* window, texturePack* textures){
				std::string path = textures->at(2 * static_cast<unsigned>(type) + (Clicked ? 1 : 0));
				sf::Texture tex;
				tex.loadFromFile(path);
				this->setTexture(&tex);
				window->draw(*this);
			}
			
			Object(){
				Clicked = false;
				type = objectType::Object;
				onClick = none;
			}
	};
}

#endif
