// 2025 The Revelate Engine


#include "PlayerMovementTrigger.h"

void APlayerMovementTrigger::BeginPlay()
{
	Super::BeginPlay();
	bCollisionHandled = false;
}

void APlayerMovementTrigger::CollisionHandled()
{
	bCollisionHandled = true;
}

bool APlayerMovementTrigger::CanTrigger()
{
	if (bCollisionHandled)
	{
		return false; 
	}
	bCollisionHandled = true;
	return true;
}