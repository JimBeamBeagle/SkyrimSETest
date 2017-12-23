#pragma once

#include "../../NiMain/NiColor.h"
#include "../BSShader.h"

class BSBloodSplatterShader : public BSShader
{
private:
	enum
	{
		RAW_TECHNIQUE_SPLATTER = 0,
		RAW_TECHNIQUE_FLARE = 1,
	};

	uint32_t m_CurrentRawTechnique;// Is either 0 or 1, set in SetupTechnique(), used in SetupGeometry()

	inline AutoPtr(BSBloodSplatterShader *, pInstance, 0x32573B8);
	inline AutoPtr(NiColorA, LightLoc, 0x32573B8);
	inline AutoPtr(int, iAdaptedLightRenderTarget, 0x32573C8);
	inline AutoPtr(float, fGlobalAlpha, 0x10);
	inline AutoPtr(float, fFlareMult, 0x10);
	inline AutoPtr(float, fAlpha, 0x10);
	inline AutoPtr(float, fFlareOffsetScale, 0x10);

public:
	BSBloodSplatterShader();
	virtual ~BSBloodSplatterShader();

	virtual bool SetupTechnique(uint32_t Technique) override;	// Implemented
	virtual void RestoreTechnique(uint32_t Technique) override;	// Implemented
	virtual void SetupGeometry(BSRenderPass *Pass) override;	// Implemented
	virtual void RestoreGeometry(BSRenderPass *Pass) override;	// Implemented

	// NiBoneMatrixSetterI/BSReloadShaderI unknown

	uint32_t GetVertexTechnique(uint32_t RawTechnique);
	uint32_t GetPixelTechnique(uint32_t RawTechnique);
};
static_assert(sizeof(BSBloodSplatterShader) == 0x98, "");
//static_assert(offsetof(BSBloodSplatterShader, m_CurrentRawTechnique) == 0x90, "");