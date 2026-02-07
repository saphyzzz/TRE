// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "LevelEditorWidget.generated.h"

/**
 * 
 */
UCLASS()
class THEREVELATEENGINE_API ULevelEditorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "LevelEditorWidget")
	bool CheckAssetBounds(USizeBox *InSizeBox, UUserWidget *InWidget); 
};
