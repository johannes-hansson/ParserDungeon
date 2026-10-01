#pragma once

class World;

class GameObject {
private:
	int instanceId;
	friend class World;
	void setInstanceId(int instanceId);
public:
	GameObject(int instanceId);
	int getInstanceId() const;
};

