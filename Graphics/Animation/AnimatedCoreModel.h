#pragma once

#include <vector>
#include <string>

#include <Base/Utils/Named.h>
#include <Base/Math/Math.h>
#include <Base/Utils/TMapManager.h>


class CalCoreModel;

class CMaterial;

class CAnimatedCoreModel : public CNamed
{
private:
	CalCoreModel *m_CalCoreModel;
	std::vector<TMapManager<CMaterial>::Ref> m_Materials;
	std::string m_Path;
	Vect3f m_BSPosition;
	Vect3f m_BSRadius;
	bool LoadMesh(CXMLTreeNode& treeNode);
	bool LoadSkeleton(CXMLTreeNode& treeNode);
	bool LoadAnimation(CXMLTreeNode& treeNode);
	void Load();
public:
	CAnimatedCoreModel(CXMLTreeNode& treeNode);
	virtual ~CAnimatedCoreModel();
	CalCoreModel *GetCoreModel() const;
	std::vector<TMapManager<CMaterial>::Ref> &GetMaterials() { return m_Materials; }
};
