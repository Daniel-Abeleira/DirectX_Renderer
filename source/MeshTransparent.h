#pragma once
#include "Mesh.h"
class EffectBase;
class Texture;


class MeshTransparent final : public Mesh
{
public:
	MeshTransparent(ID3D11Device* pDevice, const std::string& filename, Texture* pDiffuseMap);
	~MeshTransparent() = default;

	void PrintTypeName() override;

	void SetDiffuseMap(Texture* pDiffuseMap);
};