#include "gl.hpp"

#include <iostream>
#include <SFML/Window.hpp>

int main()
{
	sf::Window window;
	sf::ContextSettings settings;
	settings.majorVersion = 4;
	settings.minorVersion = 4;
	settings.attributeFlags = sf::ContextSettings::Debug;

	window.create( sf::VideoMode{ 600, 600 }, "SFML Window", sf::Style::Close, settings );
	gl_init();
	glClearColor( 1.0f, 0, 1.0f, 1.0f );

	sf::Event ev;
	while ( window.isOpen() ) {
		while ( window.pollEvent( ev ) ) {
			if ( ev.type == sf::Event::Closed ) {
				window.close();
			}
		}

		glClear( GL_COLOR_BUFFER_BIT );
		window.display();
	}


	std::cout << "Hello, world!\n";
}