
#include "pch.h"
#include "EffectTransparent.h"
#include <assert.h>
#include "Camera.h"
#include "Texture.h"

EffectTransparent::EffectTransparent(ID3D11Device* pDevice, const std::wstring& assetFile)
	:EffectBase(pDevice, assetFile)
{
	m_pDiffuseMapVariable = m_pEffect->GetVariableByName("gDiffuseMap")->AsShaderResource();
	if (!m_pDiffuseMapVariable->IsValid())
	{
		std::cout <<"Diffuse map not valid\n";
	}
}

EffectTransparent::~EffectTransparent()
{
	//Maps

	if (m_pDiffuseMapVariable)
	{
		m_pDiffuseMapVariable->Release();
	}
}

void EffectTransparent::SetDiffuseMap(Texture* pDiffuseTexture)
{
	if (m_pDiffuseMapVariable)
		m_pDiffuseMapVariable->SetResource(pDiffuseTexture->GetResource());
	std::cout <<"Diffuse map: OK\n";
}

