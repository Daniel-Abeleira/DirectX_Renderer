#pragma once

class Texture final
{
public:
	Texture() = default;
	Texture(ID3D11Device* pDevice, const std::string& path);
	virtual ~Texture();

	ID3D11ShaderResourceView* GetResource() const;

private:
	dae::ColorRGB Sample(const dae::Vector2& uv) const;

	Uint8* m_pRed, * m_pGreen, * m_pBlue;

	ID3D11Texture2D* m_pResource{ nullptr };
	ID3D11ShaderResourceView* m_pSRV{ nullptr };

	SDL_Surface* m_pSurface{ nullptr };
	uint32_t* m_pSurfacePixels{ nullptr };
};

