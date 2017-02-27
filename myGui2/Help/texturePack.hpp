#ifndef mGUItexturePack

#define mGUItexturePack

namespace mGUI{
	enum class texturesNames{
		Object,					// 0
		ObjectClicked,			// 1
		Button,					// 2
		ButtonClicked,			// 3
		CheckBox,				// 4
		CheckBoxChecked,		// 5
		RadioBox,				// 6
		RadioBoxChecked,		// 7
		TextBox,				// 8
		TextBoxClicked			// 9
	};
	
	class texturePack{
		private:
			std::vector<std::string> textures;
			std::string font;
		public:
			void load(std::string path){
				textures[0] = std::string(path + "object.png");
				textures[1] = std::string(path + "objectClicked.png");
				textures[2] = std::string(path + "button.png");
				textures[3] = std::string(path + "buttonClicked.png");
				textures[4] = std::string(path + "checkBox.png");
				textures[5] = std::string(path + "checkBoxChecked.png");
				textures[6] = std::string(path + "radioBox.png");
				textures[7] = std::string(path + "radioBoxChecked.png");
				textures[8] = std::string(path + "textBox.png");
				textures[9] = std::string(path + "textBoxClicked.png");
				font = std::string(path + "font.ttf");
			}
			
			std::string at(unsigned index){
				return textures[index];
			}
			
			std::string getFont(){
				return font;
			}
			
			texturePack(){
				textures.resize(10);
			}
	};
}

#endif
