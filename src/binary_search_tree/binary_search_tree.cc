#include "src/binary_search_tree/binary_search_tree.h"
#include <string>
#include <stdlib.h>

BinarySearchTree* BinarySearchTree::find(const std::string &key)
{
	if(!data_)
		return NULL;
	if(data_->get_key() == key) {
		return this;
	} else if(data_->get_key() > key) {
		if(left_child)
			return left_child->find(key);
		return NULL;
	} else {
		if(right_child)
			return right_child->find(key);
		return NULL;
	}
}
	
void BinarySearchTree::insert(std::string key, void *value)
{
	if(this->empty()) {
		data_ = new DataNode();
		data_->set_key(key);
		data_->set_value(value);
		return ;
	}
/*
	BinarySearchTree *cur_node = this;
	while(cur_node && !cur_node->empty()) {
		if(cur_node->data() > key) {
			cur_node = cur_node->get_lchild();
		} else {
			cur_node = cur_node->get_rchild();
		}
	}
	if(!cur_node)
		cur_node = new BinarySearchTree();

	cur_node->insert(key, value);

*/

	if(this->data() > key) {
		if(this->get_lchild() == NULL) {
			left_child = new BinarySearchTree();
		}
		left_child->insert(key, value);
	} else {
		if(this->get_rchild() == NULL) {
			right_child = new BinarySearchTree();
		}
		right_child->insert(key, value);
	}
		
}
void BinarySearchTree::modify_val(void *val)
{
	data_->set_value(val);
}

