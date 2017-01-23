#include "graphic.hpp"
#include "monster.hpp"
#include "attack.hpp"

CGraphic::CGraphic(){
	if (m_font.loadFromFile("DIMIS.ttf")){
		std::cout << "FONT LOADED \n\n";
	}

	sf::ContextSettings l_settings;
	l_settings.antialiasingLevel = 8;

	m_window.create(sf::VideoMode(800, 400), "POKET MONSTER", sf::Style::Default || ~sf::Style::Resize, l_settings);
	m_window.setVerticalSyncEnabled(true);
}

CGraphic::~CGraphic(){
}

void CGraphic::update(){
	m_window.display();
	m_window.clear(sf::Color(122, 122, 122, 255));
}

void CGraphic::displayPlayerName(std::string p_name){
	sf::Text l_text;
	sf::Vector2f l_position(m_window.getSize().x / 2.f, 0.f);

	l_text.setFont(m_font);

	l_text.setString(p_name);
	l_position.x -= l_text.getGlobalBounds().width / 2.f;
	l_text.setPosition(l_position);

	l_text.setFillColor(sf::Color::Blue);
	m_playerName = l_text.getGlobalBounds();

	m_window.draw(l_text);
}

void CGraphic::displayMonsters(CMonster& p_playerMonster, CMonster& p_enemyMonster){
	sf::Text l_text;
	sf::Vector2f l_position(m_window.getSize().x / 4.f, (m_playerName.height + m_playerName.top) * 1.5f);
	sf::RectangleShape l_rectangle;

	m_monsters.top = (m_playerName.height + m_playerName.top) * 1.5f;
	m_monsters.left = 0.f;
	m_monsters.width = (float)m_window.getSize().x;

	l_text.setFont(m_font);
	
	l_text.setFillColor(sf::Color::Green);
	l_text.setString(p_playerMonster.getName());
	l_position.x -= l_text.getGlobalBounds().width / 2.f;
	l_text.setPosition(l_position);
	l_position.x += l_text.getGlobalBounds().width / 2.f;
	l_position.y = l_text.getGlobalBounds().top + (l_text.getGlobalBounds().height * 1.2f);

	m_window.draw(l_text);

	l_rectangle.setFillColor(sf::Color::Transparent);
	l_rectangle.setOutlineThickness(2);
	l_rectangle.setOutlineColor(sf::Color::Black);

	l_rectangle.setSize(sf::Vector2f(m_window.getSize().x / 5.f, m_window.getSize().y / 40.f));
	l_rectangle.setPosition(sf::Vector2f(l_position.x - (l_rectangle.getGlobalBounds().width / 2.f), l_position.y));

	m_window.draw(l_rectangle);

	l_rectangle.setFillColor(sf::Color::Green);
	l_rectangle.setOutlineThickness(0);
	l_rectangle.setOutlineColor(sf::Color::Black);

	l_rectangle.setSize(sf::Vector2f((m_window.getSize().x / 5.f) * p_playerMonster.getLifePercentage(), m_window.getSize().y / 40.f));

	m_window.draw(l_rectangle);

	l_position = sf::Vector2f((m_window.getSize().x / 4.f) * 3.f, (m_playerName.height + m_playerName.top) * 1.5f);

	l_text.setFillColor(sf::Color::Red);
	l_text.setString(p_enemyMonster.getName());
	l_position.x -= l_text.getGlobalBounds().width / 2.f;
	l_text.setPosition(l_position);
	l_position.x += l_text.getGlobalBounds().width / 2.f;
	l_position.y = l_text.getGlobalBounds().top + (l_text.getGlobalBounds().height * 1.2f);

	m_window.draw(l_text);

	l_rectangle.setFillColor(sf::Color::Transparent);
	l_rectangle.setOutlineThickness(2);
	l_rectangle.setOutlineColor(sf::Color::Black);

	l_rectangle.setSize(sf::Vector2f(m_window.getSize().x / 5.f, m_window.getSize().y / 40.f));
	l_rectangle.setPosition(sf::Vector2f(l_position.x - (l_rectangle.getGlobalBounds().width / 2.f), l_position.y));

	m_window.draw(l_rectangle);

	l_rectangle.setFillColor(sf::Color::Green);
	l_rectangle.setOutlineThickness(0);
	l_rectangle.setOutlineColor(sf::Color::Black);

	l_rectangle.setSize(sf::Vector2f((m_window.getSize().x / 5.f) * p_enemyMonster.getLifePercentage(), m_window.getSize().y / 40.f));

	m_window.draw(l_rectangle);

	m_monsters.height = (l_rectangle.getGlobalBounds().top + l_rectangle.getGlobalBounds().height) - m_monsters.top;
}

