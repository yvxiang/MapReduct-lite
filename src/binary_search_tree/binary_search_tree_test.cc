#include "gtest/gtest.h"
#include "src/binary_search_tree/binary_search_tree.h"
#include <iostream>
#include <string>
#include <stdlib.h>

TEST(BINARY_SEARCH_TREE_TEST, InsertToEmptyTree) {
	BinarySearchTree *root = new BinarySearchTree();
	int *v1 = new int();
	*v1 = 3;
	root->insert("apple", v1);
	EXPECT_EQ(root->get_key(), std::string("apple"));
	EXPECT_EQ(*(int *)root->get_value(), 3);
}

TEST(BINARY_SEARCH_TREE_TEST, InsertToNoEmptyTree) {
	BinarySearchTree *root = new BinarySearchTree();
	int *v1 = new int();
	*v1 = 1;
	root->insert("apple", v1);
	EXPECT_EQ(root->get_key(), std::string("apple"));
	EXPECT_EQ(*(int *)root->get_value(), 1);
	std::string key2 = "orange";
	int *v2 = new int();
	*v2 = 2;
	root->insert(key2, v2);
	EXPECT_EQ(root->get_key(), std::string("apple"));
	EXPECT_EQ(*(int *)root->get_value(), 1);
	EXPECT_EQ(root->get_rchild()->get_key(), std::string("orange"));
	EXPECT_EQ(*(int *)(root->get_rchild()->get_value()), 2);
	EXPECT_EQ(root->get_lchild(), (BinarySearchTree *)NULL);
}

TEST(BINARY_SEARCH_TREE_TEST, SearchInTree) {
	BinarySearchTree *root = new BinarySearchTree();
	int *v1 = new int();
	*v1 = 1;
	root->insert("apple", v1);
	EXPECT_EQ(root->get_key(), std::string("apple"));
	EXPECT_EQ(*(int *)root->get_value(), 1);
	std::string key2 = "orange";
	int *v2 = new int();
	*v2 = 2;
	root->insert(key2, v2);
	EXPECT_EQ(root->find("apple"), root);	
	EXPECT_EQ(root->find("orange"), root->get_rchild());	
	EXPECT_EQ(root->find("cat"), (BinarySearchTree *)NULL);
}
