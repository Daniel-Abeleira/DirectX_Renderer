#include "pch.h"
#include "EffectOpaque.h"
#include "Camera.h"
#include "Texture.h"

EffectOpaque::EffectOpaque(ID3D11Device* pDevice, const std::wstring& assetFile)
	:EffectBase(pDevice, assetFile)
{
	// Matrices								

	m_pWorldMatrix = m_pEffect->GetVariableByName("gWorld")->AsMatrix();

	if (!m_pWorldMatrix->IsValid())
	{
		std::cout <<"World matrix not valid\n";
	}

	m_pViewInverseMatrix = m_pEffect->GetVariableByName("gViewInverse")->AsMatrix();

	if (!m_pViewInverseMatrix->IsValid())
	{
		std::cout <<"View inverse matrix not valid\n";
	}

	// Maps	

	m_pDiffuseMapVariable = m_pEffect->GetVariableByName("gDiffuseMap")->AsShaderResource();

	if (!m_pDiffuseMapVariable->IsValid())
	{
		std::cout <<"Diffuse map not valid\n";
	}

	m_pNormalMapVariable = m_pEffect->GetVariableByName("gNormalMap")->AsShaderResource();

	if (!m_pNormalMapVariable->IsValid())
	{
		std::cout <<"Normal map not valid\n";
	}

	m_pSpecularMapVariable = m_pEffect->GetVariableByName("gSpecularMap")->AsShaderResource();

	if (!m_pSpecularMapVariable->IsValid())
	{
		std::cout <<"Specular map not valid\n";
	}

	m_pGlossinessMapVariable = m_pEffect->GetVariableByName("gGlossinessMap")->AsShaderResource();

	if (!m_pGlossinessMapVariable->IsValid())
	{
		std::cout <<"Glossiness map not valid\n";
	}


	m_pUseNormalMap = m_pEffect->GetVariableByName("gUseNormalMap");
}

EffectOpaque::~EffectOpaque()
{
	//Maps

	if (m_pGlossinessMapVariable)
	{
		m_pGlossinessMapVariable->Release();
	}

	if (m_pSpecularMapVariable)
	{
		m_pSpecularMapVariable->Release();
	}

	if (m_pNormalMapVariable)
	{
		m_pNormalMapVariable->Release();
	}

	if (m_pDiffuseMapVariable)
	{
		m_pDiffuseMapVariable->Release();
	}

	//Matrices

	if (m_pViewInverseMatrix)
	{
		m_pViewInverseMatrix->Release();
	}

	if (m_pWorldMatrix)
	{
		m_pWorldMatrix->Release();
	}
}

void EffectOpaque::UpdateMatrices(dae::Camera* pCamera, const dae::Matrix& worldMatrix)
{
	EffectBase::UpdateMatrices(pCamera, worldMatrix);

	m_pWorldMatrix->SetMatrix(reinterpret_cast<const float*>(&(worldMatrix)));
	m_pViewInverseMatrix->SetMatrix(reinterpret_cast<const float*>(&(pCamera->invViewMatrix)));
}

void EffectOpaque::SetDiffuseMap(Texture* pDiffuseTexture)
{
	if (m_pDiffuseMapVariable)
		m_pDiffuseMapVariable->SetResource(pDiffuseTexture->GetResource());
}

void EffectOpaque::SetNormalMap(Texture* pNormalTexture)
{
	if (m_pNormalMapVariable)
		m_pNormalMapVariable->SetResource(pNormalTexture->GetResource());
	std::cout <<"Normal map: OK\n";
}

void EffectOpaque::SetSpecularMap(Texture* pSpecularTexture)
{
	if (m_pSpecularMapVariable)
		m_pSpecularMapVariable->SetResource(pSpecularTexture->GetResource());
	std::cout <<"Specular map: OK\n";
}

void EffectOpaque::SetGlossinessMap(Texture* pGlossinessTexture)
{
	if (m_pGlossinessMapVariable)
		m_pGlossinessMapVariable->SetResource(pGlossinessTexture->GetResource());

	std::cout <<"Glossines map: OK\n";
}

