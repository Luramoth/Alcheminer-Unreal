// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.


#include "mainmap.h"

void Amainmap::BeginPlay()
{
	const FVector loc(0.0f,0.0f,0.0f);
	const FTransform trans(FQuat::Identity, loc);
	
	LoadedChunks.Add(GetWorld()->SpawnActor<AChunk>(AChunk::StaticClass(), trans));
}
