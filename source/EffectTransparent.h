#pragma once
#include "EffectBase.h"

class EffectTransparent final : public EffectBase
{
public:
	EffectTransparent(ID3D11Device* pDevice, const std::wstring& assetFile);
	~EffectTransparent();

	void SetDiffuseMap(Texture* pDiffuseTexture);

private:

	ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVariable;
};


