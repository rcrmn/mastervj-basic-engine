#pragma once

#include <vector>
#include "CinematicPlayer.h"
#include "Renderable/RenderableObject.h"

class CCinematicObject;
class CRenderManager;

class CCinematic : public CRenderableObject, public CCinematicPlayer
{
protected:
	std::vector<CCinematicObject *> m_CinematicObjects;
public:
	CCinematic( CXMLTreeNode &TreeNode );
	virtual ~CCinematic();
	virtual void Stop();
	virtual void Play( bool Cycle );
	virtual void Pause();
	void AddCinematicObject( CCinematicObject *CinematicObject );
	virtual void Update( float ElapsedTime );
	void SetAnimTime(float Time);
	virtual void Render(CContextManager *_context);
};