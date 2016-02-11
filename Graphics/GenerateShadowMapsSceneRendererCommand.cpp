#include "Scene\GenerateShadowMapsSceneRendererCommand.h"
#include "Engine/Engine.h"

CGenerateShadowMapsSceneRendererCommand::CGenerateShadowMapsSceneRendererCommand(CXMLTreeNode &TreeNode) 
	:CSceneRendererCommand(TreeNode){

}

CGenerateShadowMapsSceneRendererCommand::~CGenerateShadowMapsSceneRendererCommand(){

}


void CGenerateShadowMapsSceneRendererCommand::Execute(CContextManager &_context){
	/*El m�todo Execute recorrer� las luces del lightmanager y comprobar� si la luz ha
	de generar ShadowMap y si est� activa, en ese caso llamar� al m�todo
	SetShadowMap de la luz que establecer� las matrices de View y Projecci�n,
	realizar� el clear del zbuffer y del stencil buffer y pintar� las capas que el
	shadowmap tenga aplicadas.	*/
	CEngine::GetSingleton().getLightManager()->ExecuteShadowCreation(_context);
}
