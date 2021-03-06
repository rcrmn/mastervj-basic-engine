#include "Scene/SetPoolRenderableObjectsTechniqueSceneRendererCommand.h"

#include "Engine/Engine.h"
#include <Graphics/Renderable/RenderableObjectTechniqueManager.h>
#include <Base/XML/XMLTreeNode.h>

CSetPoolRenderableObjectsTechniqueSceneRendererCommand::CSetPoolRenderableObjectsTechniqueSceneRendererCommand(CXMLTreeNode &TreeNode)
	: CSceneRendererCommand(TreeNode)
{
	m_Pool = CEngine::GetSingleton()
				.getRenderableObjectTechniqueManager()
					->getPool(TreeNode.GetPszProperty("pool"));
}

void CSetPoolRenderableObjectsTechniqueSceneRendererCommand::Execute(CContextManager &_context)
{
	m_Pool->Apply();
}