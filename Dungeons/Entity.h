#pragma once
class Entity {
private:
	int entidyId;
public:
	Entity(int entityId);
	virtual ~Entity() = default;
	int getEntityId() const;
};

