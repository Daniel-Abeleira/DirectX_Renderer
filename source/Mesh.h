#pragma once
namespace dae { struct Camera; }
class EffectBase;
class Texture;

struct Vertex
{
	dae::Vector3 position;
	dae::Vector2 uv;
	dae::Vector3 normal;
	dae::Vector3 tangent;
};

class Mesh
{
public:
	Mesh(ID3D11Device* pDevice, const std::string& filePath);
	virtual ~Mesh();

	void Render(ID3D11DeviceContext* pDeviceContext);
	void SetSamplerState(ID3D11SamplerState* pSamplerState);
	void UpdateMatrices(dae::Camera* pCamera);

	void Translate(const dae::Vector3& translation);
	void RotateY(float angle);

	virtual void PrintTypeName() = 0;
protected:
	std::unique_ptr<EffectBase> m_pEffect;

	uint32_t m_NumIndices;

	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;

	dae::Matrix m_WorldMatrix{};
};