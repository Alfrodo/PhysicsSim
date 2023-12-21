#include "Space.h"
#include "iostream"


void Space::addGravitySource(GravitySource* obj) {

		grav_sources.push_back(obj);
}

void Space::addParticle(Particle* obj) {

	particles.push_back(obj);
}

void Space::renderAllObjects(sf::RenderWindow& window) {
	for (GravitySource* gs: grav_sources)
	{
		gs->render(window);
	}

	for (Particle* p : particles)
	{
		p->render(window);
	}
}

void Space::updatePhysics() {
	for (GravitySource* gs : grav_sources)
	{
		for (Particle* p : particles)
		{
			p->updatePhysics(*gs);
		}
		
	}
}

GravitySource& Space::getGravitySourceByCoordinates(int x, int y)
{
	for (GravitySource* gs : grav_sources) {
		//if (x <= gs->getPos().x + gs->getSize())
	}
}
