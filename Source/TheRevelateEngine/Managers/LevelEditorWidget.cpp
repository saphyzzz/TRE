// 2025 The Revelate Engine


#include "LevelEditorWidget.h"

bool ULevelEditorWidget::CheckAssetBounds(USizeBox InSizeBox, UUserWidget InWidget)
{
	if (IsValid(&InSizeBox) && IsValid(&InWidget))
	{
		// Get bounds of Sizebox
		FGeometry SizeBoxGeometry = InSizeBox.GetCachedGeometry();
		// FVector SizeBoxAbsPos = SizeBoxGeometry.GetAbsolutePosition(); 
	}
	return false; 
}
