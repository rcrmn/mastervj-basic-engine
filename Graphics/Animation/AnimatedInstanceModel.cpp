#include "AnimatedInstanceModel.h"


#include <Base/Math/MathUtils.h>
#include "Mesh/VertexTypes.h"
#include "Animation/AnimatedCoreModel.h"
#include "Mesh/RenderableVertexs.h"
#include "Renderable/RenderableObjectTechnique.h"
#include <Graphics/Animation/AnimatedModelManager.h>
#include <Graphics/Effect/EffectManager.h>
#include <Graphics/Material/Material.h>

#include <cal3d/cal3d.h>
#include <XML/XMLTreeNode.h>

#include <Core/Engine/Engine.h>

CAnimatedInstanceModel::CAnimatedInstanceModel(CXMLTreeNode& TreeNode)
	: CRenderableObject(TreeNode)
{
	const char* coreName = TreeNode.GetPszProperty("core_name");
	DEBUG_ASSERT(coreName);
	auto core = CEngine::GetSingleton().getAnimatedModelManager()->ref(coreName);
	DEBUG_ASSERT(core);
	Initialize(std::move(core));
	BlendCycle(0, 1.0f, 0.0f);
}

CAnimatedInstanceModel::~CAnimatedInstanceModel()
{
	delete m_CalModel;
	delete m_CalHardwareModel;
	delete m_RenderableVertexs;
}

void CAnimatedInstanceModel::Initialize(TMapManager<CAnimatedCoreModel>::Ref AnimatedCoreModel)
{
	m_AnimatedCoreModel = std::move(AnimatedCoreModel);
	m_CalModel = new CalModel(m_AnimatedCoreModel->GetCoreModel());
	m_CalHardwareModel = new CalHardwareModel(m_AnimatedCoreModel->GetCoreModel());

	LoadVertexBuffer();
}

void CAnimatedInstanceModel::Render(CContextManager *context)
{
	if ( !m_Visible )
	{
		return;
	}

	Mat44f l_Transform = GetTransform();

	for (int l_HardwareMeshId = 0;
		 l_HardwareMeshId < m_CalHardwareModel->getHardwareMeshCount();
		 ++l_HardwareMeshId)
	{
		m_AnimatedCoreModel->GetMaterials().at(l_HardwareMeshId)->apply();
		m_CalHardwareModel->selectHardwareMesh(l_HardwareMeshId);
		Mat44f l_Transformations[MAXBONES];

		for (int l_BoneId = 0;
			 l_BoneId<m_CalHardwareModel->getBoneCount();
			 ++l_BoneId)
		{
			Quatf l_Quaternion = (const Quatf &)m_CalHardwareModel->getRotationBoneSpace(l_BoneId, m_CalModel->getSkeleton());
			l_Transformations[l_BoneId].SetIdentity();
			l_Transformations[l_BoneId].SetRotByQuat(l_Quaternion);
			CalVector translationBoneSpace = m_CalHardwareModel->getTranslationBoneSpace(l_BoneId, m_CalModel->getSkeleton());
			l_Transformations[l_BoneId].SetPos(Vect3f(translationBoneSpace.x, translationBoneSpace.y, translationBoneSpace.z));
		}
		memcpy(&CEffectManager::m_AnimatedModelEffectParameters.m_Bones,
			   l_Transformations,
			   MAXBONES*sizeof(float) * 4 * 4);

		CEffectTechnique *l_EffectTechnique = m_AnimatedCoreModel->GetMaterials().at(l_HardwareMeshId)->getRenderableObjectTechique()->GetEffectTechnique();

		l_EffectTechnique->SetConstantBuffer(2, &CEffectManager::m_AnimatedModelEffectParameters.m_Bones);
		m_RenderableVertexs->RenderIndexed(context,
			l_EffectTechnique,
										   m_CalHardwareModel->getFaceCount() * 3,
										   m_CalHardwareModel->getStartIndex(),
										   m_CalHardwareModel->getBaseVertexIndex());
	}
}


void CAnimatedInstanceModel::Update(float ElapsedTime)
{
	m_CalModel->update(ElapsedTime);
}

void CAnimatedInstanceModel::ExecuteAction(int Id, float DelayIn, float DelayOut, float WeightTarget, bool AutoLock)
{
	m_CalModel->getMixer()->executeAction(Id, DelayIn, DelayOut, WeightTarget, AutoLock);
}

void CAnimatedInstanceModel::BlendCycle(int Id, float Weight, float DelayIn)
{
	m_CalModel->getMixer()->blendCycle(Id, Weight, DelayIn);
}

void CAnimatedInstanceModel::ClearCycle(int Id, float DelayOut)
{
	m_CalModel->getMixer()->clearCycle(Id, DelayOut);
}

bool CAnimatedInstanceModel::IsCycleAnimationActive(int Id) const
{
	// TODO
	return false;
}

bool CAnimatedInstanceModel::IsActionAnimationActive(int Id) const
{
	// TODO
	return false;
}

void CAnimatedInstanceModel::LoadMaterials()
{
	m_CalModel->setMaterialSet(0);
}

bool CAnimatedInstanceModel::LoadVertexBuffer()
{
	m_NumVertices = 0;
	m_NumFaces = 0;
	CalCoreModel *l_CalCoreModel = m_AnimatedCoreModel->GetCoreModel();
	for (int i = 0; i<l_CalCoreModel->getCoreMeshCount(); ++i)
	{
		CalCoreMesh *l_CalCoreMesh = l_CalCoreModel->getCoreMesh(i);
		for (int j = 0; j<l_CalCoreMesh->getCoreSubmeshCount(); ++j)
		{
			CalCoreSubmesh *l_CalCoreSubmesh = l_CalCoreMesh->getCoreSubmesh(j);
			m_NumVertices += l_CalCoreSubmesh->getVertexCount();
			m_NumFaces += l_CalCoreSubmesh->getFaceCount();
		}
	}
	MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX * l_Vertexs = (MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX *) malloc(m_NumFaces * 3 * sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));

	CalIndex *l_Faces = (CalIndex *)malloc(m_NumFaces * 3 * sizeof(CalIndex));

	m_CalHardwareModel->setVertexBuffer((char*)l_Vertexs, sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));
	m_CalHardwareModel->setNormalBuffer(((char*)l_Vertexs) + 12, sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));
	m_CalHardwareModel->setWeightBuffer(((char*)l_Vertexs) + 24, sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));
	m_CalHardwareModel->setMatrixIndexBuffer(((char*)l_Vertexs) + 40, sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));


	m_CalHardwareModel->setTextureCoordNum(1);
	m_CalHardwareModel->setTextureCoordBuffer(0, ((char*)l_Vertexs) + 56, sizeof(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX));
	m_CalHardwareModel->setIndexBuffer(l_Faces);
	m_CalHardwareModel->load(0, 0, MAXBONES);
	m_NumFaces = m_CalHardwareModel->getTotalFaceCount();
	m_NumVertices = m_CalHardwareModel->getTotalVertexCount();
	if (sizeof(CalIndex) == 2)
	{
		m_RenderableVertexs = new CKGTriangleListRenderableIndexed16Vertexs<MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX>(l_Vertexs, m_NumVertices, l_Faces, m_NumFaces * 3);
	}
	else
	{
		m_RenderableVertexs = new CKGTriangleListRenderableIndexed32Vertexs<MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX>(l_Vertexs, m_NumVertices, l_Faces, m_NumFaces * 3);
	}
	free(l_Vertexs);
	free(l_Faces);
	return true;
}

