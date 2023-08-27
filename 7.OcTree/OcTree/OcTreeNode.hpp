#pragma once

#include "Vector3.hpp"
#include "NodeData.hpp"

/*     _ _ _ _ _ _ _ _ _
*    /_ _ _ _ /_ _ _ _ / |
*  /_ _ _ _ /_ _ _ _ / | |
* |           |           |  |/|
* | _ _ _ _ | _ _ _ _ |/ | |
* |           |           |  |/
* | _ _ _ _ | _ _ _ _ |/
*
*           |z
*           |
*           | _ _ _ _ _ x
*         /
*       /y
*  _ _ _ _ _ _ _ _ _
* |     0    |     1    |
* | _ _ _ _ | _ _ _ _ |
* |     2    |    3     |
* | _ _ _ _ | _ _ _ _ |
*
*  _ _ _ _ _ _ _ _ _
* |     4    |     5    |
* | _ _ _ _ | _ _ _ _ |
* |     6    |    7     |
* | _ _ _ _ | _ _ _ _ |
*
*	[0]	0,0,0		-1,-1,-1
*	[1]	0,0,1		 1,-1,-1
*	[2]	0,1,0		-1, 1,-1
*	[3]	0,1,1		 1, 1,-1
*	[4]	1,0,0		-1,-1, 1
*	[5]	1,0,1		 1,-1, 1
*	[6]	1,1,0		-1, 1, 1
*	[7]	1,1,1		 1, 1, 1
*/

class OcTreeNode
{
public:
	OcTreeNode(Vector3 location, float halfSize);
	~OcTreeNode();

public:
	// 是否为叶子节点
	bool IsLeafNode() const;
	// 该 Location 是否在节点内部
	bool IsLocationInside(Vector3 location) const;
	// 通过位置来找到对应的节点
	OcTreeNode* FindChildNode(Vector3 location);
	// 插入数据
	bool InsertData(NodeData* data);
	// 获取数据
	NodeData* GetData();

private:
	NodeData* Data;
	Vector3 Center;
	float HalfSize;
	OcTreeNode* Children[8];

private:
	void CreateChildren();
};