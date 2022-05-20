#ifndef __LEVEL_GENERATOR_H__
#define __LEVEL_GENERATOR_H__

#include "DefinitionGenerator.h"
#include "StaticGenerator.h"
#include "CollisionGenerator.h"
#include "../DisplayListSettings.h"
#include "TriggerGenerator.h"

class LevelGenerator {
public:
    LevelGenerator(
        const DisplayListSettings& settings,
        const StaticGeneratorOutput& staticOutput,
        const CollisionGeneratorOutput& collisionOutput,
        const TriggerGeneratorOutput& triggerOutput
    );

    void GenerateDefinitions(const aiScene* scene, CFileDefinition& fileDefinition);

private:
    DisplayListSettings mSettings;
    StaticGeneratorOutput mStaticOutput;
    CollisionGeneratorOutput mCollisionOutput;
    TriggerGeneratorOutput mTriggerOutput;

    std::unique_ptr<StructureDataChunk> CalculatePortalSingleSurface(CFileDefinition& fileDefinition, CollisionQuad& quad, ExtendedMesh& mesh, float scale);
    int CalculatePortalSurfaces(const aiScene* scene, CFileDefinition& fileDefinition, std::string& surfacesName, std::string& surfaceMappingName);
    void CalculateBoundingBoxes(const aiScene* scene, CFileDefinition& fileDefinition, std::string& boundingBoxesName);

    void CalculateTriggers(const aiScene* scene, CFileDefinition& fileDefinition, std::string& triggersName);
};

#endif