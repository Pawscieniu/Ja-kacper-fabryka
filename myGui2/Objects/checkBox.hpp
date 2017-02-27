#ifndef mGUIcheckBox

#define mGUIcheckBox

namespace mGUI{
	enum class boxType{
		check,
		radio
	};

	class BoxGroup{
		private:
			boxType type;
		public:
			void manage(){
			
			}
			
			BoxGroup(){};
	};
	
	class CheckBox : public Object{
		private:
			BoxGroup* group;
		public:
			void setGroup(BoxGroup* val){
				group = val;
			}
			
			void click(sf::Time time){
				Clicked = !Clicked;
				onClick();
			}
			
			BoxGroup* getGroup(){
				return group;
			}
			
			CheckBox(){
				type = objectType::CheckBox;
				onClick = none;
			}
	};
};

#endif
