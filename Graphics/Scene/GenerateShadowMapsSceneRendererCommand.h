#ifndef GENERATE_SHADOW_MAPS_SCENE_RENDERER_COMMAND_H
#define GENERATE_SHADOW_MAPS_SCENE_RENDERER_COMMAND_H

#include "Scene\SceneRendererCommand.h"

class CGenerateShadowMapsSceneRendererCommand : public CSceneRendererCommand
{
public:
	CGenerateShadowMapsSceneRendererCommand(CXMLTreeNode &TreeNode);
	virtual ~CGenerateShadowMapsSceneRendererCommand();
	void Execute(CContextManager &_context);
	/*El m�todo Execute recorrer� las luces del lightmanager y comprobar� si la luz ha
de generar ShadowMap y si est� activa, en ese caso llamar� al m�todo
SetShadowMap de la luz que establecer� las matrices de View y Projecci�n,
realizar� el clear del zbuffer y del stencil buffer y pintar� las capas que el
shadowmap tenga aplicadas.*/
};

#endif