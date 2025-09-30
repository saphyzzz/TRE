// 2025 The Revelate Engine


#include "PlayerTask.h"

void UPlayerTask::SetCompleted(bool InCompleted)
{
	bCompleted = InCompleted;
}

void UPlayerTask::SetTested(bool InTested)
{
	bTested = InTested;
}

void UPlayerTask::SetTaskDescription(FString InDescription)
{
	TaskDescription = InDescription;
}
