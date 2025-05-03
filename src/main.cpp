#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode({800,800}), "Robotron test");
    
    sf::Image heroimage;
    heroimage.loadFromFile("src/images/wolf.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);
    
    sf::Sprite herosprite(herotexture);
    herosprite.setTextureRect(sf::IntRect({0, 192}, {96, 96}));
    herosprite.setPosition ({50,25});

    float CurrentFrame = 0; 
    sf::Clock clock;

    
    while (window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        std::optional<sf::Event> event;

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
   
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)))) { herosprite.move({-0.1f*time, 0.f}); herosprite.setTextureRect(sf::IntRect({0, 96}, {96, 96})); } //добавили управление на клавиши W,S,A,D
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))) { herosprite.move({0.1f*time, 0.f}); herosprite.setTextureRect(sf::IntRect({0, 192}, {96, 96})); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)))) { herosprite.move({0.f, -0.1f*time}); herosprite.setTextureRect(sf::IntRect({0, 288}, {96, 96})); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))) { herosprite.move({0.f, 0.1f*time}); herosprite.setTextureRect(sf::IntRect({0, 0}, {96, 96})); }  
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            herosprite.setColor(sf::Color::Red);
        }

        if (herosprite.getPosition().x )
        window.clear();
        window.draw(herosprite);
        window.display();
    }
    return 0;
}