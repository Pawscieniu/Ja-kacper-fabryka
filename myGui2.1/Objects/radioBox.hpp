#ifndef mGUIradioBox

#define mGUIradioBox

namespace mGUI{
	class RadioBox : public CheckBox{
		public:
			void click(sf::Time time){
				Clicked = !Clicked;
				onClick();
				if(group){
					group->clicked(id);
				}
			}
			
			RadioBox(){
				group = NULL;
				type = objectType::RadioBox;
				onClick = none;
				afterClick = none;
			}
	};
};

#endif
