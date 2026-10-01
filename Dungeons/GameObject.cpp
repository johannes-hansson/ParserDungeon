#include "GameObject.h"

GameObject::GameObject(int instanceId) {
	this->instanceId = instanceId;
}

void GameObject::setInstanceId(int instanceId) {
	this->instanceId = instanceId;
}

int GameObject::getInstanceId() const {
	return this->instanceId;
}
