#ifndef mGUItextBox

#define mGUItextBox

namespace mGUI{
	class TextBox : public Object{
		private:
			std::string text;
		public:
			void addLetter(char c){
				text += c;
			}
			
			void delLetter(){
				text = text.substr(0, text.size() - 1);
			}
			
			std::string getString(){
				return text;
			}
	};
};

#endif

