#include "particle.hpp"

CParticleSystem::CParticleSystem(unsigned int p_amount) : m_particles(p_amount), m_vertices(sf::LinesStrip, p_amount), m_lifetime(sf::seconds(3)), m_emitter(0, 0){
}

void CParticleSystem::setEmitter(sf::Vector2f p_position){
	m_emitter = p_position;
}

void CParticleSystem::update(sf::Time p_elapsed){
	srand(time(NULL));
	for (std::size_t l_i = 0; l_i < m_particles.size(); ++l_i){
		Particle& p = m_particles[l_i];
		p.sm_lifetime -= p_elapsed;

		if (p.sm_lifetime <= sf::Time::Zero)
			resetParticle(l_i);

		m_vertices[l_i].position += p.sm_velocity * p_elapsed.asSeconds();

		float ratio = p.sm_lifetime.asSeconds() / m_lifetime.asSeconds();
		m_vertices[l_i].color = sf::Color(rand() % 254, rand() % 254, rand() % 254);
		m_vertices[l_i].color.a = static_cast<sf::Uint8>(ratio * 255);
	}
}

void CParticleSystem::draw(sf::RenderTarget& p_target, sf::RenderStates p_states) const{

	p_states.transform *= getTransform();
	p_states.texture = NULL;
	p_target.draw(m_vertices, p_states);
}

void CParticleSystem::resetParticle(std::size_t p_index){
	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = (std::rand() % 50) + 50.f;
	m_particles[p_index].sm_velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[p_index].sm_lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

	m_vertices[p_index].position = m_emitter;
}