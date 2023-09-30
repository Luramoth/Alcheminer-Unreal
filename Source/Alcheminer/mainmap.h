// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"
#include "Engine/LevelScriptActor.h"
#include "mainmap.generated.h"

/**
 * 
 */
UCLASS()
class ALCHEMINER_API Amainmap : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TArray<AChunk*> LoadedChunks;
};
