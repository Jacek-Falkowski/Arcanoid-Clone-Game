all:  link

link: 
	g++ src/States/Game_over.cpp src/Objects/Bonus.cpp src/Objects/Sprite_object.cpp src/Music_player.cpp src/Utility.cpp src/Resource_manager.cpp src/GUI.cpp src/Objects/Shape.cpp  src/Objects/Brick.cpp src/States/Level_state.cpp src/States/Menu_state.cpp src/Collision.cpp src/Objects/Paddle.cpp src/Objects/Ball.cpp src/States/Play_state.cpp src/States/State_base.cpp src/Game.cpp src/main.cpp -o main -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 