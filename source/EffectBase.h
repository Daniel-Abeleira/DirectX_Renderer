#pragma once

namespace dae { struct Camera; }
class Texture;

class EffectBase
{
public:
	EffectBase() = default;
	EffectBase(ID3D11Device* pDevice, const std::wstring& assetFile);
	virtual ~EffectBase();

	ID3DX11Effect* GetEffect() const;
	ID3DX11EffectTechnique* GetTechnique() const;
	ID3D11InputLayout* GetInputLayout() const;

	virtual void UpdateMatrices(dae::Camera* pCamera, const dae::Matrix& worldMatrix);
	void SetSamplerState(ID3D11SamplerState* pSamplerState);

	ID3DX11EffectVariable* m_pUseNormalMap{};

protected:
	static ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);

	ID3DX11Effect* m_pEffect;
	ID3DX11EffectTechnique* m_pTechnique;
	ID3D11InputLayout* m_pInputLayout;

	ID3DX11EffectMatrixVariable* m_pWorldViewProjectionMatrix;

	ID3DX11EffectSamplerVariable* m_pSamplerStateVariable;
};

