#pragma once
class Sampler final
{
public:
	Sampler(ID3D11Device* pDevice);
	virtual ~Sampler();

	ID3D11SamplerState* GetSamplerState(D3D11_FILTER filter) const;
	
private:
	ID3D11SamplerState* m_pPointSampler;
	ID3D11SamplerState* m_pLinearSampler;
	ID3D11SamplerState* m_pAnisotropicSampler;
};