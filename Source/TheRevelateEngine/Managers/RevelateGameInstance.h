// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RevelateGameInstance.generated.h"

/**
 *  
 */
UCLASS()
class THEREVELATEENGINE_API URevelateGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:

	virtual void Init() override;

	/** Opportunity for blueprints to handle the game instance after it has been initialized */
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "PostInit"))
	void ReceiveInitPostSubsystem();

	
};

