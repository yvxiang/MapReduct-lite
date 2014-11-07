#include <string>
#include <stdlib.h>
class BinarySearchTree;
class DataNode {
	public :
		DataNode() : value_(NULL) {}
		~DataNode() { free(value_); }
		void set_key(std::string key) { key_ = key; } 
		void set_value(void *value) { value_ = value; }
		const std::string& get_key() { return key_; }
		const void* get_value() { return value_; }
	private:
		std::string key_;
		void *value_;
};

class BinarySearchTree {
	public:
		BinarySearchTree() : data_(NULL), left_child(NULL), right_child(NULL) {};
		~BinarySearchTree() {
			free(data_);
			free(left_child);
			free(right_child);
		}
		bool find(const std::string &key);
		void insert(std::string key, void *value);
		std::string data() { return data_->get_key(); }
		bool empty() { return data_ == NULL; }
		BinarySearchTree *get_lchild() { return left_child; }
		BinarySearchTree *get_rchild() { return right_child; }

	private:
		DataNode *data_;
		BinarySearchTree *left_child;
		BinarySearchTree *right_child;
};
