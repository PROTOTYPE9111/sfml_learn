#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode({800,650}), "Robotron test");
    
    sf::Image heroimage;
    heroimage.loadFromFile("src/images/wolf.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);
    
    sf::Sprite herosprite(herotexture);
    herosprite.setTextureRect(sf::IntRect({0, 192}, {96, 96}));

    herosprite.setPosition ({50,25});

    while (window.isOpen()){
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { herosprite.move ({-0.1,0}); }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { herosprite.move ({0.1,0}); }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { herosprite.move ({0,-0.1}); }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { herosprite.move ({0,0.1}); }
        window.clear();
        window.draw(herosprite);
        window.display();
    }
    return 0;
}