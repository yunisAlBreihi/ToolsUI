#include <SFML/Graphics.hpp>
#include "EditorWorld.h"

int main()
{
	std::unique_ptr<editor::EditorWorld> editor = std::make_unique<editor::EditorWorld>();

	editor->start();
	while (editor->gameRunning() == true) {
		editor->eventHandler();
		editor->update();
		editor->render();
	}
	editor->quit();

	return 0;
}