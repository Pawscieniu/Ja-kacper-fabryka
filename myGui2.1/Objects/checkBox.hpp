#ifndef mGUIcheckBox

#define mGUIcheckBox

namespace mGUI{
	enum class boxType{
		check,
		radio
	};
	
	class CheckBox;

	class BoxGroup{
		private:
			boxType type;
			std::vector<Object*> objects;
		public:
			bool allChecked(){
				for(unsigned i = 0; i < objects.size(); i++){
					if(!objects[i]->ifClicked())
						return false;
				}
				return true;
			}
			
			bool indexChecked(unsigned val){
				return objects[val]->ifClicked();
			}
			
			unsigned push_back(Object* val){
				objects.push_back(val);
				return objects.size() - 1;
			}
			
			void clicked(unsigned index){
				for(unsigned i = 0; i < objects.size(); i++){
					if(objects[i]->ifClicked() and i != index)
						objects[i]->unClick();
				}
			}
			
			std::function<void()> manage;
			
			BoxGroup(boxType Type){
				type = Type;
				manage = none;
			};
	};
	
	class CheckBox : public Object{
		protected:
			BoxGroup* group;
			unsigned id;
		public:
			void setGroup(BoxGroup* val){
				group = val;
				id = group->push_back(this);
			}
			
			void click(sf::Time time){
				Clicked = !Clicked;
				onClick();
			}
			
			unsigned getId(){
				return id;
			}
			
			BoxGroup* getGroup(){
				return group;
			}
			
			CheckBox(){
				group = NULL;
				type = objectType::CheckBox;
				onClick = none;
				afterClick = none;
			}
	};
};

#endif
