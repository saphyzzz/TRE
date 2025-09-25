// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TaskManager.generated.h"

UCLASS()
class THEREVELATEENGINE_API ATaskManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATaskManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
