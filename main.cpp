#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "imgui.h"
#include "imgui-SFML.h"

static bool win = false;
static bool isFinished = false;
static bool constFPS = false;
static int fps = 0;
static float backgroundColor[3] = {0, 0, 0};
static float cardBackgroundColor[3] = {0, 0, 0};
class Card;
std::vector<Card*> cards;

class Card
{
private:
    sf::Sprite* sprite;
    sf::Text text;
    sf::Font font;
    sf::Texture* backgroundTextTexture;
    bool clicked = false;

public:
    void setText(const std::string& message)
    {
        if (message == "")
        {
            text.setString(message);
            return;
        }
        if (clicked == false)
        {
            clicked = true;
            text.setString(message);
        }
    }

    sf::Text& getText() { return text; }
    Card() = delete;
    bool& changed() { return clicked; }

    Card(const sf::Vector2f vector2)
    {
        backgroundTextTexture = new sf::Texture;
        sprite = new sf::Sprite;
        backgroundTextTexture->loadFromFile("res/Rectangle 1.png");
        font.loadFromFile("res/FredokaOne-Regular.ttf");
        text.setFont(font);
        text.setCharacterSize(150);
        text.setFillColor(sf::Color::White);
        text.setOutlineThickness(0.25f);
        text.setOutlineColor(sf::Color::Red);
        text.setPosition(vector2 + sf::Vector2f(80, 45));
        text.setString("");
        sprite->setTexture(*backgroundTextTexture);
        sprite->setPosition(vector2);
        clicked = false;
    }

    explicit operator sf::Sprite*() const
    {
        return sprite;
    }

    void setTextColor(const sf::Color& color) { text.setFillColor(color); }
};

Card* ai()
{
    using namespace std;
    vector<int> ivec;

    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i]->changed() == false)
        {
            ivec.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ivec.begin(), ivec.end(), g);
    auto randomIndex = ivec.size() > 0 ? ivec[0] : -1;


    return randomIndex == -1 ? nullptr : cards[randomIndex];
}

