#include "src/binary_search_tree/binary_search_tree.h"
#include <string>
#include <stdlib.h>

bool BinarySearchTree::find(const std::string &key)
{
	if(!data_)
		return false;
	if(data_->get_key() == key) {
		return true;
	} else if(data_->get_key() < key) {
		return left_child->find(key);
	} else {
		return right_child->find(key);
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
}
