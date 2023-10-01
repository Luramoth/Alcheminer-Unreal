// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chunk.generated.h"

#define CHUNKSIZE 16

class UProceduralMeshComponent;

UCLASS()
class ALCHEMINER_API AChunk : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AChunk();

	UPROPERTY(BlueprintReadOnly, Transient, VisibleAnywhere)
	FVector ID;

	UFUNCTION(BlueprintCallable, Category="Generation")
	void GenerateMesh();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, meta=(MakeEditWidget = true))
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere)
	TArray<int> Triangles;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Replicated)
	int Grid[CHUNKSIZE * CHUNKSIZE * CHUNKSIZE];
	//TArray<int16> Grid;

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMesh;

	void MakeID();
};
