#include <SFML/Graphics.hpp>
#include <thread>

using namespace sf;

#define g 9.81

struct pallina
{
    double velocity;
    double position;
    sf::CircleShape shape;
    double radius= 50;
    pallina(double _position, double _velocity) : position(_position), velocity(_velocity)
    {
        shape.setRadius(radius);
        shape.setPosition(500, _position);
        shape.setFillColor(sf::Color::Blue);
    }
};

void updateState(pallina& myPallina, double timeStep)
{   float dampening = 0.9; 
         if (myPallina.position > 600)
    {
          myPallina.velocity = -myPallina.velocity * dampening;
    }
    
    myPallina.velocity += (g * timeStep);
    myPallina.position += (myPallina.velocity * timeStep);
    myPallina.shape.setPosition(500, myPallina.position);

}

int main()
{
    pallina myPallina(400, 0);
    //pallina myPallina2(600,0); 
    double timeStep = 0.1;
    double totalTime = 0.0;
    double maxTime = 1000;
    sf::RenderWindow window(VideoMode(1000, 700), "pallina che cade");

    while (window.isOpen() && totalTime < maxTime)
    {
        updateState(myPallina, timeStep);

        window.clear();
        window.draw(myPallina.shape);
       // window.draw(myPallina2.shape);
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        totalTime += timeStep;
    }

    return 0;
}
