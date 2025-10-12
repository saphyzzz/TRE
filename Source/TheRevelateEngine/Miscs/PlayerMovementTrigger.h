// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerMovementTrigger.generated.h"

UCLASS()
class THEREVELATEENGINE_API APlayerMovementTrigger : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable) void CollisionHandled();
	UFUNCTION(BlueprintCallable) bool CanTrigger(); 
	
	inline static bool bCollisionHandled = false;

protected:
	virtual void BeginPlay() override;
};
