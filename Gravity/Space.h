#pragma once
#include "SpaceObject.h"
#include "GravitySource.h"
#include "Particle.h"
#include "Space.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Space
{
	std::vector<GravitySource*> grav_sources = {};
	std::vector<Particle*> particles = {};


public:
	void addGravitySource(GravitySource* obj);
	void addParticle(Particle* obj);

	void renderAllObjects(sf::RenderWindow& window);
	void updatePhysics();

	GravitySource& getGravitySourceByCoordinates(int x, int y);
};

