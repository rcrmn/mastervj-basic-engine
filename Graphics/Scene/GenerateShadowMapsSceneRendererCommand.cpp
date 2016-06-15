#include "Scene/GenerateShadowMapsSceneRendererCommand.h"

#include <Core/Engine/Engine.h>
#include <Core/Debug/DebugPerf.h>
#include <Graphics/Renderable/RenderableObjectTechniqueManager.h>
#include <Graphics/Light/LightManager.h>
#include <Base/XML/XMLTreeNode.h>
#include "Renderable/PoolRenderableObjectTechnique.h"

CGenerateShadowMapsSceneRendererCommand::CGenerateShadowMapsSceneRendererCommand(CXMLTreeNode &TreeNode)
	: CSceneRendererCommand(TreeNode)
	, m_pool(nullptr)
{
	std::string pool = TreeNode.GetPszProperty("pool", "", false);
	if (pool != "")
	{
		m_pool = CEngine::GetSingleton().getRenderableObjectTechniqueManager()->getPool(pool);
	}
}

CGenerateShadowMapsSceneRendererCommand::~CGenerateShadowMapsSceneRendererCommand()
{

}


void CGenerateShadowMapsSceneRendererCommand::Execute(CContextManager &_context)
{
	/*El m�todo Execute recorrer� las luces del lightmanager y comprobar� si la luz ha
	de generar ShadowMap y si est� activa, en ese caso llamar� al m�todo
	SetShadowMap de la luz que establecer� las matrices de View y Projecci�n,
	realizar� el clear del zbuffer y del stencil buffer y pintar� las capas que el
	shadowmap tenga aplicadas.
	*/
	SCOPED_DEBUG_PERF(L"Generate Shadowmaps");
	if (m_pool)
	{
		m_pool->Apply();
	}
	CEngine::GetSingleton().getLightManager()
		->ExecuteShadowCreation(_context);
}
