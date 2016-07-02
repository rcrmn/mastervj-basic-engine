#include "Component.h"

#include <Base/XML/XMLTreeNode.h>

#include <Core/Engine/Engine.h>
#include <Core/Component/ComponentManager.h>

CComponent::CComponent(CXMLTreeNode& node, CElement* Owner)
	: CNamed(node)
	, m_Owner(Owner)
	, m_Initialized(false)
{
	DEBUG_ASSERT( Owner != nullptr );

	m_Enabled = node.GetBoolProperty("enabled", true, false);

	for (int i = 0; i < node.GetNumChildren(); ++i)
	{
		auto prop = node(i);
		if (prop.GetName() != std::string("property"))
		{
			return;
		}

		std::string name = prop.GetPszProperty("name", "", false);
		std::string value = prop.GetPszProperty("value", "", false);
		std::string type = prop.GetPszProperty("type", "string", false);
		m_properties.push_back({name, type, value});
	}
}

CComponent::CComponent( const std::string& Name, CElement* Owner )
	: CNamed(Name)
	, m_Owner(Owner)
	, m_Initialized(false)
{
}

void CComponent::Initialize()
{
	if ( CEngine::GetSingleton().getComponentManager()->IsInitialized() )
	{
		Init();
		m_Initialized = true;
	}
}

void CComponent::ObjectInitialized()
{
	if ( m_Initialized )
	{
		OnObjectInitialized();
	}
}
