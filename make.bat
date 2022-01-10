g++ -o EqnoCraft.exe ^
src/setup.cpp src/window.cpp ^
src/init.cpp src/texture.cpp ^
src/render.cpp src/view.cpp ^
src/pointer.cpp src/coord.cpp src/block.cpp ^
src/bedrock.cpp src/ground.cpp ^
src/listener.cpp src/timer.cpp ^
-Wall -O2 -D FREEGLUT_STATIC -static-libgcc -static -std=c++17 -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32