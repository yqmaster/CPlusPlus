#include "OcTreeNode.hpp"
#include <iostream>

void test(OcTreeNode* node, float x, float y, float z)
{
	OcTreeNode* child = node->FindChildNode(Vector3(x, y, x));
	if (child == nullptr)
	{
		std::cout << "Get ChidNode Empty" << std::endl;
		return;
	}
	NodeData* data = child->GetData();
	if (data == nullptr)
	{
		std::cout << "GetNodeDataFailed" << std::endl;
		return;
	}
	std::cout << *data << std::endl;
}

int main()
{
	OcTreeNode* root = new OcTreeNode(Vector3(0, 0, 0), 100);

	root->InsertData(new NodeData(Vector3(50, 50, 50), "张三"));
	root->InsertData(new NodeData(Vector3(1, 1, 1), "李四"));
	root->InsertData(new NodeData(Vector3(100, 100, 100), "王五"));
	root->InsertData(new NodeData(Vector3(2, 2, 2), "赵六"));
	root->InsertData(new NodeData(Vector3(-1, -1, -1), "周七"));

	test(root, 1, 1, 1);
	test(root, 2, 2, 2);
	test(root, 99, 99, 99);
	test(root, 101, 100, 100);
	test(root, -1, -1, -1);

	return 0;
}