bool check()
{
    if (cards[0]->getText().getString() != "" && cards[0]->getText().getString() == cards[1]->getText().getString()
        && cards[1]->getText().getString() == cards[2]->getText().getString())
    {
        const std::string s = cards[0]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[0]->getText().setFillColor(sf::Color::Green);
            cards[1]->getText().setFillColor(sf::Color::Green);
            cards[2]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[0]->getText().setFillColor(sf::Color::Red);
            cards[1]->getText().setFillColor(sf::Color::Red);
            cards[2]->getText().setFillColor(sf::Color::Red);
        }
    }

    else if (cards[3]->getText().getString() != "" && cards[3]->getText().getString() == cards[4]->getText().getString()
        && cards[3]->getText().getString() == cards[5]->getText().getString())
    {
        const std::string s = cards[3]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[3]->getText().setFillColor(sf::Color::Green);
            cards[4]->getText().setFillColor(sf::Color::Green);
            cards[5]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[3]->getText().setFillColor(sf::Color::Red);
            cards[4]->getText().setFillColor(sf::Color::Red);
            cards[5]->getText().setFillColor(sf::Color::Red);
        }
    }
    else if (cards[6]->getText().getString() != "" && cards[6]->getText().getString() == cards[7]->getText().getString()
        && cards[6]->getText().getString() == cards[8]->getText().getString())
    {
        const std::string s = cards[6]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[6]->getText().setFillColor(sf::Color::Green);
            cards[7]->getText().setFillColor(sf::Color::Green);
            cards[8]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[6]->getText().setFillColor(sf::Color::Red);
            cards[7]->getText().setFillColor(sf::Color::Red);
            cards[8]->getText().setFillColor(sf::Color::Red);
        }
    }


    else if (cards[0]->getText().getString() != "" && cards[0]->getText().getString() == cards[3]->getText().getString()
        && cards[0]->getText().getString() == cards[6]->getText().getString())
    {
        const std::string s = cards[0]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[0]->getText().setFillColor(sf::Color::Green);
            cards[3]->getText().setFillColor(sf::Color::Green);
            cards[6]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[0]->getText().setFillColor(sf::Color::Red);
            cards[3]->getText().setFillColor(sf::Color::Red);
            cards[6]->getText().setFillColor(sf::Color::Red);
        }
    }

    else if (cards[1]->getText().getString() != "" && cards[1]->getText().getString() == cards[4]->getText().getString()
        && cards[1]->getText().getString() == cards[7]->getText().getString())
    {
        const std::string s = cards[1]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[1]->getText().setFillColor(sf::Color::Green);
            cards[4]->getText().setFillColor(sf::Color::Green);
            cards[7]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[1]->getText().setFillColor(sf::Color::Red);
            cards[4]->getText().setFillColor(sf::Color::Red);
            cards[7]->getText().setFillColor(sf::Color::Red);
        }
    }


    else if (cards[2]->getText().getString() != "" && cards[2]->getText().getString() == cards[5]->getText().getString()
        && cards[2]->getText().getString() == cards[8]->getText().getString())
    {
        const std::string s = cards[2]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[2]->getText().setFillColor(sf::Color::Green);
            cards[5]->getText().setFillColor(sf::Color::Green);
            cards[8]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[2]->getText().setFillColor(sf::Color::Red);
            cards[5]->getText().setFillColor(sf::Color::Red);
            cards[8]->getText().setFillColor(sf::Color::Red);
        }
    }


    else if (cards[0]->getText().getString() != "" && cards[0]->getText().getString() == cards[4]->getText().getString()
        && cards[0]->getText().getString() == cards[8]->getText().getString())
    {
        const std::string s = cards[0]->getText().getString();
        isFinished = true;

        if (s == "X")
        {
            cards[0]->getText().setFillColor(sf::Color::Green);
            cards[4]->getText().setFillColor(sf::Color::Green);
            cards[8]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[0]->getText().setFillColor(sf::Color::Red);
            cards[4]->getText().setFillColor(sf::Color::Red);
            cards[8]->getText().setFillColor(sf::Color::Red);
        }
    }

    else if (cards[2]->getText().getString() != "" && cards[2]->getText().getString() == cards[4]->getText().getString()
        && cards[2]->getText().getString() == cards[6]->getText().getString())
    {
        const std::string s = cards[2]->getText().getString();
        isFinished = true;
        if (s == "X")
        {
            cards[2]->getText().setFillColor(sf::Color::Green);
            cards[4]->getText().setFillColor(sf::Color::Green);
            cards[6]->getText().setFillColor(sf::Color::Green);
            win = true;
        }
        else
        {
            cards[2]->getText().setFillColor(sf::Color::Red);
            cards[4]->getText().setFillColor(sf::Color::Red);
            cards[6]->getText().setFillColor(sf::Color::Red);
        }
    }

    return win;
}

void reset()
{
    isFinished = false;
    win = false;

    for (const auto card : cards)
    {
        card->changed() = false;
        card->setText("");
        card->changed() = false;
        card->setTextColor(sf::Color::White);
    }
    win = false;
}

