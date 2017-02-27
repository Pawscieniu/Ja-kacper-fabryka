#ifndef mGUIbutton

#define mGUIbutton

namespace mGUI{
	class Button : public Object{
		private:
			sf::Time clickDelay;
			sf::Time timeZero;
		public:
			void setClickDelay(sf::Time time){
				clickDelay = time;
			}
			
			void checkTime(sf::Time absoulutTime){
				if(Clicked and absoulutTime.asMilliseconds() >= timeZero.asMilliseconds() + clickDelay.asMilliseconds()){
					Clicked = false;
					afterClick();
				}
			}
			
			void click(sf::Time time){
				Clicked = true;
				timeZero = time;
				onClick();
			}
			
			Button(){
				type = objectType::Button;
				Clicked = false;
				clickDelay = sf::milliseconds(250);
				onClick = none;
				afterClick = none;
			}
	};
}

#endif
