#pragma once
#include "Mesh.h"
#include "EffectBase.h"
class Texture;


class MeshOpaque final : public Mesh
{
public:
	MeshOpaque(ID3D11Device* pDevice, const std::string& filename, Texture* pDiffuseMap, Texture* pNormalMap, Texture* pSpecularMap, Texture* pGlossinessMap);
	~MeshOpaque() = default;

	void PrintTypeName() override;

	void SetDiffuseMap(Texture* pDiffuseMap);
	void SetNormalMap(Texture* pNormalMap);
	void SetSpecularMap(Texture* pSpecularMap);
	void SetGlossinessMap(Texture* pGlossinessMap);

	void SetUseNormalMap(bool useNormalMap) const { Mesh::m_pEffect.get()->m_pUseNormalMap->SetRawValue(&useNormalMap, 0, sizeof(bool)); }

};