int main()
{
    Card* card0 = new Card(sf::Vector2f(500, 45));
    cards.push_back(card0);
    Card* card1 = new Card(sf::Vector2f(800, 45));
    cards.push_back(card1);
    Card* card2 = new Card(sf::Vector2f(1100, 45));
    cards.push_back(card2);

    Card* card3 = new Card(sf::Vector2f(500, 345));
    cards.push_back(card3);
    Card* card4 = new Card(sf::Vector2f(800, 345));
    cards.push_back(card4);
    Card* card5 = new Card(sf::Vector2f(1100, 345));
    cards.push_back(card5);

    Card* card6 = new Card(sf::Vector2f(500, 645));
    cards.push_back(card6);
    Card* card7 = new Card(sf::Vector2f(800, 645));
    cards.push_back(card7);
    Card* card8 = new Card(sf::Vector2f(1100, 645));
    cards.push_back(card8);


    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tic-Tac-Toe");
    ImGui::SFML::Init(window);

    sf::Clock clock;
    sf::Clock deltaClock;


    int inputFps = 60;
    ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.0f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_Header] = ImVec4(1.f, 1.f, 1.0f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_CheckMark] = ImVec4(0.f, 1.f, 0.0f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.f, 0.f, .050f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ImVec4(0.f, 1.f, .050f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = ImVec4(0.f, 0.f, 0.f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_TextDisabled] = ImVec4(1.f, 1.f, 1.f, 1.f);
    ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(1.f, 1.f, 0.f, 1.f);
    while (window.isOpen())
    {
        fps = static_cast<int>(1.f / clock.getElapsedTime().asSeconds());
        clock.restart();


        sf::Event event;


        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            reset();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                for (int i = 0; i < cards.size(); ++i)
                {
                    Card& card = *cards[i];
                    auto b = check();

                    if (card.changed()) { continue; }
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (isFinished == false && static_cast<sf::Sprite*>(card)->getGlobalBounds().contains(mousePos))
                    {
                        using namespace std;

                        card.setText("X");

                        if (check() == false)
                        {
                            auto c = ai();
                            if (c != nullptr)
                            {
                                c->setText("O");
                            }
                        }
                    }
                }
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("Color Settings");

        ImGui::GetFont()->FontSize = 25;
        ImGui::SetWindowSize(ImVec2(250, 1080));
        ImGui::SetWindowPos(ImVec2(0, 0));
        ImGui::Text(" Background Color");
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(1.f, 0.f, 0.f, 1.f);
        ImGui::SliderFloat("Red##", &backgroundColor[0], 0, 255);
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(0.f, 1.f, 0.f, 1.f);
        ImGui::SliderFloat("Green##", &backgroundColor[1], 0, 255);
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(0.f, 0.f, 1.f, 1.f);
        ImGui::SliderFloat("Blue##", &backgroundColor[2], 0, 255);
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Text(" Sprite  Color");
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(1.f, 0.f, 0.f, 1.f);
        ImGui::SliderFloat("Red", &cardBackgroundColor[0], 0, 255);
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(0.f, 1.f, 0.f, 1.f);
        ImGui::SliderFloat("Green", &cardBackgroundColor[1], 0, 255);
        ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = ImVec4(0.f, 0.f, 1.f, 1.f);
        ImGui::SliderFloat("Blue", &cardBackgroundColor[2], 0, 255);
        ImGui::SetColorEditOptions(ImGuiColorEditFlags_DisplayHex);
        ImGui::Spacing();
        ImGui::End();
        ImGui::Begin("Game Settings");
        ImGui::GetFont()->FontSize = 25;
        ImGui::SetWindowSize(ImVec2(300, 1080));
        ImGui::SetWindowPos(ImVec2(1920 - 300, 0));
        ImGui::Text("Fps");
        ImGui::Text(std::to_string(static_cast<int>(fps)).c_str());
        ImGui::Spacing();
        ImGui::Spacing();
        if (ImGui::Button("Reset Game"))
        {
            reset();
        }
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::DragInt("Target FPS", &inputFps);
        ImGui::Spacing();
        ImGui::Spacing();
        if (ImGui::Checkbox("Frame Rate Limit", &constFPS))
        {
            if (constFPS)
            {
                window.setFramerateLimit(inputFps);
            }
            else
            {
                window.setFramerateLimit(9000);
            }
        }

        ImGui::End();
        window.clear(sf::Color(backgroundColor[0], backgroundColor[1], backgroundColor[2], 255));
        for (int i = 0; i < cards.size(); ++i)
        {
            static_cast<sf::Sprite*>(*cards[i])->setColor(
                sf::Color(cardBackgroundColor[0], cardBackgroundColor[1], cardBackgroundColor[2], 255));
            window.draw(*static_cast<sf::Sprite*>(*cards[i]));
            window.draw(cards[i]->getText());
        }
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
