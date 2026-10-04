#pragma once
class Character {
private:
	int instanceId;
	double health;
public:
	Character(int instanceId);
	int getInstanceId() const;
	double getHealth() const;
};
