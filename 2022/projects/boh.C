#include <SFML/Graphics.hpp>
#include <cmath>
#include <thread>

const double G = 667.430;  // Adjusted gravitational constant
const double dampingFactor = 0.999;  // Damping factor to prevent unbounded acceleration

struct Vector2D {
    double x, y;

    Vector2D(double _x, double _y) : x(_x), y(_y) {}
};

struct CelestialBody {
    Vector2D position;
    Vector2D velocity;
    double mass;
    sf::CircleShape shape;

    CelestialBody(Vector2D _position, Vector2D _velocity, double _mass)
        : position(_position), velocity(_velocity), mass(_mass) {
        shape.setRadius(5.0f);
        shape.setPosition(static_cast<float>(_position.x), static_cast<float>(_position.y));
        shape.setFillColor(sf::Color::Blue);
    }
};

Vector2D calculateGravity(const CelestialBody& body1, const CelestialBody& body2) {
    double dx = body2.position.x - body1.position.x;
    double dy = body2.position.y - body1.position.y;
    double distanceSquared = dx * dx + dy * dy;
    double distance = sqrt(distanceSquared);

    double forceMagnitude = (G * body1.mass * body2.mass) / distanceSquared;

    double forceX = forceMagnitude * (dx / distance);
    double forceY = forceMagnitude * (dy / distance);

    return Vector2D(forceX, forceY);
}

void updateState(CelestialBody& body, const Vector2D& force, double timeStep) {
    // Semi-implicit Euler integration with damping
    body.velocity.x += force.x / body.mass * timeStep;
    body.velocity.y += force.y / body.mass * timeStep;

    body.velocity.x *= dampingFactor;
    body.velocity.y *= dampingFactor;

    body.position.x += body.velocity.x * timeStep;
    body.position.y += body.velocity.y * timeStep;

    body.shape.setPosition(static_cast<float>(body.position.x), static_cast<float>(body.position.y));
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Planet Orbit Simulation");

    CelestialBody planet1(Vector2D(400, 300), Vector2D(0, 100), 1e4);
    CelestialBody planet2(Vector2D(600, 300), Vector2D(0, -100), 1e4);

    double timeStep = 0.1;  // Adjusted time step
    double totalTime = 0.0;
    double maxTime = 100.0;  // Maximum simulation time

    while (window.isOpen() && totalTime < maxTime) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Vector2D forcePlanet1 = calculateGravity(planet1, planet2);
        Vector2D forcePlanet2 = calculateGravity(planet2, planet1);

        updateState(planet1, forcePlanet1, timeStep);
        updateState(planet2, forcePlanet2, timeStep);

        window.clear();
        window.draw(planet1.shape);
        window.draw(planet2.shape);
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        totalTime += timeStep;
    }

    return 0;
}

