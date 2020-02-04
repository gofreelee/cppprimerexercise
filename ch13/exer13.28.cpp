#include <string>
#include <stack>
using std::stack;
using std::string;
class TreeNode
{
public:
    TreeNode(const string &str = string())
        : value(str), count(new int(1)), left(nullptr), right(nullptr)
    {
    }
    TreeNode(const TreeNode &res)
        : value(res.value), count(res.count), left(res.left), right(res.right)
    {
        ++*count;
    }
    TreeNode &operator=(const TreeNode &res)
    {
        ++*res.count;
        if (--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
        value = res.value;
        count = res.count;
        left = res.left;
        right = res.right;
        return *this;
    }
    ~TreeNode()
    {
        if (--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }

private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &res) : root(new TreeNode(*res.root))
    {
    }
    BinStrTree &operator=(const BinStrTree &res)
    {
        TreeNode *ptr = new TreeNode(*res.root);
        delete root;
        root = ptr;
        return *this;
    }
    ~BinStrTree()
    {
        delete root;
    }

private:

    TreeNode *root;
};
