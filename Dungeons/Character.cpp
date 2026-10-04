#include "Character.h"

Character::Character(int instanceId) {
	this->instanceId = instanceId;
}

int Character::getInstanceId() const {
	return instanceId;
}

double Character::getHealth() const {
	return health;
}
