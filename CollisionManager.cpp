#include "CollisionManager.h"



//int CollisionManager::squaredDistance(glm::vec2 P1, glm::vec2 P2)
//{
//	int diffOfXs = P2.x - P1.x;
//	int diffOfYs = P2.y - P1.y;
//	int result = diffOfXs * diffOfXs + diffOfYs * diffOfYs;
//
//	return result;
//}
//
//bool CollisionManager::squaredRadiusCheck(GameObject * object1, GameObject * object2)
//{
//	glm::vec2 P1 = object1->getPosition();
//	glm::vec2 P2 = object2->getPosition();
//	int halfHeights = (object1->getHeight() + object2->getHeight()) * 0.5;
//
//	//if (glm::distance(P1, P2) < halfHeights) {
//
//	if (CollisionManager::squaredDistance(P1, P2) < (halfHeights * halfHeights)) {
//		if (!object2->getIsColliding()) {
//			
//			object2->setIsColliding(true);
//
//			switch (object2->getType()) {
//			case ISLAND:
//				std::cout << "Collision with Island!" << std::endl;
//				TheSoundManager::Instance()->playSound("yay", 0);
//				break;
//			case CLOUD:
//				std::cout << "Collision with Cloud!" << std::endl;
//				TheSoundManager::Instance()->playSound("thunder", 0);
//				break;
//			case BULLET:
//				break;
//			case ENEMY:
//				break;
//			default:
//				std::cout << "Collision with unknown type!" << std::endl;
//					break;
//			}
//
//			return true;
//		}
//		return false;
//	}
//	return false;
//	
//}

bool CollisionManager::AABBCollisionCheck(GameObject * object1, GameObject * object2)
{
	glm::vec2 vector1 = object1->getPosition();
	glm::vec2 vector2 = object2->getPosition();
	
	if (vector1.x < vector2.x + object2->getWidth() && //player left check
		vector1.x + object1->getWidth() > vector2.x && //player right check
		vector1.y < vector2.y + object2->getHeight() && //player top check
		vector1.y + object1->getHeight() > vector2.y) //player bottom check
	{
		return true;
	}

	return false;
}

bool CollisionManager::AABBCollisionTypeCheck(GameObject * object1, GameObject * object2)
{
	if (Collision::AABBCollisionCheck(object1, object2) == false) 
		return false;

	if (!object2->getIsColliding())
	{
		object2->setIsColliding(true);

		switch (object2->getType())
		{
		case ISLAND:
			std::cout << "Collision with Island!" << std::endl;
			TheSoundManager::Instance()->playSound("yay", 0);
			break;
		case CLOUD:
			std::cout << "Collision with Cloud!" << std::endl;
			TheSoundManager::Instance()->playSound("thunder", 0);
			break;
		case BULLET:
			break;
		case ENEMY:
			break;
		default:
			std::cout << "Collision with unknown type!" << std::endl;
			break;
		}
		return true;
	}
	return false;
}

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}
