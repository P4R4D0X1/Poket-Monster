#include "graphic.hpp"
#include "monster.hpp"

CGraphic::CGraphic(){
	if (m_font.loadFromFile("DIMIS.ttf")){
		std::cout << "FONT LOADED \n\n";
	}

	sf::ContextSettings l_settings;
	l_settings.antialiasingLevel = 8;

	m_window.create(sf::VideoMode(800, 600), "POKET MONSTER", sf::Style::Default);
	m_window.setVerticalSyncEnabled(true);
}

CGraphic::~CGraphic(){
}

void CGraphic::update(){
	m_window.display();
	m_window.clear(sf::Color::White);
}

bool CGraphic::displayMenuAction(std::map<std::string, Menu::TYPE>& p_actions, std::map<std::string, Menu::TYPE>::iterator& p_action){
	std::map<std::string, Menu::TYPE>::iterator l_iterator;
	
	sf::Event l_event;
	sf::Text l_text;
	sf::Vector2f l_position(0.f, 0.f);

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
		l_text.setPosition(l_position);

		if (*l_iterator == *p_action)
			l_text.setFillColor(sf::Color::Red);
		else
			l_text.setFillColor(sf::Color::Black);

		l_position.y += l_text.getGlobalBounds().height;
		m_window.draw(l_text);
	}

	return false;
}

bool CGraphic::displayMenuMonster(std::vector<CMonster*>& p_monsters, std::vector<CMonster*>::iterator& p_monster){
	std::vector<CMonster*>::iterator l_iterator;

	sf::Event l_event;
	sf::Text l_text;
	sf::Vector2f l_position(0.f, 0.f);

	l_text.setFont(m_font);

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
	l_position.x = m_window.getSize().x / 2.f;
	l_text.setString((*p_monster)->infoToString());
	l_text.setPosition(l_position);
	l_text.setFillColor(sf::Color::Black);

	m_window.draw(l_text);
	l_position = sf::Vector2f(0, 0);

	//FAIRE L'AFFICHAGE DU TEXTE LA
	for (l_iterator = p_monsters.begin(); l_iterator != p_monsters.end(); ++l_iterator){
		l_text.setString((*l_iterator)->getName());
		l_text.setPosition(l_position);

		if (l_iterator == p_monster)
			l_text.setFillColor(sf::Color::Red);
		else
			l_text.setFillColor(sf::Color::Black);

		l_position.y += (l_text.getGlobalBounds().height * 1.5f);
		m_window.draw(l_text);
	}

	return false;
}