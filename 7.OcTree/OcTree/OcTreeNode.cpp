#include "OcTreeNode.hpp"
#include "iostream"

OcTreeNode::OcTreeNode(Vector3 NodeData, float halfSize) :Center(NodeData), HalfSize(halfSize), Data(nullptr)
{
	for (size_t i = 0; i < 8; i++)
	{
		Children[i] = nullptr;
	}
}

OcTreeNode::~OcTreeNode()
{
	for (size_t i = 0; i < 8; i++)
	{
		if (Children[i] != nullptr)
		{
			delete Children[i];
		}
	}
}

bool OcTreeNode::IsLeafNode() const
{
	return Children[0] == nullptr;
}

bool OcTreeNode::IsLocationInside(Vector3 location) const
{
	return this->Center.X - this->HalfSize <= location.X && location.X <= this->Center.X + this->HalfSize
		&& this->Center.Y - this->HalfSize <= location.Y && location.Y <= this->Center.Y + this->HalfSize
		&& this->Center.Z - this->HalfSize <= location.Z && location.Z <= this->Center.Z + this->HalfSize;
}

OcTreeNode* OcTreeNode::FindChildNode(Vector3 location)
{
	// 不在内部没必要判断了
	if (!this->IsLocationInside(location))
	{
		return nullptr;
	}

	// 如果已经是叶子节点了，就返回自身
	if (this->IsLeafNode())
	{
		if (this->Data == nullptr)
		{
			return nullptr;
		}
		// 确保数据一定是对的上的
		return this->Data->GetLocation() == location ? this : nullptr;
	}

	// 不是叶子节点的话就交给子节点递归了
	for (size_t i = 0; i < 8; i++)
	{
		OcTreeNode* child = this->Children[i]->FindChildNode(location);
		if (child != nullptr)
		{
			return child;
		}
	}

	return nullptr;
}

bool OcTreeNode::InsertData(NodeData* data)
{
	// 插入空的数据就没必要继续了
	if (data == nullptr)
	{
		return false;
	}

	// 插入目标位置在节点范围外也没必要继续了
	if (!this->IsLocationInside(data->GetLocation()))
	{
		return false;
	}

	// 处理是叶子节点的情况
	if (this->IsLeafNode())
	{
		// 如果 Data 为空，那就正好插在这里
		if (this->Data == nullptr)
		{
			this->Data = data;
			return true;
		}
		// 不为空就创建子节点们
		this->CreateChildren();
	}

	// 如果当前节点不满足添加的话，交给子节点插入了
	for (size_t i = 0; i < 8; i++)
	{
		if (this->Children[i]->InsertData(data))
		{
			return true;
		}
	}

	// 这里没插入成功就应该报错的，按照目前的设计，一定会插入成功的
	std::cout << "Error" << std::endl;
	return false;
}

NodeData* OcTreeNode::GetData()
{
	return this->Data;
}

void OcTreeNode::CreateChildren()
{
	float newHalfSize = this->HalfSize / 2;
	for (size_t i = 0; i < 8; i++)
	{
		Vector3 newCenter = this->Center + Vector3(
			i & 1 ? newHalfSize : -newHalfSize,
			i & 2 ? newHalfSize : -newHalfSize,
			i & 4 ? newHalfSize : -newHalfSize
		);
		this->Children[i] = new OcTreeNode(newCenter, newHalfSize);
		this->Children[i]->InsertData(this->Data);
	}
	this->Data = nullptr;
}
