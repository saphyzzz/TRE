// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ScareManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class THEREVELATEENGINE_API UScareManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite) bool bCanvasScareHandled = false; 
};
