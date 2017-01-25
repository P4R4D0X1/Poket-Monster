#ifndef PARTICLE_HPP_INCLUDE
#define PARTICLE_HPP_INCLUDE


#include "SFML/Graphics.hpp"

class CParticleSystem : public sf::Drawable, public sf::Transformable{
	public:
		CParticleSystem(unsigned int p_amount);

		void setEmitter(sf::Vector2f p_position);
		void update(sf::Time p_elapsed);

	private:
		virtual void draw(sf::RenderTarget& p_target, sf::RenderStates p_states) const;
		void resetParticle(std::size_t p_index);

		struct Particle{
			sf::Vector2f sm_velocity;
			sf::Time sm_lifetime;
		};

		std::vector<Particle> m_particles;
		sf::VertexArray m_vertices;
		sf::Time m_lifetime;
		sf::Vector2f m_emitter;
};
#endif