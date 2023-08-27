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
	// �����ڲ�û��Ҫ�ж���
	if (!this->IsLocationInside(location))
	{
		return nullptr;
	}

	// ����Ѿ���Ҷ�ӽڵ��ˣ��ͷ�������
	if (this->IsLeafNode())
	{
		if (this->Data == nullptr)
		{
			return nullptr;
		}
		// ȷ������һ���ǶԵ��ϵ�
		return this->Data->GetLocation() == location ? this : nullptr;
	}

	// ����Ҷ�ӽڵ�Ļ��ͽ����ӽڵ�ݹ���
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
	// ����յ����ݾ�û��Ҫ������
	if (data == nullptr)
	{
		return false;
	}

	// ����Ŀ��λ���ڽڵ㷶Χ��Ҳû��Ҫ������
	if (!this->IsLocationInside(data->GetLocation()))
	{
		return false;
	}

	// ������Ҷ�ӽڵ�����
	if (this->IsLeafNode())
	{
		// ��� Data Ϊ�գ��Ǿ����ò�������
		if (this->Data == nullptr)
		{
			this->Data = data;
			return true;
		}
		// ��Ϊ�վʹ����ӽڵ���
		this->CreateChildren();
	}

	// �����ǰ�ڵ㲻������ӵĻ��������ӽڵ������
	for (size_t i = 0; i < 8; i++)
	{
		if (this->Children[i]->InsertData(data))
		{
			return true;
		}
	}

	// ����û����ɹ���Ӧ�ñ���ģ�����Ŀǰ����ƣ�һ�������ɹ���
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
