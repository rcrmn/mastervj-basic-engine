#pragma once

#include <string>
#include <Base/Math/Math.h>
#include <Base/Math/Color.h>
#include "Utils\Utils.h"
#include <d3d11.h>
#include <d3d9.h>

#define MV_VERTEX_TYPE_POSITION				0x01
#define MV_VERTEX_TYPE_COLOR				0x02
#define MV_VERTEX_TYPE_NORMAL				0x04
#define MV_VERTEX_TYPE_BLEND_INDICES		0x08
#define MV_VERTEX_TYPE_BLEND_WEIGHT			0x10
#define MV_VERTEX_TYPE_TEXTURE1				0x20
#define MV_VERTEX_TYPE_TEXTURE2				0x40
#define MV_VERTEX_TYPE_POSITION4			0x80
#define MV_VERTEX_TYPE_NORMAL4				0x160
#define MV_VERTEX_TYPE_BINORMAL				0x320
#define MV_VERTEX_TYPE_TANGENT			0x640

#define CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, NumBytes) \
	LayoutVariable[IdLayoutVariable].AlignedByteOffset=OffsetBytesVariable; \
	OffsetBytesVariable+=NumBytes; \
	++IdLayoutVariable;

//Position
#define IFDEF_CREATE_MV_0_POSITION_VERTEX
#define IFDEF_CREATE_MV_1_POSITION_VERTEX Vect3f Position;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION MV_VERTEX_TYPE_POSITION
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION_CREATE_LAYOUT { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 12);

