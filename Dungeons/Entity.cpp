#include "Entity.h"

Entity::Entity(int entityId) {
	this->entidyId = entityId;
}

int Entity::getEntityId() const {
	return entidyId;
}
