#ifndef RENDERABLE_OBJECT_TECHNIQUE_H
#define RENDERABLE_OBJECT_TECHNIQUE_H

#include <Utils\Named.h>
#include "Effect\EffectTechnique.h"

class CRenderableObjectTechnique : public CNamed
{
private:
	CEffectTechnique *m_EffectTechnique;
public:
	CRenderableObjectTechnique(const std::string &Name, CEffectTechnique
		*EffectTechnique);
	void SetEffectTechnique(CEffectTechnique *EffectTechnique);
	CEffectTechnique * GetEffectTechnique() const;
};

#endif