#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H
#include <string>
#include <stdlib.h>
#include "src/mapreduce_lite/mapreduce_lite.h"
#include "src/base/scoped_ptr.h"
class BinarySearchTree;
class DataNode {
	public :
		DataNode() : value_(NULL) {}
		~DataNode() { }
		void set_key(std::string key) { key_ = key; } 
		void set_value(void *value) { value_ = value; }
		const std::string& get_key() { return key_; }
		void* get_value() { return value_; }
	private:
		std::string key_;
		void* value_;
};

class BinarySearchTree {
	public:
		BinarySearchTree() : data_(NULL), left_child(NULL), right_child(NULL) {};
		~BinarySearchTree() {
			free(data_);
		}
		BinarySearchTree* find(const std::string &key);
		void insert(std::string key, void *value);
		void modify_val(void *val);
		std::string data() { return data_->get_key(); }
		bool empty() { return data_ == NULL; }
		const std::string get_key() { return data_->get_key(); }
		void* get_value() { return data_->get_value(); }
		BinarySearchTree *get_lchild() { return left_child; }
		BinarySearchTree *get_rchild() { return right_child; }

	private:
		DataNode *data_;
		BinarySearchTree *left_child;
		BinarySearchTree *right_child;
};
void binary_search_tree_endreduce(scoped_ptr<BinarySearchTree> &root);
#endif
