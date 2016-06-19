#include "TriggerComponent.h"

#include "Scene/Element.h"
#include <Base/XML/XMLTreeNode.h>
#include <Core/Engine/Engine.h>
#include <PhysX/PhysXManager.h>
#include "ComponentManager.h"

CTriggerComponent::CTriggerComponent(const std::string& name, CXMLTreeNode& node, CElement* Owner)
	: CPhysxComponent(name, node, Owner)
{
	m_isTrigger = true;
	m_isKinematic = false;
}

CTriggerComponent::CTriggerComponent(const std::string& name, CElement* Owner)
	: CPhysxComponent(name, Owner)
{
	m_isTrigger = true;
	m_isKinematic = false;
}

CTriggerComponent::~CTriggerComponent()
{
}

void CTriggerComponent::Destroy()
{
}

void CTriggerComponent::Init()
{
	CPhysxComponent::Init(GetOwner()->GetScale()*m_scale, GetOwner()->GetPosition() + m_offset);
}


void CTriggerComponent::FixedUpdate(float ElapsedTime)
{
	if (!m_isStatic)
	{
		Move(GetOwner()->GetPosition() + m_offset);
	}

	auto elems = CEngine::GetSingleton().getPhysXManager()->getTriggerCollisions(getName());

	auto newElems = elems;

	std::vector<std::string> left;
	std::vector<std::string> active;

	for (auto &const e : m_activeElements)
	{
		newElems.erase(e);
		if (elems.find(e) == elems.end())
		{
			left.push_back(e);
		}
		else
		{
			active.push_back(e);
		}
	}

	m_activeElements.swap(active);


	auto cm = CEngine::GetSingleton().getComponentManager();

	auto own = GetOwner();
	for (auto &const e : left)
	{
		auto otherOwner = cm->get(e)->GetOwner();
		own->SendMsg("OnTriggerLeave", otherOwner);
	}

	for (auto &const e : m_activeElements)
	{
		auto otherOwner = cm->get(e)->GetOwner();
		own->SendMsg("OnTriggerStay", otherOwner);
	}

	for (auto &const e : newElems)
	{
		auto otherOwner = cm->get(e)->GetOwner();
		own->SendMsg("OnTriggerEnter", otherOwner);
	}
}

