CC	= g++

NAME	= feg.out

CXXFLAGS += -Wall -Wextra
#CXXFLAGS += -Weffc++
CXXFLAGS += -Wshadow
CXXFLAGS += -Wold-style-cast
CXXFLAGS += -Wcast-align
CXXFLAGS += -Wunused
CXXFLAGS += -Woverloaded-virtual
CXXFLAGS += -Wpedantic
CXXFLAGS += -Wsign-conversion
CXXFLAGS += -Wlogical-op
CXXFLAGS += -Wuseless-cast
CXXFLAGS += -std=c++17

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -I ./inc

SRCS	= src/main.cpp \
		  src/GameObject/Crate.cpp \
		  src/TextureManager.cpp \
		  src/GameObject/GameObject.cpp \
		  src/GameObject/MovableGameObject.cpp \
		  src/Scene.cpp \
		  src/GameObject/Player.cpp \
		  src/GameObject/Ai.cpp \
		  src/GameObject/Character.cpp \
		  src/PhysicsManager.cpp \
		  src/GameObject/Bullet.cpp \
		  src/Gun/Gun.cpp \
		  src/Chrono.cpp \
		  src/Gun/Handgun.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDLIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