bool CGraphic::displayMenuAction(std::map<std::string, Menu::TYPE>& p_actions, std::map<std::string, Menu::TYPE>::iterator& p_action){
	std::map<std::string, Menu::TYPE>::iterator l_iterator;
	
	sf::Event l_event;
	sf::Text l_text;
	sf::Vector2f l_position(m_window.getSize().x / 2.f, (m_monsters.top + m_monsters.height) * 1.5f);

	l_text.setFont(m_font);

	while (m_window.pollEvent(l_event)){
		switch (l_event.type){
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::KeyPressed:
				switch (l_event.key.code){
					case sf::Keyboard::Up:
						if (p_action == p_actions.begin())
							p_action = --p_actions.end();
						else 
							p_action--;

						break;

					case sf::Keyboard::Down:
						if (p_action == --p_actions.end())
							p_action = p_actions.begin();
						else
							p_action++;

						break;

					case sf::Keyboard::Return:
						return true;
						break;
				}
				break;

			default:
				break;
		}
	}
	
	//FAIRE L'AFFICHAGE DU TEXTE LA
	for (l_iterator = p_actions.begin(); l_iterator != p_actions.end(); ++l_iterator){
		l_text.setString(l_iterator->first);
		l_position.x -= l_text.getGlobalBounds().width / 2.f;
		l_text.setPosition(l_position);
		l_position.x += l_text.getGlobalBounds().width / 2.f;

		if (*l_iterator == *p_action)
			l_text.setFillColor(sf::Color::Red);
		else
			l_text.setFillColor(sf::Color::Black);

		l_position.y += l_text.getGlobalBounds().height * 1.5f;
		m_window.draw(l_text);
	}

	return false;
}

bool CGraphic::displayMenuMonster(std::vector<CMonster*>& p_monsters, std::vector<CMonster*>::iterator& p_monster){
	std::vector<CMonster*>::iterator l_iterator;

	sf::Event l_event;
	sf::Text l_text;
	sf::Vector2f l_position(m_window.getSize().x / 4.f, (m_monsters.top + m_monsters.height) * 1.5f);
	sf::RectangleShape l_rectangle;

	l_text.setFont(m_font);

	l_rectangle.setFillColor(sf::Color::Transparent);
	l_rectangle.setOutlineThickness(2);
	l_rectangle.setOutlineColor(sf::Color::Black);

	while (m_window.pollEvent(l_event)){
		switch (l_event.type){
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			switch (l_event.key.code){
			case sf::Keyboard::Up:
				if (p_monster == p_monsters.begin())
					p_monster = --p_monsters.end();
				else
					p_monster--;

				break;

			case sf::Keyboard::Down:
				if (p_monster == --p_monsters.end())
					p_monster = p_monsters.begin();
				else
					p_monster++;

				break;

			case sf::Keyboard::Return:
				return true;
				break;
			}
			break;

		default:
			break;
		}
	}
	
	//On affiche les caractéristiques du monstre séléctionné
	l_position.x = (m_window.getSize().x / 4.f) * 3.f;
	l_text.setString((*p_monster)->infoToString());
	l_position.x -= l_text.getGlobalBounds().width / 2.f;
	l_text.setPosition(l_position);
	l_text.setFillColor(sf::Color::Black);

	m_window.draw(l_text);
	l_position = sf::Vector2f(m_window.getSize().x / 4.f, (m_monsters.top + m_monsters.height) * 1.5f);

	//FAIRE L'AFFICHAGE DU TEXTE LA
	for (l_iterator = p_monsters.begin(); l_iterator != p_monsters.end(); ++l_iterator){
		l_text.setString((*l_iterator)->getName());

		l_position.x -= l_text.getGlobalBounds().width / 2.f;
		l_text.setPosition(l_position);
		l_position.x += l_text.getGlobalBounds().width / 2.f;

		if (l_iterator == p_monster)
			l_text.setFillColor(sf::Color::Red);
		else
			l_text.setFillColor(sf::Color::Black);

		l_position.y += (l_text.getGlobalBounds().height * 1.5f);
		m_window.draw(l_text);
	}

	return false;
}

bool CGraphic::displayMenuAttack(std::vector<CAttack*>& p_attacks, std::vector<CAttack*>::iterator& p_attack){
	std::vector<CAttack*>::iterator l_iterator;

	sf::Event l_event;
	sf::Text l_text;
	sf::Vector2f l_position(m_window.getSize().x / 4.f, (m_monsters.top + m_monsters.height) * 1.5f);

	l_text.setFont(m_font);

	while (m_window.pollEvent(l_event)){
		switch (l_event.type){
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			switch (l_event.key.code){
			case sf::Keyboard::Up:
				if (p_attack == p_attacks.begin())
					p_attack = --p_attacks.end();
				else
					p_attack--;

				break;

			case sf::Keyboard::Down:
				if (p_attack == --p_attacks.end())
					p_attack = p_attacks.begin();
				else
					p_attack++;

				break;

			case sf::Keyboard::Return:
				return true;
				break;
			}
			break;

		default:
			break;
		}
	}

	//On affiche les caractéristiques du monstre séléctionné
	l_position.x = (m_window.getSize().x / 4.f) * 3.f;
	l_text.setString((*p_attack)->infoToString());
	l_position.x -= l_text.getGlobalBounds().width / 2.f;
	l_text.setPosition(l_position);
	l_text.setFillColor(sf::Color::Black);

	m_window.draw(l_text);
	l_position = sf::Vector2f(m_window.getSize().x / 4.f, (m_monsters.top + m_monsters.height) * 1.5f);

	//FAIRE L'AFFICHAGE DU TEXTE LA
	for (l_iterator = p_attacks.begin(); l_iterator != p_attacks.end(); ++l_iterator){
		l_text.setString((*l_iterator)->getName());

		l_position.x -= l_text.getGlobalBounds().width / 2.f;
		l_text.setPosition(l_position);
		l_position.x += l_text.getGlobalBounds().width / 2.f;

		if (l_iterator == p_attack)
			l_text.setFillColor(sf::Color::Red);
		else
			l_text.setFillColor(sf::Color::Black);

		l_position.y += (l_text.getGlobalBounds().height * 1.5f);
		m_window.draw(l_text);
	}

	return false;
}