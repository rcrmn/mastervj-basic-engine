#include "CinematicObject.h"

#include "CinematicObjectKeyFrame.h"

#include "Core/Engine/Engine.h"

#include <Core/Scene/Element.h>
#include <Core/Scene/Scene.h>
#include <Core/Scene/SceneManager.h>

#include <XML/XMLTreeNode.h>
#include <Windows.h>

CCinematicObject::CCinematicObject( CXMLTreeNode &treeNode )
	: m_CurrentKeyFrame(0)
{
	m_name = treeNode.GetPszProperty("resource");
	std::string loopType = treeNode.GetPszProperty("loopType");

	if (loopType == std::string("Cycle"))
	{
		m_Cycle = true;
	}
	else if (loopType == std::string("One-Shot") || loopType == std::string("Reverse"))
	{
		m_Cycle = false;
		//TODO: anim reverse
	}

	m_object = CEngine::GetSingleton().getSceneManager()->GetObjectById(m_name);

	float duration = 0;
	for ( int i = 0; i < treeNode.GetNumChildren(); ++i )
	{
		auto kf = new CCinematicObjectKeyFrame( treeNode( i ) );
		AddCinematicObjectKeyFrame(kf);
		if ( kf->getKeyFrameTime() > duration )
		{
			duration = kf->getKeyFrameTime();
		}
	}

	CCinematicPlayer::Init( duration );
}


CCinematicObject::~CCinematicObject()
{
	for ( auto it = m_CinematicObjectKeyFrames.begin(); it != m_CinematicObjectKeyFrames.end(); ++it )
	{
		delete ( *it );
	}
}


bool CCinematicObject::IsOk()
{
	// TODO
	return true;
}


void CCinematicObject::AddCinematicObjectKeyFrame( CCinematicObjectKeyFrame *CinematicObjectKeyFrame )
{
	m_CinematicObjectKeyFrames.push_back( CinematicObjectKeyFrame );
}


void CCinematicObject::Update( float ElapsedTime )
{
	CCinematicPlayer::Update( ElapsedTime );

	if ( !m_Playing )
	{
		return;
	}

	if ( !m_object )
	{
		m_object = CEngine::GetSingleton().getSceneManager()->GetObjectById(m_name);
		if ( !m_object )
		{
			OutputDebugStringA( ( "CCinematicObject: Could not find object " + m_name + "\n" ).c_str() );
			return;
		}
	}

	m_CurrentKeyFrame = 0;
	while (m_CurrentKeyFrame < m_CinematicObjectKeyFrames.size() - 2
		   && m_CinematicObjectKeyFrames[m_CurrentKeyFrame+1]->getKeyFrameTime() < m_CurrentTime)
	{
		m_CurrentKeyFrame++;
	}

	int nextKF = mathUtils::Min( m_CurrentKeyFrame + 1, m_CinematicObjectKeyFrames.size()-1);

	auto current = m_CinematicObjectKeyFrames[m_CurrentKeyFrame];
	auto next = m_CinematicObjectKeyFrames[nextKF];

	float t = 0;
	if ( nextKF != m_CurrentKeyFrame )
	{
		t = ( getCurrentTime() - current->getKeyFrameTime() ) / ( next->getKeyFrameTime() - current->getKeyFrameTime() );
	}

	m_object->SetPosition(mathUtils::Lerp(current->GetPosition(), next->GetPosition(), t));
	Quatf q = current->GetQuat();
	q.SLerp(t, next->GetQuat());
	m_object->SetQuat(q);
	m_object->SetScale( mathUtils::Lerp( current->GetScale(), next->GetScale(), t ) );
}


void CCinematicObject::Stop()
{
	CCinematicPlayer::Stop();
	m_CurrentKeyFrame = 0;
}


void CCinematicObject::OnRestartCycle()
{
}


