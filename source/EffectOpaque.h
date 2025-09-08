#pragma once
#include "EffectBase.h"


class EffectOpaque final : public EffectBase
{
public:
	EffectOpaque(ID3D11Device* pDevice, const std::wstring& assetFile);
	~EffectOpaque();

	virtual void UpdateMatrices(dae::Camera* pCamera, const dae::Matrix& worldMatrix) override;

	void SetDiffuseMap(Texture* pDiffuseTexture);
	void SetNormalMap(Texture* pNormalTexture);
	void SetGlossinessMap(Texture* pGlossinessTexture);
	void SetSpecularMap(Texture* pSpecularTexture);


private:

	ID3DX11EffectMatrixVariable* m_pViewInverseMatrix;
	ID3DX11EffectMatrixVariable* m_pWorldMatrix;

	ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVariable;
	ID3DX11EffectShaderResourceVariable* m_pNormalMapVariable;
	ID3DX11EffectShaderResourceVariable* m_pSpecularMapVariable;
	ID3DX11EffectShaderResourceVariable* m_pGlossinessMapVariable;


};


