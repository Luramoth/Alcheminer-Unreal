// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.



#include "Chunk.h"
#include "ProceduralMeshComponent.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("procmesh");
	ProceduralMesh->SetupAttachment(GetRootComponent());
	
	//Grid.Reserve(CHUNKSIZE * CHUNKSIZE * CHUNKSIZE);
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AChunk::GenerateMesh()
{
	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2d>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);

}

void AChunk::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AChunk::MakeID()
{
	ID = GetActorLocation();
}
