#include "CinematicsActionManager.h"

#include "Engine/Engine.h"
#include "CinematicsAction.h"

CCinematicsActionManager::CCinematicsActionManager()
	: m_FileName("")
{
}

CCinematicsActionManager::~CCinematicsActionManager()
{
}

void CCinematicsActionManager::Update()
{
	CEngine::GetSingleton().getScriptManager()->RunCode("CinematicsActionManager_Update()");
}

void CCinematicsActionManager::LoadXML(std::string fileName)
{
	m_FileName = fileName;
	CEngine::GetSingleton().getScriptManager()->RunCode("CinematicsActionManager_LoadXML()");
}