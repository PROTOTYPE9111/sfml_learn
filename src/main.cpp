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
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)))) { herosprite.move({-0.1, 0}); herosprite.setTextureRect(sf::IntRect({0, 96}, {96, 96})); } //добавили управление на клавиши W,S,A,D
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))) { herosprite.move({0.1, 0}); herosprite.setTextureRect(sf::IntRect({0, 192}, {96, 96})); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)))) { herosprite.move({0, -0.1}); herosprite.setTextureRect(sf::IntRect({0, 288}, {96, 96})); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))) { herosprite.move({0, 0.1}); herosprite.setTextureRect(sf::IntRect({0, 0}, {96, 96})); }  
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            herosprite.setColor(sf::Color::Red);
        }
        window.clear();
        window.draw(herosprite);
        window.display();
    }
    return 0;
}