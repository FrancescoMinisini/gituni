#include <SFML/Graphics.hpp>
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
#include <iostream>

using namespace std;

struct puntoR2 {
    double x;
    double y;
};

// Function prototypes
void imposta_seed();
double distance(puntoR2 p1, puntoR2 p2);
bool is_inside_circle(puntoR2 p, double r, sf::RenderWindow& window);
int count_within(int n, double r, sf::RenderWindow& window);
double rilev(int n, double r, sf::RenderWindow& window);

int main() {
    imposta_seed();
    puntoR2 O;
    O.x = 0;
    O.y = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Window");

    sf::CircleShape circle(100);
    circle.setPosition(500, 500);

    // Main loop
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    double res;
    double r = 1;
    double n = 10000000;
    res = rilev(n, r, window);
    cout << endl << res << endl;

    return 0;
}

double distance(puntoR2 p1, puntoR2 p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool is_inside_circle(puntoR2 p, double r, sf::RenderWindow& window) {
    puntoR2 O;
    O.x = 0, O.y = 0;
    double d = distance(p, O);

    return (r >= d);
}

int count_within(int n, double r, sf::RenderWindow& window) {
    puntoR2 test;
    int res = 0;

    for (int i = 0; i < n; i++) {
        test.x = rand_uniforme(0, r);
        test.y = rand_uniforme(0, r);

        sf::CircleShape circle(1);
        circle.setPosition(test.x * 100 + 500, test.y * 100 + 500);

        if (is_inside_circle(test, r, window)) {
            res++;
            circle.setFillColor(sf::Color::Green);
        } else {
            circle.setFillColor(sf::Color::Red);
        }

        window.draw(circle);
        window.display();
    }

    return res;
}

double rilev(int n, double r, sf::RenderWindow& window) {
    double res;
    res = static_cast<double>(count_within(n, r, window)) * 4 / n;
    return res;
}
