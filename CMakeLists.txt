cmake_minimum_required (VERSION 2.6)
project(Fight_Epitech_Grades)
include_directories(
        inc/
        inc/GameObject/
        inc/GameObject/Gun/
        inc/GameObject/UI/)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wshadow -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wsign-conversion -Wlogical-op -Wuseless-cast")
add_executable(feg.out
        src/main.cpp
		src/GameObject/Crate.cpp
		src/ResourcesManager.cpp
		src/GameObject/GameObject.cpp
		src/GameObject/MovableGameObject.cpp
		src/Scene.cpp
		src/GameObject/Player.cpp
		src/GameObject/Ai.cpp
		src/GameObject/Character.cpp
		src/PhysicsManager.cpp
		src/GameObject/Bullet.cpp
		src/Gun/Gun.cpp
		src/Chrono.cpp
		src/Gun/Handgun.cpp
		src/GameObject/HealthBar.cpp
		src/Gun/Machinegun.cpp
		src/GameObject/UI/ClickableUI.cpp
		src/GameObject/UI/Switch.cpp
		src/GameObject/UI/Text.cpp
		src/GameObject/UI/Button.cpp
		src/Gun/MineLauncher.cpp
		src/GameObject/Portal.cpp)
find_package(SFML 2.4 REQUIRED system window graphics)
target_link_libraries(feg.out ${SFML_LIBRARIES})