#include "SpeakerComponent.h"

#include "Scene/Element.h"
#include <Base/XML/XMLTreeNode.h>
#include <Core/Engine/Engine.h>

CSpeakerComponent::CSpeakerComponent(const std::string& name, CXMLTreeNode& node, CElement* Owner)
	: CComponent(node, Owner)
{
	setName(name);

}

CSpeakerComponent::CSpeakerComponent(const std::string& name, CElement* Owner)
	: CComponent(name, Owner)
{
}

CSpeakerComponent::~CSpeakerComponent()
{
}

void CSpeakerComponent::Init()
{
	// TODO: Crear estructures necess�ries en el manager d'audio utilitzant getName com a identificador
}


void CSpeakerComponent::Destroy()
{
	// TODO: Eliminar estructures que calgui del manager d'audio
}

void CSpeakerComponent::Play( const std::string audioClipName, bool loop )
{
	// TODO: Reproduir one-shot o bucle depenent de loop
}

void CSpeakerComponent::Stop()
{
	// TODO: Parar reproducci� d'audios iniciats per aquest component
}

void CSpeakerComponent::Update(float ElapsedTime)
{
	// TODO: Actualitzar posici� i rotaci� del speaker en el manager d'audio a partir del GetOwner()->GetPosition() i GetOwner()->GetDirection()
}