//Position 4
#define IFDEF_CREATE_MV_0_POSITION4_VERTEX
#define IFDEF_CREATE_MV_1_POSITION4_VERTEX Vect4f Position;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION4 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION4 MV_VERTEX_TYPE_POSITION4
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION4_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION4_CREATE_LAYOUT { "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_POSITION4_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_POSITION4_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16);

//Normal
#define IFDEF_CREATE_MV_0_NORMAL_VERTEX
#define IFDEF_CREATE_MV_1_NORMAL_VERTEX Vect3f Normal;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL MV_VERTEX_TYPE_NORMAL
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL_CREATE_LAYOUT { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 12);

//Normal 4
#define IFDEF_CREATE_MV_0_NORMAL4_VERTEX
#define IFDEF_CREATE_MV_1_NORMAL4_VERTEX Vect4f Normal4;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL4 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL4 MV_VERTEX_TYPE_NORMAL4
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL4_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL4_CREATE_LAYOUT { "NORMAL", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_NORMAL4_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_NORMAL4_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16);

//Weight and indices
#define IFDEF_CREATE_MV_0_WEIGHT_INDICES_VERTEX
#define IFDEF_CREATE_MV_1_WEIGHT_INDICES_VERTEX \
	Vect4f		Weights; \
	Vect4f 		Indices;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_WEIGHT_INDICES 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_WEIGHT_INDICES MV_VERTEX_TYPE_BLEND_WEIGHT | MV_VERTEX_TYPE_BLEND_INDICES
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_WEIGHT_INDICES_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_WEIGHT_INDICES_CREATE_LAYOUT \
		{ "BLENDWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, \
		{ "BLENDINDICES", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_WEIGHT_INDICES_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_WEIGHT_INDICES_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16); \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16);

//Color
#define IFDEF_CREATE_MV_0_COLOR_VERTEX
#define IFDEF_CREATE_MV_1_COLOR_VERTEX CColor Color;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_COLOR 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_COLOR MV_VERTEX_TYPE_COLOR
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_COLOR_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_COLOR_CREATE_LAYOUT { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_COLOR_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_COLOR_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16);

//UV
#define IFDEF_CREATE_MV_0_UV_VERTEX

#define IFDEF_CREATE_MV_1_UV_VERTEX Vect2f		UV;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV MV_VERTEX_TYPE_TEXTURE1
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV_CREATE_LAYOUT { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 8);

//UV2
#define IFDEF_CREATE_MV_0_UV2_VERTEX
#define IFDEF_CREATE_MV_1_UV2_VERTEX Vect2f		UV2;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV2 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV2 MV_VERTEX_TYPE_TEXTURE2
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV2_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV2_CREATE_LAYOUT { "TEXCOORD", 1, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_UV2_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_UV2_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 8);

//BINORMAL & TANG
#define IFDEF_CREATE_MV_0_BINTANG_VERTEX
#define IFDEF_CREATE_MV_1_BINTANG_VERTEX \
	Vect3f		Binormal; \
	Vect3f 		Tangencial;
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_BINTANG 0
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_BINTANG MV_VERTEX_TYPE_BINORMAL | MV_VERTEX_TYPE_TANGENT
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_BINTANG_CREATE_LAYOUT
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_BINTANG_CREATE_LAYOUT  \
		{ "BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, \
		{ "TANGENCIAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#define IFDEF_CREATE_GET_VERTEX_TYPE_0_BINTANG_CREATE_LAYOUT_DETAIL
#define IFDEF_CREATE_GET_VERTEX_TYPE_1_BINTANG_CREATE_LAYOUT_DETAIL(LayoutVariable, IdLayoutVariable, OffsetBytesVariable) \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16); \
	CREATE_INPUT_LAYOUT(LayoutVariable, IdLayoutVariable, OffsetBytesVariable, 16);

#define CREATE_MVD3D11_VERTEX(StructName, HasPosition, HasPosition4, HasNormal, HasNormal4, HasWeightIndices, HasColor, HasUV, HasUV2, HasBinormalTang) \
struct StructName \
{ \
	IFDEF_CREATE_MV_##HasPosition##_POSITION_VERTEX; \
	IFDEF_CREATE_MV_##HasPosition4##_POSITION4_VERTEX; \
	IFDEF_CREATE_MV_##HasWeightIndices##_WEIGHT_INDICES_VERTEX; \
	IFDEF_CREATE_MV_##HasNormal##_NORMAL_VERTEX; \
	IFDEF_CREATE_MV_##HasNormal4##_NORMAL4_VERTEX; \
	IFDEF_CREATE_MV_##HasColor##_COLOR_VERTEX; \
	IFDEF_CREATE_MV_##HasUV##_UV_VERTEX; \
	IFDEF_CREATE_MV_##HasUV2##_UV2_VERTEX; \
	IFDEF_CREATE_MV_##HasBinormalTang##_BINTANG_VERTEX; \
\
	static bool CreateInputLayout(ID3D11Device *Device, ID3DBlob *VSBlob, ID3D11InputLayout **VertexLayout) \
		{ \
		D3D11_INPUT_ELEMENT_DESC l_Layout[] = \
				{ \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition##_POSITION_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition4##_POSITION4_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasWeightIndices##_WEIGHT_INDICES_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal##_NORMAL_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal4##_NORMAL4_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasColor##_COLOR_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV##_UV_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV2##_UV2_CREATE_LAYOUT \
			IFDEF_CREATE_GET_VERTEX_TYPE_##HasBinormalTang##_BINTANG_CREATE_LAYOUT \
				}; \
		unsigned int l_OffsetBytes=0; \
		unsigned int l_IdLayout=0; \
		\
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition##_POSITION_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition4##_POSITION4_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasWeightIndices##_WEIGHT_INDICES_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal##_NORMAL_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal4##_NORMAL4_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasColor##_COLOR_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV##_UV_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV2##_UV2_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		IFDEF_CREATE_GET_VERTEX_TYPE_##HasBinormalTang##_BINTANG_CREATE_LAYOUT_DETAIL(l_Layout, l_IdLayout, l_OffsetBytes); \
		\
		UINT l_NumElements=ARRAYSIZE(l_Layout); \
		HRESULT l_HR=Device->CreateInputLayout(l_Layout, l_NumElements, VSBlob->GetBufferPointer(), VSBlob->GetBufferSize(), VertexLayout); \
		return !FAILED(l_HR); \
		} \
	static unsigned int GetVertexType() \
		{ \
		return IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition##_POSITION | IFDEF_CREATE_GET_VERTEX_TYPE_##HasPosition4##_POSITION4 | IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal##_NORMAL | IFDEF_CREATE_GET_VERTEX_TYPE_##HasNormal4##_NORMAL4 | IFDEF_CREATE_GET_VERTEX_TYPE_##HasWeightIndices##_WEIGHT_INDICES | IFDEF_CREATE_GET_VERTEX_TYPE_##HasColor##_COLOR | IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV##_UV | IFDEF_CREATE_GET_VERTEX_TYPE_##HasUV2##_UV2 | IFDEF_CREATE_GET_VERTEX_TYPE_##HasBinormalTang##_BINTANG; \
		} \
};

CREATE_MVD3D11_VERTEX(MV_POSITION_WEIGHT_INDICES_NORMAL_TEXTURE_VERTEX, 1, 0, 1, 0, 1, 0, 1, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_NORMAL_TEXTURE_VERTEX, 1, 0, 1, 0, 0, 0, 1, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION4_COLOR_TEXTURE_VERTEX, 0, 1, 0, 0, 0, 1, 1, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_COLOR_VERTEX, 1, 0, 0, 0, 0, 1, 0, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_TEXTURE_VERTEX, 1, 0, 0, 0, 0, 0, 1, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_COLOR_TEXTURE_VERTEX, 1, 0, 0, 0, 0, 1, 1, 0, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_NORMAL_TEXTURE_TEXTURE2_VERTEX, 1, 0, 1, 0, 0, 0, 1, 1, 0);
//Falta color_normal_text?
CREATE_MVD3D11_VERTEX(MV_POSITION_NORMAL4_TEXTURE_TEXTURE2_VERTEX, 1, 1, 0, 1, 0, 0, 1, 1, 0);
CREATE_MVD3D11_VERTEX(MV_POSITION_NORMAL4_TEXTURE_VERTEX, 1, 1, 0, 1, 0, 0, 1, 0, 0);

CREATE_MVD3D11_VERTEX(MV_POSITION_NORMAL4_TEXTURE_BINTANG_VERTEX, 1, 0, 0, 1, 1, 0, 1, 0, 1);


struct TNORMAL_TANGENT_BINORMAL_TEXTURED_VERTEX
{
	float x, y, z;
	float nx, ny, nz, nw;
	float tangentx, tangenty, tangentz, tangentw;
	float binormalx, binormaly, binormalz, binormalw;
	float tu, tv;
	static inline unsigned short GetVertexType();
	static inline unsigned int GetFVF()
	{
		return 0;
	}
	//TODO: Pide DX9?? included
	static LPDIRECT3DVERTEXDECLARATION9 s_VertexDeclaration;
	static LPDIRECT3DVERTEXDECLARATION9 & GetVertexDeclaration();
	static void ReleaseVertexDeclaration()
	{
		CHECKED_RELEASE(s_VertexDeclaration);
	}
};

struct TCOLORED_VERTEX
{
	Vect3f x, y, z;
	float nx, ny, nz, nw;
	float tangentx, tangenty, tangentz, tangentw;
	float binormalx, binormaly, binormalz, binormalw;
	float tu, tv;
	static bool CreateInputLayout(CContextManager *RenderManager, ID3DBlob *VSBlob,
		ID3D11InputLayout **VertexLayout)
	{
		D3D11_INPUT_ELEMENT_DESC l_Layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
			D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
			D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TANGENT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 28,
			D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "BINORMAL", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 44,
			D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 60,
			D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};
		UINT l_NumElements = ARRAYSIZE(l_Layout);
		HRESULT l_HR = RenderManager->GetDevice()->CreateInputLayout(l_Layout,
			l_NumElements, VSBlob->GetBufferPointer(), VSBlob->GetBufferSize(), VertexLayout);
		return !FAILED(l_HR);
	}
	static unsigned int GetVertexType()
	{
		return MV_VERTEX_TYPE_POSITION | MV_VERTEX_TYPE_NORMAL4 |
			MV_VERTEX_TYPE_TANGENT | MV_VERTEX_TYPE_BINORMAL |
			MV_VERTEX_TYPE_TEXTURE1;
	}
};