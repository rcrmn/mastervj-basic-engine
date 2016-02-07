#include "Scene\StagedTexturedSceneRendererCommand.h"

CStagedTexturedSceneRendererCommand::CStagedTexturedSceneRendererCommand(CXMLTreeNode &TreeNode):CSceneRendererCommand(TreeNode)
{

}
CStagedTexturedSceneRendererCommand::~CStagedTexturedSceneRendererCommand(){
}

void CStagedTexturedSceneRendererCommand::CreateRenderTargetViewVector(){
	/*El m�todo CreateRenderTargetViewVector se llamar� al terminar de leer el nodo
y se rellenar� con todos los RenderTargets de las texturas din�micas.*/


}
void CStagedTexturedSceneRendererCommand::ActivateTextures(){
	for (int i = 0; i < m_StageTextures.size(); i++){
		m_StageTextures[i].Activate();
	}
}
void CStagedTexturedSceneRendererCommand::AddStageTexture(int StageId, CTexture *Texture){
	CStageTexture * stagedText =
		new CStageTexture(StageId, Texture);
	m_StageTextures.push_back(*stagedText);
}